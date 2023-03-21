/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:05:45 by aaespino          #+#    #+#             */
/*   Updated: 2023/03/21 17:40:28 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	binario_decimal(char *bits)
{
	int				base;
	unsigned int	num;
	int				i;

	num = 0;
	i = 0;
	base = 128;
	while (bits[i])
	{
		num += base * (bits[i] - '0');
		base /= 2;
		i++;
	}
	if (write(1, &num, 1) == -1)
		exit(1);
}

void	ft_signal(int signal)
{
	static char	bits[9];
	static int	contador;

	bits[8] = '\0';
	if (signal == SIGUSR1)
		bits[contador] = '0';
	else
		bits[contador] = '1';
	if (contador == 7)
	{
		binario_decimal(bits);
		contador = -1;
	}
	contador++;
}

void	ft_putstr(char *s)
{
	if (write(1, s, ft_strlen(s)) == -1)
		exit(1);
}

int	main(void)
{
	int		pid;
	char	*pid_str;

	pid = 0;
	pid = getpid();
	ft_putstr("PID: ");
	pid_str = ft_itoa(pid);
	ft_putstr(pid_str);
	if (write(1, "\n", 1) == -1)
		exit(1);
	while (1)
	{
		signal(SIGUSR1, ft_signal);
		signal(SIGUSR2, ft_signal);
		pause();
	}
	return (0);
}
