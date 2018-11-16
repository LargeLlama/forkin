#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

int main()
{
	int time_slept_0 = 0;
	int child_0;
	srand( time(NULL) );
	printf("What's cracking\n");
	child_0 = fork();
	wait(&time_slept_0);

	if(!child_0)
	{
		printf("hey losers, child 0 reporting for duty with a pid of %d\n", getpid());
		time_slept_0 = (rand() % 16) + 5;
		sleep(time_slept_0);
		exit(time_slept_0);
	}
	printf("the pid of child 0 was %d\n", child_0);
	printf("time slept for child 0 was %d seconds\n", time_slept_0 / 255 );
}
