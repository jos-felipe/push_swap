import subprocess

def user_input():
	cmd0 = "../push_swap"
	valgrind = ["valgrind", "--leak-check=full", "--show-leak-kinds=all", "--track-origins=yes"]
	substring = "All heap blocks were freed -- no leaks are possible"

	# Int min and max
	int_max = (2**31) - 1
	int_min = -(2**31)

	# Colors Definition 
	GREEN = "\033[32;1m"
	RED = "\033[31;1m"
	CYAN = "\033[36;1;3;208m"
	WHITE = "\033[37;1;4m"
	COLOR_LIMITER = "\033[0m"

	# Creating args
	battery = ["ordered_list", "str_on_list", "dup_on_list", "min_on_list", "max_on_list", "nothing_on_list"]
	ordered_list = []
	ordered_range = range(-1, 11, 1)
	for n in ordered_range:
		ordered_list.append(str(n))
	str_on_list = ordered_list[:]
	dup_on_list = ordered_list[:]
	min_on_list = ordered_list[:]
	max_on_list = ordered_list[:]
	nothing_on_list = []
	str_on_list[4] = "abc"
	dup_on_list[9] = "1" 
	min_on_list[4] = str(int_min - 1)
	max_on_list[4] = str(int_max + 1)
	args = [ordered_list, str_on_list, dup_on_list, min_on_list, max_on_list, nothing_on_list]

	# Reference output
	stderr_ref_list = ["", "Error\n", "Error\n", "Error\n", "Error\n", ""]
	stdout_ref_list = ["", "", "", "", "", ""]

	# Runing and colecting output and error
	stdout_list = []
	stderr_list = []
	stderr_val_list = []
	for arg in args:
		arg.insert(0, cmd0)
		output = subprocess.run(arg, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
		arg[:0] = valgrind
		output_val = subprocess.run(arg, stderr=subprocess.PIPE, text=True)
		stderr_list.append(output.stderr)
		stdout_list.append(output.stdout)
		stderr_val_list.append(output_val.stderr)
		
	# Printing test check
	i = 0
	for out, err, err_val in zip(stdout_list, stderr_list, stderr_val_list):
		print(f"{battery[i].upper()}")
		if ((out == stdout_ref_list[i]) and (err == stderr_ref_list[i])):
			print(f"{GREEN}{i + 1}. OK{COLOR_LIMITER}")
		else:
			print(f"{RED}{i + 1}. KO{COLOR_LIMITER}")
		string = err_val
		if substring in string:
			print(f"{GREEN}   MOK\n{COLOR_LIMITER}")
		else:
			print(f"{RED}   MKO\n{COLOR_LIMITER}")
		i = i + 1