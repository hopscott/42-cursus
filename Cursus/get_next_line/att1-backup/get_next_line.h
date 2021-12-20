/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:08:52 by swillis           #+#    #+#             */
/*   Updated: 2021/12/15 18:20:13 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

size_t		ft_strlen(char *str);
size_t		ft_eolcheck(char *str);
char		*ft_strndup(char *src, size_t n);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_freechar(char *s);
char		*ft_concat(char *str, char *buffer);
char		*get_next_line(int fd);
void		ft_realign_buff(char buffer[]);

#endif
