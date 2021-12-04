/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 11:10:32 by aaapatou          #+#    #+#             */
/*   Updated: 2021/12/01 14:59:56 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	dispatche_forks(int philo_nbr, t_philo *philo)
{
	int		i;

	i = 0;
	while (i < philo_nbr)
	{
		if (pthread_mutex_init(philo[i].rfork, NULL) != 0)
    	{
        	printf("mutex init failed\n");
        	return (0);
    	}
		i++;
	}
	i--;
	while (i >= 0)
	{
		if (i == philo_nbr - 1)
			philo[i].lfork = philo[0].rfork;
		else
			philo[i].lfork = philo[i + 1].rfork;
		i--;
	}
	return (1);
}

int	set_philo(t_data *data, t_philo *philo)
{
	int		i;

	i = 0;
	philo = malloc(sizeof(t_philo) * data->philo_nbr);
	if (!philo)
		return (-1);
	if (pthread_mutex_init(philo[i].m_display, NULL) != 0)
    {
    	printf("mutex init failed\n");
    	return (0);
	}
	while (i < data->philo_nbr)
	{
		philo[i].number = i + 1;
		philo[i].die_time = data->die_time;
		philo[i].eat_nbr = data->eat_nbr;
		philo[i].eat_time = data->eat_time;
		philo[i].is_dead = 0;
		philo[i].sleep_time = data->sleep_time;
		if (i > 0)
			philo[i].m_display = philo[i - 1].m_display;
	}
	if (!dispatche_forks(data->philo_nbr, philo))
		return (-1);
	return (1);
}

int	main(int ac, char **av)
{
	t_data data;
	t_philo *philo;

	if (ac != 5 && ac != 6)
	{
		ft_putstr("uncorrect number of arguments\n");
		return (0);
	}
	if (ft_check_argument(ac, av) == -1)
	{
		ft_putstr("unvalid arguments\n");
		return (0);
	}
	init_data(&data);
	if (parse_data(ac, av, &data) < 0)
		return (0);
	if (!set_philo(&data, philo))
		return (0);
}
