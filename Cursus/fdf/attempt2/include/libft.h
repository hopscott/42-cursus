/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:31:50 by swillis           #+#    #+#             */
/*   Updated: 2022/04/05 13:40:50 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef unsigned char	t_uchar;
# define BUFFER_SIZE 100

int			ft_isnum(unsigned char c);
size_t		ft_strlen(t_uchar *s);
size_t		strlen_eol(unsigned char *str);
t_uchar		*ft_freestr(t_uchar *s);
int			ft_atoi(t_uchar *nptr);
t_uchar		*ft_strdup(t_uchar *s);
t_uchar		*ft_strjoin(t_uchar *s1, t_uchar *s2);
size_t		ft_strlcpy(t_uchar *dst, t_uchar *src, size_t size);
size_t		ft_strlen_eol(t_uchar *s);
t_uchar		*ft_strjoin_eol(t_uchar *s1, t_uchar *s2);
t_uchar		*ft_strndup(t_uchar *s, size_t n);
void		ft_bzero(t_uchar *s, size_t n);
t_uchar		*get_next_line(int fd);
t_uchar		**ft_freetbl(t_uchar **tbl, int pos);
int			ft_wordcount(t_uchar *str, t_uchar c);
t_uchar		**ft_split(t_uchar *s, t_uchar c);

#endif
