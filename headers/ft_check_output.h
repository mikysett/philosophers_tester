#ifndef FT_CHECK_OUTPUT_H
# define FT_CHECK_OUTPUT_H

void			ft_check_output(t_data *data);
t_instruction	ft_parse_instruction(t_data *data, char *line);
void			ft_replace_spaces_in_action(char *line);
int				ft_str_arr_size(char **str_arr);
int				ft_set_timestamp(t_data *data, char *timestamp_str);
int				ft_set_philo_id(t_data *data, char *id_str);
t_philo_state	ft_set_action(t_data *data, char *action_str);
void			ft_print_instruction(t_data *data, t_instruction instr);

#endif
