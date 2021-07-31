# Philosophers Tester - 42Lisbon

To clone with submodules: `git clone --recursive <project url>`

Work in progress

For now to run tests you can `make` and then call `./philo_tester [BONUS/NO_BONUS] nb_philosophers time_to_die time_to_eat time_to_sleep nb_of_times_every_philo_must_eat(optionnal)`.

The programm will set `nb_of_times_every_philo_must_eat` to 20 as default value (if you want to change this default you can modify `DEFAULT_NB_TIMES_TO_EAT` in `philosophers_tester.h`).

The program should be named `philo` and be in the directory `philo` located next to the directory `philosophers_tester`, to change that path modify `PATH_PHILO` in `philosophers_tester.h`.

Same for testing the bonus, the program should be named `philo_bonus` and be in the directory `philo_bonus` located next to the directory `philosophers_tester`.

By default the tester will show also the output of the philo program, to toggle it modifiy `SHOW_PHILO_OUTPUT` in `philosophers_tester.h`.

## Disclaimer
- Memory allocations/leaks are not tested
- The tester is not ready for bonus
- The tester assume all philosophers starts in thinking state (subject doesn't explicitely define which starting state to use but thinking seems to more obvious)
- The tester assume the philosopher will take the fork at his right (if it's available) and then the one at his left (this is kind of arbitrary, but a decision must be made, this is the one this tester uses).
- There may be still bugs and errors, please report any issue or interesting insight