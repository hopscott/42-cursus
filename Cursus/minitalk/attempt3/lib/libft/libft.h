/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:31:50 by swillis           #+#    #+#             */
/*   Updated: 2022/02/07 19:45:37 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

size_t			ft_strlen(unsigned char *s);
int				ft_atoi(unsigned char *nptr);
unsigned char	*ft_strdup(unsigned char *s);
unsigned char	*ft_strjoin(unsigned char *s1, unsigned char *s2);
size_t			ft_strlcpy(unsigned char *dst, unsigned char *src, size_t size);

#endif
