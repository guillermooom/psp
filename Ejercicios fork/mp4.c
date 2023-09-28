//programa que genera una salida en orden inverso del abecedario
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

void main(){
	printf("CCC \n");
	
	if(fork()!=0){
	wait(0);
		printf("AAA \n");
		
		
	}else{
		printf("BBB \n");
		
  	}
 	exit(0);
}
