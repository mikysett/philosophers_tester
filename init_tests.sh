#! /bin/bash

declare -a cmd

export cmd

cmd+=("$tester_pathname NO_BONUS 1 200 100 100")

cmd+=("$tester_pathname NO_BONUS 2 200 100 100")

cmd+=("$tester_pathname NO_BONUS 2 400 100 100")

cmd+=("$tester_pathname NO_BONUS 4 300 100 100")

cmd+=("$tester_pathname NO_BONUS 4 300 20 100")

cmd+=("$tester_pathname NO_BONUS 4 300 200 10")

cmd+=("$tester_pathname NO_BONUS 4 500 200 10")

cmd+=("$tester_pathname NO_BONUS 5 300 20 100")

cmd+=("$tester_pathname NO_BONUS 5 300 200 10")

cmd+=("$tester_pathname NO_BONUS 5 500 200 10")

cmd+=("$tester_pathname NO_BONUS 10 400 100 100")

cmd+=("$tester_pathname NO_BONUS 20 400 100 100")

cmd+=("$tester_pathname NO_BONUS 20 400 1 100")

# TESTS FOR BONUS

# cmd+=("$tester_pathname BONUS 1 200 100 100")

# cmd+=("$tester_pathname BONUS 2 200 100 100")

# cmd+=("$tester_pathname BONUS 2 400 100 100")

# cmd+=("$tester_pathname BONUS 4 300 100 100")

# cmd+=("$tester_pathname BONUS 4 300 20 100")

# cmd+=("$tester_pathname BONUS 4 300 200 10")

# cmd+=("$tester_pathname BONUS 4 500 200 10")

# cmd+=("$tester_pathname BONUS 5 300 20 100")

# cmd+=("$tester_pathname BONUS 5 300 200 10")

# cmd+=("$tester_pathname BONUS 5 500 200 10")

# cmd+=("$tester_pathname BONUS 10 400 100 100")

# cmd+=("$tester_pathname BONUS 20 400 100 100")

# cmd+=("$tester_pathname BONUS 20 400 1 100")
