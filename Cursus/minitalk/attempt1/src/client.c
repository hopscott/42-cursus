/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:35:56 by swillis           #+#    #+#             */
/*   Updated: 2022/02/07 16:34:23 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft.h"
#include "ft_printf.h"

char	*ft_strbase(int n, char *base)
{
	char			*str;
	unsigned int	nb;
	int				digits;
	int				i;

	digits = ft_finddigits_int(n, ft_strleni(base));
	str = malloc(sizeof(char) * (digits + 1));
	if (!str)
		return (0);
	nb = n;
	if (n < 0)
		nb = -n;
	str[digits] = '\0';
	i = digits - 1;
	while (i >= 0)
	{
		if ((i == 0) && (n < 0))
			str[i--] = '-';
		else
			str[i--] = base[nb % ft_strleni(base)];
		nb /= ft_strleni(base);
	}
	return (str);
}

char	*ft_itobinoct(int n)
{
	char	*str;

	str = ft_strbase(n, "01");
	while (ft_strlen(str) < 8)
		str = ft_strjoin("0", str);
	return (str);
}

int	ready;

void	handler(int sig)
{
	if (sig == SIGUSR1)
		ready = 1;
}

int	main(int ac, char **av)
{
	int	pid;
	char	*str;
	unsigned char	c;
	char	*oct;
	size_t	i;
	size_t	j;
	struct sigaction	sa;

	ready = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		str = av[2];

		// set up ping signal to give server client pid
		kill(pid, SIGUSR1);

		// when receive signal can send a bit
		sigemptyset(&sa.sa_mask);
		sa.sa_handler = handler;
		sa.sa_flags = SA_RESTART;
		sigaction(SIGUSR1, &sa, NULL);

		// iterate over each char to convert to binary
		i = 0;
		while (i <= ft_strlen(str))
		{
			c = str[i];
			oct = ft_itobinoct(c);
			j = 0;
			while (j < ft_strlen(oct))
			{

				if (!ready)
					pause();
				ft_printf("Ready for next bit: %c\n", oct[j]);

				if (oct[j] == '0')
					if (kill(pid, SIGUSR1) == -1)
						return (-1);

				if (oct[j] == '1')
					if (kill(pid, SIGUSR2) == -1)
						return (-1);

				ready = 0;
				j++;
			}

			free(oct);
			i++;
		}
	}
	return (0);
}
