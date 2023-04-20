/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:58:17 by melsahha          #+#    #+#             */
/*   Updated: 2023/04/20 14:47:04 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int c, char **v)
{
	t_data	data;
	t_philo	*philos;

	gettimeofday(&data.start_time, 0);
	if (parse_input(c, v, &data))
	{
		philos = init(&data);
		for (int i = 0; i < data.num_philos; i++)
			pthread_create(philos[i].th_philo, NULL, &philosophize, (void *) &philos[i]);
		free_destroy(&data, philos);
	}
	else
	{
		printf("Please enter the following positive integers:\n");
		printf("1- number of philosophers\n2- time to die");
		printf("\n3- time to eat\n4- time to sleep\n");
		printf("(optional) number of times each philosopher must eat\n");
	}
	return (0);
}

// valgrind --tool=helgrind ./philo
