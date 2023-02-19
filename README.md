# OS-Inter-Process-Communication-Technique-In-C
Implementation of OS Inter Process Communication Technique, signals, in C.

For this purpose I have written two programs. The first program is called “cementmixer.c” and the second one is called “bricklayer.c”  Both programs have to be run in different shell (terminal) windows on the same system.<br>
• cementmixer.c represents a construction worker who is responsible for mixing the cement.<br> 
• bricklayer.c represents a construction worker who is a bricklayer.<br>
• Both the processes are able to run in parallel. The product of cementmixer.c is delivered to bricklayer.c, and bricklayer needs the cement to work. Therefore, if the bricklayer runs out of cement, it sends a signal to the cement-mixer to provide it with more cement.<br><br>
<strong>• Mixed cement is prepared in the following way:</strong><br> o A fixed small delay (e.g., 0.5 seconds) is needed to mix a unit of cement. 
•	The mixer does not deliver unless a total of 10 units are completely mixed.<br>
•	A variable goes from 0 to 10 when the cement is fully mixed. <br>
•	When cement is delivered, this variable goes to 0 and starts over. <br>
•	The bricklayer goes into waiting if the cement is being mixed, and his batch is fully laid.<br>
<strong>• Bricklayer works in the following way.</strong><br>
•	A fixed small delay (e.g., 0.5 seconds) is needed to lay one brick.<br>
•	One batch of cement can only be used to lay 15 bricks. <br>
•	A variable goes from 0 to 15 when a batch is complete. <br>
•	When the batch is complete, this variable goes back to 0 and starts over.<br> 
•	The cement-mixer goes into waiting if the bricks are being laid, and cement is being mixed.<br><br><br><br>

P.S Instructions to use. First run the cement.c file then run brick,c file. Enter the PID of the brick in cement.c file and the process will start.

