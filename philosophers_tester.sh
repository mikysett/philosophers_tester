#! /bin/bash

export WHT="\033[0;37m"
export BLK="\033[0;30m"
export RED="\033[0;31m"
export YEL="\033[0;33m"
export BLU="\033[0;34m"
export GRN="\033[0;32m"

export philo_path=../philo/philo
export philo_bonus_path=../philo_bonus/philo_bonus
export tester=./philo_tester
export default_nb_meals=7

make all

. init_tests.sh
. tester_loop.sh