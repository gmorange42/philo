/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:33:06 by gmorange          #+#    #+#             */
/*   Updated: 2021/11/25 11:12:01 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

float	time_diff(struct timeval *start, struct timeval *end)
{
	return (1e+3 * ((end->tv_sec - start->tv_sec) + \
			1e-6 * (end->tv_usec - start->tv_usec)));
}

int	now(t_philo *philo)
{
	gettimeofday(&philo->end, NULL);
	return (time_diff(&philo->start, &philo->end));
}
