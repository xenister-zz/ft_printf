/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalldigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:47:55 by susivagn          #+#    #+#             */
/*   Updated: 2017/03/18 13:42:44 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalldigit(char* src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		if ((src[i] < '0' && src[i] > '9') || src[i] == ' ')
			return (i);
		i++;
	}
	return (1);
}