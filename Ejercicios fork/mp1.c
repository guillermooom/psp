//el hijo mostrara nuestro nombre
//luego el padre mostrara su pid y el pid del hijo

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){

	pid_t proceso;
	
	proceso=fork();
	
	
	if(proceso == -1){
	    printf("ERROR !!! No se ha podido crear el proceso hijo...");
	    exit(-1);       
  	}
  	
  	if(proceso == 0)
  		printf("Guillermo Moreno\n");

  	else{
  	wait(NULL);
  	printf("PID del hijo %d\n",proceso);
  	printf("PID del padre %d\n",getpid());
  	 	
  	}
  	
  	exit(0);
}
