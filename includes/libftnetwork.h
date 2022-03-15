/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftnetwork.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebastienlecaille <sebastienlecaille@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:32:02 by dgascon           #+#    #+#             */
/*   Updated: 2022/03/15 23:14:19 by sebastienle      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTNETWORK_H
# define LIBFTNETWORK_H

# include <sys/types.h>
# include <netinet/if_ether.h>	/* arp_header */
# include <arpa/inet.h> 		/* inet_ntoa */
# include <errno.h>				/* errno, ENOENT */
# include <string.h>			/* strerror */

# ifdef OSX
// #  include <net/ethernet.h> 		/* ETH_P_ARP, struct ether_header, struct header_addr */
typedef struct ether_header	etherHead_t;
typedef struct ether_addr	macAddr_t;
typedef struct ether_arp	arp_t;
# elif defined LINUX
// #  include <linux/if_ether.h>
// #  include <netinet/if_ether.h>	/* arp_header */

struct arp_hdr {
	struct arphdr	ea_hdr;
	uint8_t			arp_sha[ETHER_ADDR_LEN];
	uint8_t			arp_spa[4];
	uint8_t			arp_tha[ETHER_ADDR_LEN];
	uint8_t			arp_tpa[4];
};

struct	_macAddr
{
	uint16_t			octet[ETH_ALEN];
};

typedef struct ethhdr		etherHead_t;
typedef struct _macAddr		macAddr_t;
typedef struct arp_hdr		arp_t;
# endif


# define IPV4_ADDR_LEN		4
# define ETHER_ADDRSTRLEN	18



/* ARP */
int		fillArpPacket(
	arp_t		*arphdr,
	macAddr_t	*srcMac,
	macAddr_t	*trgMac,
	uint8_t		*srcIp,
	uint8_t		*trgIp,
	uint16_t	arpType);

/* Ether */

int			fillEtherPacket(etherHead_t *eth, macAddr_t *src, macAddr_t *dst, uint16_t type);
void		printMac(macAddr_t *dst, const char *str);
char		*macToStr(const macAddr_t *mac, char dst[ETHER_ADDRSTRLEN]);
macAddr_t	*strToMac(macAddr_t *dst, const char *str);


/* IP */
char		*ipToStr(const struct sockaddr *sa, char *dest, size_t maxlen);

# ifdef OSX
/* BPF */
int		openBpfFile(int *socket, int logFd, int verbose);
# endif // OSX


#endif
