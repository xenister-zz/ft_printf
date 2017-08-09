/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 12:27:45 by susivagn          #+#    #+#             */
/*   Updated: 2017/03/21 19:45:57 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src, int freesrc)
{
	size_t	a;
	char	*dst;

	dst = NULL;
	a = ft_strlen(src);
	dst = (char*)malloc(sizeof(char) * (a + 1));
	if (!dst)
		return (NULL);
	a = 0;
	while (src[a])
	{
		dst[a] = src[a];
		a++;
	}
	dst[a] = '\0';
	if (freesrc == 1)
		free(src);
	return (dst);
}
