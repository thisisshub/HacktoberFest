#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
char name[10],city[20];
void start()
{
    printf("*********************************************************************\n");
	printf("*                                                                   *\n");
	printf("*                  * WELCOME TO THE KBC GAME *                      *\n");
	printf("*                 -------------------------------                   *\n");
	printf("*                                By                                 *\n");
	printf("*                                                                   *\n");
	printf("*                         The Innovative Beast                      *\n");
	printf("*                                                                   *\n");
	printf("*********************************************************************\n");
};
void intro(char name[],char city[])
{
    printf("\nToday we have a NEW PLAYER,here with us whose name is %s.\n He belongs to the place called %s.\n",name,city);
};
int main()
{   
    int j=1,i=0,p,sav=0,m=0;
    char ans[5];
     int l,k, n,r[10];
 
 srand(time(NULL));
  for (l = 0; l <=9; l++)
  {
    n = rand() % 10;
    for(k = 0;k<=l-1;k++)
    {
        if(n==r[k])
        break;
    }
    if(l==k)
    r[l]=n;
    else
    l--;
  }
    char a[10][100]={
        "who is the railway minister of india?",
        "how many jyotirlings are there in india",
        "indian independence year",
        "national drink of india",
        "indian state with most GDP ",
        "In which of the place the Kumbha Mela is held every twelve years?",
        "how old is the taj mahal",
        "what is the duration of emergency in india",
        "under operation Blue star which holy place was seiged by the army",
        "when is international yoga day observed"

    };
    char b[10][100]={
        " a. mamta bannerje b.piush goyal  c.suresh prabhu d.venkaiya naidu",
        " a. 16 b.12 c.10 d.14",
        " a. 1947 b. 1927 c.1937 d.1917",
        " a. coffe b. nimbu paani c.tea d.sugarcane juice",
        " a. punjab b. west bengal c.karnataka d.maharashtra",
        " A. Purl B Prayag.C. Rameshwaram D. Chittakoot",
        "a. 305 b. 300 c. 388 d 288",
        "a.1975-77 b.1976-79 c.1974-77 d.1970-75",
        "a.akshardham temple b.tirupati balaji c.sidhivinayak temple d.golden temple",
        "a.21 july b.23 june c.21 june d.22 july "
        };
     char c[10][2]={
        "b",
        "b",
        "a",
        "c",
        "d",
        "b",
        "c",
        "a",
        "d",
        "c"
    };
    printf("\nEnter your name : ");
    gets(name);
    printf("\nEnter your city : ");
    gets(city);
    start();
    intro(name,city);
   do
   {    
        printf("\n%s",a[r[i]]);
        printf("\n%s\n",b[r[i]]);
        scanf("%s",ans);
        if (strcmp(ans,c[r[i]])==0)
        {system("clear");
            m=(1000*j);
         printf("\n you won Rs. %d\n",1000*j);
         j++;
         
         if(i%3==0)
         {
            printf("u have cleared a level...ur progress has been saved\n");
            sav = m;
         }
         
         i++;
        }
         else
         {
            printf("\n Unfortunately you lost and you have to go home with Rs.%d\ntry nex time",sav);
            sav=0;
            exit(1);
            
         }
        
    }while(i<10);
    printf("u have won rs%d\n",sav);
    printf("thank you for playing with us.....\n");
    return 0;
}





