/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:50:12 by swillis           #+#    #+#             */
/*   Updated: 2022/01/06 20:00:35 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_varcheck(const char *str);
int		ft_putvar(const char c, va_list vars);
int		ft_printf(const char *str, ...);
int		ft_putchar_len(char c);
int		ft_strlen(char *str);
int		ft_putstr_len(char *s);
int		ft_intlen(int n, char *base);
void	ft_putint(int n, char *base);
int		ft_putint_len(int n, char *base);
int		ft_uintlen(unsigned int n, char *base);
void	ft_putuint(unsigned int n, char *base);
int		ft_putuint_len(unsigned int n, char *base);
int		ft_ulllen(unsigned long long n, char *base);
void	ft_putull(unsigned long long n, char *base);
int		ft_putptr(unsigned long long add, char *base);

#endif
