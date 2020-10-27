//SasmithaAthige

#ifndef _GNU_SOURCE
#define _GNU_SOURCE 1
#endif

#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

//Basic Functions
int downloadArg();
int uploadArg();
int deleteCase();
void showAll();
int updateArg();
void editArg();

//Functions to access Shared Memory
char* getSharedMemory(int k);
int addToSharedMemory(char caseID[], int id);
int validateSharedMemory(int k);

//Functions to modify the data
char *getTitle(char * fBlock);
char *getContent(char * fBlock);
char *combineStrings(const char *oldString, const char c);



// 1K shared memory segment
#define SHMSIZE 1024

int itmKey = 6969;
int shareKey = 8800;

int main(int argc,char *argv[])
{
 	if (validateSharedMemory(itmKey)==0)
	{
		addToSharedMemory("0",itmKey);
	}

    if(argc==1)
        printf("No arguments passed\n");
    if(argc==2)
    {
      if (strcmp(argv[1], "view")== 0){
        showAll();
      }
      if (strcmp(argv[1], "upload")== 0){
      uploadArg();
      }
	  if (strcmp(argv[1], "download")== 0){
      downloadArg();
      }
	  if (strcmp(argv[1], "delete")== 0){
       deleteCase();
     }
		if (strcmp(argv[1], "update")== 0){
      updateArg();
      }
      if (strcmp(argv[1], "edit")== 0){
        editArg();
        }
    }
pthread_mutex_destroy(&lock);
    return 0;

}

void editArg(){


    char caseID[10];
    FILE *filep1;
  	char fileName[50];

    printf("Enter case ID: ");  //Asking the user to input case ID
    scanf("%s", &caseID);

    //Getting the content from the shared Memory related to caseID provided
  	char *dataBlock = getSharedMemory(atoi(caseID));

    // Passing it through the seperation function to separate the title and it's contents
  	char *title = getTitle(dataBlock);
  	char *content = getContent(dataBlock);

  	chdir("downloads/"); //cd into the downloads folder

  	snprintf(fileName, sizeof(fileName), "%s", title); //Getting the case study name as fileName
    strcat(fileName,".txt"); // Adding the extension

  	filep1 = fopen(fileName, "w"); //Opening the file to write
    fprintf(filep1, "%s", content);
    fflush(filep1);
    fclose(filep1);

    printf("File Downloaded Successfully and Ready to Edit\n");
    printf("To Update The Content, Use The Update Function\n");

    char *args[] = {"vi",fileName,NULL};
    execvp("vi",args);

		printf("Edited Case is stored in your downloads folder\n");
}

int updateArg(){

  	int k;
	int shmID;
	key_t key;
	char *shm;

	char fileName[30];

	char cTitle[24];
	char *title;
	char *body;
	char *data;
	char str[999];

  printf("Enter case ID to update Case: ");
  scanf("%d", &k);

  key = k;

	FILE *filePntr;

	printf("Enter path to the edited file: \n");
	scanf("%s", &fileName);

	filePntr = fopen(fileName , "r");

	 if (filePntr == NULL){
        printf("Could not open file %s",fileName);
        return 1;
    }

	printf("Enter the case study title: ");
	scanf("%s", &cTitle);

	while (fgets(str, 1000, filePntr) != NULL)

	printf("%s\n", str);

	title = combineStrings(cTitle,'*');
	body = combineStrings(str,'#');

	data = strcat(title,body);

	if ((shmID = shmget(key, SHMSIZE, 0666)) < 0)
	{
		printf("shmget failed\n");
		exit(1);
	}

	if ((shm = shmat(shmID, NULL, 0)) == (char *) -1)
	{
		printf("shmat failed\n");
		exit(1);
	}

	memcpy(shm,data,strlen(data));

}


