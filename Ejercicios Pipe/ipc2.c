#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <time.h> 
#include <string.h>

void main(){

     int fd[2],total=0; 
     char buffer[4];
     pid_t pid;
     char cad[2];

     // Creamos el pipe
     pipe(fd); 
     
     //Se crea un proceso hijo
     pid = fork();

     if (pid==0){
     
     close(fd[1]); // Cierra el descriptor de lectura
     read(fd[0], buffer,4);
     
     //cuando printeo tiene que ser c ya que si no lo lee en codigo ascii
     for(int i=0;i<3;i++){
     	printf("Numero a sumar: %c\n", buffer[i]);
     	total+=(buffer[i]-'0');
     	
     }
     
     printf("Simbolo: %c\n",buffer[3]);
     printf("Total: %d\n",total);
     
 
     
     }
     
     else{
         
         close(fd[0]); // Cierra el descriptor de lectura
         for(int i=0;i<3;i++){
         	sprintf(cad,"%d",i+1);
         	write(fd[1],cad,1);

         	
         }
         
         write(fd[1],"+",1);
         wait(NULL);
         
         
     }
     
        
}
