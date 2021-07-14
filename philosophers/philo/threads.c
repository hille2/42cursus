/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:52:31 by sgath             #+#    #+#             */
/*   Updated: 2021/07/14 17:50:25 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_one_philo *one)
{
	pthread_mutex_lock(&one->all->print);
	printf("%zu %zu is eating\n", what_time_is_it(one->all->time_start),
		one->num_one);
	pthread_mutex_unlock(&one->all->print);
	pthread_mutex_lock(&one->all->forks[one->left_fork]);
	pthread_mutex_lock(&one->all->forks[one->right_fork]);
	usleep(one->all->time_to_eat * 1000);
	pthread_mutex_unlock(&one->all->forks[one->left_fork]);
	pthread_mutex_unlock(&one->all->forks[one->right_fork]);
}

void	sleeping(t_one_philo *one)
{
	pthread_mutex_lock(&one->all->print);
	printf("%zu %zu is sleeping\n", what_time_is_it(one->all->time_start),
		one->num_one);
	pthread_mutex_unlock(&one->all->print);
	usleep(one->all->time_to_sleep * 1000);
}

void	thinking(t_one_philo *one)
{
	pthread_mutex_lock(&one->all->print);
	printf("%zu %zu is thinking\n", what_time_is_it(one->all->time_start),
		one->num_one);
	pthread_mutex_unlock(&one->all->print);
	
}

void	*thread_fun(void *one)
{
	t_one_philo	*philo;

	philo = (t_one_philo *)one;
	while (1)
	{
		eating(one);
		sleeping(one);
		thinking(one);
	}
}