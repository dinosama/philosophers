/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 11:10:29 by aaapatou          #+#    #+#             */
/*   Updated: 2021/12/01 16:09:57 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

typedef struct		s_data
{
	int				philo_nbr;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				eat_nbr;
}					t_data;

typedef struct 		s_philo
{
	pthread_t		thread;
	int				number;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				eat_nbr;
	unsigned long	time_eat;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*m_display;
}					t_philo;


# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

// INITIALIZING
void	init_info(t_data *data);
// PARSING
void	ft_read_argument(int ac, char **av, long long *tab);
int		ft_check_argument(int ac, char **av);
// DISPLAY
void	display_fork(t_philo *philo);
// UTILS
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putlongnbr(unsigned long nb);
unsigned long	ft_get_time(void);
void	ft_usleep(unsigned long time);

#endif