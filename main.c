//Rubin Peci
//Period 5
//Systems
//2018-11-17

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

//helper function
int get_random()
{
	//open the random file, and declare the int to store it
	int file = open("/dev/random", O_RDONLY);
	unsigned int rand;
	//read exactly an integers worth of data and place it in rand
	read(file, &rand, sizeof(int));
	//return any errors if they exist
	if (errno)
	{
		printf("ERROR %d: %s\n", errno, strerror(errno));
	}
	
	//close and return the value of rand
	close(file);
	return rand;
}

int main()
{
	//declare our variables
	int time_slept;
	int pid;
	//array to store the two child processes
	int children[2];

	//introduce the beautiful parent process
	printf("What's cracking, papa process here with a pid of %d\n", getpid());
	
	//loop to create our child processes, and make them sleep
	for(int i = 0; i < 2; i++)
	{
		if(!(children[i] = fork()))
		{
			printf("Child %d reporting for duty with a pid of %d\n", i, getpid());
			time_slept = abs((get_random()  % 16) + 5);	//has to be absolute value b/c it makes it negative sometimes (idk why)
			//printf("Child %d gonna sleep for %d seconds\n", i, time_slept);
			sleep(time_slept);
			printf("I, child %d, have finished shlumping\n", i);
			exit(time_slept);
		}
	}
	//the parent waits until one of the children exit, and stores the pid into the variable
	//also stores the time_slept so we can print it out
	pid = wait(&time_slept);
	printf("Child pid of %d slept for %d seconds\n", pid, time_slept / 255);
	printf("Papa process is done, deuces!\n");

	return 0;
}
