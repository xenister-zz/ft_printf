/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 17:24:49 by susivagn          #+#    #+#             */
/*   Updated: 2017/03/29 19:02:09 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "../check/libft.h"

int				ft_printf(char *arg, ...);
int				ft_starter_with_flags(char *arg);
char			*conv_hexa(uintmax_t nbr, char c);
void			ft_noflags(char *arg);
int				ft_putunicodesup(int c);
int				ft_putunicode(int c);
void			ft_get_flags(char *arg, char c);
void			ft_get_len_mod(char *arg, char c);
int				ft_get_width_precision_zero(char *arg, int b);
void			init_struct_flag_lenmod(void);
int				ft_start_processing(char c);
void			ft_string_char(char c);
void			ft_signed_numbers(char c);
void			ft_process_precision_str(char *str, char c);
void			ft_process_precision_nbr(char *str);
void			ft_process_flag_str(int lenstr);
void			ft_char();
void			poire(char *arg);
void			ft_place_sign(int sign);
void			ft_place_sign_pres(int sign);
void			ft_unsigned_numbers(char c);
void			ft_place_htag_pres(int sign);
void			assign_htag(int sign);
void			ft_place_htag(int sign, int i);
intmax_t		ft_process_lenmod_signed();
uintmax_t		ft_process_lenmod_unsigned();
intmax_t		ft_process_lenmod_signed_big();
char			*ft_getwchar(int c);

typedef struct	s_flags
{
	int		flagminus;
	int		flagplus;
	int		flaghtag;
	int		flagspace;
	int		flagprecision;
	int		flagzero;
	int		flagwidth;
	int		lm;

}				t_flags;

typedef struct	s_len_modifier
{
	int		modhh;
	int		modh;
	int		modll;
	int		modl;
	int		modj;
	int		modz;
}				t_len_modifier;

int				g_len;
char 			*g_buff;
va_list			g_vl;
t_flags			g_flags;
t_len_modifier	g_len_modifier;

#endif