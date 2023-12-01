#include <stdio.h> 
#include <signal.h> 
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

	time_t hora;
     	char *fecha;
    

void crea(){
//Crea la fecha y hora actual
    	time(&hora);
    	fecha = ctime(&hora);
	printf("Inicio del proceso %d : %s \n",getpid(),fecha);
}

void mata(int i){
//Crea la fecha y hora actual
    	time(&hora);
    	fecha = ctime(&hora);
	printf("Fin del proceso %d : %s \n",getpid(),fecha);
	kill(getpid(),SIGKILL);
}



int main(void){
  crea();
  signal(SIGQUIT, mata);
  //signal(SIGINT, sig_handler);
 //Bucle infinito proceso queda a la espera de la señal
  while(1)
    sleep(1);

  return 0;
}
