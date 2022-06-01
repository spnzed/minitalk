/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:05:45 by aaespino          #+#    #+#             */
/*   Updated: 2022/06/01 20:02:07 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void binario_decimal(char *bits)
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
	write(1, &num, 1);
}

void ft_signal(int signal)
{
	static int contador;
	static char *bits;

	contador++;
	if (bits == NULL)
	{
		bits = ft_strdup("");
		contador = 1;
	}

	if (signal == SIGUSR1)
		bits = ft_strjoin(bits, '0');
	else
		bits = ft_strjoin(bits, '1');
	if (contador == 8)
	{
		binario_decimal(bits);
		free(bits);
		bits = NULL;
	}
}

int	main(void)
{
	int	pid;
	char *pid_str;

	pid = 0;
	pid = getpid();
	//getpid devuelve el identificador de proceso del proceso 
	//actual. (Esto es usado normalmente por rutinas que generan 
	//nombres únicos de ficheros temporales.) getppid devuelve 
	//el identificador de proceso del padre del proceso actual.
	ft_putstr("PID: ");
	//metemos el identificador en una placeholder para la string
	pid_str = ft_itoa(pid);
	//imprime la string en cuestion
	ft_putstr(pid_str);
	write(1, "\n", 1);

	while (1)
	{
		//Establecemos los receptores y que haremos con los receptivos
		signal(SIGUSR1, ft_signal);
		signal(SIGUSR2, ft_signal);
		pause();
	}
	return (0);
}