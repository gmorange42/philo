/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:58:12 by gmorange          #+#    #+#             */
/*   Updated: 2021/11/26 12:58:45 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	ft_strisonlyc(char *str, char *to_check)
{
	int	i;
	int	j;

	if (str == NULL || to_check == NULL)
		return (-1);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (to_check[j])
		{
			if (str[i] != to_check[j])
				j++;
			else if (str[i] == to_check[j])
				break ;
		}
		if (to_check[j] == 0)
			return (-1);
		i++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str, int *nbr)
{
	int			i;
	long int	res;

	i = 0;
	res = 0;
	while (str[i] == '0')
		i++;
	if (ft_strlen((char *)&str[i]) > 10)
		return (FALSE);
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	if (res > 2147483647)
		return (FALSE);
	*(nbr) = (int)res;
	return (TRUE);
}

void	put_status(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->philo_speak);
	if (check_someone_died(philo) == FALSE)
		printf("%d %d %s\n", now(philo), philo->nbr, str);
	pthread_mutex_unlock(philo->philo_speak);
}
