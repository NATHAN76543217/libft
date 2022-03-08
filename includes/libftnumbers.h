/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftnumbers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebastienlecaille <sebastienlecaille@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:32:02 by dgascon           #+#    #+#             */
/*   Updated: 2022/03/08 15:04:58 by sebastienle      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTNUMBERS_H
# define LIBFTNUMBERS_H

int				ft_atoi(const char *str);
int             ft_natoi(const char *str, int n);
int             ft_atoi_base(const char *str, const char *baseSet);
char			*ft_itoa(int n);
char			*ft_itoa_base(int nb, char *charset);
int				ft_digit(long num);
int				ft_digit_base(long num, char *base);
int				ft_digit_ul_base(unsigned long num, char *base);
int				ft_digit_format_base(long num, char *base);
#endif
