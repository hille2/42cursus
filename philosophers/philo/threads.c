/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:52:31 by sgath             #+#    #+#             */
/*   Updated: 2021/07/18 12:52:06 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eating(t_one_philo *one)
{
	pthread_mutex_lock(one->smallest_fork);
	pthread_mutex_lock(one->largest_fork);
	pthread_mutex_lock(one->print);
	printf("%zu\t %zu has taken a fork\n",
		what_time(one->all->t_start), one->num);
	pthread_mutex_unlock(one->print);
	pthread_mutex_lock(&one->eat);
	one->time_die = what_time(one->all->t_start) + one->all->time_die;
	pthread_mutex_lock(one->print);
	printf("%zu\t %zu is eating\n", what_time(one->all->t_start), one->num);
	pthread_mutex_unlock(one->print);
	my_usleep(one->time_die, one->all->time_to_eat);
	one->count_eating++;
	pthread_mutex_unlock(one->smallest_fork);
	pthread_mutex_unlock(one->largest_fork);
	pthread_mutex_unlock(&one->eat);
}

static void	sleeping(t_one_philo *one)
{
	pthread_mutex_lock(one->print);
	printf("%zu\t %zu is sleeping\n", what_time(one->all->t_start), one->num);
	pthread_mutex_unlock(one->print);
	my_usleep(one->all->t_start, one->all->time_to_sleep);
}

static void	thinking(t_one_philo *one)
{
	pthread_mutex_lock(&one->all->print);
	printf("%zu\t %zu is thinking\n", what_time(one->all->t_start), one->num);
	pthread_mutex_unlock(&one->all->print);
}

static void	*thread_one(void *one)
{
	t_one_philo	*philo;

	philo = (t_one_philo *)one;
	while (1)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

void	life_cycle(t_all *all)
{
	size_t		i;

	all->thred = malloc(sizeof(pthread_t) * all->p_count);
	if (!all->thred)
		error_exit(MEMORY, NULL, all);
	i = -1;
	while (++i < all->p_count)
	{
		pthread_create(&all->thred[i], NULL, thread_one,
			&all->one[i]);
		pthread_detach(all->thred[i]);
	}
}
