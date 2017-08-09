/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_unicode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 19:41:04 by susivagn          #+#    #+#             */
/*   Updated: 2017/08/08 15:11:39 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include <wchar.h>
#include "../check/libft.h"

char	*ft_putwchar(int c);

int		main()
{
	wchar_t		*tab;

	tab = malloc(sizeof(wchar_t) * 6);
	tab[0] = L'ℜ';
	printf("%C\n", tab[0]);
	printf("|%s| ", ft_putwchar(L'È'));
	return (0);
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
		wchar[0] = (((c >> 6) & 0x3F) | 0X80);
		wchar[0] = ((c & 0x3F) | 0x80);
	}
	else if ((c >= 0x10000) && (c <= 0x10FFFF))
	{
		wchar[0] = ((c >> 18) | 0xF0);
		wchar[0] = (((c >> 12) & 0x3F) | 0X80);
		wchar[0] = (((c >> 6) & 0x3F) | 0X80);
		wchar[0] = ((c & 0x3F) | 0x80);
	}
	return (wchar);
}
