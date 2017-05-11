/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_encounter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 18:52:09 by susivagn          #+#    #+#             */
/*   Updated: 2017/05/11 17:55:15 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_encounter(char *str, char *caras)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (caras[j])
		{
			if (str[i] == caras[j])
				return (str[i]);
			j++;
		}
		i++;
	}
	return (0);
}