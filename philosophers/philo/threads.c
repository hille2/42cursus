/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu <yu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:52:31 by sgath             #+#    #+#             */
/*   Updated: 2021/07/17 14:45:28 by yu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eating(t_one_philo *one)
{
	pthread_mutex_lock(&one->all->print);
	one->last_time = what_time_is_it(one->all->time_start);
	printf("%zu %zu is eating\n", one->last_time, one->num_one);
	pthread_mutex_unlock(&one->all->print);
	pthread_mutex_lock(&one->all->forks[one->left_fork]);
	pthread_mutex_lock(&one->all->forks[one->right_fork]);
	usleep(one->all->time_to_eat * 1000);
	pthread_mutex_unlock(&one->all->forks[one->left_fork]);
	pthread_mutex_unlock(&one->all->forks[one->right_fork]);
}

static void	sleeping(t_one_philo *one)
{
	pthread_mutex_lock(&one->all->print);
	//one->last_time = what_time_is_it(one->all->time_start);
	printf("%zu %zu is sleeping\n", one->last_time, one->num_one);
	pthread_mutex_unlock(&one->all->print);
	usleep(one->all->time_to_sleep * 1000);
}

static void	thinking(t_one_philo *one)
{
	pthread_mutex_lock(&one->all->print);
	//one->last_time = what_time_is_it(one->all->time_start);
	printf("%zu %zu is thinking\n", one->last_time, one->num_one);
	pthread_mutex_unlock(&one->all->print);
	
}

void	*thread_one(void *one)
{
	t_one_philo	*philo;

	philo = (t_one_philo *)one;
	while (1)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
}