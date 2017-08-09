/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenmod_unsign.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:20:51 by susivagn          #+#    #+#             */
/*   Updated: 2017/08/08 15:00:53 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	ft_process_lenmod_unsigned(char c)
{
	uintmax_t	nbr;

	if (c == 'U' || c == 'O')
		return (ft_process_lenmod_unsigned_big(void));
	if (g_len_modifier.modhh == 1)
		nbr = (unsigned char)va_arg(g_vl, void*);
	else if (g_len_modifier.modh == 1)
		nbr = (unsigned short)va_arg(g_vl, void*);
	else if (g_len_modifier.modl == 1)
		nbr = (unsigned long)va_arg(g_vl, void*);
	else if (g_len_modifier.modll == 1)
		nbr = (long long)va_arg(g_vl, void*);
	else if (g_len_modifier.modj == 1)
		nbr = (uintmax_t)va_arg(g_vl, void*);
	else if (g_len_modifier.modz == 1)
		nbr = (size_t)va_arg(g_vl, void*);
	else
		nbr = (unsigned int)(va_arg(g_vl, uintmax_t));
	return (nbr);
}

uintmax_t	ft_process_lenmod_unsigned_big(void)
{
	uintmax_t	nbr;

	if (g_len_modifier.modhh == 1 || g_len_modifier.modh == 1 ||
		g_len_modifier.modl == 1 || g_len_modifier.nomod == 1)
		return (unsigned long)va_arg(g_vl, void*);
	else if (g_len_modifier.modll == 1)
		nbr = (unsigned long long)va_arg(g_vl, void*);
	else if (g_len_modifier.modj == 1)
		nbr = (uintmax_t)va_arg(g_vl, void*);
	else if (g_len_modifier.modz == 1)
		nbr = (size_t)va_arg(g_vl, void*);
	else
		nbr = (uintmax_t)(va_arg(g_vl, uintmax_t));
	return (nbr);
}

void		ft_unsigned_numbers(char c)
{
	uintmax_t	nbr;

	nbr = ft_process_lenmod_unsigned(c);
	if (g_flags.flaghtag == 1 && (c == 'x' || c == 'X'))
		g_flags.flaghtag = (c == 'x') ? 1 : 2;
	else if (g_flags.flaghtag == 1 && (c == 'o' || c == 'O'))
		g_flags.flaghtag = 3;
	if (nbr != 0 && (c != 'u' || c != 'U'))
		g_buff = conv_hexa(nbr, c);
	if (c == 'u' || c == 'U')
		g_buff = ft_utoa(nbr);
	if (nbr == 0 && (c != 'u' || c != 'U'))
		g_buff = ft_strdup("0\0", 0);
	if (g_flags.flagprecision >= 0 && (g_flags.flagzero = -1))
	{
		ft_process_precision_nbr(g_buff);
		if (nbr == 0 && g_flags.flaghtag == 3)
			ft_place_htag(g_flags.flaghtag);
		else if (nbr != 0)
			ft_place_htag(g_flags.flaghtag);
	}
	ft_process_flag_str(ft_strlen(g_buff));
	if (g_flags.flaghtag != 0 && nbr != 0)
		ft_place_htag(g_flags.flaghtag);
}
