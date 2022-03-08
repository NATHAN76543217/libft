/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capitalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebastienlecaille <sebastienlecaille@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 19:34:58 by dgascon           #+#    #+#             */
/*   Updated: 2022/03/08 14:33:51 by sebastienle      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

/*
** ft_capitalize apply a to_upper operation to every character in str.
** return a pointer to str.
*/
char    *ft_capitalize(char *str)
{
    int i = 0;
    while (str[i])
    {
        str[i] = ft_toupper(str[i]);
        i++;
    }
    return str; 
}