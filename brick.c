//BRICK
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <signal.h>
#include <time.h>

void delay_func(){
	for(int j=0;j<0XFFFFFFFFFF;j++){	
		printf(" ");
		fflush(stdout);
		sleep(1);
	}

}
void sighandler(int signum){
	printf("\nThe bricklayer starts laying bricks.\n");
	int lay = 0;
	for (int lay = 0; lay<15; lay++){
		sleep(1);//delay of 0.5 seconds
		printf("%d layed\n",lay);	
	}
	printf("The bricklayer fineshes laying bricks. \n");
	
	if (lay == 15){
		printf("The brick-layer goes into waiting due to insufficent cement.\n");
	}
	
	lay = 0;
	exit(0);

}

int main(){
	
	printf("brick's PID--%d",getpid());
	signal(SIGUSR1,sighandler);//if a signal is received it handels it via start_brick
	delay_func();//waits for a signal from cement-mixer
	
	
}
