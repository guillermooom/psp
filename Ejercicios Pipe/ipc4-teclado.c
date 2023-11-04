#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <time.h> 
#include <string.h>

void main(){

     int p1[2],p2[2],res=1,cont; 
     char buffer[2];
     pid_t pid;
     char cad[2];
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

     for(int i=0;i<cont;i++){
     	res=res*(i+1);
     }
     
     sprintf(cad,"%d",res);
     write(p2[1],cad,strlen(cad));

     }
     
     else{
         
         close(p1[0]);
         close(p2[1]);
	 
 	 srand((unsigned)time(&t));
	 int num;
	 char escribe [2],lectu[255];
	 int total;
	 
	 printf("Introduzca un numero para hacer el factorial: ");
    	 scanf("%d", &num);

	 sprintf(escribe,"%d",num);
	 write(p1[1],escribe,strlen(escribe));
	 
	 read(p2[0],lectu,sizeof(lectu));
	 total = atoi(lectu);
	 printf("\nFactorial calculado por el hijo de %i es %i \n",num,total);
	 
	 wait(NULL);
         }
         
         
         
         
         
     }
