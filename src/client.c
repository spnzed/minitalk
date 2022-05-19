/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:01:52 by aaespino          #+#    #+#             */
/*   Updated: 2022/05/19 20:25:55 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int pid;

	//si nos pasan menos o mas de dos argumentos
	if (argc != 2)
	{
		//imprimimos que los argumentos son invalidos
		printf("client: invalid arguments\n");
		//termina la funcion llamada automaticamente
		exit(0);
	}
	//igualamos el pid al caracter numero uno del argumento
	//y lo pasamos a int
	pid = atoi(argv[1]);
	//acaba proceso del pid y de la señal en concreto
	kill(pid, SIGUSR1);
	return (0);
}
