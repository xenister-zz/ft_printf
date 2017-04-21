/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_processing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 13:42:34 by susivagn          #+#    #+#             */
/*   Updated: 2017/04/21 19:21:06 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_start_processing(char c)
{
	if (g_flags.flagwidth != 0 || g_flags.flagzero != -1)
		g_flags.lm = g_flags.flagwidth >= g_flags.flagzero ? g_flags.flagwidth :
			g_flags.flagzero;
	if (c == 's' || c == 'S' || c == 'c' || c == 'C')
		ft_string_char(c);
	if (c == 'd' || c == 'i' || c == 'D')
		ft_signed_numbers(c);
	if (c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X')
		ft_unsigned_numbers(c);
	/*if (c == 'p')
		ft_print_adress();*/
	return (0);
}

intmax_t	ft_process_lenmod_signed()
{
	intmax_t	nbr;

	if (g_len_modifier.modhh == 1 || g_len_modifier.modh == 1 ||
		g_len_modifier.modl == 1)
	{
		nbr = (int)va_arg(g_vl, void*);
		if (g_len_modifier.modhh == 1)
			nbr = (char)nbr;
		else if (g_len_modifier.modh == 1)
			nbr = (short)nbr;
		else if (g_len_modifier.modl == 1)
			nbr = (long)nbr;
		return (nbr);
	}
	else if (g_len_modifier.modll == 1)
		nbr = (long long)va_arg(g_vl, void*);
	else if (g_len_modifier.modj == 1)
		nbr = (intmax_t)va_arg(g_vl, void*);
	else if (g_len_modifier.modz == 1)
		nbr = (size_t)va_arg(g_vl, void*);
	else
		nbr = (int)va_arg(g_vl, void*);
	return (nbr);
}

intmax_t	ft_process_lenmod_signed_big()
{
	intmax_t	nbr;

	if (g_len_modifier.modhh == 1 || g_len_modifier.modh == 1 ||
		g_len_modifier.modl == 1)
		return ((intmax_t)va_arg(g_vl, void*));
	else if (g_len_modifier.modll == 1)
		nbr = (long long)va_arg(g_vl, void*);
	else if (g_len_modifier.modj == 1)
		nbr = (intmax_t)va_arg(g_vl, void*);
	else if (g_len_modifier.modz == 1)
		nbr = (size_t)va_arg(g_vl, void*);
	else
		nbr = (int)va_arg(g_vl, void*);
	return (nbr);
}

uintmax_t	ft_process_lenmod_unsigned()
{
	uintmax_t	nbr;

	if (g_len_modifier.modhh == 1)
		nbr = (unsigned char)va_arg(g_vl, void*);
	else if (g_len_modifier.modh == 1)
		nbr = (unsigned short)va_arg(g_vl, void*);
	else if (g_len_modifier.modl == 1)
		nbr = (unsigned long)va_arg(g_vl, void*);
	else if (g_len_modifier.modll == 1)
		nbr = (unsigned long long)va_arg(g_vl, void*);
	else if (g_len_modifier.modj == 1)
		nbr = (uintmax_t)va_arg(g_vl, void*);
	else if (g_len_modifier.modz == 1)
		nbr = (size_t)va_arg(g_vl, void*);
	else
		nbr = (unsigned int)(va_arg(g_vl, uintmax_t));
	return (nbr);
}

void	ft_unsigned_numbers(char c)
{
	uintmax_t	nbr;

	nbr = ft_process_lenmod_unsigned();
	printf("%ju\n", nbr);
	if (g_flags.flaghtag == 1 && (c == 'x' || c == 'X'))
		g_flags.flaghtag = (c == 'x') ? 1 : 2;
	else if (g_flags.flaghtag == 1 && (c == 'o' || c == 'O'))
		g_flags.flaghtag = 3;
	if (nbr != 0 && (c != 'u' || c != 'U'))
		g_buff = conv_hexa(nbr, c);
	if (c == 'u' || c == 'U')
		g_buff = ft_itoa(nbr);
	if (nbr == 0 && (c != 'u' || c != 'U'))
		g_buff = ft_strdup("0\0", 0);
	if (g_flags.flagprecision != -1 && (g_flags.flagzero = -1))
	{
		ft_process_precision_nbr(g_buff);
		if (nbr == 0 && g_flags.flaghtag == 3)
			ft_place_htag(g_flags.flaghtag);
		else if (nbr != 0)
			ft_place_htag(g_flags.flaghtag);
	}
	ft_process_flag_str(ft_strlen(g_buff));
	if (g_flags.flaghtag != 0 && nbr != 0)
		ft_place_htag(g_flags.flaghtag);
}

