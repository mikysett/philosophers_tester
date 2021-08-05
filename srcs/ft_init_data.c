#include "philosophers_tester.h"

t_data	ft_init_data(int argc, char **argv)
{
	t_data	data;

	if (argc < 6 || argc > 7)
		ft_exit_error(NULL, WRONG_ARGUMENTS);
	data.is_philo_bonus = ft_set_bonus(argv[1]);
	data.nb_philo = ft_save_number(argv[2]);
	data.time_to_die = ft_save_number(argv[3]);
	data.time_to_eat = ft_save_number(argv[4]);
	data.time_to_sleep = ft_save_number(argv[5]);
	data.nb_times_to_eat = ft_set_nb_times_to_eat(argc, argv);
	data.last_ts = 0;
	ft_init_philo(&data);
	ft_init_forks(&data);
	ft_init_philo_output(&data);
	data.somebody_died = false;
	data.death_reported = false;
	return (data);
}

bool	ft_set_bonus(char *philo_prog_type)
{
	if (!strcmp(philo_prog_type, "NO_BONUS"))
		return (false);
	else if (!strcmp(philo_prog_type, "BONUS"))
		return (true);
	else
		ft_exit_error(NULL, WRONG_ARGUMENTS);
	return (false);
}

int		ft_save_number(char *arr_nb)
{
	int	nb;

	if (!ft_is_number(arr_nb) || !ft_is_int(arr_nb))
		ft_exit_error(NULL, WRONG_ARGUMENTS);
	nb = ft_atoi(arr_nb);
	if (nb <= 0)
		ft_exit_error(NULL, WRONG_ARGUMENTS);
	return (nb);
}

bool	ft_is_number(char *nb)
{
	if (*nb == '-')
		nb++;
	if (!*nb)
		return (false);
	while (*nb)
	{
		if (*nb < '0' || *nb > '9')
			return (false);
		nb++;
	}
	return (true);
}

bool	ft_is_int(char *nb)
{
	size_t	nb_size;
	char	*nb_char;

	ft_delete_starting_zeros(nb);
	nb_size = ft_strlen(nb);
	nb_char = ft_itoa(ft_atoi(nb));
	if (nb_size != ft_strlen(nb_char)
		|| ft_strncmp(nb, nb_char, nb_size))
	{
		free(nb_char);
		return (false);
	}
	free(nb_char);
	return (true);
}

void	ft_delete_starting_zeros(char *nb)
{
	int	i;
	int	nb_len;

	i = 0;
	nb_len = strlen(nb);
	if (*nb == '0' && nb_len != 1)
	{
		while (i < nb_len)
		{
			nb[i] = nb[i + 1];
			i++;	
		}
		ft_delete_starting_zeros(nb);
	}
}

int		ft_set_nb_times_to_eat(int argc, char **argv)
{
	if (argc == 7)
		return (ft_save_number(argv[6]));
	else
		return (DEFAULT_NB_TIMES_TO_EAT);
}

void	ft_init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philo)
		ft_exit_error(NULL, MEMORY_FAIL);
	while (i < data->nb_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].state = thinking;
		data->philo[i].forks_in_hand = 0;
		data->philo[i].last_eat_ts = 0;
		data->philo[i].last_sleep_ts = -1;
		data->philo[i].nb_meals = 0;
		i++;
	}
}

void	ft_init_forks(t_data *data)
{
	data->busy_forks = ft_calloc(data->nb_philo, sizeof(bool));
	if (!data->busy_forks)
		ft_exit_error(NULL, MEMORY_FAIL);
}

void	ft_init_philo_output(t_data *data)
{
	data->philo_output_line = NULL;
	data->philo_output_line_nb = 0;
}
