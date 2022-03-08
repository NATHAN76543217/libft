/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftnetwork.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlecaill <nlecaill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:32:02 by dgascon           #+#    #+#             */
/*   Updated: 2022/03/08 18:22:07 by nlecaill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTNETWORK_H
# define LIBFTNETWORK_H

# include <sys/types.h>
# include <netinet/if_ether.h>	/* arp_header */
# include <net/ethernet.h> 		/* ETH_P_ARP, struct ether_header, struct header_addr */
# include <arpa/inet.h> 		/* inet_ntoa */
# include <errno.h>				/* errno, ENOENT */
# include <string.h>			/* strerror */

# define IPV4_ADDR_LEN 4
# define ETHER_ADDRSTRLEN 18

/* ARP */
int		fillArpPacket(
	struct ether_arp	*arphdr,
	struct ether_addr	*srcMac, struct ether_addr	*trgMac,
	u_char *srcIp, u_char *trgIp,
	u_short arpType);

/* IP */
char	*ipToStr(const struct sockaddr *sa, char *dest, size_t maxlen);

/* BPF */
int		openBpfFile(int *socket, int logFd, int verbose);

/* Ether */
void				printMac(struct ether_addr *dst, const char *str);
char				*macToStr(const struct ether_addr *mac, char dst[ETHER_ADDRSTRLEN]);
struct ether_addr	*strToMac(struct ether_addr *dst, const char *str);


#endif
