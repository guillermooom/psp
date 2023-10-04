//programa que genera una salida en orden inverso del abecedario
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

void main(){
	pid_t pid;
	
	for(int i=0;i<2;i++){
		pid = fork();
		
		if(pid==0){
			printf("Mi PID es %d\n",getpid());
			printf("El PID de mi padre es %d\n\n",getppid());
			
		}else{
			wait(0);
			//printf("\n\nPAPA PID %d\n\n",getpid());
		
  		}
	}

 	exit(0);
 	
}
