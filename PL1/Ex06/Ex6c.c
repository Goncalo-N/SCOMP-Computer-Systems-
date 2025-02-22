#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
	pid_t p1;
	int status;
	int i,j,count=0;
	pid_t pids[4]; 

	for(i=0;i<4;i++){
		p1 = fork();
		
		if(p1%2 == 0 && p1>0){
			pids[count] = p1;
			count++;
		}

		if(p1==0){
			sleep(1);
			exit(0);
		}
	}

	for(j=0;j<count;j++){
		waitpid(pids[j],&status,0);
	}

	printf("\nPID:%d � This is the end.\n",getpid());
	return 0;
}