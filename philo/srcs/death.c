/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:33:03 by gmorange          #+#    #+#             */
/*   Updated: 2021/11/26 15:07:29 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	check_death(t_all *all)
{
	int	i;

	i = 0;
	while (TRUE)
	{
		if (i == all->nbr_philo)
			i = 0;
		pthread_mutex_lock(&all->mutex_of_death);
		if (now(&all->philo[i]) > all->tab_of_life[i])
		{
			pthread_mutex_lock(&all->mutex_cycle);
			if (all->nbr_of_cycles != 0)
				printf("%d %d died\n", now(&all->philo[i]), all->philo[i].nbr);
			pthread_mutex_unlock(&all->mutex_cycle);
			all->someone_is_dead = TRUE;
			pthread_mutex_unlock(&all->mutex_of_death);
			break ;
		}
		pthread_mutex_unlock(&all->mutex_of_death);
		i++;
	}
}

int	check_someone_died(t_philo *philo)
{
	int	death;

	death = FALSE;
	pthread_mutex_lock(philo->mutex_of_death);
	if (*(philo->someone_is_dead) == TRUE)
		death = TRUE;
	pthread_mutex_unlock(philo->mutex_of_death);
	return (death);
}
