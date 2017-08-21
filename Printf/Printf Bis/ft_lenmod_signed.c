/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenmod_signed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:20:04 by susivagn          #+#    #+#             */
/*   Updated: 2017/08/21 19:52:56 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	ft_process_lenmod_signed(t_printf *m_struct)
{
	intmax_t	nbr;

	if (m_struct->modhh == 1 || m_struct->modh == 1)
	{
		nbr = (int)va_arg(m_struct->vap, void*);
		if (m_struct->modhh == 1)
			nbr = (char)nbr;
		else if (m_struct->modh == 1)
			nbr = (short)nbr;
		return (nbr);
	}
	else if (m_struct->modl == 1)
		nbr = (long)va_arg(m_struct->vap, void*);
	else if (m_struct->modll == 1)
		nbr = (long long)va_arg(m_struct->vap, long long);
	else if (m_struct->modj == 1)
		nbr = (intmax_t)va_arg(m_struct->vap, void*);
	else if (m_struct->modz == 1)
		nbr = (size_t)va_arg(m_struct->vap, void*);
	else
		nbr = (int)va_arg(m_struct->vap, void*);
	return (nbr);
}

intmax_t	ft_process_lenmod_signed_big(t_printf *m_struct)
{
	intmax_t	nbr;

	if (m_struct->modhh == 1 || m_struct->modh == 1 ||
			m_struct->modl == 1 || m_struct->nomod == 1)
		return ((long)va_arg(m_struct->vap, void*));
	else if (m_struct->modll == 1)
		nbr = (long long)va_arg(m_struct->vap, void*);
	else if (m_struct->modj == 1)
		nbr = (intmax_t)va_arg(m_struct->vap, void*);
	else if (m_struct->modz == 1)
		nbr = (size_t)va_arg(m_struct->vap, void*);
	else
		nbr = (int)va_arg(m_struct->vap, void*);
	return (nbr);
}

void		ft_signed_numbers(char c, t_printf *m_struct)
{
	if (c == 'd' || c == 'i')
		m_struct->buffer = ft_itoa(ft_process_lenmod_signed(m_struct));
	else
		m_struct->buffer = ft_itoa(ft_process_lenmod_signed_big(m_struct));
	if (ft_strchr(m_struct->buffer, '-') && (m_struct->flagplus = -1))
		m_struct->buffer = ft_strdup(&m_struct->buffer[1], 0);
	if (m_struct->flagspace == 1 && ((m_struct->flagwidth == 0 &&
					m_struct->flagprecision == -1) || (m_struct->flagwidth <
						m_struct->flagprecision)))
		m_struct->buffer = ft_append(" ", m_struct->buffer, 2);
	if (m_struct->flagprecision != -1 && (m_struct->flagzero = -1))
		ft_process_precision_nbr(m_struct->buffer, m_struct);
	ft_process_flag_str(ft_strlen(m_struct->buffer), m_struct);
	ft_place_sign(m_struct->flagplus, m_struct);
}
