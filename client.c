/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:01:52 by aaespino          #+#    #+#             */
/*   Updated: 2022/05/11 17:39:40 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int	main(int argc, char *argv[])
{
	int pid;

	if (argc != 2)
	{
		printf("client: invalid arguments\n");
		exit(EXIT_FAILURE);
	}
	pid = atoi(argv[1]);
	kill(pid, SIGUSR1);
	return (0);
}
