#ifndef FT_FORKS_H
# define FT_FORKS_H

void	ft_process_fork_taken(t_data *data, t_instruction instr);
void	ft_take_available_fork_no_bonus(t_data *data, t_instruction instr);
void	ft_take_available_fork_bonus(t_data *data);
void	ft_process_forks_release(t_data *data, t_instruction instr);
void	ft_release_forks_no_bonus(t_data *data, t_instruction instr);
void	ft_release_forks_bonus(t_data *data);
int		previous(int i, int size);

#endif
