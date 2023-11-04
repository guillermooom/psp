#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <time.h> 
#include <string.h>

void main(){

     int p1[2],p2[2],res=1,cont; 
     char buffer[8];
     pid_t pid;
     char cad[2];
     char letra [] = "TRWAGMYFPDXBNJZSQVHLCKE";
     time_t t;

     // Creamos los pipes
     pipe(p1); 
     pipe(p2);
     
     //Se crea un proceso hijo
     pid = fork();

     if (pid==0){
     
     
     close(p1[1]);
     close(p2[0]);
     
     read(p1[0], buffer,sizeof(buffer));
     cont = atoi(buffer);

     cont%=23;
     cad[0]=letra[cont];
     cad[1]='\0'; //ultima posicion y para cerrar

     write(p2[1],cad,strlen(cad));

     }
     
     else{
         
         close(p1[0]);
         close(p2[1]);
	 
 	 srand((unsigned)time(&t));
	 int dni;
	 char escribe [8],lectu[1];
	 int total;
	 
	 printf("Introduzca su DNI: ");
    	 scanf("%d", &dni);

	 sprintf(escribe,"%d",dni);
	 write(p1[1],escribe,strlen(escribe));
	 
	 read(p2[0],lectu,sizeof(lectu));
	 
	 printf("\nLa letra del NIF es %s \n",lectu);
	 
	 wait(NULL);
         }
         
         
         
         
         
     }
