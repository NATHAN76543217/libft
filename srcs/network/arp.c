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

// # ifdef OSX
void	fillArpHeader(arp_t *arpFrame, uint16_t arpType)
{
		/* fill ARP header */
	arpFrame->ea_hdr.ar_hrd	= htons(ARPHRD_ETHER);
	arpFrame->ea_hdr.ar_pro	= htons(ETHERTYPE_IP);
	arpFrame->ea_hdr.ar_hln	= ETHER_ADDR_LEN;
	arpFrame->ea_hdr.ar_pln	= IPV4_ADDR_LEN;
	arpFrame->ea_hdr.ar_op	= htons(arpType);
}
// # endif //OSX
// #elif defined LINUX
// void	fillArpHeaderLinux(arp_t *arpFrame)
// {
// 
// }
// # endif //LINUX
/*
** Fill an ARP Packet with provided data
*/
int	fillArpPacket(
	arp_t	*arphdr,
	macAddr_t	*srcMac,
	macAddr_t	*trgMac,
	uint8_t *srcIp,
	uint8_t *trgIp,
	uint16_t arpType)
{
	if (!arphdr || !srcIp || !trgIp || !srcMac || !trgMac)
		return EXIT_FAILURE;
// # ifdef OSX
	fillArpHeader(arphdr, arpType);
// # endif //OSX
// #elif defined LINUX
	// fillArpHeaderLinux(arphdr);
// # endif //LINUX


	/* fill ARP values */
	ft_memcpy(arphdr->arp_tha, srcMac, ETHER_ADDR_LEN);	
	ft_memcpy(arphdr->arp_tpa, srcIp, IPV4_ADDR_LEN);	
	ft_memcpy(arphdr->arp_spa, trgIp, IPV4_ADDR_LEN); 	
	ft_memcpy(arphdr->arp_sha, trgMac, ETHER_ADDR_LEN);
	return EXIT_SUCCESS;
}
