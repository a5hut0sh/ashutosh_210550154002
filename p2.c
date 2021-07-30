#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>   
#include<stdio.h>
#include<unistd.h>

#include <fcntl.h>    
#include <sys/stat.h> 
#include <semaphore.h>
#include<string.h>

char *count;
unsigned char buff[64];
ssize_t readq;

int main()
{
    int shmd;
    
    shmd=shm_open("/usr/share/dictionary",O_RDWR | O_CREAT,S_IRWXU);
    ftruncate(shmd,sizeof(buff));

    count=(char*)mmap(NULL,sizeof(int),PROT_READ | PROT_WRITE,MAP_SHARED,shmd,0);
    

        printf("string : %s\n",count);
       // readq=read(shmd,buff,sizeof(buff));
        strcpy(buff,count);
    

        printf("length of msg : %ld\n",strlen(buff));

              
    return 0;
}
