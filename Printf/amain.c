/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:28:54 by susivagn          #+#    #+#             */
/*   Updated: 2017/09/27 10:24:07 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <locale.h>
#include <limits.h>
#include "Printf Bis/libft.h"
#include "Printf Bis/ft_printf.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	char c = 'r';
	char *str = "12345+lrmlll";
	long long	nbr = 4444444;
/*	wchar_t myChar1 = L'Ω';*/
	setlocale(LC_ALL, "");

	if(ac || av)
		;

	//printf("|%d|\n", ft_no_encounter_until(str, "-+# .0123456789hljz", c));
	printf("%.0p, %.p", 0, 0);
	printf("% Zoooo");
	//printf("%d---", printf("%hhC, %hhC\n", 0, L'米'));
	//printf("%d---", ft_printf("%hhC, %hhC\n", 0, L'米'));

	// printf("%-rDr+# .012o     |%d\n", 45, 46);
	// ft_printf("%-rDr+# .012o     |%d\n", 45, 46);
	//
	// printf("|aa%%bb|\n");
	// ft_printf("|aa%%bb|\n");
	//
	// printf("|% Zoooo|\n");
	// ft_printf("|% Zoooo|\n");
	//
	// printf("|{%}|\n");
	// ft_printf("|{%}|\n");

	// ft_printf("%#09.3o\n", 0);
	// printf("%#09.3o\n", 0);
	//
	// ft_printf("%#.4o\n", 1);
	// printf("%#.4o\n", 1);
	//
	// ft_printf("%#0.3o\n", 1);
	// printf("%#0.3o\n", 1);
	//
	// ft_printf("%#09.0o\n", 482);
	// printf("%#09.0o\n", 482);
	//
	// ft_printf("%#04096o\n", 1337);

	//printf("------*START*-------\n");

	////printf("%5%\n");
  //
  // t_printf("%#-08x|\n", 42);
  // /printf("%#-08x|\n", 42);
  // t_printf("%-#6o|\n", 2500);
  // /printf("%-#6o|\n", 2500);
  // t_printf("@moulitest: %s|\n", NULL);
  // /printf("@moulitest: %s|\n", NULL);
  // t_printf("%+d|\n", 0);
  // /printf("%+d|\n", 0);
  // t_printf("%lld|\n", -9223372036854775808);
  // /printf("%lld|\n", -9223372036854775808);
  //
  //
  // t_printf("%C\n", L'ë');
  //
  // /printf("% Zoooo\n");
  // /printf("*%#.o*\n", 42);
  // t_printf("|%#.o|\n", 42);
  //
  // /printf("|%d|", ft_printf("%C", 0));
  // /printf("|%d|", //printf("%C", 0));
  // /printf("%O\n", LONG_MAX);
  // t_printf("%O\n", LONG_MAX);
  //
  // ft_printf("|%x|\n", -42);
  // //printf("|%x|\n", -42);
  //
  // ft_printf("%X\n", -42);
  // //printf("%X\n", -42);
  //
  // ft_printf("%x\n", 4294967296);
  // //printf("%x\n", 4294967296);
  //
  // ft_printf("%X\n", 4294967296);
  // //printf("%X\n", 4294967296);
  //
  // ft_printf("%u\n", "-1");
  // //printf("%u\n", "-1");
  //
  // ft_printf("%u\n", "4294967296");
  // //printf("%u\n", "4294967296");
  //
  // t_printf("|% d|\n", 42);
  // /printf("|% d|\n", 42);
  //
  // t_printf("|%-5d|\n", -42);
  // t_printf("|%-05d|\n", -42);
  //
  // /printf("|%-5d|\n", -42);
  // /printf("|%-05d|\n", -42);
  //
  // /printf("%0+5d\n", -42);
  // t_printf("%0+5d\n", -42);
  // /printf("%0+5d\n", 42);
  // t_printf("%0+5d\n", 42);
  // t_printf("|%+d|\n", 0);
  // t_printf("|% 10.5d|\n", 4242);
  // /printf("|% 10.5d|", 4242);
  // /printf("|% Zoooo|\n");
  // t_printf("|% Zoooo|");
  //
  // /printf("|P = %p|", str);
  //
  // t_printf("% 10.5d\n", 4242);
  // /printf("% 10.5d\n", -4242);
  // t_printf("%+d", 0);
  //
  // t_printf("%% %%%% %%%  %%U\n", 4294967296);
  //
  // /printf("NEW STRING\n");
  //
  // t_printf("%U\n", 4294967296);
  // t_printf("%lu\n", -42l);
  // t_printf("%hU\n", 4294967296);
  // t_printf("%lu", -42);
  //
  // t_printf("|@moulitest: %#.o %#.0o|\n", 0, 0);
  // /printf("|@moulitest: %#.o %#.0o|\n", 0, 0);
  //
  // t_printf("%#.8x\n", 42);
  //
  // /printf("%#.8x\n", 42);
  //
  //
  // /printf("@moulitest: %.x %.0x\n", 0, 0);
  //
  // t_printf("@moulitest: %.x %.0x\n", 0, 0);
  //
  // nt size = 100;
  //
  // t_printf("%x\n", 0);
  //
  // t_printf("%X\n", 0);
  //
  // t_printf("%x\n", 4294967296);
  //
  // t_printf("%X\n", 4294967296);
  //
  // t_printf("----------------\n");
  //
  // /printf("%x\n", 0);
  //
  // /printf("%X\n", 0);
  //
  // /printf("%x\n", 4294967296);
  //
  // /printf("%X\n", 4294967296);
  //
  //
  // /printf("%x\n", -42);
  // /printf("%X\n", -42);
  //
  // t_printf("%x\n", 0);
  // t_printf("%X\n", 0);
  //
  // t_printf("%x\n", -42);
  // t_printf("%X\n", -42);
  //
  // t_printf("%X\n", 42);
  // /printf("@moulitest: %s\n", NULL);
  // t_printf("ft == %   3yttt %D  q\n", 42949696);
  //
  // / //printf("|%-8C| |%#0 9lc| |%S|\n", myChar1, L'ℜ', L"ο Δικαιοπολις");
  // / ft_printf("%d\n", ft_printf("|%-8C| |%#0 9lc| |%S|\n", myChar1, L'ℜ', L"ο Δικαιοπολις"));
  //
  // /printf("|%#0.23s| |%3s| |%04s| |%-04s| |%+011s| |%07.2s| |%-8.4s|\n", "salut", "42", "32", "wq", "43", "salut", "123456789");
  // t_printf("|%#0.23s| |%3s| |%04s| |%-04s| |%+011s| |%07.2s| |%-8.4s|\n", "salut", "42", "32", "wq", "43", "salut", "123456789");
  //
  // /printf("|%-#3.6hs| |%0.0js| |%+06.12hhs| |%-07lls| |%#-7.3zs|\n", "qwerty", "qwerty", "qwerty", "qwerty", "qwerty");
  // t_printf("|%-#3.6hs| |%0.0js| |%+06.12hhs| |%-07lls| |%#-7.3zs|\n", "qwerty", "qwerty", "qwerty", "qwerty", "qwerty");
  //
  // /printf("%d\n", //printf("|%x| |%#08x| |%#-08x| |%#x| |%#08.6X| |%#-06x| |%++++++-0-++++06X| |%9.6x|\n", 4, 43, 23, 954, 971, 34, 31, 23));
  // t_printf("|%x| |%#08x| |%#-08x| |%#x| |%#08.6X| |%#-06x| |%++++++-0-++++06X| |%9.6x|\n", 4, 43, 23, 954, 971, 34, 31, 23);
  //
  // /printf("|%012d| |%%| |%D| |% i| |%-05d| |%+4d| |%+9.6d| |%-09.0d| |%12d|\n", nbr, 5, -4, 8, 3, 32, 15, -21);
  // t_printf("|%012d| |%%| |%D| |% i| |%-05d| |%+4d| |%+9.6d| |%-09.0d| |%12d|\n", nbr, 5, -4, 8, 3, 32, 15, -21);
  //
  // /printf("|%+3d| |%-#3.6d| |%0.0d| |%+06.12d| |%-07d| |%#-7.3d|\n", 5, 676, 8, 123456789, -543, 9876);
  // t_printf("|%+3d| |%-#3.6d| |%0.0d| |%+06.12d| |%-07d| |%#-7.3d|\n", 5, 676, 8, 123456789, -543, 9876);
  //
  // /printf("|%+3D| |%-#3.6D| |%0.0D| |%+06.12D| |%-07D| |%#-7.3D|\n", -435, -676, -47478, -123456789, -543, -9876);
  // t_printf("|%+3D| |%-#3.6D| |%0.0D| |%+06.12D| |%-07D| |%#-7.3D|\n", -435, -676, -47478, -123456789, -543, -9876);
  //
  // /printf("|%+05.12c| |%+ 4c| |%13c| |%-07.0c| |%012.0c| |%#1c|\n", c, 'a', 'b', 'c', 'd', 'e');
  // t_printf("|%+05.12c| |%+ 4c| |%13c| |%-07.0c| |%012.0c| |%#1c|\n\n", c, 'a', 'b', 'c', 'd', 'e');
  //
  // /printf("|%+3c| |%-#3.6c| |%0.0c| |%+06.12c| |%-07c| |%#-7.3c|\n", 'w', 'b', 'c', 'd', 'e', 'f');
  // t_printf("|%+3c| |%-#3.6c| |%0.0c| |%+06.12c| |%-07c| |%#-7.3c|\n", 'w', 'b', 'c', 'd', 'e', 'f');
  //
  // / //printf("%d\n", //printf("|%-8C| |%#0 9lc| |%S|\n", myChar1, L'ℜ', L"ο Δικαιοπολις"));
  // / ft_printf("|%-8C| |%#0 9c| |%S|\n", myChar1, L'ℜ', L"ο Δικαιοπολις");
	return (0);
}