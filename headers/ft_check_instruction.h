#ifndef FT_CHECK_INSTRUCTION_H
# define FT_CHECK_INSTRUCTION_H

void	ft_check_instruction(t_data *data, t_instruction instr);
void	ft_check_philo_died(t_data *data, int timestamp);
void	ft_run_instruction_action(t_data *data, t_instruction instr);
void	ft_check_out_of_order_action(t_data *data, t_instruction instr);
void	ft_process_eating(t_data *data, t_instruction instr);
void	ft_process_sleeping(t_data *data, t_instruction instr);
void	ft_process_thinking(t_data *data, t_instruction instr);

#endif
