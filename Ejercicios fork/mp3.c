//cremos 2 procesos hijos, uno q muestre los pid y otro que se duerama y despierte
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){

	pid_t proceso1,proceso2;
	
	//creamos los procesos
	//for(int i=0;i<2;i++){}
	proceso1=fork();
	proceso2=fork();	
  	
  	if(proceso1==0 || proceso2==0){
  		//dormimos el primer proceso y que diga cuando se despierte
  		if(proceso1 == 0){
  			/*sleep(10);
  			printf("\nDespierto!");*/
  			printf("Soy el Proceso 2\n");
  			printf("Mi PID es %d\n",getpid());
  			printf("El PID de mi padre es %d\n",getppid());
  		}
  		
  		//el ultimo proceso mostrara su pid y el de su padre
  		if(proceso2 == 0){
  			printf("Soy el Proceso 3\n");
  			printf("Mi PID es %d\n",getpid());
  			printf("El PID de mi padre es %d\n",getppid());
  		}
  		

  	}else{
  	wait(NULL);
  	printf("\nCIERRE DE PROGRAMA\n");
  	 	
  	}
  	
  	exit(0);
}
