import subprocess

def	tiny_sort(program, valgrind, valgrind_check, colours):

	# Definig args
	all_tiny_sort_args = [["1", "2", "3"], ["1", "3", "2"], ["2", "1", "3"], ["2", "3", "1"], ["3", "1", "2"], ["3", "2", "1"]]

	# Defining references
	nbr_refs_pre = ["1 2 3 \n", "1 3 2 \n", "2 1 3 \n", "2 3 1 \n", "3 1 2 \n", "3 2 1 \n"]
	move_refs = ["", "rra\nsa\n", "sa\n", "rra\n", "ra\n", "ra\nsa\n"]
	nbr_refs_pos = ["1 2 3\n", "1 2 3\n", "1 2 3\n", "1 2 3\n", "1 2 3\n", "1 2 3\n"]
	output_ref_list = []
	for nbr_pre, move, nbr_pos in zip(nbr_refs_pre, move_refs, nbr_refs_pos):
		output_ref_list.append(nbr_pre + move + nbr_pos)

	all_outputs = []
	all_outputs_val = []
	for tiny_sort_arg in all_tiny_sort_args:
		cmd = program + tiny_sort_arg
		output = subprocess.run(cmd, stdout=subprocess.PIPE, text=True)
		cmd_val = valgrind + cmd
		output_val = subprocess.run(cmd_val, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
		all_outputs.append(output.stdout)
		all_outputs_val.append(output_val.stderr)
	
	i = 1
	for out, out_val, out_ref in zip(all_outputs, all_outputs_val, output_ref_list):
		print("---------")
		if (out == out_ref):
			print(f"{colours[0]}{i}. OK  {colours[2]}")
		else:
			print(f"{colours[1]}{i}. KO  {colours[2]}")
		if valgrind_check in out_val:
			print(f"{colours[0]}   MOK{colours[2]}")
		else:
			print(f"{colours[1]}   MKO{colours[2]}")
		i = i + 1