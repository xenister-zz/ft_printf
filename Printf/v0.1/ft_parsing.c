/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:11:38 by susivagn          #+#    #+#             */
/*   Updated: 2017/03/18 14:06:36 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_struct_flag_lenmod(void)
{
	g_flags.flagminus = 0;
	g_flags.flagplus = 0;
	g_flags.flaghtag = 0;
	g_flags.flagspace = 0;
	g_flags.flagprecision = -1;
	g_flags.flagzero = -1;
	g_flags.flagwidth = 0;
	g_flags.lm = 0;
	g_len_modifier.modhh = 0;
	g_len_modifier.modh = 0;
	g_len_modifier.modll = 0;
	g_len_modifier.modl = 0;
	g_len_modifier.modj = 0;
	g_len_modifier.modz = 0;
}

int		ft_pourcent_chck(char *arg, int i, int l)
{
	int		j;
	char	c;

	j = 0;
	while (arg[i] && i < l && arg[i] != '%')
		i++;
	if (arg[i + 1] == '%')
	{
		while (arg[i] == '%')
			i++;
		ft_putchar('%');
		ft_putstr_a_to_b(&arg[i - 1], '%', '%');
		while (arg[i] && i < l && arg[i] != '%')
			i++;
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
		c = ft_encounter(&arg[i], "sSpdDioOuUxXcC");
		if (!(ft_no_encounter_until(&arg[i], "-+# .0123456789hljz", c)))
		{
			init_struct_flag_lenmod();
			ft_get_flags(&arg[i], c);
			ft_get_len_mod(&arg[i], c);
			ft_start_processing(&arg[i], c);
			ft_putstr(g_buff);
		}
		ft_putstr_a_to_b(&arg[i], c, '%');
		i++;
	}
	return (0);
}

int		ft_get_width_precision_zero(char *arg, int b)
{
	int		i;

	i = 0;
	if (b == 0)
	{
		g_flags.flagprecision = ft_atoi(arg);
		while (arg[i] && ft_isdigit(arg[i]))
			i++;
		return (i);
	}
	else if (b == 1)
	{
		g_flags.flagwidth = ft_atoi(arg);
		while (arg[i] && ft_isdigit(arg[i]))
			i++;
		return (i);
	}
	else if (b == 2)
	{
		g_flags.flagzero = ft_atoi(arg);
		while (arg[i] && ft_isdigit(arg[i]))
			i++;
		return (i);
	}
	return (0);
}

void	ft_get_len_mod(char *arg, char c)
{
	int		i;

	i = 0;
	while (arg[i] && arg[i] != c)
	{
		if (arg[i] == 'h' && arg[i + 1] == 'h' && (i += 2))
			g_len_modifier.modhh = 1;
		else if (arg[i] == 'h' && (i += 1))
			g_len_modifier.modh = 1;
		else if (arg[i] == 'l' && arg[i + 1] == 'l' && (i += 2))
			g_len_modifier.modll = 1;
		else if (arg[i] == 'l' && (i += 1))
			g_len_modifier.modl = 1;
		else if (arg[i] == 'j' && (i += 1))
			g_len_modifier.modj = 1;
		else if (arg[i] == 'z' && (i += 1))
 			g_len_modifier.modz = 1;
		else
			i++;
	}
}

void	ft_get_flags(char *arg, char c)
{
	int		i;

	i = 0;
	while (arg[i] && arg[i] != c)
	{
		if (arg[i] == '-' && (i += 1))
			g_flags.flagminus = 1;
		else if (arg[i] == '+' && (i += 1))
			g_flags.flagplus = 1;
		else if (arg[i] == '#' && (i += 1))
			g_flags.flaghtag = 1;
		else if (arg[i] == ' ' && (i += 1))
			g_flags.flagspace = 1;
		else if (arg[i] == '.' && (i += 1))
			i += ft_get_width_precision_zero(&arg[i], 0);
		else if (arg[i] == '0' && (i += 1))
 			i += ft_get_width_precision_zero(&arg[i], 2);
		else if (ft_isnum_no_zero(arg[i]) && g_flags.flagprecision == -1)
 			i += ft_get_width_precision_zero(&arg[i], 1);
		else
			i++;
	}
}