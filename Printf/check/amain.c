/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:28:54 by susivagn          #+#    #+#             */
/*   Updated: 2017/03/22 22:30:47 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <locale.h>

int		main(int ac, char **av)
{
	char c = 'r';
	char *str = "dede";
	long long	nbr = 4444444;
	wchar_t myChar1 = L'Ω';
	setlocale(LC_ALL, "");

	if(ac || av)
		;
	printf("------*START*-------\n");

	printf("% -12d|\n", 854);
	ft_printf("% -12d|\n", 854);

	/*printf("|%#0.23s| |%3s| |%04s| |%-04s| |%+011s| |%07.2s| |%-8.4s|\n", "salut", "42", "32", "wq", "43", "salut", "123456789");
	ft_printf("|%#0.23s| |%3s| |%04s| |%-04s| |%+011s| |%07.2s| |%-8.4s|\n", "salut", "42", "32", "wq", "43", "salut", "123456789");

	printf("|%-#3.6hs| |%0.0js| |%+06.12hhs| |%-07lls| |%#-7.3zs|\n", "qwerty", "qwerty", "qwerty", "qwerty", "qwerty");
	ft_printf("|%-#3.6hs| |%0.0js| |%+06.12hhs| |%-07lls| |%#-7.3zs|\n", "qwerty", "qwerty", "qwerty", "qwerty", "qwerty");

	printf("%d\n", printf("|%x| |%#08x| |%#-08x| |%#x| |%#08.6X| |%#-06x| |%++++++-0-++++06X| |%9.6x|\n", 4, 43, 23, 954, 971, 34, 31, 23));
	ft_printf("|%x| |%#08x| |%#-08x| |%#x| |%#08.6X| |%#-06x| |%++++++-0-++++06X| |%9.6x|\n", 4, 43, 23, 954, 971, 34, 31, 23);

	printf("|%012d| |%%| |%D| |% i| |%-05d| |%+4d| |%+9.6d| |%-09.0d| |%12d|\n", nbr, 5, -4, 8, 3, 32, 15, -21);
	ft_printf("|%012d| |%%| |%D| |% i| |%-05d| |%+4d| |%+9.6d| |%-09.0d| |%12d|\n", nbr, 5, -4, 8, 3, 32, 15, -21);

	printf("|%+3d| |%-#3.6d| |%0.0d| |%+06.12d| |%-07d| |%#-7.3d|\n", 5, 676, 8, 123456789, -543, 9876);
	ft_printf("|%+3d| |%-#3.6d| |%0.0d| |%+06.12d| |%-07d| |%#-7.3d|\n", 5, 676, 8, 123456789, -543, 9876);

	printf("|%+3D| |%-#3.6D| |%0.0D| |%+06.12D| |%-07D| |%#-7.3D|\n", -435, -676, -47478, -123456789, -543, -9876);
	ft_printf("|%+3D| |%-#3.6D| |%0.0D| |%+06.12D| |%-07D| |%#-7.3D|\n", -435, -676, -47478, -123456789, -543, -9876);

	printf("|%+05.12c| |%+ 4c| |%13c| |%-07c| |%012c| |%#1c|\n", c, 'a', 'b', 'c', 'd', 'e');
	ft_printf("|%+05.12c| |%+ 4c| |%13c| |%-07c| |%012c| |%#1c|\n\n", c, 'a', 'b', 'c', 'd', 'e');

	printf("|%+3c| |%-#3.6c| |%0.0c| |%+06.12c| |%-07c| |%#-7.3c|\n", 'a', 'b', 'c', 'd', 'e', 'f');
	ft_printf("|%+3c| |%-#3.6c| |%0.0c| |%+06.12c| |%-07c| |%#-7.3c|\n", 'a', 'b', 'c', 'd', 'e', 'f');

	printf("%d\n", printf("|%-8C| |%#0 9lc| |%S|\n", myChar1, L'ℜ', L"ο Δικαιοπολις"));
	ft_printf("|%-8C| |%#0 9c| |%S|\n", myChar1, L'ℜ', L"ο Δικαιοπολις");*/
	return (0);
}