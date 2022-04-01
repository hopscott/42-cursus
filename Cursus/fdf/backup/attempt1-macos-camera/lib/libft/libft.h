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
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef unsigned char uchar;
# define BUFFER_SIZE 100

size_t		ft_strlen(uchar *s);
int		ft_atoi(uchar *nptr);
uchar		*ft_strdup(uchar *s);
uchar		*ft_strjoin(uchar *s1, uchar *s2);
size_t		ft_strlcpy(uchar *dst, uchar *src, size_t size);
size_t		ft_strlen_eol(uchar *s);
uchar		*ft_strjoin_eol(uchar *s1, uchar *s2);
uchar		*ft_strndup(uchar *s, size_t n);
void		ft_bzero(uchar *s, size_t n);
uchar		*get_next_line(int fd);
uchar		**ft_freetbl(uchar **tbl, int pos);
int     	ft_wordcount(uchar *str, uchar c);
uchar		**ft_split(uchar *s, uchar c);

#endif
