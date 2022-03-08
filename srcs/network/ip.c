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
** Fill dest with the string representation of the IP address sa.
** Support IPv4 and IPv6.
** Keep in mind that maxlen should be big enought
** return a pointer to dest
*/
char *ipToStr(const struct sockaddr *sa, char *dest, size_t maxlen)
{
	switch(sa->sa_family) {
		case AF_INET:
			inet_ntop(AF_INET, &(((struct sockaddr_in *)sa)->sin_addr),
					dest, maxlen);
			break;

		case AF_INET6:
			inet_ntop(AF_INET6, &(((struct sockaddr_in6 *)sa)->sin6_addr),
					dest, maxlen);
			break;
		default:
			ft_strlcpy(dest, "Unknown AF", maxlen);
			return NULL;
	}

	return dest;
}