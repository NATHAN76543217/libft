/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebastienlecaille <sebastienlecaille@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 19:34:58 by dgascon           #+#    #+#             */
/*   Updated: 2022/03/08 14:36:00 by sebastienle      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

/*
** ft_strncpy copy len characters from src to dst.
** if src lenght is less than len the rest of dst is filled with '\0'
** return a pointer to dst 
*/
char    *ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i = 0;

	while (src[i] && i < len)
	{
		dst[i] = src[i];
		i++; 
	}
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	} 
	return dst;
}