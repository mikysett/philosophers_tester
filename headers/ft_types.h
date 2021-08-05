#ifndef FT_TYPES_H
# define FT_TYPES_H

typedef enum e_exit_code
{
	MEMORY_FAIL,
	CANT_RUN_PHILO,
	WRONG_ARGUMENTS,
	TAKEN_BUSY_FORK,
	EATING_WITH_WRONG_FORKS,
	DEATH_NOT_REPORTED,
	INSTRUCTIONS_AFTER_DEATH,
	EAT_TOO_FAST,
	SLEEP_TOO_FAST,
	AVOIDABLE_DEATH,
	WRONG_DEATH_REPORT,
	WRONG_STATUS_ORDER,
	WRONG_NUMBER_OF_MEALS,
	WRONG_TIMESTAMP_ORDER,
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
	int				last_eat_ts;
	int				last_sleep_ts;
	int				nb_meals;
}			t_philo;

typedef struct s_data
{
	bool		is_philo_bonus;
	int			nb_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nb_times_to_eat;
	int			last_ts;
	t_philo		*philo;
	bool		*busy_forks;

	char		*philo_output_line;
	int			philo_output_line_nb;

	bool		somebody_died;
	bool		death_reported;
}			t_data;

typedef struct s_instruction
{
	int				ts;
	int				philo_id;
	t_philo_state	action;
}			t_instruction;

#endif
