/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_initlst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebastienlecaille <sebastienlecaille@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:12:37 by dgascon           #+#    #+#             */
/*   Updated: 2022/03/08 14:12:37 by sebastienle      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pf_initlst(va_list *ap, t_pf *tpf)
{
	tpf->ap = ap;
	tpf->fmoins = FT_FALSE;
	tpf->fprecision = FT_FALSE;
	tpf->fstars = FT_FALSE;
	tpf->fzero = FT_FALSE;
	tpf->fplus = FT_FALSE;
	tpf->fdiese = FT_FALSE;
	tpf->fspace = FT_FALSE;
	tpf->fapostrophe = FT_FALSE;
	tpf->vprecision = -1;
	tpf->whitespace = 0;
	tpf->zero = 0;
	tpf->specifier = ' ';
	tpf->width = 0;
}
