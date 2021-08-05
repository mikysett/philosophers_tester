#include "philosophers_tester.h"

int	ft_take_philo_output(t_data *data)
{
	char	**philo_args;
	// pid_t	philo_pid;
	// int		pipefd[2];

	philo_args = ft_init_philo_args(data);
	// pipe(pipefd);
	// philo_pid = fork();
	// if (philo_pid == 0)
	// {
	// 	dup2(pipefd[p_write], STDOUT_FILENO);
	// 	if (execve(data->full_path, philo_args, data->envp) == -1)
	// 		ft_exit_error(NULL, CANT_RUN_PHILO);
	// }
	// else if (philo_pid == -1)
	// 	ft_exit_error(NULL, CANT_RUN_PHILO);
	// if (wait(NULL) == -1)
	// 	ft_exit_error(NULL, CANT_RUN_PHILO);
	// close(pipefd[p_write]);
	// ft_free_str_arr(philo_args);
	// return (pipefd[p_read]);
}

char	**ft_init_philo_args(t_data *data)
{
	char	**philo_args;

	philo_args = malloc(sizeof(char *) * 7);
	if (data->is_philo_bonus)
		philo_args[0] = ft_strdup("philo");
	else
		philo_args[0] = ft_strdup("philo_bonus");
	philo_args[1] = ft_itoa(data->nb_philo);
	philo_args[2] = ft_itoa(data->time_to_die);
	philo_args[3] = ft_itoa(data->time_to_eat);
	philo_args[4] = ft_itoa(data->time_to_sleep);
	philo_args[5] = ft_itoa(data->nb_times_to_eat);
	philo_args[6] = NULL;
	return (philo_args);
}
