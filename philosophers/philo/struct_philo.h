/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_philo.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:35:59 by sgath             #+#    #+#             */
/*   Updated: 2021/07/05 19:10:31 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_PHILO_H
# define STRUCT_PHILO_H

typedef struct s_options_philo
{
	size_t		number_of_philo;
	size_t		time_to_die;
	size_t		time_to_eat;
	size_t		time_to_sleep;
	size_t		number_of_must_eat;
}				t_options_philo;

typedef struct s_all_philo
{
	t_options_philo	philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	time_t			die;
}				t_all_philo

#endif
