/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 16:32:34 by susivagn          #+#    #+#             */
/*   Updated: 2017/09/17 19:36:35 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pourcent_chck(char *arg, int i, int l, t_printf *m_struct)
{
	char	c;

	ft_merde_checker(arg, &i, l);
	while (arg[i] && i < l)
	{
		while (i < l && arg[i] != '%')
			i++;
		i = (i >= l) ? i : ++i;
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

int		ft_merde_checker(char *arg, int *i, int l)
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
		j = ft_no_encounter_until_index(&arg[*i], "-+# .0123456789hljz%", c);
		if (j < 0)
		{
			*i = *i + (-j);
			(*i) += ft_putstr_until_a(&arg[*i], '%');
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

	i = 0;
	l = ft_strlen(arg);
	while (i < l)
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
			//free (m_struct->buffer);
		}
		m_struct->len += ft_putstr_a_to_b(&arg[i], c, '%');
		i++;
	}
	return (0);
}
