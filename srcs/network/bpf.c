/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bpf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlecaill <nlecaill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 19:34:58 by nlecaill           #+#    #+#             */
/*   Updated: 2022/03/08 17:44:33 by nlecaill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

# ifdef OSX
/*
** Open a Bfd file and fill socket with the corresponding fd.
** Log will be written into logFd. Set LogFd to -1 to disable log.
** if verbose is true, output more log
*/
int	openBpfFile(int *socket, int logFd, int verbose)
{
	int		i = 0;
	int		newFd = 0;
	char	buf[100];

	while(i < 99)
	{
		sprintf( buf, "/dev/bpf%i", i );
		newFd = open( buf, O_RDWR );
		if( newFd != -1 ) 
		{
			if (logFd != -1)
				dprintf(logFd, "Opened device /dev/bpf%i\n", i);
			*socket = newFd;
			return EXIT_SUCCESS ;
		}
		else if (errno == ENOENT)
		{
			if (logFd != -1 && verbose)
				dprintf(logFd, "Failed to open bpf%i: %s\n", i, strerror(errno));
			break ;
		}
		else if (logFd != -1 && verbose)
			dprintf(logFd, "Failed to open bpf%i: %s\n", i, strerror(errno));
		i++;
	}
	if (logFd != -1)
		dprintf(logFd, "Failed to open a bpf file (have you the right permissions?)\n");
	return EXIT_FAILURE;
}
# endif //OSX