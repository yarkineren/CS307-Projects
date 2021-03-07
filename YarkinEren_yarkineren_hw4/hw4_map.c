#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

int main()
{
    clock_t start = clock();
    
    int count=0;
    int fd= open("loremipsum.txt",O_RDWR);
    struct stat s;
    size_t size;
    int status =fstat(fd,&s);
    size= s.st_size;
    char *ptr=mmap(0,size,PROT_READ | PROT_WRITE, MAP_SHARED,fd,0);
    if(ptr==MAP_FAILED)
    {
        printf("map failed bro");
        return 1;
    }
    close(fd);
    
    for(size_t i=0;i<=size;i++)
    {
        if(ptr[i]=='a')
            count++;
    }
    printf("%d",count);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("%f",seconds);
    status =munmap(ptr, size);
    return 0;
    
    
}