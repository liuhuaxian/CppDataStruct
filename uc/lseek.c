/*lseek示例，写一个句子到空白文件，完事调整光标位置，读取刚才写那个文件。
 * 这个示例中，如果不调整光标位置，是读取不到内容的，因为读写指针在内容的末尾
* */
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdio.h>
int main(){
        int fd,n;
        char msg[] = "this is a test for lseek hahahhahayll\n";
        char ch;

        fd = open("lseek.txt",O_RDWR|O_CREAT,0644);
        if(fd < 0){
                perror("open lseek.txt error\n");
                exit(1);
        }
        write(fd,msg,strlen(msg));

        lseek(fd,0,SEEK_SET);

        while(n=read(fd,&ch,1)){
                if(n < 0){
                        perror("open lseek.txt error\n");
                        exit(1);
                }
                write(STDOUT_FILENO,&ch,n);
        }

        close(fd);
        return 0;
}
