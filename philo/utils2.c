/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:21:00 by melsahha          #+#    #+#             */
/*   Updated: 2023/04/28 15:29:17 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_message(void)
{
	printf("Please enter the following positive integers:\n");
	printf("1- number of philosophers\n2- time to die");
	printf("\n3- time to eat\n4- time to sleep\n");
	printf("(optional) number of times each philosopher must eat\n");
}

unsigned long	ft_atol(const char *str)
{
	unsigned long	res;
	int				i;

	i = 0;
	if (str[i] == '+')
		i++;
	res = 0;
	while (str[i] <= '9' && str[i] >= '0')
	{
		res = res * 10 + (int) str[i] - 48;
		i++;
	}
	return (res);
}

void	free_destroy(t_data *data, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < data->num_philos)
	{
		pthread_join(*philos[i].th_philo, NULL);
		pthread_join(*philos[i].th_monitor, NULL);
	}
	pthread_join(data->meal_monitor, NULL);
	i = -1;
	while (++i < data->num_philos)
	{
		pthread_mutex_destroy(&data->m_forks[i]);
		free(philos[i].th_philo);
		free(philos[i].th_monitor);
	}
	free(data->m_forks);
	free(data->forks_tracker);
	pthread_mutex_destroy(&data->m_eat);
	pthread_mutex_destroy(&data->m_timer);
	pthread_mutex_destroy(&data->m_print);
	free(philos);
}
