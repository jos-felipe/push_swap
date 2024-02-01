{
 "cells": [
  {
   "cell_type": "code",
   "execution_count": 2,
   "metadata": {},
   "outputs": [],
   "source": [
    "unordered_list = [\"-1\", \"1\", \"0\", \"10\", \"-10\"]\n",
    "ranking_list = [\"2\", \"4\", \"3\", \"5\", \"1\"]\n"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 40,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "[../push_swap1../push_swap,../push_swap ../push_swap2../push_swap,../push_swap ../push_swap3../push_swap,../push_swap ../push_swap4../push_swap,../push_swap ../push_swap5../push_swap,../push_swap ../push_swap6../push_swap,../push_swap ../push_swap7../push_swap,../push_swap ../push_swap8../push_swap,../push_swap ../push_swap9../push_swap,../push_swap ../push_swap1../push_swap0../push_swap]\n",
      "[../push_swap1../push_swap,../push_swap ../push_swap2../push_swap,../push_swap ../push_swap3../push_swap,../push_swap ../push_swap4../push_swap,../push_swap ../push_swap5../push_swap,../push_swap ../push_swap6../push_swap,../push_swap ../push_swap7../push_swap,../push_swap ../push_swap8../push_swap,../push_swap ../push_swap9../push_swap,../push_swap ../push_swap1../push_swap0../push_swap]\n"
     ]
    }
   ],
   "source": [
    "import subprocess\n",
    "command = \"../push_swap\"\n",
    "\n",
    "args = [unordered_list]\n",
    "\n",
    "for arg in args:\n",
    "\t_args = command.join(arg)\n",
    "\t# print(_args)\n",
    "\tsubprocess.run(command, arg, stdout=subprocess.PIPE, stderr=subprocess.PIPE)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 6,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "stdout: -10 -1 0 1 10 \n",
      "ranking_list: 2 4 3 5 1\n",
      "1. KO\n",
      "\n"
     ]
    }
   ],
   "source": [
    "import subprocess\n",
    "\n",
    "cmd0 = \"../push_swap\"\n",
    "unordered_list = [\"-1\", \"1\", \"0\", \"10\", \"-10\"]\n",
    "ranking_list = \"2 4 3 5 1\"\n",
    "\n",
    "stdout_list = []\n",
    "stderr_list = []\n",
    "stderr_ref_list = [\"\"]\n",
    "stdout_ref_list = ranking_list\n",
    "unordered_list.insert(0, cmd0)\n",
    "output = subprocess.run(unordered_list, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)\n",
    "\n",
    "print (f\"stdout: {output.stdout}\")\n",
    "print (f\"ranking_list: {ranking_list}\")\n",
    "if ((output.stdout == stdout_ref_list)):\n",
    "\tprint(f\"1. OK\\n\")\n",
    "else:\n",
    "\tprint(f\"1. KO\\n\")"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "metadata": {},
   "outputs": [],
   "source": []
  }
 ],
 "metadata": {
  "kernelspec": {
   "display_name": "Python 3",
   "language": "python",
   "name": "python3"
  },
  "language_info": {
   "codemirror_mode": {
    "name": "ipython",
    "version": 3
   },
   "file_extension": ".py",
   "mimetype": "text/x-python",
   "name": "python",
   "nbconvert_exporter": "python",
   "pygments_lexer": "ipython3",
   "version": "3.8.10"
  }
 },
 "nbformat": 4,
 "nbformat_minor": 2
}
