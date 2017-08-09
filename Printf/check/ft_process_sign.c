/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_sign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:28:46 by susivagn          #+#    #+#             */
/*   Updated: 2017/08/08 15:08:56 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_place_sign_pres(int sign)
{
	if (sign != 0)
	{
		if (sign == -1)
			g_buff = ft_append("-", g_buff, 2);
		else if (sign == 1)
			g_buff = ft_append("+", g_buff, 2);
	}
	g_flags.flagplus = 0;
}

void	ft_sign_zero(int sign)
{
	int		i;

	i = 0;
	if (sign != 0)
	{
		if ((sign == 1) && ft_strcmp("0", g_buff) == 0)
		{
			g_buff = ft_append("+", g_buff, 2);
			g_flags.flagplus = 0;
			return ;
		}
		if ((sign == -1) && ft_strcmp("0", g_buff) == 0)
		{
			g_flags.flagplus = 0;
			return ;
		}
		while (g_buff[i] == ' ' && g_buff[i])
			i++;
		if (i > 0 && ft_strcmp("0", &g_buff[i]) == 0 && sign == 1)
			g_buff[--i] = '+';
		else if (ft_strlen(g_buff) > 0 && ft_isallsame(g_buff, '0') == 1 &&
			sign == 1)
			g_buff[0] = '+';
	}
}

void	ft_place_sign(int sign)
{
	int		i;

	i = 0;
	ft_sign_zero(sign);
	if (sign != 0)
	{
		while (g_buff[i] == ' ' && g_buff[i])
			i++;
		if (g_buff[i] == '0')
			g_buff[i] = (sign < 0) ? '-' : '+';
		else if (i > 0 && ft_isalldigit(&g_buff[i]))
			g_buff[i - 1] = (sign < 0) ? '-' : '+';
		else if (ft_isalldigit(g_buff))
		{
			g_buff = ft_morealloc(g_buff, 1, 1);
			g_buff[i] = (sign < 0) ? '-' : '+';
		}
		else if (i == 0 && (g_buff[i] >= '1' && g_buff[i] <= '9'))
		{
			if (sign == -1)
				g_buff = ft_append("-", g_buff, 2);
			else
				g_buff = ft_append("+", g_buff, 2);
		}
	}
}
