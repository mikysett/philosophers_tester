#! /bin/bash

export WHT="\033[0;37m"
export BLK="\033[0;30m"
export RED="\033[0;31m"
export YEL="\033[0;33m"
export BLU="\033[0;34m"
export GRN="\033[0;32m"

export tester_pathname=./philo_tester

make all

. init_tests.sh
. tester_loop.sh