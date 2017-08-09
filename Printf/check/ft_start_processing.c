/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_processing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 13:42:34 by susivagn          #+#    #+#             */
/*   Updated: 2017/08/08 15:10:19 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_start_processing(char c)
{
	if (g_flags.flagwidth != 0 || g_flags.flagzero != -1)
		g_flags.lm = g_flags.flagwidth >= g_flags.flagzero ? g_flags.flagwidth :
			g_flags.flagzero;
	if (c == 's' || c == 'S' || c == 'c' || c == 'C' || c == '%')
		ft_string_char(c);
	if (c == 'd' || c == 'i' || c == 'D')
		ft_signed_numbers(c);
	if (c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X')
		ft_unsigned_numbers(c);
	if (c == 'p')
		ft_print_adress();
	return (0);
}

void	ft_print_adress(void)
{
	unsigned long	addr;

	if (!(addr = (unsigned long)va_arg(g_vl, void*)))
	{
		g_buff = ft_strdup("0x0", 0);
		ft_process_flag_str(ft_strlen(g_buff));
		return ;
	}
	g_buff = ft_itoa_base(addr, "0123456789abcdef");
	g_buff = ft_append("0x", g_buff, 2);
	ft_process_flag_str(ft_strlen(g_buff));
}

int		ft_check_space(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != ' ')
		i++;
	while (str[i] && str[i] == ' ')
	{
		j++;
		i++;
	}
	return (j);
}
