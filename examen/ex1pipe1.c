#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <time.h> 
#include <string.h>

void main(){

     int p1[2],p2[2],p3[2],res=1,nume,nu,n,veamos; 
     char buffer[2],buffer2[2],buffer3[2];
     pid_t pid2,pid3;
     char cad[2];

     // Creamos los pipes
    	pipe(p1);
    	pipe(p2);
    	pipe(p3);
     
     //Se crea un proceso hijo
     pid2 = fork();


     if (pid2==0){
     
     close(p1[1]);
     close(p2[0]);
     close(p3[1]);
    

	    	
		
		
	     	
        pid3 = fork();
        
        if(pid3==0){
        
        close(p3[0]);
        
        	int cont,sum=0;
        	char escri[20];
        	close(p2[1]);
        	read(p2[0], buffer,sizeof(buffer));
		nu = atoi(buffer);
		
		if(nu%5==0){
			cont++;
			sum+=nu;
		}
		
		sprintf(escri,"%d",cont);
		write(p3[1],escri,strlen(escri));
		
		
		
        }else{
        
        	
        	char escribe2[255];

		read(p1[0], buffer2,sizeof(buffer2));
		nume = atoi(buffer2);
			  

		for(int i=0;i<nume;i++){
		     	printf("Introduzca un numero: ");
		   	scanf("%d", &n);
		   	
		
		}
        	
        	
  		sprintf(escribe2,"%d",n);
	     	write(p2[1],escribe2,strlen(escribe2));
	     	
	     	
	     	read(p3[0], buffer3,sizeof(buffer3));
		veamos = atoi(buffer3);
		
		printf("hay %d",veamos);
		
		wait(NULL);
        
        }
        
        	


     }else{
         
         close(p1[0]);
	 
 	
	 int num;
	 char escribe [2];
	 int total;
	 
	 printf("Introduzca la cantidad de numeros a procesar: ");
    	 scanf("%d", &num);

	 sprintf(escribe,"%d",num);
	 write(p1[1],escribe,strlen(escribe));

	 
	 wait(NULL);
         }
         
         
         
         
         
     }
