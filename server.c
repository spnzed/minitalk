/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:05:45 by aaespino          #+#    #+#             */
/*   Updated: 2022/11/09 14:06:40 by aaespino         ###   ########.fr       */
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
	free(bits);
}

void ft_signal(int signal)
{
	static int 	contador;
	static char *bits;
	char		*aux;

	//aumentamos en 1 el valor de contador
	contador++;
	//si bits es nulo (al inicio del proceso) lo rellenaremos
	//con una string vacia, y ponemos el contador a 1
	if (bits == NULL)
	{
		aux = ft_strdup("");
		contador = 1;
	}
	else
		aux = ft_strdup(bits);
	//depende de la señal que recibe añadimos a bits un 1 o un 0
	if (signal == SIGUSR1)
		bits = ft_strjoin(aux, "0");
	else
		bits = ft_strjoin(aux, "1");
	free(aux);
	//cada vez que se vuelva a entrar a esta funcion, al ser los valores
	//estaticos no variaran y cuando el contador llegue a 8 (el binario completo)
	//mandamos "bits" a la funcion binario_decimal, liberamos el valor y
	//lo igualamos a nulo
	if (contador == 8)
	{
		binario_decimal(bits);
		bits = NULL;
	}
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
