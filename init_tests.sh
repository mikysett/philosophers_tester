#! /bin/bash

declare -a cmd

export cmd

# DEFENSE TESTS

args="1 800 200 200 $default_nb_meals"
cmd+=("$philo_path $args | $tester NO_BONUS $args")

args="5 800 200 200 7"
cmd+=("$philo_path $args | $tester NO_BONUS $args")

args="4 410 200 200 $default_nb_meals"
cmd+=("$philo_path $args | $tester NO_BONUS $args")

args="4 310 200 100 $default_nb_meals"
cmd+=("$philo_path $args | $tester NO_BONUS $args")

args="2 200 100 100 $default_nb_meals"
cmd+=("$philo_path $args | $tester NO_BONUS $args")

args="2 400 100 100 $default_nb_meals"
cmd+=("$philo_path $args | $tester NO_BONUS $args")

args="2 400 100 400 $default_nb_meals"
cmd+=("$philo_path $args | $tester NO_BONUS $args")

args="2 400 300 200 $default_nb_meals"
cmd+=("$philo_path $args | $tester NO_BONUS $args")

# # # EXTRA TESTS

args="4 300 100 100 $default_nb_meals"
cmd+=("$philo_path $args | $tester NO_BONUS $args")

args="4 300 300 100 1"
cmd+=("$philo_path $args | $tester NO_BONUS $args")

args="4 300 400 100 1"
cmd+=("$philo_path $args | $tester NO_BONUS $args")

args="4 300 200 10 $default_nb_meals"
cmd+=("$philo_path $args | $tester NO_BONUS $args")

args="4 500 200 10 $default_nb_meals"
cmd+=("$philo_path $args | $tester NO_BONUS $args")

args="5 300 200 10 $default_nb_meals"
cmd+=("$philo_path $args | $tester NO_BONUS $args")

args="5 500 200 10 $default_nb_meals"
cmd+=("$philo_path $args | $tester NO_BONUS $args")

args="10 400 100 100 $default_nb_meals"
cmd+=("$philo_path $args | $tester NO_BONUS $args")

args="20 400 100 100 $default_nb_meals"
cmd+=("$philo_path $args | $tester NO_BONUS $args")

# TESTS FOR BONUS

# args="1 800 200 200 $default_nb_meals"
# cmd+=("$philo_bonus_path $args | $tester BONUS $args")

# args="5 800 200 200 $default_nb_meals"
# cmd+=("$philo_bonus_path $args | $tester BONUS $args")

# args="5 800 200 200 7"
# cmd+=("$philo_bonus_path $args | $tester BONUS $args")

# args="4 410 200 200 $default_nb_meals"
# cmd+=("$philo_bonus_path $args | $tester BONUS $args")

# args="4 310 200 100 $default_nb_meals"
# cmd+=("$philo_bonus_path $args | $tester BONUS $args")

# args="2 200 100 100 $default_nb_meals"
# cmd+=("$philo_bonus_path $args | $tester BONUS $args")

# args="2 400 100 100 $default_nb_meals"
# cmd+=("$philo_bonus_path $args | $tester BONUS $args")

# args="2 400 100 400 $default_nb_meals"
# cmd+=("$philo_bonus_path $args | $tester BONUS $args")

# args="2 400 300 200 $default_nb_meals"
# cmd+=("$philo_bonus_path $args | $tester BONUS $args")
