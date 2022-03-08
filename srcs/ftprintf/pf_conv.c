/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebastienlecaille <sebastienlecaille@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:36:07 by dgascon           #+#    #+#             */
/*   Updated: 2022/03/08 14:12:37 by sebastienle      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pf_conv4(t_pf *tpf, int i)
{
	if (tpf->specifier == '%' && tpf->fprecision && tpf->vprecision == -1)
		tpf->zero = -1;
	if (ft_charstr(tpf->specifier, "diu"))
		disp_int(tpf, ft_sbase(BASE10));
	else if (tpf->specifier == 's')
		disp_str(tpf);
	else if (tpf->specifier == 'c')
		disp_char(tpf);
	else if (tpf->specifier == 'x')
		disp_int(tpf, ft_sbase(BASE16l));
	else if (tpf->specifier == 'X')
		disp_int(tpf, ft_sbase(BASE16U));
	else if (tpf->specifier == '%')
		disp_percent(tpf);
	else if (tpf->specifier == 'p')
		disp_ptr(tpf, ft_sbase(BASE16l));
	return (i);
}

int	pf_conv3(t_pf *tpf, const char *format, int i)
{
	if (format[i] == '.')
	{
		tpf->fprecision = FT_TRUE;
		tpf->fzero = FT_FALSE;
		i++;
		if (format[i] == '*')
		{
			tpf->vprecision = va_arg(*(tpf->ap), int);
			i++;
			if (tpf->vprecision < 0)
			{
				tpf->vprecision = -1;
				tpf->fprecision = FT_FALSE;
			}
		}
		else if (ft_isdigit(format[i]))
		{
			tpf->vprecision = ft_atoi(format + i);
			while (ft_isdigit(format[i]))
				i++;
		}
	}
	tpf->specifier = format[i++];
	return (pf_conv4(tpf, i));
}

int	pf_conv2(t_pf *tpf, const char *format, int i)
{
	if (format[i] == '*')
	{
		tpf->width = va_arg(*(tpf->ap), int);
		if (tpf->width < 0)
		{
			tpf->fmoins = FT_TRUE;
			tpf->width *= -1;
		}
		i++;
	}
	else
	{
		tpf->width = ft_atoi(format + i);
		while (ft_isdigit(format[i]))
			i++;
	}
	return (pf_conv3(tpf, format, i));
}

int	pf_conv(t_pf *tpf, const char *format)
{
	int	i;

	i = 0;
	while (ft_charstr(format[i], "-+0# \'"))
	{
		(format[i] == '-') ? tpf->fmoins = FT_TRUE : 0;
		(format[i] == '#') ? tpf->fdiese = FT_TRUE : 0;
		(format[i] == '0') ? tpf->fzero = FT_TRUE : 0;
		(format[i] == '+') ? tpf->fplus = FT_TRUE : 0;
		(format[i] == ' ') ? tpf->fspace = FT_TRUE : 0;
		(format[i] == '\'') ? tpf->fapostrophe = FT_TRUE : 0;
		i++;
	}
	return (pf_conv2(tpf, format, i));
}
