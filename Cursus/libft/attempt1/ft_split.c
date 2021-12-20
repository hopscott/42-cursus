/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:43:24 by swillis           #+#    #+#             */
/*   Updated: 2021/12/02 11:15:43 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_freetbl(char **tbl, int pos)
{
	while (pos)
	{
		free(tbl[pos]);
		pos--;
	}
	free(tbl[pos]);
	free(tbl);
	return (0);
}

static int	ft_wordcount(char const *str, char c)
{
	int	i;
	int	wrd;

	i = 0;
	wrd = 0;
	while (str[i])
	{
		while ((c == str[i]) && str[i])
			i++;
		if ((c != str[i]) && str[i])
			wrd++;
		while ((c != str[i]) && str[i])
			i++;
	}
	return (wrd);
}

static int	ft_wordlen(char const *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] && (c == str[i]))
		i++;
	while (str[i] && (c != str[i]))
	{
		len++;
		i++;
	}
	return (len);
}

int	ft_delimskip(char const *s, char c, int i)
{
	while ((c == s[i]) && s[i])
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**tbl;
	char	*elm;
	int		i;
	int		j;
	int		x;

	tbl = malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (!s || !tbl)
		return (0);
	i = 0;
	x = 0;
	while (s[i] && (ft_wordlen(&s[i], c) != 0))
	{
		i = ft_delimskip(s, c, i);
		elm = malloc((ft_wordlen(&s[i], c) + 1) * sizeof(char));
		if (!elm)
			return (ft_freetbl(tbl, x));
		j = 0;
		while ((c != s[i]) && s[i])
			elm[j++] = s[i++];
		elm[j] = 0;
		tbl[x++] = elm;
	}
	tbl[x] = 0;
	return (tbl);
}
