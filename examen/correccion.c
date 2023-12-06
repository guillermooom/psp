#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <time.h> 
#include <string.h>

void main(){

     pid_t pid2,pid3;
     int p1[2],p2[2],p3[2];
     
     

     // Creamos los pipes
     pipe(p1);
    	 
     //Se crea un proceso hijo
     pid2 = fork();


     if (pid2==0){
     
    	pipe(p2);
    	pipe(p3);
     	pid3 = fork();
 
        if(pid3==0){
        
        
        close(p2[1]);
        
        int cont=0,sum=0,cant=0,num=0;
        read(p2[0], &cant,sizeof(cant));
       
		
		for(int i=0; i<cant; i++){
			read(p2[0], &num,sizeof(num));
			if(num%5==0){
				
				sum+=num;
			}else{
				cont++;
			}
		}
		
		close(p3[0]);
		write(p3[1],&sum,sizeof(sum));
		write(p3[1],&cont,sizeof(cont));

		
		
        }else{
        
   
        	 close(p1[1]);
        	 int numeros=0,suma=0,cont=0,n;
        	 read(p1[0], &numeros,sizeof(numeros));
        	 
     		 close(p2[0]);
		
		write(p2[1],&numeros,sizeof(numeros));
		
		for(int i=0;i<numeros;i++){
		     	printf("Introduzca un numero: ");
		   	scanf("%d", &n);
		   	write(p2[1],&n,sizeof(n));
		   	
		
		}
		
		wait(NULL);
        	
        	 close(p3[1]);
        	 read(p3[0], &suma,sizeof(suma));
        	 printf("La suma de los multiplos de 5 es: %d \n",suma);
        	 read(p3[0], &cont,sizeof(cont));
        	 printf("Se han procesado no multiplos de 5: %d \n",cont);
        
        }
        
        	


     }else{
         
	 int numeros;
	 
	 printf("Introduzca la cantidad de numeros a procesar: ");
    	 scanf("%d", &numeros);

	 close(p1[0]);
	 write(p1[1],&numeros,sizeof(numeros));//lo mete en el pipe

	 
	 wait(NULL);
         }
         
         
         
         
         
     }
