#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>   
#include<stdio.h>
#include<unistd.h>

#include<string.h>
char *count;
unsigned char buff[64]="ashutosh\n";

int main()
{
    int shmd;
    int num;
    
    shmd=shm_open("/usr/share/dictionary",O_RDWR | O_CREAT,S_IRWXU);
    ftruncate(shmd,sizeof(char));

    count=(char*)mmap(NULL,sizeof(char),PROT_READ | PROT_WRITE,MAP_SHARED,shmd,0);

   
   

      strcpy(count,buff);

    return 0;
}
