/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:27:48 by gmorange          #+#    #+#             */
/*   Updated: 2021/11/29 13:59:28 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	cycle(t_philo *philo)
{
	put_status(philo, "is thinking");
	eating(philo);
	sleeping(philo);
	if (check_someone_died(philo) == TRUE)
		return (FALSE);
	return (TRUE);
}

void	*ft_philo(void *arg)
{
	t_philo	*philo;
	int		ret;

	philo = arg;
	ret = TRUE;
	if (philo->nbr % 2 == 1)
		usleep(philo->time_to_die / 2);
	if (philo->nbr_of_cycles > 0)
	{
		while (philo->nbr_of_cycles > 0 && ret == TRUE)
		{
			philo->nbr_of_cycles--;
			ret = cycle(philo);
			if (philo->nbr_of_cycles == 0)
			{
				pthread_mutex_lock(&philo->all->mutex_cycle);
				philo->all->nbr_of_cycles = philo->nbr_of_cycles;
				pthread_mutex_unlock(&philo->all->mutex_cycle);
			}
		}
	}
	else
		while (ret == TRUE)
			ret = cycle(philo);
	return (NULL);
}

void	launcher(t_all *all)
{
	int	i;
	int	right;
	int	left;

	i = 0;
	while (i < all->nbr_philo)
	{
		right = i;
		left = i - 1;
		if (i % 2 == 1)
			init_philos(all, i, right, left);
		i++;
	}
	i = 0;
	while (i < all->nbr_philo)
	{
		right = i;
		left = i - 1;
		if (i % 2 == 0)
			init_philos(all, i, right, left);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_all	all;
	int		i;

	i = 0;
	gettimeofday(&all.start, NULL);
	if (ac != 5 && ac != 6)
		return (1);
	if (init(&all, ac, av) == FALSE || all.nbr_of_cycles == 0)
		return (1);
	all.philo = malloc(sizeof(t_philo) * (all.nbr_philo));
	init_forks_mutexes_tab(&all);
	launcher(&all);
	check_death(&all);
	while (i < all.nbr_philo)
	{
		pthread_join(all.philo[i].thr, NULL);
		i++;
	}
	destroy_all(&all);
	free(all.philo);
	return (0);
}
