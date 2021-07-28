#ifndef PHILOSOPHERS_TESTER_H
# define PHILOSOPHERS_TESTER_H

# define PATH_PHILO			"../philo/philo"
# define PATH_PHILO_BONUS	"../philo_bonus/philo_bonus"
# define SHOW_PHILO_OUTPUT			true
# define DEFAULT_NB_TIMES_TO_EAT	20

# define MAX_LAG_TOLERANCE			10

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
# include "get_next_line.h"
# include "ft_types.h"
# include "ft_init_data.h"
# include "ft_take_philo_output.h"
# include "ft_check_output.h"
# include "ft_forks.h"
# include "ft_check_instruction.h"

void	ft_exit_error(t_data *data, t_exit_code exit_code);
char	*set_err_str(t_exit_code exit_code);
void	ft_print_success(t_data *data);
void	ft_free_data(t_data *data);
char	*ft_str_replace(char *s, char original, char replacement);

#endif
