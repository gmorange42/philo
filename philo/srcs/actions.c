/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:38:18 by gmorange          #+#    #+#             */
/*   Updated: 2021/11/26 15:10:17 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	if (philo->all->nbr_philo > 1)
		pthread_mutex_unlock(philo->left_fork);
	else
		return ;
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	put_status(philo, "has taken a fork");
	if (philo->all->nbr_philo > 1)
	{
		pthread_mutex_lock(philo->left_fork);
		put_status(philo, "has taken a fork");
	}
	else
		while (now(philo) <= *(philo->end_of_life))
			usleep(100);
}

void	eating(t_philo *philo)
{
	int	time_of_death;

	take_forks(philo);
	put_status(philo, "is eating");
	pthread_mutex_lock(philo->mutex_of_death);
	*(philo->end_of_life) = now(philo) + philo->time_to_die;
	time_of_death = *(philo->end_of_life);
	pthread_mutex_unlock(philo->mutex_of_death);
	philo->end_of_eat = now(philo) + philo->time_to_eat;
	while (now(philo) < philo->end_of_eat && now(philo) < time_of_death)
		usleep(100);
	release_forks(philo);
}

void	sleeping(t_philo *philo)
{
	int	time_of_death;

	philo->end_of_sleep = now(philo) + philo->time_to_sleep;
	put_status(philo, "is sleeping");
	pthread_mutex_lock(philo->mutex_of_death);
	time_of_death = *(philo->end_of_life);
	pthread_mutex_unlock(philo->mutex_of_death);
	while (now(philo) < philo->end_of_sleep && now(philo) < time_of_death)
		usleep(100);
}
