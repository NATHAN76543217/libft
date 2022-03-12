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
** Fill an Ethernet Packet with provided data
*/
int		fillEtherPacket(etherHead_t *eth, macAddr_t *src, macAddr_t *dst, uint16_t type)
{
	if (!eth || !src || !dst)
		return EXIT_FAILURE;

# ifdef OSX
	ft_memcpy(eth->ether_dhost, dst, ETHER_ADDR_LEN);
	ft_memcpy(eth->ether_shost, src, ETHER_ADDR_LEN);
	eth->ether_type = htons(type);
# else
	ft_memcpy(eth->h_dest, dst, ETHER_ADDR_LEN);
	ft_memcpy(eth->h_source, src, ETHER_ADDR_LEN);
	eth->h_proto = htons(type);
# endif //OSX
	return EXIT_SUCCESS;
}


/*
** Print a Mac address prefixed by str
*/
void	printMac(macAddr_t *addr, const char *str)
{
	dprintf(STDOUT_FILENO, "%s %02x:%02x:%02x:%02x:%02x:%02x\n",
			str,
			addr->octet[0], addr->octet[1],
			addr->octet[2], addr->octet[3],
			addr->octet[4], addr->octet[5]);
	return ;
}


/*
** Convert a MAC address into its string representation.
** return a pointer to dest.
*/
char	*macToStr(const macAddr_t *mac, char dst[ETHER_ADDRSTRLEN])
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
macAddr_t *strToMac(macAddr_t *dst, const char *str)
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
