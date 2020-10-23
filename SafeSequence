#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {

        int fd1, fd2;    //file descriptors
        char c;        //holds read char
        int offset;     //current offset

        fd1 = open("foo.txt", O_RDONLY);      //open file to read
        if (fd1 < 0) {
                printf("%s", "Open error");
        }

        fd2 = open("foorev.txt", O_WRONLY | O_CREAT, 0670);   //open file to write with rwxrw----
        if(fd2 < 0) {
                printf("%s", "Open error");
        }

        offset = lseek(fd1, 0, SEEK_END);    //go to the end of the file

        while (offset > 0) {  //while it is not the beginning of the file        
                read(fd1, &c, 1);  //read a char
                write(fd2, &c, 1);  //write the char
                lseek(fd1, -2, SEEK_CUR);   //go back 2 spots to the char before the one just read
                offset--;     //track the current offset
        }

        close(fd1);  //close the files
        close(fd2);

        return 0;

}
