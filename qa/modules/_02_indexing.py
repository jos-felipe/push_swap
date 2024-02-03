import subprocess

def indexing():
	cmd0 = "../push_swap"
	valgrind = ["valgrind", "--leak-check=full", "--show-leak-kinds=all", "--track-origins=yes"]
	substring = "All heap blocks were freed -- no leaks are possible"

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
	unordered_list.insert(0, cmd0)

	# Runing cmd and getting output
	output = subprocess.run(unordered_list, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
	unordered_list[:0] = valgrind
	output_val = subprocess.run(unordered_list, stderr=subprocess.PIPE, text=True)

	# Printing test check
	print(f"{battery.upper()}")
	if ((output.stdout == ranking_list)):
		print(f"{GREEN}1. OK{COLOR_LIMITER}")
	else:
		print(f"{RED}1. KO{COLOR_LIMITER}")
	string = output_val.stderr
	if substring in string:
		print(f"{GREEN}   MOK\n{COLOR_LIMITER}")
	else:
		print(f"{RED}   MKO\n{COLOR_LIMITER}")