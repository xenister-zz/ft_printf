/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_precision_flag.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:24:19 by susivagn          #+#    #+#             */
/*   Updated: 2017/08/08 15:05:01 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_flag_str(int lenstr)
{
	char	*buff;
	int		len;

	if (g_flags.flagplus != 0 && g_flags.flagminus == 1)
		g_flags.lm--;
	if (g_flags.lm >= lenstr)
	{
		len = g_flags.lm >= lenstr ? g_flags.lm : lenstr;
		buff = (char*)ft_memalloc((sizeof(char) * len), ' ');
		buff[len] = '\0';
		if (g_flags.flagminus == 0 && g_flags.flagzero != -1)
		{
			ft_str_fill_nchar_rl(buff, '0', g_flags.flagzero);
			g_buff = ft_place_in_str(buff, g_buff, 1);
		}
		else if (g_flags.flagminus == 1)
			g_buff = ft_place_in_str(buff, g_buff, 0);
		else
			g_buff = ft_place_in_str(buff, g_buff, 1);
	}
}

void	ft_process_precision_str(char *str, char c)
{
	int		lenstr;

	lenstr = ft_strlen(str);
	if (g_flags.flagprecision >= lenstr)
		g_buff = str;
	else if (g_flags.flagprecision == 0 && (c == 'c' || c == 'C'))
	{
		g_flags.flagprecision = 1;
		g_buff = ft_strsub(str, 0, g_flags.flagprecision);
	}
	else if (g_flags.flagprecision == 0 && (c != 'c' || c != 'C'))
		g_buff = ft_strsub(str, 0, 0);
	else
		g_buff = ft_strsub(str, 0, g_flags.flagprecision);
}

void	ft_process_precision_nbr(char *str)
{
	int		lenstr;
	int		sizeprecision;

	lenstr = ft_strlen(str);
	if (g_flags.flagprecision == 0 && g_buff[0] == '0')
		g_buff = ft_strdup("", 0);
	else if (g_flags.flagprecision > lenstr)
	{
		g_buff = ft_memalloc((sizeof(char) * (g_flags.flagprecision + 1)), ' ');
		g_buff[g_flags.flagprecision] = '\0';
		sizeprecision = g_flags.flagprecision - lenstr;
		ft_str_fill_nchar_lr(g_buff, '0', sizeprecision);
		ft_place_in_str(&g_buff[sizeprecision], str, 0);
		ft_place_sign_pres(g_flags.flagplus);
	}
	else if (g_flags.flagprecision <= lenstr)
	{
		g_buff = str;
		ft_place_sign(g_flags.flagplus);
	}
}
