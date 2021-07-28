#include "philosophers_tester.h"

void	ft_process_fork_taken(t_data *data, t_instruction instr)
{
	if (!data->is_philo_bonus)
		ft_take_available_fork_no_bonus(data, instr);
	else
		ft_take_available_fork_bonus(data);
	data->philo[instr.philo_id - 1].forks_in_hand++;
}

void	ft_take_available_fork_no_bonus(t_data *data, t_instruction instr)
{
	if (data->busy_forks[instr.philo_id - 1] == false)
		data->busy_forks[instr.philo_id - 1] = true;
	else if (data->busy_forks[previous(instr.philo_id - 1, data->nb_philo)] == false)
		data->busy_forks[previous(instr.philo_id - 1, data->nb_philo)] = true;
	else
		ft_exit_error(data, TAKEN_BUSY_FORK);
}

void	ft_take_available_fork_bonus(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (data->busy_forks[i] == false)
		{
			data->busy_forks[i] = true;
			return ;
		}
		i++;
	}
	ft_exit_error(data, TAKEN_BUSY_FORK);
}

void	ft_process_forks_release(t_data *data, t_instruction instr)
{
	if (!data->is_philo_bonus)
		ft_release_forks_no_bonus(data, instr);
	else
		ft_release_forks_bonus(data);
}

void	ft_release_forks_no_bonus(t_data *data, t_instruction instr)
{
	data->busy_forks[instr.philo_id - 1] = false;
	data->busy_forks[previous(instr.philo_id - 1, data->nb_philo)] = false;
}

void	ft_release_forks_bonus(t_data *data)
{
	int	i;
	int	forks_to_release;

	i = 0;
	forks_to_release = 2;
	while (i < data->nb_philo)
	{
		if (data->busy_forks[i] == true)
		{
			data->busy_forks[i] = false;
			forks_to_release--;
			if (forks_to_release == 0)
				return ;
		}
		i++;
	}
}

int	previous(int i, int size)
{
	if (i == 0)
		return (size - 1);
	return (i - 1);
}
