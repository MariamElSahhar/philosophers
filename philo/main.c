/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:58:17 by melsahha          #+#    #+#             */
/*   Updated: 2023/04/19 15:55:02 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *eat(void *args)
{
	t_args *eat_args = (t_args *)args;
	pthread_mutex_lock(eat_args->eat_mutex);
	int philo_id = eat_args->philo_id;

	pthread_mutex_lock(eat_args->fork1);
	pthread_mutex_lock(eat_args->fork2);

	printf("philo %i is eating using forks %i and %i\n", philo_id, philo_id, (philo_id + 1) % 5);

	pthread_mutex_unlock(eat_args->fork2);
	pthread_mutex_unlock(eat_args->fork1);
	pthread_mutex_unlock(eat_args->eat_mutex);

	return NULL;
}

int main(void)
{
	pthread_t philos[5];
	pthread_mutex_t *forks = malloc(sizeof(pthread_mutex_t) * 5);
	pthread_mutex_t eat_mutex;

	pthread_mutex_init(&eat_mutex, NULL);
	for (int i = 0; i < 5; i++)
		pthread_mutex_init(&forks[i], NULL);

	for (int i = 0; i < 5; i++) {
		t_args *eat_args = malloc(sizeof(t_args));
		eat_args->philo_id = i;
		eat_args->eat_mutex = &eat_mutex;
		if (i == 4)
		{
			eat_args->fork1 = &forks[0];
			eat_args->fork2 = &forks[i];
		}
		else
		{
			eat_args->fork1 = &forks[i];
			eat_args->fork2 = &forks[i + 1];
		}
		pthread_create(&philos[i], NULL, &eat, (void *)eat_args);
		free(eat_args);
	}

	for (int i = 0; i < 5; i++)
		pthread_join(philos[i], NULL);

	for (int i = 0; i < 5; i++)
		pthread_mutex_destroy(&forks[i]);

	free(forks);

	return 0;
}

// valgrind --tool=helgrind ./philo
