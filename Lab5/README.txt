Arthur Dooner & Project Partner
CS2303 Group H2
Lab 5

To Compile this program, type: 
	make
Everything else is done for you.

This program runs by just calling ./Lab5 without any input. 

This program sends 100 packets each from S1 and S2 through to mule node M1, which then transmits the packets 
to M2, which then transmits the packets to the receiver R1. Sending packets takes time, as well as propagating packets at each node. S1 begins sending packets 
at time zero, while S2 begins sending packets at time 3 sim. Each packet takes care of its own timekeeping, and when everything is received at R1, the facts for 
each packet's transmission time, etc, are printed.
