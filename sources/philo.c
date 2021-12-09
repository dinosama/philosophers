/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 11:10:32 by aaapatou          #+#    #+#             */
/*   Updated: 2021/12/08 04:30:59 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	dispatche_forks(int philo_nbr, t_philo *philo)
{
	int		i;

	i = 0;
	while (i < philo_nbr)
	{
		philo[i].rfork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * 1);
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

t_philo	*set_philo(t_data *data, t_philo *philo)
{
	int		i;
	unsigned long time;

	i = 0;
	philo = malloc(sizeof(t_philo) * data->philo_nbr);
	if (!philo)
		return (NULL);
	philo[i].m_display = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * 1);
	if (pthread_mutex_init(philo[i].m_display, NULL) != 0)
    {
    	ft_putstr("mutex init failed\n");
    	return (0);
	}
	time = ft_get_time();
	while (i < data->philo_nbr)
	{
		philo[i].data = data;
		philo[i].number = i + 1;
		philo[i].die_time = data->die_time;
		philo[i].eat_nbr = data->eat_nbr;
		philo[i].eat_time = data->eat_time;
		philo[i].sleep_time = data->sleep_time;
		philo[i].last_meal = time;
		if (i > 0)
			philo[i].m_display = philo[i - 1].m_display;
		i++;
	}
	if (!dispatche_forks(data->philo_nbr, philo))
		return (NULL);
	return (philo);
}

int	death_monitoring(t_philo *philo)
{
	unsigned long	time;
	static int	philo_number;

	time = ft_get_time();
	if (time - philo[philo_number].last_meal >= (unsigned long)philo->die_time)
	{
		display_death(&philo[philo_number]);
		philo[philo_number].data->dead = 1;
		return (1);
	}
	if (philo->data->satiate_nbr == philo->data->philo_nbr)
	{
		display_satiate(&philo[philo_number]);
		philo[philo_number].data->satiate = 1;
		return (1);
	}
	philo_number++;
	if (philo_number >= philo->data->philo_nbr)
		philo_number = 0;
	return (0);
}

void	launch_threads(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->philo_nbr)
	{
		pthread_create(&data->philo[i].thread, NULL, &routine, (void *)&data->philo[i]);
		pthread_detach(data->philo[i].thread);
		usleep(100);
		i = i + 2;
	}
	i = 1;
	while (i < data->philo_nbr)
	{
		pthread_create(&data->philo[i].thread, NULL, &routine, (void *)&data->philo[i]);
		pthread_detach(data->philo[i].thread);
		usleep(100);
		i = i + 2;
	}
	while (!death_monitoring(data->philo))
		;
}

int	main(int ac, char **av)
{
	t_data data;
	t_philo *philo;

	philo = NULL;
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
	data.philo = set_philo(&data, philo);
	if (!data.philo)
		return (0);
	launch_threads(&data);
	usleep(10000);
	ft_clean(&data);
	return (0);
}
