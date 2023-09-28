//cremos 2 procesos hijos, uno q muestre los pid y otro que se duerama y despierte
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){

	pid_t proceso;
	
	//creamos los procesos
	for(int i=0;i<2;i++){
	proceso=fork();

  	if(proceso==0){
  	
  		//dormimos el primer proceso y que diga cuando se despierte
  			/*sleep(10);
		printf("\nDespierto!");*/
		printf("Soy el Proceso %d\n",i);
		printf("Mi PID es %d\n",getpid());
		printf("El PID de mi padre es %d\n",getppid());
  	
  		//el ultimo proceso mostrara su pid y el de su padre
 	break;
  		

  	}else{
  	wait(NULL);
  	
	printf("\n\nPAPA PID %d\n\n",getpid());
	}
}
  	
  	exit(0);
}
