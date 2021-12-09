/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 11:10:29 by aaapatou          #+#    #+#             */
/*   Updated: 2021/12/08 03:38:34 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct	s_philo
{
	pthread_t		thread;
	int				number;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				eat_nbr;
	int				meals;
	unsigned long	last_meal;
	unsigned long	time_eat;
	struct s_data	*data;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*m_display;
}					t_philo;

typedef struct	s_data
{
	int				philo_nbr;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				eat_nbr;
	int				dead;
	int				satiate;
	int				satiate_nbr;
	unsigned long	start;
	t_philo			*philo;
}					t_data;

// ACTIONS
void	*routine(void *philo);
// INITIALIZING
void	init_info(t_data *data);
void	init_data(t_data *data);
// PARSING
void	ft_read_argument(int ac, char **av, long long *tab);
int		ft_check_argument(int ac, char **av);
int		parse_data(int ac, char **av, t_data *data);
// DISPLAY
void	display_fork(t_philo *philo);
void	display_eating(t_philo *philo);
void	display_sleeping(t_philo *philo);
void	display_death(t_philo *philo);
void	display_satiate(t_philo *philo);
// UTILS
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putlongnbr(unsigned long nb);
unsigned long	ft_get_time(void);
void	ft_usleep(unsigned long time);
long long	ft_longatoi(const char *str);
// CLEANING
void	ft_clean(t_data *data);

#endif