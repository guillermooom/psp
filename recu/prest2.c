#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <time.h> 
#include <string.h>
#include <math.h>

void main(){

     pid_t pid2,pid3;
     int p1[2],p2[2];
     
     

     // Creamos los pipes
     pipe(p1);
    	 
     //Se crea un proceso hijo
     pid2 = fork();


     if (pid2==0){
     
    	pipe(p2);
     	pid3 = fork();
 
        if(pid3==0){
        
	//ACCIONES DEL P3

	int prestamo,amort;

        printf("Introduce importe del prestamo: ");
	scanf("%d", &prestamo);
	
	close(p2[0]);
	write(p2[1],&prestamo,sizeof(prestamo));
	
	printf("Introduce periodo amortitacion (en años): ");
	scanf("%d", &amort);
	
	close(p2[0]);
	write(p2[1],&amort,sizeof(amort));
		
		
        }else{
        
		
		wait(NULL);
        	//ACCCIONES DEL P2
        	
        	int prestamo,amort,c,n;
        	float tipo,resultado,t;
        	
        	close(p2[1]);
        	read(p2[0],&prestamo,sizeof(prestamo));
        	
        	close(p2[1]);
        	read(p2[0],&amort,sizeof(amort));
        	
        	printf("Introduce tipo de interes mensual: ");
		scanf("%e", &tipo);
		
		c=prestamo;
		n=amort*12;
		t=tipo/1200;
		
		resultado=(c*t*pow(t+1,n))/(pow((t+1),n)-1);
		
		close(p1[0]);
		write(p1[1],&resultado,sizeof(resultado));
        
        }
        
        	


     }else{
         printf("*****************************************\n");
         printf("CALCULO CUOTA PRESTAMO\n");
         printf("*****************************************\n");
	 
	 wait(NULL);
	 //ACCIONES DEL P1
	 float resultado;
	 
	 close(p1[1]);
	 read(p1[0],&resultado,sizeof(resultado));
	 
	 printf("Cuota resultante: %f\n",resultado);
	  
	 
         }
         
         
         
         
         
     }
