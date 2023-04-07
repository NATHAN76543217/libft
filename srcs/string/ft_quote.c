/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebastienlecaille <sebastienlecaille@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 04:03:52 by nlecaill          #+#    #+#             */
/*   Updated: 2023/04/08 00:14:58 by sebastienle      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_quote() function take a string and return it between double quotes.
*/

char    *ft_quote(char *s)
{
    if (s == NULL)
        return NULL;
    return ft_strjoin("\"", ft_strjoin(s, "\""));
}
