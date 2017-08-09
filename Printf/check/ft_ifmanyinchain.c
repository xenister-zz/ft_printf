/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifmanyinchain.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 15:59:11 by susivagn          #+#    #+#             */
/*   Updated: 2017/08/08 14:51:49 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ifmanyinchain(char const *s)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	while (s[i])
	{
		j = 0;
		count = 0;
		while (s[j])
		{
			if (s[i] == s[j])
			{
				count++;
				if (count > 1)
					return (count);
			}
			j++;
		}
		i++;
	}
	return (count);
}