int downloadArg()
{

  char caseID[5];
  FILE *filep1;
	char fileName[50];

  printf("Enter case ID: ");  //Asking the user to input case ID
  scanf("%s", &caseID);

  //Getting the content from the shared Memory related to caseID provided
	char *dataBlock = getSharedMemory(atoi(caseID));

  // Passing it through the seperation function to separate the title and it's contents
	char *title = getTitle(dataBlock);
	char *content = getContent(dataBlock);

	chdir("downloads/"); //cd into the downloads folder

	snprintf(fileName, sizeof(fileName), "%s", title); //Getting the case study name as fileName
  strcat(fileName,".txt"); // Adding the extension

	filep1 = fopen(fileName, "w"); //Opening the file to write
  fprintf(filep1, "%s", content);
  fflush(filep1);
  fclose(filep1);

  printf("File Downloaded Successfully\n");
  return 0;
}
int uploadArg(){

   pthread_mutex_lock(&lock);

  char fileName[50];
	FILE *filep2;
	char block[999];
	char tag[30];
	char *title;
	char *content;
	char *data;

  int iKey;
  int count; //Important Variables


  printf("Enter Path to Case Study to Upload: ");
  scanf("%s", &fileName);

  iKey = shareKey; //Passing the initializer key to temp variable
  count = atoi(getSharedMemory(itmKey)); //Getting the current count of existing records
  iKey += count; //Adding the number of records to the initial key to get a new key value
  count++; //Increasing the count by 1

	filep2 = fopen(fileName , "r");

	 if (filep2 == NULL){
        printf("Could Not Open File %s",fileName);
        return 1;
    }

//Asking the user to enter a name for the case study to be saved in the shared memory
	printf("Enter The Name for Case Study : ");
	scanf("%s", &tag);

	while (fgets(block, 1000, filep2) != NULL)

	printf("%s\n", block);

//Combining the Name of the case study and it's content together
//A unique delimeter is used to seperate the two later
	title = combineStrings(tag,'*');
  content = combineStrings(block,'#');
	data = strcat(title,content);

//Adding data to the shared memory
	addToSharedMemory(data,iKey);

//Updating the count of records in shared memory
	char string[]="";
  sprintf(string,"%d",count);
  addToSharedMemory(string,itmKey);
//Updating Finished

  printf("Case ID is - %i\n",iKey);
  printf("Please Use The Case ID to Access The Files\n");

	fclose(filep2);

	return 0;
  pthread_mutex_unlock(&lock);
  pthread_exit(0);
}

char *getTitle(char * fBlock)
{
	 char *block1;
   char delim[] = "*"; //Delimiter used to seperate the name of the case study
	 char temp[50]; //Array to temporarily store the data

	strcpy(temp, fBlock);  //  Copy the full block to array
	block1  = strtok(temp, delim); // Seperate by delimiter and passs to block1

  return block1;
}
char *getContent(char * fBlock)
{
	char temp2[999]; // Array to temporarily store the full block from Shared Memory
  char delim1[] = "*";  // Delimiter to seperate the name of case study
	char delim2[] = "#"; // Delimiter to seperate the content

	strcpy(temp2, fBlock);
	char *block2 = strtok(temp2, delim1);

	block2 = strtok(NULL,delim2);

	return block2;
}
char *combineStrings(const char *oldString, const char c)
{

    int result;
    char *newString;

    //Combines the special character used as the delimiter with the string passed into it
    result = asprintf(&newString, "%s%c", oldString, c);

    if (result == -1){
      newString = NULL;
    }
    return newString;
}
int addToSharedMemory(char data[], int id)
{

	int shmID;
	key_t key;
	char *shm;
	key = id;

	if ((shmID = shmget(key, SHMSIZE, IPC_CREAT | 0666)) < 0) //Creating the shared Memory block
	{
		printf("shmget failed\n");
		exit(1);
	}

	if ((shm = shmat(shmID, NULL, 0)) == (char *) -1) //Attaching to shared Memory
	{
		printf("shmat failed\n");
		exit(1);
	}

	strncpy(shm, data, strlen(data)); 

	return 1;  pthread_mutex_unlock(&lock);
  pthread_exit(0);


}
char* getSharedMemory(int k)
{
	int shmID;
	key_t key;
	char *shm;
	key = k;

	if ((shmID = shmget(key, SHMSIZE, 0666)) < 0) //Checking if the segment exists or not?
	{
		printf("shmget failed\n");
		exit(1);
	}

	if ((shm = shmat(shmID, NULL, 0)) == (char *) -1) //Checking whether you can attach to it or not?
	{
		printf("shmat failed\n");
		exit(1);
	}

	return shm; //return the segment
}
int validateSharedMemory(int k)
{
	int shmID;
	key_t key;
	key = k;

	if ((shmID = shmget(key, SHMSIZE, 0666)) < 0) //Checking if the segment exists
	{
		return 0;
	}

	return 1;
}
int deleteCase()
{

  pthread_mutex_lock(&lock);
  char caseID[4];

  printf("Enter Case ID to Delete: ");
  scanf("%s", &caseID);

	int shmID;
	key_t key;
	char *shm;
	key = atoi(caseID);

	if (validateSharedMemory(key)==0) {
		printf("Invalid Case ID\n");
		return 0;
	}

	if ((shmID = shmget(key, SHMSIZE, 0666)) < 0)
	{
		printf("shmget failed\n");
		exit(1);
	}

	shmctl(shmID, IPC_RMID, NULL);

  printf("Case Deleted Successfully\n");

	return 1;
   pthread_mutex_unlock(&lock);
    pthread_exit(0);

}
void showAll()
{
	int itmCount = atoi(getSharedMemory(itmKey));

  printf("Case ID  | Name of the Study\n");

	for(int i=shareKey;i<(shareKey+itmCount);i++)
	{
		if (validateSharedMemory(i)==0){
      continue;
    }

	char *data = getSharedMemory(i);
	char *tag = getTitle(data);

	printf("%i        | %s\n", i, tag);
	}
}

