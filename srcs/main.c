#include "philosophers_tester.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data = ft_init_data(argc, argv);
	ft_check_output(&data);
	ft_print_success(&data);
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
	{
		printf("> LINE %d: %s\n",
			data->philo_output_line_nb,
			ft_str_replace(data->philo_output_line, '_', ' '));
		ft_print_nb_meals(data);
	}
	exit(EXIT_FAILURE);
}

char	*set_err_str(t_exit_code exit_code)
{
	if (exit_code == WRONG_ARGUMENTS)
		return(ft_strdup("ARGUMENTS ARE WRONG - PROGRAM DIDN'T RUN"));
	else if (exit_code == MEMORY_FAIL)
		return(ft_strdup("MALLOC FAILED IN TESTER"));
	else if (exit_code == CANT_RUN_PHILO)
		return(ft_strdup("CAN'T RUN PHILO (MAYBE EXECVE OR FORK FAILED)"));
	else if (exit_code == INVALID_LINE)
		return(ft_strdup("INVALID LINE"));
	else if (exit_code == WRONG_TIMESTAMP_ORDER)
		return(ft_strdup("TIMESTAMP SMALLER THAN PREVIOUS ONE"));
	else if (exit_code == DEATH_NOT_REPORTED)
		return(ft_strdup("DEATH NOT REPORTED (IN A TIMELY MANNER)"));
	else if (exit_code == INSTRUCTIONS_AFTER_DEATH)
		return(ft_strdup("INSTRUCTIONS AFTER DEATH REPORTED"));
	else if (exit_code == WRONG_DEATH_REPORT)
		return(ft_strdup("WRONG DEATH REPORT"));
	else if (exit_code == WRONG_STATUS_ORDER)
		return(ft_strdup("WRONG STATUS ORDER"));
	else if (exit_code == SLEEP_TOO_FAST)
		return(ft_strdup("SLEEP TOO FAST"));
	else if (exit_code == EAT_TOO_FAST)
		return(ft_strdup("EAT TOO FAST"));
	else if (exit_code == EATING_WITH_WRONG_FORKS)
		return(ft_strdup("EATING WITH WRONG NUMBER OF FORKS"));
	else if (exit_code == TAKEN_BUSY_FORK)
		return(ft_strdup("TAKEN AN ALREADY BUSY FORK"));
	else if (exit_code == AVOIDABLE_DEATH)
		return(ft_strdup("THIS DEATH WAS AVOIDABLE (MAYBE DUE TO SYSTEM LAG)"));
	else if (exit_code == WRONG_NUMBER_OF_MEALS)
		return(ft_strdup("WRONG NUMBER OF MEALS"));
	else
		return(ft_strdup("UNKNOWN ERROR"));
}

void	ft_print_success(t_data *data)
{
	printf("%s", CLR_GREEN);
	if (data->somebody_died)
		printf("OK (SOMEBODY DIED BUT IT WAS INEVITABLE)\n");
	else
		printf("OK (NOBODY DIED)\n");
	printf("%s", CLR_WHITE);
}

void	ft_free_data(t_data *data)
{
	if (data)
	{
		if (data->philo)
			free(data->philo);
	}
}

char	*ft_str_replace(char *s, char original, char replacement)
{
	char	*o_str;

	o_str = s;
	while (*s)
	{
		if (*s == original)
			*s = replacement;
		s++;
	}
	return (o_str);
}

void	ft_print_nb_meals(t_data *data)
{
	int	i;

	i = 0;
	printf(" MEALS RECAP:\n");
	while (i < data->nb_philo)
	{
		printf("philo %d - nb_meals: %d\n",
			data->philo[i].id,
			data->philo[i].nb_meals);
		i++;
	}
}