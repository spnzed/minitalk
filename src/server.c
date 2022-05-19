/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:05:45 by aaespino          #+#    #+#             */
/*   Updated: 2022/05/18 17:36:47 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void handler_sigusr1(int signum)
{
	printf("signal %d recieved.\n", signum);
}

int	main(void)
{
	//pid_t: No es más que un identificador de
	//proceso.
	pid_t	pid;

	//getpid devuelve el identificador de proceso del proceso 
	//actual. (Esto es usado normalmente por rutinas que generan 
	//nombres únicos de ficheros temporales.) getppid devuelve 
	//el identificador de proceso del padre del proceso actual.
	pid = getpid();
	//imprimimos identificador
	printf("PID: %d\n", pid);
	//receptor de la señal
	signal(SIGUSR1, handler_sigusr1);
	while (1)
		pause();
}
