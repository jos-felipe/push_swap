import subprocess

int_max = (2**31) - 1
int_min = -(2**31)
cmd0 = "../push_swap"

# Colors Definition 
GREEN = "\033[32;1m"
RED = "\033[31;1m"
CYAN = "\033[36;1;3;208m"
WHITE = "\033[37;1;4m"
COLOR_LIMITER = "\033[0m"

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

stdout_list = []
stderr_list = []
battery = ["ordered_list", "str_on_list", "dup_on_list", "min_on_list", "max_on_list", "nothing_on_list"]
args = [ordered_list, str_on_list, dup_on_list, min_on_list, max_on_list, nothing_on_list]
stderr_ref_list = ["", "Error\n", "Error\n", "Error\n", "Error\n", ""]
stdout_ref_list = ["", "", "", "", "", ""]
for arg in args:
	arg.insert(0, cmd0)
	output = subprocess.run(arg, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
	stderr_list.append(output.stderr)
	stdout_list.append(output.stdout)

i = 0
for out, err in zip(stdout_list, stderr_list):
	print(f"{battery[i].upper()}")
	if ((out == stdout_ref_list[i]) and (err == stderr_ref_list[i])):
		print(f"{GREEN}{i + 1}. OK\n{COLOR_LIMITER}")
	else:
		print(f"{RED}{i + 1}. KO\n{COLOR_LIMITER}")
	# print(out, stdout_ref_list[i])
	i = i + 1