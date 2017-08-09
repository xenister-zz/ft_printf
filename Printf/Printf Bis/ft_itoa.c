/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:45:49 by susivagn          #+#    #+#             */
/*   Updated: 2017/02/14 14:26:21 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(intmax_t n)
{
	char				*str;
	int					sizemalloc;
	intmax_t			nbr;

	nbr = n;
	sizemalloc = ft_strintlen(n);
	if (n < 0)
	{
		nbr = -n;
		sizemalloc++;
	}
	if (!(str = (char*)malloc(sizeof(char) * (sizemalloc + 1))))
		return (NULL);
	str[sizemalloc] = '\0';
	sizemalloc--;
	while (sizemalloc != 0)
	{
		str[sizemalloc] = (nbr % 10) + '0';
		nbr = nbr / 10;
		sizemalloc--;
	}
	str[sizemalloc] = '0' + nbr;
	if (n < 0)
		str[sizemalloc] = '-';
	return (str);
}
