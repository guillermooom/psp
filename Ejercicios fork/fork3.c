#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

void main(){
	pid_t pid1,pid2,pid3;
	
	pid1 = fork();
		
	if(pid1==0){
		printf("Mi PID es %d\n",getpid());
		printf("El PID de mi padre es %d\n\n",getppid());
		for(int i=0;i<2;i++){
			pid2 = fork();
		}
		/*if(pid2==0){
			printf("Mi PID es %d\n",getpid());
			printf("El PID de mi padre es %d\n\n",getppid());
			pid3 = fork();
			if(pid3==0){
				printf("Mi PID es %d\n",getpid());
				printf("El PID de mi padre es %d\n\n",getppid());
			}else{
				wait(0);
				printf("Soy el padre y tengo el %d\n",getpid());
			}
		}else{
			wait(0);
			printf("Soy el padre y tengo el %d\n",getpid());
		}*/
			
	}else{
		wait(0);
		printf("Soy el padre y tengo el %d\n",getpid());
	}

 	exit(0);
 	
}
