/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:05:45 by aaespino          #+#    #+#             */
/*   Updated: 2022/11/10 16:42:08 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void binario_decimal(char *bits)
{
	int				base;
	unsigned int	num;
	int				i;

	num = 0;
	i = 0;
 	base = 128;
	//recibimos cadena de bits y la recorremos
	while (bits[i])
	{
		//num sera la posicion en char de bits pasado a int
		//multiplicamos por la base y despues la dividimos en dos
		//pasamos al siguiente char de la string bits
		num += base * (bits[i] - '0');
		base /= 2;
		i++;
	}
	write(1, &num, 1);
}

void ft_signal(int signal)
{
	static char	bits[9];
	static int 	contador;

	//aumentamos en 1 el valor de contador
	bits[8] = '\0';
	//si bits es nulo (al inicio del proceso) lo rellenaremos
	//con una string vacia, y ponemos el contador a 1
	if (signal == SIGUSR1)
		bits[contador] = '0';
	else
		bits[contador] = '1';
	//depende de la señal que recibe añadimos a bits un 1 o un 0
	if (contador == 7)
	{
		binario_decimal(bits);
		contador = -1;
	}
	contador++;
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
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
		//Establecemos los receptores y que haremos con lo recibido
		signal(SIGUSR1, ft_signal);
		signal(SIGUSR2, ft_signal);
		//pausa en el programa
		pause();
	}
	return (0);
}
