#ifndef FT_TYPES_H
# define FT_TYPES_H

typedef enum e_exit_code
{
	MEMORY_FAIL,
	CANT_RUN_PHILO,
	WRONG_ARGUMENTS,
	TAKEN_BUSY_FORK,
	PHILO_DIED,
	DEATH_NOT_REPORTED,
	INSTRUCTIONS_AFTER_DEATH,
	EAT_TOO_FAST,
	SLEEP_TOO_FAST,
	WRONG_STATUS_ORDER,
	WRONG_NUMBER_OF_MEALS,
	INVALID_LINE
}			t_exit_code;

typedef enum e_philo_state
{
	eating,
	sleeping,
	thinking,
	dead,
	fork_taken
}			t_philo_state;	

typedef struct s_philo
{
	int				id;
	t_philo_state	state;
	int				forks_in_hand;
	int				last_eat_timestamp;
	int				last_sleep_timestamp;
}			t_philo;

typedef struct s_data
{
	bool		is_philo_bonus;
	char		full_path[200];

	int			nb_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nb_times_to_eat;
	int			last_timestamp;
	t_philo		*philo;

	int			philo_output_fd;
	char		*philo_output_line;
	int			philo_output_line_nb;
}			t_data;

typedef enum e_pipe_side
{
	p_read = 0,
	p_write = 1
}				t_pipe_side;

typedef struct s_instruction
{
	int				timestamp;
	int				philo_id;
	t_philo_state	action;
}			t_instruction;

#endif
