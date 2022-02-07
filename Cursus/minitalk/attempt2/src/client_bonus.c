/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 22:44:30 by swillis           #+#    #+#             */
/*   Updated: 2022/02/07 22:57:15 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_ready;

void	handler(int sig)
{
	if (sig == SIGUSR1)
		g_ready = 1;
	if (sig == SIGUSR2)
		g_ready = 2;
}

void	init_handler(int pid)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_handler = handler;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	kill(pid, SIGUSR1);
}

int	send_char(int pid, unsigned char c)
{
	unsigned char	*oct;
	size_t			j;

	oct = ft_itobinoct(c);
	if (!oct)
		return (-1);
	j = 0;
	while (j < ft_strlen(oct))
	{
		if (g_ready != 1)
			pause();
		if (oct[j] == '0')
			if (kill(pid, SIGUSR1) == -1)
				return (-1);
		if (oct[j] == '1')
			if (kill(pid, SIGUSR2) == -1)
				return (-1);
		g_ready = 0;
		j++;
	}
	free(oct);
	return (0);
}

int	main(int ac, char **av)
{
	int				pid;
	unsigned char	*str;
	size_t			i;
	unsigned char	c;

	g_ready = 0;
	if (ac == 3)
	{
		pid = ft_atoi((unsigned char *)av[1]);
		str = (unsigned char *)av[2];
		init_handler(pid);
		i = 0;
		while (i <= ft_strlen(str))
		{
			c = str[i];
			if (send_char(pid, c) == -1)
				return (-1);
			i++;
		}
		if (g_ready != 2)
			pause();
		ft_printf(">>> MESSAGE SUCCESSFULLY RECEIVED BY SERVER <<<\n");
	}
	return (0);
}
