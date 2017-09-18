/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 16:32:34 by susivagn          #+#    #+#             */
/*   Updated: 2017/09/18 18:32:03 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pourcent_chck(char *arg, int i, int l, t_printf *m_struct)
{
	char	c;

	ft_merde_checker(arg, &i, l, m_struct);
	while (arg[i] && i < l)
	{
		while (i < l && arg[i] != '%')
			i++;
		i = (i >= l) ? i : ++i;
		i = ft_minicheck(arg, i, m_struct);
		if ((c = ft_encounter(&arg[i], "sSpdDioOuUxXcC%")) == '%')
		{
			init_struct_flag_lenmod(m_struct);
			ft_get_flags(&arg[i], '%', m_struct);
			ft_start_processing('%', m_struct);
			m_struct->len += ft_putstr(m_struct->buffer);
			m_struct->len += ft_putstr_a_to_b(&arg[i], '%', '%');
			while (i < l && arg[i] != '%')
				i++;
			i = (i >= l) ? i : ++i;
			//free (m_struct->buffer);
		}
		else
			return (i);
	}
	return (i);
}

int		ft_minicheck(char *arg, int i, t_printf *m_struct)
{
	int		j;
	char	c;

	j = 0;
	init_struct_flag_lenmod(m_struct);
	ft_get_flags(&arg[i], '\0', m_struct);
	ft_set_init_flag(m_struct);
	c = ft_encounter(&arg[i], "sSpdDioOuUxXcC%");
	if (c == -1 && m_struct->flagzero == -1 && m_struct->flagwidth == 0)
	{
		j += ft_putstr(&arg[i]);
		m_struct->len += j;
	}
	else if (c == -1 && (m_struct->flagzero != -1 || m_struct->flagwidth != 0))
	{
		i += ft_no_encounter_index(&arg[i], "-+# .0123456789hljz");
		m_struct->buffer = ft_strnew(2, '\0');
		m_struct->buffer[0] = arg[i];
		ft_process_flag_str(ft_strlen(m_struct->buffer), m_struct);
		j += ft_putstr(m_struct->buffer);
		m_struct->len += j;
	}
	return (i++);
}

int		ft_merde_checker(char *arg, int *i, int l, t_printf *m_struct)
{
	char	c;
	int		j;
	int		mem;

	j = 0;
	mem = *i;
	while (arg[*i] && *i < l)
	{
		while (*i < l && arg[*i] != '%')
			(*i)++;
		c = ft_encounter(&arg[*i], "sSpdDioOuUxXcC");
		if (c == -1)
		{
			*i = mem;
			return (1);
		}
		j = ft_no_encounter_until_index(&arg[*i], "-+# .0123456789hljz%", c);
		if (j < 0)
		{
			*i = *i + (-j);
			j = ft_putstr_until_a(&arg[*i], '%');
			m_struct->len += j;
			(*i) += j;
			return (0);
		}
		(*i)++;
	}
	*i = mem;
	return (1);
}

int		ft_starter_with_flags(char *arg, t_printf *m_struct)
{
	int		i;
	int		l;
	char	c;

	i = -1;
	l = ft_strlen(arg);
	while (i++ < l)
	{
		i = ft_pourcent_chck(arg, i, l, m_struct);
		if (i >= l)
			return (0);
		c = ft_encounter(&arg[i], "sSpdDioOuUxXcC");
		if ((ft_no_encounter_until(&arg[i], "-+# .0123456789hljz", c)))
		{
			init_struct_flag_lenmod(m_struct);
			ft_get_flags(&arg[i], c, m_struct);
			ft_get_len_mod(&arg[i], c, m_struct);
			ft_start_processing(c, m_struct);
			m_struct->len += ft_putstr(m_struct->buffer);
		}
		m_struct->len += ft_putstr_a_to_b(&arg[i], c, '%');
	}
	return (0);
}
