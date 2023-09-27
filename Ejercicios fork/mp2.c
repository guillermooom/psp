//cada proceso debe presentarse e indicar su pid y ppid
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){

	pid_t proceso1,proceso2;
	
	proceso1=fork();	//creamos el primer proceso
  	
  	if(proceso1 == 0){
  		proceso2=fork();	//una vez dentro del proceso creamos el nieto
  					//no hace falta q espere el hijo
  		if(proceso2 == 0){
  			printf("Soy el nieto\n");
  			printf("Mi PID es -> %d\n",getpid());
  			printf("Mi PID de mi padre es -> %d\n",getppid());
  		}else{
  			wait(NULL);
	  		printf("\nSoy el padre\n");
	  		printf("Mi PID es -> %d\n",getpid());
	  		printf("Mi PID de mi padre es -> %d\n",getppid());
  		}

  	}else{
  	wait(NULL);
  	printf("\nSoy el abuelo\n");
  	printf("Mi PID es -> %d\n",getpid());
  	printf("Mi PID de mi hijo es -> %d\n",proceso1);
  	 	
  	}
  	
  	exit(0);
}
