#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <time.h> 
#include <string.h>

void main(){

     int fd[2]; 
     char buffer[5];
     pid_t pid;
     char cad[2];
     time_t t;

     // Creamos el pipe
     pipe(fd); 
     
     //Se crea un proceso hijo
     pid = fork();

     if (pid==0){
     int num1,num2,sum,res,mul,div;
     
     close(fd[1]); // Cierra el descriptor de lectura
     read(fd[0], buffer,sizeof(buffer));
     //printf("\n %s",buffer);
     
     char *n1 = strtok(buffer," ");
     char *n2 = strtok(NULL,buffer);
     num1 = atoi(n1);
     num2 = atoi(n2);
     

     //operaciones
     sum = num1+num2;
     res = num1-num2;
     mul = num1*num2;
     div = num1/num2;
     
     printf("\n %i + %i = %d \n",num1,num2,sum);
     printf("\n %i - %i = %d \n",num1,num2,res);
     printf("\n %i * %i = %d \n",num1,num2,mul);
     printf("\n %i / %i = %d \n",num1,num2,div);
     
     }
     
     else{
         
         close(fd[0]); // Cierra el descriptor de lectura
	 
 	srand((unsigned)time(&t));
	 int numero1=rand()%50;
	 int numero2=rand()%50;
	 char escribe [5];
	 /*printf("\nPadre dice num1 = %i",numero1);
	 printf("\nPadre dice num2 = %i",numero2);*/

	 sprintf(escribe,"%d %d",numero1,numero2);
	 write(fd[1],escribe,strlen(escribe));
	 
	 wait(NULL);
         }
         
         
         
         
         
     }
