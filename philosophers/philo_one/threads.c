/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu <yu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:52:31 by sgath             #+#    #+#             */
/*   Updated: 2021/07/17 22:17:26 by yu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eating(t_one_philo *one)
{
	pthread_mutex_lock(&one->eat);
	pthread_mutex_lock(one->smallest_fork);
	pthread_mutex_lock(one->largest_fork);
	one->time_die = what_time_is_it(one->all->time_start) + one->all->time_to_die;
	pthread_mutex_lock(one->print);
	printf("%zu\t %zu is eating\n", what_time_is_it(one->all->time_start), one->num_one);
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
	printf("%zu\t %zu is sleeping\n", what_time_is_it(one->all->time_start), one->num_one);
	pthread_mutex_unlock(one->print);
	my_usleep(one->all->time_start, one->all->time_to_sleep);
}

static void	thinking(t_one_philo *one)
{
	pthread_mutex_lock(&one->all->print);
	//one->time_die = what_time_is_it(one->all->time_start);
	printf("%zu\t %zu is thinking\n", what_time_is_it(one->all->time_start), one->num_one);
	pthread_mutex_unlock(&one->all->print);
	//my_usleep(one->all->time_start,one->all->time_to_die);
	
}

static void	*thread_one(void *one)
{
	t_one_philo	*philo;

	philo = (t_one_philo *)one;
	while (1)
	{
		//pthread_mutex_lock(&philo->eat);
		eating(philo);
		//philo->count_eating++;
		//pthread_mutex_unlock(&philo->eat);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

void	life_cycle(t_all *all)
{
	size_t		i;

	all->thred = malloc(sizeof(pthread_t) * all->num_of_philo);
	if (!all->thred)
		error_exit(MEMORY, NULL, all);
	i = -1;
	while (++i < all->num_of_philo)
	{
		pthread_create(&all->thred[i], NULL, thread_one,
			&all->one[i]);
		pthread_detach(all->thred[i]);
	}
}