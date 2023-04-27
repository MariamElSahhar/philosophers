/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:58:17 by melsahha          #+#    #+#             */
/*   Updated: 2023/04/27 15:40:39 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_game_over(t_data *data)
{
	int	over;

	pthread_mutex_lock(&data->m_print);
	over = data->game_over;
	pthread_mutex_unlock(&data->m_print);
	return (over);
}

void	*meal_monitor(void *args)
{
	t_data	*data;
	int		i;
	int		done;

	data = (t_data *)args;
	done = 0;
	while (!check_game_over(data) && !done)
	{
		i = -1;
		done = 1;
		pthread_mutex_lock(&data->m_print);
		while (++i < data->num_philos)
		{
			if (data->philos[i].meals < data->num_eat)
				done = 0;
		}
		if (done)
		{
			data->game_over = 1;
			pthread_mutex_unlock(&data->m_print);
			return (0);
		}
		pthread_mutex_unlock(&data->m_print);

	}
	return (0);
}

int	main(int c, char **v)
{
	t_data	data;
	t_philo	*philos;
	int		i;

	gettimeofday(&data.start_time, 0);
	if (parse_input(c, v, &data))
	{
		philos = init(&data);
		i = -1;
		while(++i < data.num_philos)
		{
			pthread_create(philos[i].th_philo, NULL, &philosophize, (void *) &philos[i]);
			pthread_create(philos[i].th_monitor, NULL, &monitor, (void *) &philos[i]);
		}
		pthread_create(&data.meal_monitor, NULL, &meal_monitor, (void *) &data);
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
