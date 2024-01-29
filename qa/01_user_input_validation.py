import subprocess

int_max = (2**31) - 1
int_min = -(2**31)
cmd0 = "../push_swap"

ordered_list = []
ordered_range = range(1, 11, 1)
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
args = [ordered_list, str_on_list, dup_on_list, min_on_list, max_on_list, nothing_on_list]
stderr_ref_list = ["b''", "b'Error\n'", "b'Error\n'", "b'Error\n'", "b'Error\n'", "b''"]
stdout_ref_list = ["b''", "b''", "b''", "b''", "b''", "b''"]
for arg in args:
	arg.insert(0, cmd0)
	output = subprocess.run(arg, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
	stderr_list.append(output.stderr)
	stdout_list.append(output.stdout)

print(stderr_list)
print(stdout_list)

i = 0
for out, err in zip(stdout_list, stderr_list):
	if ((out == stdout_ref_list[i])):
		print(f"{i + 1}. OK\n")
	else:
		print(f"{i + 1}. KO\n")
	i = i + 1

i = 0
for out, err in zip(stdout_list, stderr_list):
	print(f"out:{out} | err:{err}")
	print(f"out_ref:{stdout_ref_list[i]} | err_ref:{stderr_ref_list[i]}\n")