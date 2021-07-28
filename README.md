# Philosophers Tester - 42Lisbon

To clone with submodules: `git clone --recursive <project url>`

Work in progress

## How to use it

- Run `bash philosophers_tester.sh`.

- The evaluated program should be named `philo` and be in the directory `philo` located next to the directory `philosophers_tester`, to change that path modify `PATH_PHILO` in `philosophers_tester.h`.

- Same for testing the bonus, the program should be named `philo_bonus` and be in the directory `philo_bonus` located next to the directory `philosophers_tester`.

- The programm will set `nb_of_times_every_philo_must_eat` to 4 as default value (if you want to change this default you can modify `DEFAULT_NB_TIMES_TO_EAT` in `philosophers_tester.h`).

- By default the tester will show also the output of the philo program, to toggle it modifiy `SHOW_PHILO_OUTPUT` in `philosophers_tester.h`.

- If you want to add some custom tests feel free to do so, it's very easy. Just edit `init_tests.sh`.

## Disclaimer
- Memory allocations/leaks are not tested
- The tester gives strange behavior for bonuses
- The tester is very strict about available forks evalutation and won't tollerate a philosopher taking a fork before the one having it explicitely stated he released it (by printing a status change to sleep).
- The program may (probably) have bugs and issues, be aware and use your own judgement when in doupt, also please feel free to reach me for feedback or bugs report.