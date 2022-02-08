Author: Ryan Kelly

Class: Computer Science 4760

School: University of Missouri - Saint Louis

Assignment: Project 1 - Linux System Calls and Library

Due Date: 2/8/2022

Language Used: C

Description: The program takes in command line parameters using getopt. -h is for help, -p is the number of processes, -c is the number of characters, -s is how long
the processes should sleep, and -i is the number of iterations that should occur. The program will split into the specified number of processes, each one pulling nchars
from a textfile that is read from stdin.

Build Instructions (Linux Terminal): make

Delete chain Executable and Output Files: make clean

How to run with a file named 'textfile': ./chain [-h] [-p num of processes] [-c num of characters] [-s sleeptime] [-i num of iterations] < textfile

Notes: This is my fault but I didn't use version control for the first 7 tasks, and started using git for task 8. I kept track of what I had typed in my document file,
so I will just include those versions there. I understand if you have to take off the 10 points.