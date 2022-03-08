/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlecaill <nlecaill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 19:34:58 by dgascon           #+#    #+#             */
/*   Updated: 2022/03/08 18:08:01 by nlecaill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"


static int		ft_check_base(const char *base)
{
	int	count = 0;
	int	count2 = 0;

	if (base[count] == '\0' || base[count + 1] == '\0')
		return (EXIT_FAILURE);
	while (base[count] != '\0')
	{
		count2 = 0;
		if (base[count] == '-' || base[count] == '+')
			return EXIT_FAILURE;
		while (base[count2] != '\0')
		{
			if (count != count2 && base[count] == base[count2])
				return (EXIT_FAILURE);
			count2++;
		}
		count++;
	}
	return (EXIT_SUCCESS);
}


static int		ft_find_index(char ch, const char *base)
{
	int index = 0;

	while (base[index])
	{
		if (ch == base[index])
			return (index);
		index++;
	}
	return (-1);
}

int     ft_atoi_base(const char *str, const char *baseSet)
{
	int result	= 0;
	int base	= 0;
	int negative = 1;
	int i		= 0;

	if (!str || !baseSet || ft_check_base(baseSet))
		return (result);
	while (str[i] != '\0'
		&& (str[i] == '-' || str[i] == '+'))
	{
		negative *= (str[i] == '-') ? -1 : 1;
		i++;
	}

	base = ft_strlen(baseSet);
	while (str[i] != '\0')
	{
		if (ft_find_index(str[i], baseSet) < 0)
			return negative * result;
		result *= base;
		result += (ft_find_index(str[i], baseSet));
		i++;
	}
	return negative * result;
}

