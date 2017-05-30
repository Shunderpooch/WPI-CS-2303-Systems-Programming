==================================
|Arthur Dooner, CS2303 C02		 |
|ajdooner@wpi.edu				 |
|Program 3						 |
|Event-Driven Simlation of a Pro-|
|Cessor Scheduling Quene in C    |
==================================
_________________________________________________

To Compile:
	make
To Run:
	./Program3 <number of lines of input> <timeslice>
To run FCFS, use a Timeslice of 0.  
_________________________________________________

To input data from a file, add these commands on to run:
	<<Name of Input File>> <Name of Output File>
_________________________________________________

Program 3, our third program, is designed to simulate how a processor works. With both required simulations, First Come, First Serve (FCFS),
and Round Robin are designed to use a list of events coming into a processor, with the eventList (pointed to by the Link *sPtr in my program),
the list for all of the processes to be sent to the CPU, and the processorList (pointed to by the Link *sProcPtr in my program), which has a list
of all of the enquened processes about to be processed by the computer.

For FCFS:
	I implemented a check in the program to ensure that we have not reached the end of the eventList, indicated by a sentinel Link with a processID
	of -1. While the program is not at the end of the list, it will check to see if there are any events to be added. If there are, it will run them
	in the proccessor simulator (processorSimulation()) for their required CPU Time, and if there are not any, it will increment the time and state
	that the CPU is sitting idle. 

For Round Robin:
	I implemented a check in the program to ensure that we have not reached the end of the eventList, indicated by a sentinel Link with a processID
	of -1. While the program is not at the end of the list, it will check to see if there are any events to be added. If there are, it will run them
	in the proccessor simulator (processorSimulation()) for the given timeslice, and if there are not any, and there are no processes in the CPU quene
	currently running it will increment the time and state that the CPU is sitting idle. Undoubtably, Round Robin will have processes continue to be 
	acted upon after there are none left being added in the event list, so after this, I check to see if the processorList is empty after this, and run
	while it is not. 

For processorSimulation:
	I implemented processorSimulation to take in a pointer to a list, along with the System Time and timeSlice given by the user. It will take the first
	item off the list, work on it for the timeslice provided or the time required by the process, whichever comes first. If the process is completed, it
	will return the time used and add the total time of the process for calculations of mean and variance later, with the process freed from memory. 
	Otherwise, its CPUTime will be decremented by the time slice and added to the back of the processorList, returning the timeslice.

All of these combined allow for the complete program, along with movement operations, and the calculation of mean and variance to give us the final output
of the program.

Thank you for using this program!
