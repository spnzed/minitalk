/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:05:45 by aaespino          #+#    #+#             */
/*   Updated: 2022/05/11 17:36:47 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler_sigusr1(int signum)
{
	printf("signal %d recieved.\n", signum);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("PID: %d\n", pid);
	signal(SIGUSR1, handler_sigusr1);
	while (1)
		pause();
}
