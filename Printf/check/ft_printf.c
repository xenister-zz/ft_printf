/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 21:06:46 by susivagn          #+#    #+#             */
/*   Updated: 2017/03/23 21:21:50 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_noflags(char *arg)
{
	int		i;

	i = 0;
	while (arg[i])
		g_len += ft_putunicode(arg[i++]);
}

char	*conv_hexa(uintmax_t nbr, char c)
{
	//printf("nbr|%D|\n", nbr);
	if (c == 'x')
		return (ft_itoa_base(nbr, "0123456789abcdef"));

	else if (c == 'X')
		return (ft_itoa_base(nbr, "0123456789ABCDEF"));
	else if (c == 'o' || c == 'O')
		return (ft_itoa_base(nbr, "01234567"));
	return (NULL);
}

int		ft_printf(char *arg, ...)
{
	if (!arg)
		return(0);
	if (!(ft_strchr(arg, '%')))
		ft_noflags(arg);
	else
	{
		printf("VOILA\n");
		va_start(g_vl, arg);
		g_len += ft_putstr_until_a(arg, '%');
		ft_starter_with_flags(arg);
	}
	return (g_len);
}