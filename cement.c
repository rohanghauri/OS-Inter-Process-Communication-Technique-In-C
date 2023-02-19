/**Claymaker process and Brick process ID's are shared via SHM
   Before sending signals both retrive each others ID's 
   Then they can send signals to each other**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>




int main(){
    const int SIZE = 4096;// Declaring var named SIZE 
    const char *name = "OS"; // Declaring ptr name that has the memory addr of string "OS"
    const char *message_0 = "Hello"; // Declaring ptr message_0 that has the memory addr of string "OS"
    const char *message_1 = "World!";//Declaring ptr message_1 that has the memory addr of string "OS"
    int fd; // Declaring int named fd
    char *ptr;//Declaring a pointer
    fd = shm_open(name,O_CREAT|O_RDWR,0666); // opens a shared memory object,O_RDWR gives permisson of read and write
    ftruncate(fd,SIZE); // fixes the file length to 4096
    ptr = (char*)mmap(0,SIZE,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);// returns a pointer to the shared memory address alowwing it to be used by other programs
    sprintf(ptr,"%s",message_0);//Writes the message into given memory address space
    ptr += strlen(message_0); //adds length of message0 into the pointer, so that it stores the next msg after it
    sprintf(ptr,"%s",message_1);//Writes the message into given memory address space
    ptr += strlen(message_1);////adds length of message1 into the pointer, so that it stores the next msg after it
    //getchar();//takes input from the command-line
    return 0;






}
