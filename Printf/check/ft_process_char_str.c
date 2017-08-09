/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_char_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:32:39 by susivagn          #+#    #+#             */
/*   Updated: 2017/08/08 15:06:19 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_string_char(char c)
{
	int		i;
	char	*cpystr;

	i = 0;
	if (c == 'c' && g_len_modifier.modl == 0)
		ft_char();
	if ((g_len_modifier.modl == 1 && c == 'c') || c == 'C')
		ft_big_char();
	if (c == 's')
	{
		if (!(cpystr = ft_strdup((char*)va_arg(g_vl, char*), 0)))
			cpystr = ft_strdup("(null)", 0);
		if (g_flags.flagprecision != -1)
			ft_process_precision_str(cpystr, c);
		else
			g_buff = ft_strdup(cpystr, 1);
		ft_process_flag_str(ft_strlen(g_buff));
	}
	if (c == '%')
	{
		g_buff = ft_strdup("%", 0);
		ft_process_flag_str(ft_strlen(g_buff));
	}
}

char	*ft_getwchar(int c)
{
	char	*wchar;

	wchar = ft_strnew(5, '\0');
	if (c < 0x80)
		wchar[0] = c;
	else if ((c >= 0x80) && (c < 0x800))
	{
		wchar[0] = ((c >> 6) | 0xC0);
		wchar[1] = ((c & 0x3F) | 0x80);
	}
	else if ((c >= 0x800) && (c < 0x10000))
	{
		wchar[0] = ((c >> 12) | 0xE0);
		wchar[1] = (((c >> 6) & 0x3F) | 0X80);
		wchar[2] = ((c & 0x3F) | 0x80);
	}
	else if ((c >= 0x10000) && (c <= 0x10FFFF))
	{
		wchar[0] = ((c >> 18) | 0xF0);
		wchar[1] = (((c >> 12) & 0x3F) | 0X80);
		wchar[2] = (((c >> 6) & 0x3F) | 0X80);
		wchar[3] = ((c & 0x3F) | 0x80);
	}
	return (wchar);
}

void	ft_char(void)
{
	char	c;

	c = (char)va_arg(g_vl, void*);
	if (c == 0)
		g_len++;
	if (!c && g_flags.flagminus == 1)
		write(1, "\0", 1);
	if (!c && g_flags.flagzero != -1)
		g_flags.lm--;
	if (c == 0 && g_flags.flagwidth > 0)
		g_flags.lm--;
	g_buff = ft_strnew(2, '\0');
	g_buff[0] = c;
	ft_process_flag_str(ft_strlen(g_buff));
	if (!c && g_flags.flagminus == 0)
	{
		g_len += ft_putstr(g_buff);
		write(1, "\0", 1);
		*g_buff = 0;
	}
}

int		ft_big_char(void)
{
	int		c;
	int		taille;

	c = (int)va_arg(g_vl, void*);
	if (c == 0)
		g_len++ && write(1, "\0", 1);
	taille = ft_size_unicode(c);
	g_buff = ft_getwchar(c);
	return (taille);
}
