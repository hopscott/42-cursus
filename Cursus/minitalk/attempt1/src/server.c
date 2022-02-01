/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:35:50 by swillis           #+#    #+#             */
/*   Updated: 2022/02/01 20:36:18 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft.h"
#include "ft_printf.h"

////////////////////////////////////////////////////////

int	ft_basefinder(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_findlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\r')
		return (1);
	if (c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int	atoi_base_check(char *base)
{
	int	i;
	int	j;

	if (ft_findlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] == '\t' || base[i] == '\n' || base[i] == '\r')
			return (0);
		if (base[i] == '\v' || base[i] == '\f' || base[i] == ' ')
			return (0);
		j = 0;
		while (base[j])
		{
			if ((base[j] == base[i]) && (i != j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int				i;
	int				sign;
	unsigned int	n;
	int				nbr;

	i = 0;
	n = 0;
	sign = 1;
	while (str[i] && ft_is_space(str[i]))
		i++;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (ft_basefinder(str[i], base) != -1))
	{
		n = n * ft_findlen(base) + ft_basefinder(str[i], base);
		i++;
	}
	nbr = n * sign;
	return (nbr);
}

int	ft_finddigits(int n, int len_base)
{
	int				digits;
	unsigned int	nb;

	if (n == 0)
		return (1);
	digits = 0;
	if (n < 0)
	{
		nb = -n;
		digits++;
	}
	else
		nb = n;
	while (nb > 0)
	{
		nb /= len_base;
		digits++;
	}
	return (digits);
}

char	*ft_itoa_base(int n, char *base)
{
	char			*str;
	unsigned int	nb;
	int				i;

	str = malloc(sizeof(str) * (ft_finddigits(n, ft_findlen(base)) + 1));
	if (n < 0)
		nb = -n;
	else
		nb = n;
	i = ft_finddigits(n, ft_findlen(base)) - 1;
	while (i >= 0)
	{
		str[i] = base[nb % ft_findlen(base)];
		nb /= ft_findlen(base);
		i--;
	}
	if (n < 0)
		str[0] = '-';
	str[ft_finddigits(n, ft_findlen(base))] = '\0';
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		n;
	char	*str;

	if (!atoi_base_check(base_from) || !atoi_base_check(base_to))
		return (NULL);
	n = ft_atoi_base(nbr, base_from);
	str = ft_itoa_base(n, base_to);
	return (str);
}

/////////////////////////////////////////////////////////

int	pidclient;
char	*str;

void	handler(int signum)
{
	if (signum == SIGUSR1)
	{
		str = ft_strjoin(str, "0");
	}
	if (signum == SIGUSR2)
	{
		str = ft_strjoin(str, "1");
	}
}

void	get_pidclient(int sig, siginfo_t *info, void *context)
{
	(void) sig;
	(void) context;

	pidclient = info->si_pid;
}

int	check_eos(char *str)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	if ((len == 0) || (len % 8 != 0))
		return (0);
	i = len - 8;
	while (i < len)
	{
		if (str[i] == '1')
			return (0);
		i++;
	}
	return (1);
}

char	ft_binocttochar(char *bin)
{
	char	*trim;
	char	c;

	trim = malloc(sizeof(char) * 9);
	if (!trim)
		return (0);
	ft_strlcpy(trim, bin, 9);
	c = ft_atoi(ft_convert_base(trim, "01", "0123456789"));
	free(trim);
	return (c);
}

char	*ft_bintostr(char *bin)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	len =  ft_strlen(bin) / 8;
	str = malloc(sizeof(char) * len);
	if (!str)
		return (0);
	i = 0;
	while (i < len)
	{
		j = i * 8;
		str[i] = ft_binocttochar(&bin[j]);
		i++;
	}
	return (str);
}

int	main(void)
{
	int					pid;
	struct sigaction	sac;
	struct sigaction	sa;

	pid = getpid();
	pidclient = -1;
	str = ft_strdup("");
	if (pid != 0)
	{
		// server pid
		ft_printf("PID: %d\n", pid);

		while (1)
		{
			if (pidclient <= 0)
			{
				// Get pid of signal sender - Pong signal
				sigemptyset(&sac.sa_mask);
				sac.sa_flags = SA_SIGINFO;
				sac.sa_sigaction = get_pidclient;
				sigaction(SIGUSR1, &sac, NULL);
				pause();		// wait for signal
			
				// Signal received
				ft_printf("CONNECTED TO CLIENT [%d]\n", pidclient);
			}
	
			// send ping to indicate ready for bit
			kill(pidclient, SIGUSR1);
	
			// set up receiving bit
			sigemptyset(&sa.sa_mask);
			sa.sa_handler = handler;
			sa.sa_flags = SA_RESTART;
			sigaction(SIGUSR1, &sa, NULL);
			sigaction(SIGUSR2, &sa, NULL);

			// send ping to indicate ready for bit
			kill(pidclient, SIGUSR1);
			
			if (check_eos(str))
			{
				ft_printf("%s\n", ft_bintostr(str));
				str = ft_strdup("");
				pidclient = 0;
			}
		}
	}
	return (0);
}
