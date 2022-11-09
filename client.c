/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:01:52 by aaespino          #+#    #+#             */
/*   Updated: 2022/11/09 12:37:33 by aaespino         ###   ########.fr       */
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
		//(c >> i) nos coloca en la ultima posicion de los binarios
		// el & 1 traduce a binario el caracter
		bit = (c >> i) & 1;
		//dependiendo del numero mandaremos por una señal u otra al servidor
		if (bit == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		//vamos restando la i para recorrer la string de final a inicio
		--i;
		usleep(150);
	}
}

//esta funcion recorre toda la string mandada
//(que es el segundo argumento) y la manda a 
//la funcion message_bin con un contador basico
void message_char(int pid, char *str)
{
	int i;
	i = 0;
	while (str[i])
	{
		message_bin(pid, str[i]);
		i++;
	}
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

int	main(int argc, char *argv[])
{
	int pid;

	//si nos pasan menos o mas de tres argumentos
	if (argc < 3 || argc > 3)
		//imprimimos que los argumentos son invalidos
		ft_putstr("client: invalid arguments\n");
	//igualamos el pid al caracter numero uno del argumento
	//y lo pasamos a int
	pid = ft_atoi(argv[1]);
	message_char(pid, argv[2]);
	return (0);
}
