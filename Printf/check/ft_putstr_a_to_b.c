/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_a_to_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:55:13 by susivagn          #+#    #+#             */
/*   Updated: 2017/02/14 14:19:36 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_a_to_b(char *str, char a, char b)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != a)
		i++;
	if (!str[i])
	 	return ;
	i++;
	while (str[i] && str[i] != b)
	{
		ft_putunicode(str[i]);
		i++;
	}
}