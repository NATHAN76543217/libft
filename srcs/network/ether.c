/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ip.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlecaill <nlecaill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 19:34:58 by nlecaill           #+#    #+#             */
/*   Updated: 2022/03/08 17:26:13 by nlecaill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"


/*
** Print a Mac address prefixed by str
*/
void	printMac(struct ether_addr *eth, const char *str)
{
	dprintf(STDOUT_FILENO, "%s %02x:%02x:%02x:%02x:%02x:%02x\n",
			str,
			eth->octet[0], eth->octet[1],
			eth->octet[2], eth->octet[3],
			eth->octet[4], eth->octet[5]);
	return ;
}


/*
** Convert a MAC address into its string representation.
** return a pointer to dest.
*/
char	*macToStr(const struct ether_addr *mac, char dst[ETHER_ADDRSTRLEN])
{
	dst[sprintf(dst, "%02x:%02x:%02x:%02x:%02x:%02x",
		mac->octet[0], mac->octet[1],
		mac->octet[2], mac->octet[3],
		mac->octet[4], mac->octet[5]
		)] = '\0';
	return dst;
}


/*
** Extract a MAC address from a string str and store it into dst.
** return a pointer to dest.
*/
struct ether_addr	*strToMac(struct ether_addr *dst, const char *str)
{
	int i = 0;
	int x = 0;
	int number = 0;
	int digit = 0;

	dprintf(STDOUT_FILENO, "str = `%s`\n", str);
	while (str[i] && x < 6)
	{
		if (str[i] == ':')
		{
			i++;
			continue ;
		}
		
		number = ft_atoi_base(str + i, "0123456789ABCDEF");
		digit = ft_digit_base(number, "0123456789ABCDEF");
		dst->octet[x] = number;
		i += digit;
		x++;
	}

	return dst;
}
