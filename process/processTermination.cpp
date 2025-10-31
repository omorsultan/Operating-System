#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){

    pid_t pid = fork();

    if(pid==0){
        printf("Child : My pid is %d\n",getpid());
        sleep(5);
        
        printf("Child : I am exiting now \n");
        
        exit(42);
    }
    
    else if(pid > 0) {
        int status;
        
        wait(&status);
        
        printf("Parent: Child exited with status %d\n",WEXITSTATUS(status));
    }

 }
