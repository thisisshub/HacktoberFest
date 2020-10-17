#include<stdio.h>
#include<unistd.h>

int main() {
   int pipefds[2];
   int returnstatus;
   int pid;
  char writer[3][40]={"operating", "system"};
   char reader[40];
   
   returnstatus = pipe(pipefds);
   if (returnstatus == -1) {
      printf("Unable to create pipe\n");
      return 1;
   }
   pid = fork();
 
   if (pid == 0) {
      read(pipefds[0], reader, sizeof(reader));
      printf("child reading message one - %s\n", reader);
      read(pipefds[0],reader, sizeof(reader));
      printf("child reading message two - %s\n", reader);
   } else { 
      printf("Parent writing message -  %s\n", writer[0]);
      write(pipefds[1], writer[0], sizeof(writer[0]));
      printf(" Parent writing message - %s\n", writer[1]);
      write(pipefds[1], writer[1], sizeof(writer[1]));
   }
   return 0;
}