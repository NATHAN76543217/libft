/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlecaill <nlecaill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 19:34:58 by dgascon           #+#    #+#             */
/*   Updated: 2022/03/08 17:01:29 by nlecaill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

/*
** Fill an ARP Packet with provided data
*/
int	fillArpPacket(
	struct ether_arp	*arphdr,
	struct ether_addr	*srcMac,
	struct ether_addr	*trgMac,
	u_char *srcIp,
	u_char *trgIp,
	u_short arpType)
{
	if (!arphdr || !srcIp || !trgIp || !srcMac || !trgMac)
		return EXIT_FAILURE;
	/* fill ARP header */
	arphdr->ea_hdr.ar_hrd	= htons(ARPHRD_ETHER);
	arphdr->ea_hdr.ar_pro	= htons(ETHERTYPE_IP);
	arphdr->ea_hdr.ar_hln	= ETHER_ADDR_LEN;
	arphdr->ea_hdr.ar_pln	= IPV4_ADDR_LEN;
	arphdr->ea_hdr.ar_op	= htons(arpType);

	/* fill ARP values */
	ft_memcpy(arphdr->arp_tha, srcMac, ETHER_ADDR_LEN);	
	ft_memcpy(arphdr->arp_tpa, srcIp, IPV4_ADDR_LEN);	
	ft_memcpy(arphdr->arp_spa, trgIp, IPV4_ADDR_LEN); 	
	ft_memcpy(arphdr->arp_sha, trgMac, ETHER_ADDR_LEN);
	return EXIT_SUCCESS;
}
