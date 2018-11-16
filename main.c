#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	int time_sleep_0 = 0;
	int time_sleep_1 = 0;
	srand(time(NULL));

	int child_0 = fork();
	int child_1 = fork();

	if (child_0 > 0 && child_1 > 0)
	{
		printf("This is the parent process, pid: %d\n", getpid());
		waitpid(child_0, &time_sleep_0, 0);
		waitpid(child_1, &time_sleep_1, 0);

		printf("child_0 was asleep for %d seconds\n", time_sleep_0);
		printf("child_1 was asleep for %d seconds\n", time_sleep_1);
		printf("DONE!\n");

	} 
	else if(!child_0 && child_1 > 0)
	{
		printf("This is the first child process, pid: %d\n", getpid());
		time_sleep_0 = (rand() % 15) + 5;
		sleep(time_sleep_0);
		printf("CHILD 0 DONE!\n");
		exit(time_sleep_0);
	}
	else if(child_0 && !child_1)
	{
		printf("This is the second child process, pid: %d\n", getpid());
		time_sleep_1 = (rand() % 15) + 5;
		sleep(time_sleep_1);
		printf("CHILD 1 DONE!\n");
		exit(time_sleep_0);
	}
}
