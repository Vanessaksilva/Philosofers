/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:33:45 by vkist-si          #+#    #+#             */
/*   Updated: 2023/04/07 21:08:49 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
#include <string.h>
# include <sys/time.h>

enum e_philo_condition {
	EATING,
	SLEEPING,
	THINKING
};

typedef pthread_mutex_t	t_fork;

typedef struct s_data
{
    time_t	last_meal;
	time_t  death;
    time_t  time_spended;
	t_fork	*forks;
} t_data;

typedef struct s_philo
{
	int	    id;
	int	    tot;
	int 	condition;
    pthread_t thread;
    time_t	time_eat;
	time_t	time_sleep;
    time_t  time_die;
	t_fork	*left_fork;
	t_fork	*right_fork;
    t_data	*data;
} t_philo;

time_t	get_time_in_ms(void);
time_t  eat_philo(t_philo *philo);
void  	sleep_philo(t_philo *philo);
t_philo	*new_philo(t_data *data, char **argv, int i);
t_data	*new_data(char **argv);

#endif