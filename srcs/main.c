#include "philosophers_tester.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data = ft_init_data(argc, argv);
	data.philo_output_fd = ft_take_philo_output(&data);
	ft_check_output(&data);
	close(data.philo_output_fd);
	// printf("philo output:\n");
	// char	buf[201];
	// int		nb_char_read;
	// while ((nb_char_read = read(data.philo_output_fd, buf, 200)) > 0)
	// {
	// 	buf[nb_char_read] = '\0';
	// 	printf("%s\n", buf);
	// }

	ft_free_data(&data);
	return (0);
}

void	ft_exit_error(t_data *data, t_exit_code exit_code)
{
	char	*err_str;

	err_str = set_err_str(exit_code);
	printf("%s%s%s\n", CLR_RED, err_str, CLR_WHITE);
	free(err_str);
	if (data && data->philo_output_line_nb > 0)
		printf("> LINE %d: %s\n",
			data->philo_output_line_nb,
			data->philo_output_line);
	exit(EXIT_FAILURE);
}

char	*set_err_str(t_exit_code exit_code)
{
	if (exit_code == WRONG_ARGUMENTS)
		return(ft_strdup("ARGUMENTS ARE WRONG - PROGRAM DIDN'T RUN"));
	if (exit_code == MEMORY_FAIL)
		return(ft_strdup("MALLOC FAILED IN TESTER"));
	if (exit_code == CANT_RUN_PHILO)
		return(ft_strdup("CAN'T RUN PHILO (MAYBE EXECVE OR FORK FAILED)"));
	if (exit_code == INVALID_LINE)
		return(ft_strdup("INVALID LINE"));
	else
		return(ft_strdup("UNKNOWN ERROR"));
}

void	ft_free_data(t_data *data)
{
	if (data)
	{
		if (data->philo)
			free(data->philo);
	}
}