/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:16:23 by swillis           #+#    #+#             */
/*   Updated: 2022/02/07 18:58:52 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include "libft.h"
# include "ft_printf.h"

int				ft_basefinder(unsigned char c, unsigned char *base);
int				ft_is_space(unsigned char c);
int				atoi_base_check(unsigned char *base);
int				ft_atoi_base(unsigned char *str, unsigned char *base);
unsigned char	*ft_itoa_base(int n, unsigned char *base);
unsigned char	*ft_strbase(int n, unsigned char *base);
unsigned char	*ft_itobinoct(unsigned char c);
unsigned char	*ft_convert_base(unsigned char *nbr, unsigned char *b_from, \
														unsigned char *b_to);
unsigned char	ft_binocttochar(unsigned char *bin);
unsigned char	*ft_bintostr(unsigned char *bin);
int				check_eos(unsigned char *str);

#endif
