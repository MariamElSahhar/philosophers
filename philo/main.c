/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:58:17 by melsahha          #+#    #+#             */
/*   Updated: 2023/04/17 15:28:29 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	forks[5];
pthread_mutex_t	eat_mutex;

int	next_fork(int index)
{
	index ++;
	if (index == 5)
		return (0);
	return (index);
}


void	*eat(void *i)
{
	int	num;
	int	fork1;
	int	fork2;

	pthread_mutex_lock(&eat_mutex);
	num = *((int*)i);
	fork1 = num;
	fork2 = next_fork(num);
	pthread_mutex_lock(&forks[fork1]);
	pthread_mutex_lock(&forks[fork2]);
	printf("philo %i is eating using forks %i and %i\n", num, fork1, fork2);
	pthread_mutex_unlock(&forks[fork1]);
	pthread_mutex_unlock(&forks[fork2]);
	pthread_mutex_unlock(&eat_mutex);
	return (0);
}

int	main(void)
{
	pthread_t		philos[5];
	int				*philo_id[5];

	for (int i = 0; i < 5; i++)
	{
		philo_id[i] = (int *)ft_calloc(1, sizeof(int));
		*philo_id[i] = i;
		pthread_create(&philos[i], NULL, &eat, (void *) philo_id[i]);
		pthread_mutex_init(&forks[i], NULL);
	}
	pthread_mutex_init(&eat_mutex, NULL);
	for (int i = 0; i < 5; i++)
	{
		pthread_join(philos[i], NULL);
		pthread_mutex_destroy(&forks[i]);
	}
	pthread_mutex_destroy(&eat_mutex);
	return (0);
}
