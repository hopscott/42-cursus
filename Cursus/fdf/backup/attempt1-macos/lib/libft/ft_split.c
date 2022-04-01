/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:43:24 by swillis           #+#    #+#             */
/*   Updated: 2021/12/06 16:19:23 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uchar	**ft_freetbl(uchar **tbl, int pos)
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

int	ft_wordcount(uchar *str, uchar c)
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

int	ft_wordlen(uchar *str, uchar c)
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

uchar	*ft_fillelem(uchar *s, uchar c, int i, uchar *elm)
{
	int	j;

	j = 0;
	while ((c != s[i]) && s[i])
		elm[j++] = s[i++];
	elm[j] = '\0';
	return (elm);
}

uchar	**ft_split(uchar *s, uchar c)
{
	uchar	**tbl;
	uchar	*elem;
	int		i;
	int		x;

	if (!s)
		return (0);
	tbl = malloc((ft_wordcount(s, c) + 1) * sizeof(tbl));
	if (!tbl)
		return (0);
	i = 0;
	x = 0;
	while (s[i] && (ft_wordlen(&s[i], c) != 0))
	{
		while ((c == s[i]) && s[i])
			i++;
		elem = malloc((ft_wordlen(&s[i], c) + 1) * sizeof(elem));
		if (!elem)
			return (ft_freetbl(tbl, x));
		tbl[x++] = ft_fillelem(s, c, i, elem);
		while ((c != s[i]) && s[i])
			i++;
	}
	tbl[x] = 0;
	return (tbl);
}
