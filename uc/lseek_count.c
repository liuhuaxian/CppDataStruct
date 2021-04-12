/*下面这个代码用lseek的偏移来读取文件大小：*/
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<fcntl.h>
#include <stdlib.h>
int main(int argc,char* argv[]){
        int fd = open(argv[1],O_RDWR);
        if(fd == -1){
                perror("open error\n");
                exit(1);
        }

        int length = lseek(fd,0,SEEK_END);
        printf("file size:%d\n",length);

        close(fd);
        return 0;
}
