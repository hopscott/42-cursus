/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:40:37 by swillis           #+#    #+#             */
/*   Updated: 2021/12/16 13:49:20 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
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
char		*ft_realign_buff(char *s, char buffer[]);
void		ft_bzero(char *s, size_t n);

#endif
