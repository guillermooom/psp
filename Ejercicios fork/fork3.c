#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

void main(){					//P1
	pid_t pid1,pid2,pid3,pid4,pid5;
	
	pid1 = fork();				//P2
		
	if(pid1==0){
		printf("Mi PID es el %d\n",getpid());
		printf("Mi padre tiene el %d\n",getppid());
		
		printf("Acaba P2\n\n");	//ACABA P2
		
		pid2 = fork();			//P3
		
		if(pid2==0){
			printf("Mi PID es el %d\n",getpid());
			printf("Mi padre tiene el %d\n",getppid());
			printf("Acaba P3\n\n");//ACABA P3
		}else if(pid2!=0){
			wait(0);
			
		}
		
		pid3 = fork();			//P4
		
		if(pid3==0 && pid2!=0){
			printf("Mi PID es el %d\n",getpid());
			printf("Mi padre tiene el %d\n",getppid());
			printf("Acaba P4\n\n");//ACABA P4
		}else if(pid3!=0){
			wait(0);
			
		}
	}else{
		wait(0);
		printf("Soy el padre y tengo el %d\n",getpid());
		
		printf("Acaba P1\n\n");	//ACABA P1
	}

 	exit(0);
 	
}
