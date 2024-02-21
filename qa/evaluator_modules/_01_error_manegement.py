import subprocess

def error_manegement(program, valgrind, valgrind_check, colours):
	# # Constant args
	# program = ["../push_swap"]
	# valgrind = ["valgrind", "--leak-check=full", "--show-leak-kinds=all", "--track-origins=yes"]
	# valgrind_check = "All heap blocks were freed -- no leaks are possible"

	# # Colours
	# GREEN = "\033[32;1m"
	# RED = "\033[31;1m"
	# COLOR_LIMITER = "\033[0m"
	# colours = [GREEN, RED, COLOR_LIMITER]

	# clean = ["make", "clean", "-C", "../"]
	# subprocess.run(clean, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
	# make = ["make", "-C", "../"]
	# subprocess.run(make, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

	# Creating args
	battery = ["str_on_list", "dup_on_list", "max_on_list", "nothing_on_list"]
	str_on_list = ["1", "2", "3", "abc", "5", "6", "7"]
	dup_on_list = ["1", "2", "3", "3", "5", "6", "7"]
	max_on_list = ["1", "2", "3", "2147483648", "5", "6", "7"]
	nothing_on_list = [""]
	args = [str_on_list, dup_on_list, max_on_list, nothing_on_list]

	# Reference output
	stderr_ref_list = ["Error\n", "Error\n", "Error\n", ""]

	# Runing and collecting output and error
	stdout_list = []
	stderr_list = []
	stderr_val_list = []
	for arg in args:
		cmd = program + arg
		output = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
		cmd_val = valgrind + cmd
		output_val = subprocess.run(cmd_val, stderr=subprocess.PIPE, text=True)
		stderr_list.append(output.stderr)
		stderr_val_list.append(output_val.stderr)
		
	# Printing test check
	i = 0
	for err, err_val in zip(stderr_list, stderr_val_list):
		print(f"{battery[i].upper()}")
		if (err == stderr_ref_list[i]):
			print(f"{colours[0]}{i + 1}. OK{colours[2]}")
		else:
			print(f"{colours[1]}{i + 1}. KO{colours[2]}")
		if valgrind_check in err_val:
			print(f"{colours[0]}   MOK\n{colours[2]}")
		else:
			print(f"{colours[1]}   MKO\n{colours[2]}")
		i = i + 1