/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:11:38 by susivagn          #+#    #+#             */
/*   Updated: 2017/02/06 17:38:11 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_struct_flag(void)
{
	printf("-1-\n");
	g_flags.flagminus = 0;
	g_flags.flagplus = 0;
	g_flags.flaghtag = 0;
	g_flags.flagspace = 0;
	g_flags.flagprecision = 0;
	g_flags.flagzero = 0;
	g_flags.flagwidth = 0;
}

void	init_struct_lenmod(void)
{
	printf("-2-\n");
	g_len_modifier.modhh = 0;
	g_len_modifier.modh = 0;
	g_len_modifier.modll = 0;
	g_len_modifier.modl = 0;
	g_len_modifier.modj = 0;
	g_len_modifier.modz = 0;
}

int		ft_starter_with_flags(char *arg)
{
	int		i;
	int		l;
	char	c;

	i = 0;
	l = ft_strlen(arg);
	init_struct_flag();
	init_struct_lenmod();
	printf("strlen == %zu\n", ft_strlen(arg));
	printf("-3-\n");
	while (i < l)
	{
		printf("i = %d\n", i);
		while (arg[i] && arg[i] != '%')
			i++;
		c = ft_encounter(&arg[i], "sSpdDioOuUxXcC");
		printf("c = %c\n", c);
		printf("--- %s ---\n", arg);
		printf("--- %s ---\n", &arg[i]);
		printf("return encounter == == %d\n", ft_no_encounter_until(&arg[i], "sSpdDioOuUxXcC", c));
		if (!(ft_no_encounter_until(&arg[i], "-+# .0hljz", c)))
		{
			ft_get_flags(&arg[i], c);
			printf("flagminus = %d\n", g_flags.flagminus);
			printf("flagplus = %d\n", g_flags.flagplus);
			printf("flaghtag = %d\n", g_flags.flaghtag);
			printf("flagspace = %d\n", g_flags.flagspace);
			printf("flagprecision = %d\n", g_flags.flagprecision);
			printf("flagzero = %d\n", g_flags.flagzero);
			printf("flagwidth = %d\n", g_flags.flagwidth);
			ft_get_len_mod(&arg[i], c);
			printf("modhh = %d\n", g_len_modifier.modhh);
			printf("modh = %d\n", g_len_modifier.modh);
			printf("modll = %d\n", g_len_modifier.modll);
			printf("modl = %d\n", g_len_modifier.modl);
			printf("modj = %d\n", g_len_modifier.modj);
			printf("modz = %d\n", g_len_modifier.modz);
		}
		i++;
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
		printf("iii === %d\n", i);
	}
}

void	ft_get_flags(char *arg, char c)
{
	int		i;

	i = 0;
	while (arg[i] && arg[i] != c)
	{
		if (arg[i] == '-')
			g_flags.flagminus = 1;
		else if (arg[i] == '+')
			g_flags.flagplus = 1;
		else if (arg[i] == '#')
			g_flags.flaghtag = 1;
		else if (arg[i] == ' ')
			g_flags.flagspace = 1;
		else if (arg[i] == '.')
			g_flags.flagprecision = 1;
		else if (arg[i] == '0')
 			g_flags.flagzero = 1;
		else if (arg[i] == '8')
 			g_flags.flagwidth = 1;
		i++;
	}
}