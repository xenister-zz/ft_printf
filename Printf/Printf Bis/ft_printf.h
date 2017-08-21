/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 15:22:17 by susivagn          #+#    #+#             */
/*   Updated: 2017/08/21 19:28:06 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "./libft.h"
# include <stdio.h>

typedef struct	s_printf
{
	va_list	vap;
	int		flagminus;
	int		flagplus;
	int		flaghtag;
	int		flagspace;
	int		flagprecision;
	int		flagzero;
	int		flagwidth;
	int		lm;
	int		nomod;
	int		modhh;
	int		modh;
	int		modll;
	int		modl;
	int		modj;
	int		modz;
	char	*buffer;
	int		len;
}				t_printf;

int				ft_printf(char *arg, ...);
void			ft_noflags(char *arg, t_printf *m_struct);
char			*conv_hexa(uintmax_t nbr, char c);
void			init_struct_flag_lenmod(t_printf *m_struct);
int				ft_pourcent_chck(char *arg, int i, int l, t_printf *m_struct);
int				ft_starter_with_flags(char *arg, t_printf *m_struct);
int				ft_get_width_precision_zero(char *arg, int b, t_printf
	*m_struct);
void			ft_get_len_mod(char *arg, char c, t_printf *m_struct);
void			ft_get_flags(char *arg, char c, t_printf *m_struct);
void			ft_place_htag_pres(int sign, t_printf *m_struct);
void			ft_place_htag(int sign, t_printf *m_struct);
void			ft_put_htag_space_after(int sign, t_printf *m_struct);
void			ft_process_flag_str(int lenstr, t_printf *m_struct);
void			ft_process_precision_str(char *str, char c, t_printf *m_struct);
void			ft_process_precision_nbr(char *str, t_printf *m_struct);
void			ft_place_sign_pres(int sign, t_printf *m_struct);
void			ft_sign_zero(int sign, t_printf *m_struct);
void			ft_place_sign(int sign, t_printf *m_struct);
void			ft_string_char(char c, t_printf *m_struct);
char			*ft_getwchar(int c);
void			ft_char(t_printf *m_struct);
int				ft_big_char(t_printf *m_struct);
intmax_t		ft_process_lenmod_signed(t_printf *m_struct);
intmax_t		ft_process_lenmod_signed_big(t_printf *m_struct);
void			ft_signed_numbers(char c, t_printf *m_struct);
uintmax_t		ft_process_lenmod_unsigned(char c, t_printf *m_struct);
uintmax_t		ft_process_lenmod_unsigned_big(t_printf *m_struct);
void			ft_unsigned_numbers(char c, t_printf *m_struct);
int				ft_start_processing(char c, t_printf *m_struct);
void			ft_print_adress(t_printf *m_struct);
int				ft_check_space(char *str);

#endif
