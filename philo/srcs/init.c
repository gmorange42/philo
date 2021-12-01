/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 09:50:53 by gmorange          #+#    #+#             */
/*   Updated: 2021/11/26 14:55:20 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	init(t_all *all, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_strisonlyc(av[i], "0123456789") == -1)
			return (FALSE);
		i++;
	}
	if (ft_atoi(av[1], &all->nbr_philo) == FALSE || all->nbr_philo == 0)
		return (FALSE);
	if (ft_atoi(av[2], &all->time_to_die) == FALSE)
		return (FALSE);
	if (ft_atoi(av[3], &all->time_to_eat) == FALSE)
		return (FALSE);
	if (ft_atoi(av[4], &all->time_to_sleep) == FALSE)
		return (FALSE);
	all->someone_is_dead = FALSE;
	all->nbr_of_cycles = -1;
	if (ac == 6)
		if (ft_atoi(av[5], &all->nbr_of_cycles) == FALSE)
			return (FALSE);
	return (TRUE);
}

void	init_philos(t_all *all, int i, int right, int left)
{
	if (left < 0)
		left = all->nbr_philo - 1;
	all->philo[i].all = all;
	all->philo[i].end_of_life = &all->tab_of_life[i];
	all->philo[i].nbr_of_cycles = all->nbr_of_cycles;
	all->philo[i].start = all->start;
	all->philo[i].end = all->end;
	all->philo[i].time_to_die = all->time_to_die;
	all->philo[i].time_to_eat = all->time_to_eat;
	all->philo[i].time_to_sleep = all->time_to_sleep;
	all->philo[i].right_fork = &all->fork[right];
	all->philo[i].left_fork = &all->fork[left];
	all->philo[i].philo_speak = &all->philo_speak;
	all->philo[i].mutex_of_death = &all->mutex_of_death;
	all->philo[i].nbr = i + 1;
	all->philo[i].someone_is_dead = &all->someone_is_dead;
	all->tab_of_life[i] = now(&all->philo[i]) + all->time_to_die;
	pthread_create(&all->philo[i].thr, NULL, &ft_philo, &all->philo[i]);
}

void	init_forks_mutexes_tab(t_all *all)
{
	int	i;

	all->fork = malloc(sizeof(pthread_mutex_t) * all->nbr_philo);
	all->tab_of_life = malloc(sizeof(int) * all->nbr_philo);
	i = 0;
	while (i < all->nbr_philo)
	{
		pthread_mutex_init(&all->fork[i], NULL);
		i++;
	}
	pthread_mutex_init(&all->philo_speak, NULL);
	pthread_mutex_init(&all->mutex_of_death, NULL);
	pthread_mutex_init(&all->mutex_cycle, NULL);
}
