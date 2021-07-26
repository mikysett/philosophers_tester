#ifndef PHILOSOPHERS_TESTER_H
# define PHILOSOPHERS_TESTER_H

# define PATH_PHILO "../philosophers/"
# define DEFAULT_NB_TIMES_TO_EAT 20

# define CLR_WHITE "\033[0;37m"
# define CLR_BLACK "\033[0;30m"
# define CLR_GRAY "\033[30;1m"
# define CLR_RED "\033[0;31m"
# define CLR_GREEN "\033[0;32m"
# define CLR_YELLOW "\033[0;33m"

# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# include "libft.h"
# include "ft_types.h"
# include "ft_init_data.h"
# include "ft_take_philo_output.h"

void	ft_exit_error(t_data *data, t_exit_code exit_code);
char	*set_err_str(t_exit_code exit_code);
void	ft_free_data(t_data *data);

#endif
