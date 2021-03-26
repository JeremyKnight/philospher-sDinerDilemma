#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int aquire(int i);
void *philoState(int n);

//chopsticks:
//  0 = not available
//  1 = available
int *chopsticks[5] = {1,1,1,1,1};

int main(char *argv[]) {

    for(int i=0; i<5; i++) {
        pthread_t tid;
        pthread_attr_t attr;
        
        pthread_attr_init(&attr);
        //creates the thread
        pthread_create(&tid, &attr, philoState, &i);
    }
}

void *philoState(int n) {
    //int pid =allocate_pid();
    
    //random seed for everything random
    time_t t;
    srand((unsigned) time(&t));
    
    int numBites=rand()%30;
    printf("Pid: %d /n", n);
    while(numBites!=0) {
        double sleepTIme = rand() % 5;
        sleep(sleepTIme); //thinking
        
        while(aquire(n)==1) {} //
        //1: think
            //2: see if chopsticks are available
            //3: eat:
            //4: realease: 
        
        numBites--;
    }

    pthread_exit(0);
}

int aquire(int i) {
    //mutex.lock goes here
    if(i==4) {
        //checks the placement at 4 and 0
        
    } else if(i<4) {
        //checks the placement at all other numbers
    } else {
        printf("something went wrong");
    }
    //mutex.unlock goes here
    
    
    return 1;
}









