/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:39:34 by gmorange          #+#    #+#             */
/*   Updated: 2021/11/26 14:55:18 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	destroy_all(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->nbr_philo)
	{
		pthread_mutex_destroy(&all->fork[i]);
		i++;
	}
	free(all->fork);
	all->fork = NULL;
	free(all->tab_of_life);
	all->tab_of_life = NULL;
	pthread_mutex_destroy(&all->philo_speak);
	pthread_mutex_destroy(&all->mutex_of_death);
	pthread_mutex_destroy(&all->mutex_cycle);
}
