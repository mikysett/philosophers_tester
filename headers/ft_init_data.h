#ifndef FT_INIT_DATA_H
# define FT_INIT_DATA_H

t_data	ft_init_data(int argc, char **argv);
bool	ft_set_bonus(char *philo_prog_type);
void	ft_set_full_path(t_data *data);
int		ft_save_number(char *arr_nb);
bool	ft_is_number(char *nb);
bool	ft_is_int(char *nb);
int		ft_set_nb_times_to_eat(int argc, char **argv);
void	ft_init_philo(t_data *data);

#endif