import subprocess

def moves():
	# Colors Definition 
	GREEN = "\033[32;1m"
	RED = "\033[31;1m"
	CYAN = "\033[36;1;3;208m"
	WHITE = "\033[37;1;4m"
	COLOR_LIMITER = "\033[0m"

	program = ["../push_swap"]
	arg = ["6", "5", "4", "3", "2", "1"]
	cmd = program + arg

	move_1 = "rra\n1 6 5 4 3 2\n"
	move_2 = "ra\n6 5 4 3 2 1\n"
	move_3 = "sa\n5 6 4 3 2 1\n"
	move_4 = "sa\n6 5 4 3 2 1\n"

	move_5 = "pb\npb\npb\npb\npb\npb\n1 2 3 4 5 6\n"

	move_6 = "rb\n2 3 4 5 6 1\n"
	move_7 = "rrb\n1 2 3 4 5 6\n"
	move_8 = "sb\n2 1 3 4 5 6\n"
	move_9 = "sb\n1 2 3 4 5 6\n"

	move_10 = "pa\npa\npa\n3 2 1\n4 5 6\n"

	move_11 = "rr\n2 1 3\n5 6 4\n"
	move_12 = "rrr\n3 2 1\n4 5 6\n"
	move_13 = "ss\n2 3 1\n5 4 6\n"

	list_of_moves = [move_1, move_2, move_3, move_4, move_5, move_6, move_7, move_8, move_9, move_10, move_11, move_12, move_13]

	output = subprocess.run(cmd, stdout=subprocess.PIPE, text=True)

	string_output = output.stdout

	i = 1
	for move in list_of_moves:
		operation = move.split("\n")
		print(operation[0])
		if move in string_output:
			print(f"{GREEN}{i}. OK{COLOR_LIMITER}")
		else:
			print(f"{RED}{i}. KO{COLOR_LIMITER}")
		i = i + 1
