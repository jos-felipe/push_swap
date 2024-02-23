import subprocess

def preparing_environment():
	arg = "wget -P ../ -nc https://cdn.intra.42.fr/document/document/23675/checker_linux"
	arg_chmod = "chmod +x ../checker_linux"

	subprocess.run(arg, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, shell=True)
	subprocess.run(arg_chmod, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, shell=True)