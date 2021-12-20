/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:50:12 by swillis           #+#    #+#             */
/*   Updated: 2021/12/17 19:53:26 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putvar(const char c, va_list vars);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
void	ft_putbase(int n, char *base);
void    ft_putptr(unsigned long long add, char *base);
int		ft_varcheck(const char *str);
int		ft_finddigits_int(int n, int len_base);
int		ft_finddigits_ull(unsigned long long add, int len_base);
int		ft_strlen(char *str);
int		ft_printf(const char *str, ...);

#endif
