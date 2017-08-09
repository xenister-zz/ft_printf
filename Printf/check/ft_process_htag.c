/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_htag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:26:19 by susivagn          #+#    #+#             */
/*   Updated: 2017/08/08 15:05:38 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_place_htag_pres(int sign)
{
	if (ft_isallhexa(g_buff))
	{
		if (g_buff[0] == '0' && g_buff[1] == '0')
		{
			if (sign == 1)
				g_buff = ft_append("0x", g_buff, 2);
			if (sign == 2)
				g_buff = ft_append("0X", g_buff, 2);
			if (sign == 3)
				return ;
		}
		else if (sign != 3 && g_buff[0] == '0' && g_buff[1] != '0' &&
		g_buff[1] != '\0')
			g_buff = ft_append("0", g_buff, 2);
		else if (sign == 1)
			g_buff = ft_append("0x", g_buff, 2);
		else if (sign == 2)
			g_buff = ft_append("0X", g_buff, 2);
		else if (sign == 3)
			g_buff = ft_append("0", g_buff, 2);
	}
	g_flags.flaghtag = 0;
}

void	ft_place_htag(int sign)
{
	int		i;

	i = 0;
	while (g_buff[i] && g_buff[i] == ' ')
		i++;
	if (g_buff[i] == '0' && g_buff[i + 1] == '0' && (sign == 1 || sign == 2))
		g_buff[i + 1] = (sign == 1) ? 'x' : 'X';
	else if (i > 0 && sign == 3)
		g_buff[i - 1] = '0';
	else if (i > 1 && (sign == 1 || sign == 2))
	{
		g_buff[i - 2] = '0';
		g_buff[i - 1] = (sign == 1) ? 'x' : 'X';
	}
	else if (ft_isallhexa(g_buff))
	{
		if (sign == 1)
			g_buff = ft_append("0x", g_buff, 2);
		if (sign == 2)
			g_buff = ft_append("0X", g_buff, 2);
		if (sign == 3)
			g_buff = ft_append("0", g_buff, 2);
	}
	else if (g_buff[i] != '0' || g_buff[i] != ' ')
		ft_put_htag_space_after(sign);
}

void	ft_put_htag_space_after(int sign)
{
	int		i;
	int		j;

	i = ft_strlen(g_buff);
	j = ft_count_char(g_buff, ' ');
	if (sign == 3)
	{
		g_buff[i - 1] = '\0';
		g_buff = ft_append("0", g_buff, 2);
	}
	if (sign != 3 && j > 1)
	{
		g_buff[i - 1] = '\0';
		g_buff[i - 2] = '\0';
		if (sign == 1)
			g_buff = ft_append("0x", g_buff, 2);
		if (sign == 2)
			g_buff = ft_append("0X", g_buff, 2);
	}
}
