/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:17:49 by gmorange          #+#    #+#             */
/*   Updated: 2021/11/26 15:06:44 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define TRUE 1
# define FALSE 0

typedef struct s_all	t_all;

typedef struct s_philo
{
	struct timeval	start;
	struct timeval	end;
	pthread_t		thr;
	int				nbr;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				end_of_eat;
	int				end_of_sleep;
	int				*end_of_life;
	int				nbr_of_cycles;
	int				*someone_is_dead;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*philo_speak;
	pthread_mutex_t	*mutex_of_death;
	t_all			*all;
}				t_philo;

struct	s_all
{
	pthread_mutex_t	mutex_cycle;
	pthread_mutex_t	mutex_of_death;
	pthread_mutex_t	philo_speak;
	int				*tab_of_life;
	int				someone_is_dead;
	struct timeval	start;
	struct timeval	end;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_cycles;
};

void	release_forks(t_philo *philo);
void	take_forks(t_philo *philo);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	check_death(t_all *all);
int		check_someone_died(t_philo *philo);
void	destroy_all(t_all *all);
int		init(t_all *all, int ac, char **av);
void	init_philos(t_all *all, int i, int right, int left);
void	init_forks_mutexes_tab(t_all *all);
int		cycle(t_philo *philo);
void	*ft_philo(void *arg);
void	launcher(t_all *all);
int		main(int ac, char **av);
float	time_diff(struct timeval *start, struct timeval *end);
int		now(t_philo *philo);
int		ft_strisonlyc(char *str, char *to_check);
int		ft_atoi(const char *str, int *nbr);
void	put_status(t_philo *philo, char *str);

#endif
