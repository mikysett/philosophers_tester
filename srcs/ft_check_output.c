#include "philosophers_tester.h"

void	ft_check_output(t_data *data)
{
	t_instruction	curr_instr;

	data->philo_output_line_nb = 1;
	while (get_next_line(STDIN_FILENO, &data->philo_output_line) > 0)
	{
		curr_instr = ft_parse_instruction(data, data->philo_output_line);
		ft_check_instruction(data, curr_instr);
		if (SHOW_PHILO_OUTPUT)
			ft_print_instruction(data);
		data->philo_output_line_nb++;
		free(data->philo_output_line);
	}
	ft_check_last_death(data);
	if (!data->somebody_died)
		ft_check_nb_meals(data);
	free(data->philo_output_line);
}

t_instruction	ft_parse_instruction(t_data *data, char *line)
{
	char			**instr;
	t_instruction	final_instr;

	ft_replace_spaces_in_action(line);
	instr = ft_split(line, ' ');
	if (ft_str_arr_size(instr) != 3)
		ft_exit_error(data, INVALID_LINE);
	final_instr.ts = ft_set_timestamp(data, instr[0]);
	final_instr.philo_id = ft_set_philo_id(data, instr[1]);
	final_instr.action = ft_set_action(data, instr[2]);
	ft_free_str_arr(instr);
	return (final_instr);
}

void	ft_replace_spaces_in_action(char *line)
{
	int	i;
	int curr_param;

	i = 0;
	curr_param = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			i++;
		else
		{
			if (curr_param < 2)
				curr_param++;
			else if (line[i] == ' ')
				line[i] = '_';
			i++;
		}
	}
}

int	ft_str_arr_size(char **str_arr)
{
	int	i;

	i = 0;
	if (!str_arr)
		return (-1);
	while (str_arr[i])
		i++;
	return (i);
}

int	ft_set_timestamp(t_data *data, char *timestamp_str)
{
	int	ts;

	if (!ft_is_number(timestamp_str) || !ft_is_int(timestamp_str))
		ft_exit_error(data, INVALID_LINE);
	ts = ft_atoi(timestamp_str);
	if (ts < 0)
		ft_exit_error(data, INVALID_LINE);
	return (ts);
}

int	ft_set_philo_id(t_data *data, char *id_str)
{
	int	philo_id;

	if (!ft_is_number(id_str) || !ft_is_int(id_str))
		ft_exit_error(data, INVALID_LINE);
	philo_id = ft_atoi(id_str);
	if (philo_id < 1 || philo_id > data->nb_philo)
		ft_exit_error(data, INVALID_LINE);
	return (philo_id);
}

t_philo_state	ft_set_action(t_data *data, char *action_str)
{
	t_philo_state	action;

	action = dead;
	if (!strcmp(action_str, "has_taken_a_fork"))
		action = fork_taken;
	else if (!strcmp(action_str, "is_eating"))
		action = eating;
	else if (!strcmp(action_str, "is_sleeping"))
		action = sleeping;
	else if (!strcmp(action_str, "is_thinking"))
		action = thinking;
	else if (!strcmp(action_str, "died"))
		action = dead;
	else
		ft_exit_error(data, INVALID_LINE);
	return (action);
}

void	ft_check_nb_meals(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (data->philo[i].nb_meals != data->nb_times_to_eat)
			ft_exit_error(data, WRONG_NUMBER_OF_MEALS);
		i++;
	}
}

void	ft_check_last_death(t_data *data)
{
	if (data->somebody_died)
	{
		if (!data->death_reported)
			ft_exit_error(data, DEATH_NOT_REPORTED);
		else if (ft_death_was_avoidable(data))
			ft_exit_error(data, AVOIDABLE_DEATH);
	}
}

bool	ft_death_was_avoidable(t_data *data)
{
	int	max_waiting_time;

	if (data->nb_philo <= 1)
		return (false);
	max_waiting_time = data->time_to_eat
		+ ft_bigger(data->time_to_eat, data->time_to_sleep);
	if (data->nb_philo % 2 == 1)
	{
		if (data->time_to_eat >= data->time_to_sleep)
			max_waiting_time += data->time_to_eat;
		else if (data->time_to_sleep - data->time_to_eat < data->time_to_eat)
			max_waiting_time += data->time_to_eat
				- (data->time_to_sleep - data->time_to_eat);
	}
	if (max_waiting_time + MAX_LAG_TOLERANCE > data->time_to_die)
		return (false);
	return (true);
}

void	ft_print_instruction(t_data *data)
{
	static int	line_nb = 1;

	printf(" %3d: %s\n",
		line_nb,
		ft_str_replace(data->philo_output_line, '_', ' '));
	line_nb++;
}

int		ft_bigger(int nb1, int nb2)
{
	return (nb1 > nb2 ? nb1 : nb2);
}
