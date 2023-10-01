//programa que genera una salida en orden inverso del abecedario
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

void main(){
	pid_t pid1, pid2;
	
	printf("AAA \n");
	
	pid1 = fork();
	
	//printf("%d\n",getpid());
	
	if(pid1==0){
	
		printf("BBB \n");
		
	}else{
		wait(0);
		pid2 = fork();
		if(pid2==0)
			printf("CCC \n");
		else
			wait(0);
		
  	}

 	exit(0);
 	
}
