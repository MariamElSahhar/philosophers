/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:50:58 by melsahha          #+#    #+#             */
/*   Updated: 2023/05/08 17:47:56 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_philo	t_philo;

typedef struct s_data {
	int				num_philos;
	int				num_eat;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	int				game_over;
	struct timeval	start_time;
	int				*forks_tracker;
	pthread_mutex_t	m_info;
	pthread_mutex_t	m_eat;
	pthread_mutex_t	m_timer;
	pthread_mutex_t	m_print;
	pthread_mutex_t	*m_forks;
	pthread_t		meal_monitor;
	t_philo			*philos;
}	t_data;

typedef struct s_philo {
	pthread_t		*th_philo;
	pthread_t		*th_monitor;
	int				philo_id;
	int				meals;
	struct timeval	last_meal_start;
	struct timeval	last_meal_end;
	int				left_fork_id;
	int				right_fork_id;
	pthread_mutex_t	*m_left_fork;
	pthread_mutex_t	*m_right_fork;
	t_data			*args;
}	t_philo;

t_philo			*init(t_data *data);
int				parse_input(int c, char **v, t_data *data);
void			free_destroy(t_data *data, t_philo *philos);
int				next_fork(int total, int i, int order);
int				times_up(struct timeval start,
					t_philo *philo, unsigned long dur);
unsigned long	time_since_start(struct timeval start);
int				get_next_philo_id(t_philo *philo);
int				check_game_over(t_data *data);
void			error_message(void);
unsigned long	ft_atol(const char *str);
void			*philosophize(void *philo_data);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);

#endif
