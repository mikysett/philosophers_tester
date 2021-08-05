#include "philosophers_tester.h"

void	ft_check_instruction(t_data *data, t_instruction instr)
{
	if (instr.ts < data->last_ts)
		ft_exit_error(data, WRONG_TIMESTAMP_ORDER);
	ft_check_philo_died(data, instr.ts);
	ft_run_instruction_action(data, instr);
}

void	ft_check_philo_died(t_data *data, int timestamp)
{
	int	i;
	int	died_since;

	i = 0;
	if (data->death_reported)
		ft_exit_error(data, INSTRUCTIONS_AFTER_DEATH);
	while (i < data->nb_philo)
	{
		died_since = timestamp - (data->philo[i].last_eat_ts
				+ data->time_to_die);
		if (data->philo[i].nb_meals != data->nb_times_to_eat
			&& died_since >= 0)
		{
			data->somebody_died = true;
			if (died_since > MAX_LAG_TOLERANCE)
				ft_exit_error(data, DEATH_NOT_REPORTED);
		}
		i++;
	}
}

void	ft_run_instruction_action(t_data *data, t_instruction instr)
{
	if (instr.action == dead)
	{
		if (data->philo[instr.philo_id - 1].last_eat_ts
				+ data->time_to_die - instr.ts > 0)
			ft_exit_error(data, WRONG_DEATH_REPORT);
		data->philo[instr.philo_id - 1].state = dead;
		data->death_reported = true;
	}
	ft_check_out_of_order_action(data, instr);
	if (instr.action == eating)
		ft_process_eating(data, instr);
	else if (instr.action == sleeping)
	{
		ft_process_sleeping(data, instr);
		ft_process_forks_release(data, instr);
	}
	else if (instr.action == thinking)
		ft_process_thinking(data, instr);
	else if (instr.action == fork_taken)
		ft_process_fork_taken(data, instr);
}

void	ft_check_out_of_order_action(t_data *data, t_instruction instr)
{
	if ((instr.action == eating && data->philo[instr.philo_id - 1].state != thinking)
		|| (instr.action == sleeping && data->philo[instr.philo_id - 1].state != eating)
		|| (instr.action == thinking && data->philo[instr.philo_id - 1].state != sleeping)
		|| (instr.action == fork_taken && data->philo[instr.philo_id - 1].state != thinking))
		ft_exit_error(data, WRONG_STATUS_ORDER);
}

void	ft_process_eating(t_data *data, t_instruction instr)
{
		if (data->philo[instr.philo_id - 1].last_sleep_ts != -1
			&& instr.ts
				- (data->philo[instr.philo_id - 1].last_sleep_ts + data->time_to_sleep) < 0)
			ft_exit_error(data, SLEEP_TOO_FAST);
		if (data->philo[instr.philo_id - 1].forks_in_hand != 2)
			ft_exit_error(data, EATING_WITH_WRONG_FORKS);
		data->philo[instr.philo_id - 1].last_eat_ts = instr.ts;
		data->philo[instr.philo_id - 1].state = eating;
		data->philo[instr.philo_id - 1].nb_meals++;
}

void	ft_process_sleeping(t_data *data, t_instruction instr)
{
	if (instr.ts - (data->philo[instr.philo_id - 1].last_eat_ts + data->time_to_eat) < 0)
		ft_exit_error(data, EAT_TOO_FAST);
	data->philo[instr.philo_id - 1].last_sleep_ts = instr.ts;
	data->philo[instr.philo_id - 1].state = sleeping;
	data->philo[instr.philo_id - 1].forks_in_hand = 0;
}

void	ft_process_thinking(t_data *data, t_instruction instr)
{
	if (data->philo[instr.philo_id - 1].last_sleep_ts != -1
		&& instr.ts
			- (data->philo[instr.philo_id - 1].last_sleep_ts + data->time_to_sleep) < 0)
		ft_exit_error(data, SLEEP_TOO_FAST);
	data->philo[instr.philo_id - 1].state = thinking;
}