void	ft_signed_numbers(char c)
{
	if (c == 'd' || c == 'i')
		g_buff = ft_itoa(ft_process_lenmod_signed());
	else
		g_buff = ft_itoa(ft_process_lenmod_signed_big());
	if (ft_strchr(g_buff, '-') && (g_flags.flagplus = -1))
		g_buff = ft_strdup(&g_buff[1], 0);
	if (g_flags.flagspace == 1)
		g_buff = ft_morealloc(g_buff, 1, 1);
	if (g_flags.flagprecision != -1 && (g_flags.flagzero = -1))
		ft_process_precision_nbr(g_buff);
	ft_process_flag_str(ft_strlen(g_buff));
	ft_place_sign(g_flags.flagplus);
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
		sizeprecision = lenstr + (g_flags.flagprecision - lenstr);
		g_buff = ft_memalloc((sizeof(char) * sizeprecision + 1), ' ');
		g_buff[sizeprecision] = '\0';
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
				return;
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
/*
int		ft_isallhexa_space_include(char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		if ((src[i] >= '0' && src[i] <= '9') || (src[i] >= 'A' && src[i] <= 'F') ||
			(src[i] >= 'a' && src[i] <= 'f') || src[i] == ' ')
			i++;
		else
			return (0);
	}
	return (i);
}
*/
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

void	ft_place_sign_pres(int sign)
{
	if (sign != 0)
	{
		g_buff = ft_morealloc(g_buff, 1, 1);
		if (sign == -1)
			g_buff[0] = '-';
		else if (sign == 1)
			g_buff[0] = '+' ;
	}
	g_flags.flagplus = 0;
}

void	ft_place_sign(int sign)
{
	int		i;

	i = 0;
	if (sign != 0)
	{
		while (g_buff[i] == ' ' && g_buff[i])
			i++;
		if (g_buff[i] == '0' && sign == -1)
			g_buff[i] = '-';
		else if (g_buff[i] == '0' && sign == 1)
			g_buff[i] = '+';
		else if (i > 0 && g_buff[i] >= '0' && g_buff[i] <= '9')
			g_buff[i - 1] = (sign < 0) ? '-' : '+';
		else if (ft_isalldigit(g_buff))
		{
			g_buff = ft_morealloc(g_buff, 1, 1);
			g_buff[i] = (sign < 0) ? '-' : '+';
		}
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
		cpystr = ft_strdup((char*)va_arg(g_vl, void*), 0);
		if (!cpystr)
			cpystr = ft_strdup("(null)", 0);
		if (g_flags.flagprecision != -1)
			ft_process_precision_str(cpystr, c);
		else
			g_buff = ft_strdup(cpystr, 1);
		ft_process_flag_str(ft_strlen(g_buff));
	}
}

void	ft_process_flag_str(int lenstr)
{
	char	*buff;
	int		len;

	if (g_flags.lm >= lenstr)
	{
		len = g_flags.lm >= lenstr ? g_flags.lm : lenstr;
		buff = (char*)ft_memalloc((sizeof(char) * len), ' ');
		buff[len] = '\0';
		if (g_flags.flagminus == 0 && g_flags.flagzero != -1)
		{
			ft_str_fill_nchar_rl(buff, '0', g_flags.flagzero);
			g_buff = ft_place_in_str(buff, g_buff , 1);
		}
		else if (g_flags.flagminus == 1)
			g_buff = ft_place_in_str(buff, g_buff, 0);
		else
			g_buff = ft_place_in_str(buff, g_buff, 1);
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

void	ft_char()
{
	char	c;

	c = (char)va_arg(g_vl, void*);
	g_buff = ft_strnew(2, '\0');
	g_buff[0] = c;
	//ft_process_precision_str(g_buff, 'c');
	ft_process_flag_str(ft_strlen(g_buff));
}

int		ft_big_char()
{
	int		c;
	int		taille;

	c = (int)va_arg(g_vl, void*);
	taille = ft_size_unicode(c);
	g_buff = ft_getwchar(c);
	return (taille);
}