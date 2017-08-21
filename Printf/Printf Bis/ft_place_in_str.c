/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_in_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:33:29 by susivagn          #+#    #+#             */
/*   Updated: 2017/08/21 15:23:41 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_place_in_str(char *dst, char *src, int b)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (b == 0)
		while (src[i] && dst[i])
		{
			dst[i] = src[i];
			i++;
		}
	if (b == 1)
	{
		i = ft_strlen(dst);
		j = ft_strlen(src);
		while (j >= 0 && i >= 0)
		{
			dst[i] = src[j];
			i--;
			j--;
		}
	}
	return (dst);
}
