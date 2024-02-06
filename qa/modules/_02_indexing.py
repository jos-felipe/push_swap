import subprocess

def indexing(program, valgrind, valgrind_check):

	# Colors Definition 
	GREEN = "\033[32;1m"
	RED = "\033[31;1m"
	CYAN = "\033[36;1;3;208m"
	WHITE = "\033[37;1;4m"
	COLOR_LIMITER = "\033[0m"

	battery = "Indexing"

	# Defining arg and output ref
	unordered_list = ["-1", "1", "0", "10", "-10"]
	ranking_list = "2 4 3 5 1 "
	cmd = program + unordered_list

	# Runing cmd and getting output
	output = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
	cmd_2 = valgrind + cmd
	output_val = subprocess.run(cmd_2, stderr=subprocess.PIPE, text=True)
	err_val = output_val.stderr

	# Printing test check
	print(f"{battery.upper()}")
	if ((output.stdout == ranking_list)):
		print(f"{GREEN}1. OK{COLOR_LIMITER}")
	else:
		print(f"{RED}1. KO{COLOR_LIMITER}")
	if valgrind_check in err_val:
		print(f"{GREEN}   MOK\n{COLOR_LIMITER}")
	else:
		print(f"{RED}   MKO\n{COLOR_LIMITER}")