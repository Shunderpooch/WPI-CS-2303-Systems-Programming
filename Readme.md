# Systems Programming for Majors (CS 2303, Worcester Polytechnic Institute [WPI])

## The course
This course was taught by Professor Robert Kinicki, from January to March 2014.

[Course Website](http://web.cs.wpi.edu/~rek/Systems/C14/C14.html)

We covered a massive range of Systems Programming Concepts, Data Structures, and intense simulations in C and C++ over the course of the class.

The professor above all else encouraged a meaningful understanding of the C compiler, and comprehension of pointers, arrays, permissions, memory allocation, and other lower-level programming concepts. 

## The Projects in this Repository
There were two main sets of assignments for this course, Labs and Programs. Labs were usually simpler, one-off ideas or concepts, and Programs covered a multitude of topics and were significantly more intricate. Below, I'll include a short summary of each Lab and Program we worked on, along with instructions on how to compile them.

### Lab 1
This was a simple C program to learn how to work with command-line input, Unix commands, and return a result based on an average of numbers.

#### Compiling Lab 1

```shell
$ gcc -o Lab1 Lab1.c
```

#### Running Lab 1

```shell
$ ./Lab1
```

### Program 1
Program 1 had us learn functions, syntax, and C variable types. We designed functions that returned the log2(input), and another function that calculated the euclidian distance between elements. We also became familiar with scanf and other C conventions. You can test the program with the included "Program1.txt" text input.

#### Compiling Program 1

```sh
$ gcc -o Program1 Program1.c -lm -std=c99
```

#### Running Program 1

```sh
$ ./Program1
```

#### Running Program 1 with Example Input

```sh
$ ./Program1 <Program1.txt >output.txt
```

### Lab 2
Lab 2 was designed to familarize us with Arrays, Makefiles, and the GDB Debugger for our C programs. It moves elements based on a direction integer across the field until it reaches the edge of the field, for the amount of elements passed to it. 

#### Compiling Lab 2
A Makefile is used from these programs on, so to compile the program all that is particularly needed is to run:

```sh
$ make
```

in the folder directory of the project.

#### Running Lab 2
Test data is included, [Here as Lab2.txt](/Lab2.txt), and can be piped in. Example output is included as well, [Here as Lab2.out](/Lab2/Lab2.out).

```sh
$ ./Lab2
```

### Program 2
Motion Smashball is a sophisticated and intricate game, with players, directions, player interactions, eliminations of the opponent, and much more. I implemented Version I of Motion Smashball, the most difficult variant of the game.
More on the Smashball assignment can be found [Here](http://web.cs.wpi.edu/~rek/Systems/C14/Program2_C14.pdf). 
You should also check out my original readme for the file, located in the Program2 directory.

#### Compiling Program 2
Again a Makefile is used, so all that is needed is:

```sh
$ make
```

#### Running Program 2
Smashball requires no additional parameters. It outputs a lot, so it's very much recommended to pipe the output, as shown below.

```sh
$ ./Program2 >output.txt
```

### Lab 3
Lab 3 was designed to teach us a simple First Come, First Serve Queue with an Event List. We can remove from, add to, and print the queue in this lab. This was our preliminary introduction to pointers, and command line arguments. 

#### Compiling Lab 3

```sh
$ make
```

#### Running Lab 3
Lab 3 has a command line argument for number of sources it takes for its queue, and then has a user input the process-id, arrival\_time and cpu\_time, one per line of text input. Input would follow as:

```sh
$ ./Lab3 [sources]
```

#### Running Lab 3 with Included Test Data

```
$ ./Lab3 10 <lab3.dat
```

### Program 3
Program 3 was a simulation of a process queue for a processor running a time-sharing operating system, in three different increasing complexities. In this Program, I implemented the first two:
The First Come First Serve (FCFS) queue was the simplest variant, where every process is scheduled linearly without any concept of timeslices.
The Round Robin Scheduler was a more realistic representation of an operating system processor queue, where every process is allowed a certain frame of time to be worked on, then brought back to the end of the queue.
Further reading on this processor simulation can be found [Here](http://web.cs.wpi.edu/~rek/Systems/C14/Program3_C14.pdf), on the course website.

#### Compiling Program 3

```sh
$ make
```

#### Running Program 3
This program is fairly complicated, and has some running options. Refer to the [Readme](/Program3/README.txt) in the Program3 folder for running options.

Sample output based on various simulation modes are provided in the program folder, including [FCFS Output](/Program3/FCFS.txt), [FCFS Debug Output](/Program3/FCFSdebug.txt), [RR Output](/Program3/RR.txt), and [RR Debug Output](/Program3/RRslice2debug.txt)

### Lab 4
Lab 4 was designed to teach us binary trees and how to print these trees in order. It furthered our understanding of binary trees, pointers, and data structure representation in C. 
Further reading on the lab description can be found [Here](http://web.cs.wpi.edu/~rek/Systems/C14/Lab4_C14.pdf), on the course website.

#### Compiling Lab 4

```sh
$ make
```

#### Running Lab 4
Further running instructions can be found in the [Readme](/Lab4/README.txt) in the Lab4 folder for running options, but simply:

```sh
$ ./Lab4 [Number of students]
```

Lab 4 can use the test data "Lab4.dat" as piped input for simple tests.

### Program 4
Program 4 generated cross references of every word (case-insensitive) that it finds in an ASCII text file with a Binary Search Tree data structure, and sorts these words in order alphabetically, noting the number of occurences of the word and the lines the word occurs on.
Further insight into this program can be found [Here](http://web.cs.wpi.edu/~rek/Systems/C14/Program4_C14.pdf).

This program was done in pairs, and I do not have permission to share my partner's name. I will refer to them in files as "Program Partner".


#### Compiling Program 4

```sh
$ make
```

When compiling, make sure to have g++ installed on your machine.

#### Running Program 4
Program 4 takes in any ASCII file as input, using the pipe character.

```sh
$ ./Program4 <[file.txt]
```

Included in the same folder is sample data such as the US Constitution "US_Constitution.txt" and a simple test "simpletest.txt" that are ideal examples for this program. 

### Lab 5
Lab 5 is mainly preparation for Program 5, a complete MANET Simulation. It is a direct simplification, with non-moving mule nodes from sender to receiver. A sender sends 100 packets of varying transmission time and propogation time across two mules with another sender, all to a receiver, with 100ms simulation time slices, or sims. This lab also helped introduce file readers and build guards.
For further reading on this lab concept, look [Here](http://web.cs.wpi.edu/~rek/Systems/C14/Lab5_C14.pdf) for a stronger understanding of Lab requirements.

#### Compiling Lab 5

```sh
$ make
```

#### Running Lab 5
The total time in sending packets increases linearly across the Lab, so you do not need to set each packet's behavior. Example output is included [Here] (/Lab5/packetsim.txt).

```sh
$ ./Lab5
```

### Program 5
Program 5 is by all means the most complicated program of the course. It combines many aspects of Program 1, Program 2, and Program 3, to design a complete Mobile Ad hoc Network (MANET) Simulation. Specific design decisions and program parameters are outlined in the [Program Description] (http://web.cs.wpi.edu/~rek/Systems/C14/Program5_C14.pdf) and my [Readme for Program 5](/Program5/README.txt).

#### Compiling Program 5

```sh
$ make
```

#### Running Program 5
There are several parameters that should be followed closely- change the prog5.txt file to change different source nodes- change these source nodes based on the guidelines of the [Program Description](http://web.cs.wpi.edu/~rek/Systems/C14/Program5_C14.pdf). Sample output is provided [Here](/Program5/output.txt)


