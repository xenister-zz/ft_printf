/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenmod_signed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:20:04 by susivagn          #+#    #+#             */
/*   Updated: 2017/08/08 14:58:08 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	ft_process_lenmod_signed(void)
{
	intmax_t	nbr;

	if (g_len_modifier.modhh == 1 || g_len_modifier.modh == 1)
	{
		nbr = (int)va_arg(g_vl, void*);
		if (g_len_modifier.modhh == 1)
			nbr = (char)nbr;
		else if (g_len_modifier.modh == 1)
			nbr = (short)nbr;
		return (nbr);
	}
	else if (g_len_modifier.modl == 1)
		nbr = (long)va_arg(g_vl, void*);
	else if (g_len_modifier.modll == 1)
		nbr = (long long)va_arg(g_vl, long long);
	else if (g_len_modifier.modj == 1)
		nbr = (intmax_t)va_arg(g_vl, void*);
	else if (g_len_modifier.modz == 1)
		nbr = (size_t)va_arg(g_vl, void*);
	else
		nbr = (int)va_arg(g_vl, void*);
	return (nbr);
}

intmax_t	ft_process_lenmod_signed_big(void)
{
	intmax_t	nbr;

	if (g_len_modifier.modhh == 1 || g_len_modifier.modh == 1 ||
			g_len_modifier.modl == 1 || g_len_modifier.nomod == 1)
		return ((long)va_arg(g_vl, void*));
	else if (g_len_modifier.modll == 1)
		nbr = (long long)va_arg(g_vl, void*);
	else if (g_len_modifier.modj == 1)
		nbr = (intmax_t)va_arg(g_vl, void*);
	else if (g_len_modifier.modz == 1)
		nbr = (size_t)va_arg(g_vl, void*);
	else
		nbr = (int)va_arg(g_vl, void*);
	return (nbr);
}

void		ft_signed_numbers(char c)
{
	if (c == 'd' || c == 'i')
		g_buff = ft_itoa(ft_process_lenmod_signed());
	else
		g_buff = ft_itoa(ft_process_lenmod_signed_big());
	if (ft_strchr(g_buff, '-') && (g_flags.flagplus = -1))
		g_buff = ft_strdup(&g_buff[1], 0);
	if (g_flags.flagspace == 1 && ((g_flags.flagwidth == 0 &&
					g_flags.flagprecision == -1) || (g_flags.flagwidth <
						g_flags.flagprecision)))
		g_buff = ft_append(" ", g_buff, 2);
	if (g_flags.flagprecision != -1 && (g_flags.flagzero = -1))
		ft_process_precision_nbr(g_buff);
	ft_process_flag_str(ft_strlen(g_buff));
	ft_place_sign(g_flags.flagplus);
}
