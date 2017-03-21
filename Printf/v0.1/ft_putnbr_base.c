/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 18:57:33 by susivagn          #+#    #+#             */
/*   Updated: 2016/08/25 18:57:35 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	put_char(char c)
{
	write(1, &c, 1);
}

int		str_len(char *str)
{
	int 	c;

	c = 0;
	while (str[c])
	{
		c++;
	}
	return (c);
}

int		checksa(char *str)
{
	int		c;
	int		d;

	c = 0;
	d = 0;
	while (str[c])
	{	
		d = c + 1;
		while (str[d])
		{
			if (str[c] == str[d] || str[d] == '+' || str[d] == '-')
				return (0);
			d++;
		}
		c++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len;

	len = str_len(base);
	if (len < 2)
		return;
	if (checksa(base) == 1)
	{
		if (nbr < 0)
		{
			put_char('-');
			nbr = -(nbr);
		}
		if (nbr < len)
			put_char(base[nbr]);
			//put_char('0' + nbr);
		if (nbr >= len)
		{
			ft_putnbr_base((nbr / len), base);
			put_char(base[(nbr % len)]);
			//put_char('0' + (nbr % len));
		}
	}
	return;
}

int 	main(int argc, char **argv)
{
	char	*str = "0123456789ABCDEF";

	printf("str = %s\n", str);
	printf("len str = %d\n", str_len(str));
	printf("check = %d\n ---------------\n", checksa(str));
	ft_putnbr_base(123456, str);
	return 0;
}