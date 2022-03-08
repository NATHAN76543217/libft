/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftendian.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebastienlecaille <sebastienlecaille@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:56:07 by dgascon           #+#    #+#             */
/*   Updated: 2022/03/08 14:20:07 by sebastienle      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTENDIAN_H
# define LIBFTENDIAN_H

# ifndef LITTLE_ENDIAN
#  define LITTLE_ENDIAN 1
#  define BIG_ENDIAN    2
# endif

int ft_endian(void);
int ft_r_endian_int(int num);

#endif