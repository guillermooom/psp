#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <time.h> 
#include <string.h>

void main(){

     int fd[2],longitud; 
     char buffer[30];
     pid_t pid;
     time_t hora;
     char *fecha;
    
    //Crea la fecha y hora actual
    time(&hora);
    fecha = ctime(&hora);
    longitud = strlen(fecha)+1; //+1 para coger bien el final

     // Creamos el pipe
     pipe(fd); 
     
     //Se crea un proceso hijo
     pid = fork();

     if (pid==0){
     
     close(fd[1]); // Cierra el descriptor de lectura
     printf("Soy el proceso hijo con pid %d",getpid());
     read(fd[0], buffer,longitud);
     printf("\n%s", buffer);
     printf("\n");
     
     
     }
     
     else{
         
         close(fd[0]); // Cierra el descriptor de lectura
         write(fd[1],fecha,longitud);
         wait(NULL);
         
         
     }
     
        
}
