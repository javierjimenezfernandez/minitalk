/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:55:32 by javjimen          #+#    #+#             */
/*   Updated: 2024/02/22 01:55:40 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

/* ft_printf.c */
int				ft_select_format(char const format, va_list ap, int *len);
int				ft_printf_logic(char const *format, va_list ap, int *len);
int				ft_printf(char const *format, ...);

/* ft_printf_utils.c */
void			ft_str_toupper(char *str);
unsigned int	ft_baselen(char format);
size_t			ft_ulen_base(unsigned long long n, unsigned int base_len);
char			*ft_utoa_base(unsigned long long n, unsigned int base_len);
int				ft_printf_putnbr(char format, char *to_write, int *len);

/* ft_printf_char.c */
int				ft_printf_char(va_list ap, int *len);

/* ft_printf_string.c */
int				ft_printf_string(va_list ap, int *len);

/* ft_printf_pointer.c */
int				ft_printf_pointer(char const format, va_list ap, int *len);

/* ft_printf_int.c */
int				ft_printf_int(char const format, va_list ap, int *len);

/* ft_printf_uint.c */
int				ft_printf_uint(char const format, va_list ap, int *len);

/* ft_printf_hexa.c */
int				ft_printf_hexa(char const format, va_list ap, int *len);

/* ft_printf_percent.c */
int				ft_printf_percent(char const format, int *len);
#endif
