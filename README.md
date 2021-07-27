# Philosophers Tester - 42Lisbon

To clone with submodules: `git clone --recursive <project url>`

Work in progress

For now to run tests you can `make` and then call `./philo_tester [BONUS/NO_BONUS] nb_philosophers time_to_die time_to_eat time_to_sleep nb_of_times_every_philo_must_eat(optionnal)`.

The programm will set nb_of_times_every_philo_must_eat to 20 as default value (if you want to change this default you can modify `DEFAULT_NB_TIMES_TO_EAT` in `philosophers_tester.h`).

The program should be named `philo` and be in the directory `philosophers` located next to the directory `philosophers_tester`, to change that path modify `PATH_PHILO` in `philosophers_tester.h`.

By default the tester will show also the output of the philo program, to toggle it modifiy `SHOW_PHILO_OUTPUT` in `philosophers_tester.h`.

## Disclaimer
- Memory allocations/leaks are not tested
- The tester is not ready for bonus
- The fork availability test is somehow experimental
- A lot of bugs are for sure still there!!! Please report any issue or interesting insight