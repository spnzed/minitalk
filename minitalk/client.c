/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:01:52 by aaespino          #+#    #+#             */
/*   Updated: 2023/03/21 17:38:23 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	message_bin(int pid, char c)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		--i;
		usleep(150);
	}
}

void	message_char(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		message_bin(pid, str[i]);
		i++;
	}
}

void	ft_putstr(char *s)
{
	if (write(1, s, ft_strlen(s)) == -1)
		exit(1);
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc < 3 || argc > 3)
		ft_putstr("client: invalid arguments\n");
	pid = ft_atoi(argv[1]);
	message_char(pid, argv[2]);
	return (0);
}
