//SasmithaAthige

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; // Initializing the mutex

struct inputGlobal{ // The global structure
  int arr[128];
  int a ;
  float answer;
  };



void* calculateAvg(void* args); //To calculate the average
void writeToFile(float r);

int main(void)
{



//Counting the number of line to create an equal amount of threads
FILE *fileptr;
 int lineCount = 0;
 char file[50], chr;

 printf("Enter file name: ");
 scanf("%s", file);
 fileptr = fopen("dataset.txt", "r");

 chr = getc(fileptr);
 while (chr != EOF)
 {
    
     if (chr == '\n')
     {
         lineCount = lineCount + 1;
     }
     
     chr = getc(fileptr);
 }
 fclose(fileptr); //close file
 printf("There are %d lines in %s  in a file\n", lineCount, file);

//End of the section


FILE *in = fopen("dataset.txt", "r"); //reading the file
if (in == NULL){
  printf("Unable to open dataset.txt\n"); //Error handling
  exit(0);
}

if (in != NULL) {
    char line[BUFSIZ]; // declaring variables
    int h,i,j=0;

    pthread_t  threadID[lineCount+1];

    struct inputGlobal buffer[lineCount+1];

while (fgets(line, sizeof line, in) != NULL) {
              int field;
              int temp = 0;
              char *begin = line;
              int h=0;
              j++;


              while (sscanf(begin, "%d%n", &field, &temp) == 1) {
                      buffer[j].arr[h] = field;
                      begin += temp;
                      h++;
                    }

                    buffer[j].a = h;

// Creating threads
 pthread_create(&threadID[j], NULL, calculateAvg, &buffer[j]);
}

// joining threads
for(i=0; i<j; i++){
  pthread_join(threadID[i], NULL);
}

fclose(in);
pthread_mutex_destroy(&lock);

return 0;
}
}


// Function Declaration

void writeToFile(float r){

  FILE *out = fopen("average.txt","a");

    fprintf(out, "%.3f\n", r);
    fclose(out);

}


void* calculateAvg(void* args)
{
    pthread_mutex_lock(&lock);
    struct inputGlobal *buffer1_ptr = (struct inputGlobal*) args;

    int sum = 0;   // declaring variables
    float avg = 0;
    int x;
    int y = 0;
    y = (buffer1_ptr->a);

    for(x=0; x < y; x++){
      sum = sum + (buffer1_ptr->arr[x]);
    }

    printf("Sum is %d\n", sum);

    avg = sum / y;

    printf("Average is %f\n", avg);

    writeToFile(avg); //Passing the calculated value to print function


    pthread_mutex_unlock(&lock);
    pthread_exit(0);
}

