/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 15:14:19 by susivagn          #+#    #+#             */
/*   Updated: 2017/08/08 15:15:00 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pourcent_chck(char *arg, int i, int l)
{
	char	c;

	while (arg[i] && i < l)
	{
		while (i < l && arg[i] != '%')
			i++;
		i = (i >= l) ? i : ++i;
		if ((c = ft_encounter(&arg[i], "sSpdDioOuUxXcC%")) == '%')
		{
			init_struct_flag_lenmod();
			ft_get_flags(&arg[i], '%');
			ft_start_processing('%');
			g_len += ft_putstr(g_buff);
			g_len += ft_putstr_a_to_b(&arg[i], '%', '%');
			while (i < l && arg[i] != '%')
				i++;
			i = (i >= l) ? i : ++i;
		}
		else
			return (i);
	}
	return (i);
}

int		ft_starter_with_flags(char *arg)
{
	int		i;
	int		l;
	char	c;

	i = 0;
	l = ft_strlen(arg);
	while (i < l)
	{
		i = ft_pourcent_chck(arg, i, l);
		if (i >= l)
			return (0);
		c = ft_encounter(&arg[i], "sSpdDioOuUxXcC");
		if ((ft_no_encounter_until(&arg[i], "-+# .0123456789hljz", c)))
		{
			init_struct_flag_lenmod();
			ft_get_flags(&arg[i], c);
			ft_get_len_mod(&arg[i], c);
			ft_start_processing(c);
			g_len += ft_putstr(g_buff);
		}
		g_len += ft_putstr_a_to_b(&arg[i], c, '%');
		i++;
	}
	return (0);
}
