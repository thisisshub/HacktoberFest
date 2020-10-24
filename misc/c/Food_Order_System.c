#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct delivery_det {
    char contact_no[20];
    char add[150];
};

struct customer {
    char name[20];
    char phone_no[10];
    struct delivery_det d; 
    char email[50];
};



struct customer delivery_ip(struct customer c)
{
    printf("-----------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\tDELIVERY INFORMATION\n");
    printf("-----------------------------------------------------------------------------------------\n");
    printf("Enter Contact number: ");
    fgets(c.d.contact_no,20,stdin);
    printf("Enter Address: ");
    scanf("%[^\n]%*c",c.d.add);
    printf("\nDetails recorded successfully!\n");
    return c;
}

void r1_menu()
{
    int ch_cat,qty;
    int ch_item,amt=0,ans;
    char bevarage[6][20]={"Elaichi Tea","Cold Coffee","Hot Coffee","Lemonande","Iced Tea","Hot choco"};
    int bev_pri[6]={50,80,50,90,100,120};
    char snacks[6][20]={"Aloo Tikki","Aloo Samosa","Vada Pav","Chicken S/w","Egg puff","Cheese S/w"};
    int snacks_pri[6]={100,20,40,100,120,80};
    char dessert[6][20]={"Oat Cookie","Cookie    ","Apple Tart","Pastry   ","Choco pops","Muffin   "};
    int dessert_pri[6]={30,40,60,50,30,40};
    printf("-----------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\tGRIND HOUSE MENU\n");
    printf("-----------------------------------------------------------------------------------------\n");
    printf("SNACKS\n-------------\t\t\t\t\t\t\t\tPrice(in Rs.)\n");
    for(int i=0;i<6;i++)
        printf("%d.  %s\t\t\t\t\t\t\t\t\t%d\n",i+1,snacks[i],snacks_pri[i]);
    printf("\nDESSERTS\n-------------\n");
    for(int i=0;i<6;i++)
        printf("%d.  %s\t\t\t\t\t\t\t\t\t%d\n",i+1,dessert[i],dessert_pri[i]);
    printf("\nBEVARAGES\n-------------\n");
    for(int i=0;i<6;i++)
        printf("%d.  %s\t\t\t\t\t\t\t\t\t%d\n",i+1,bevarage[i],bev_pri[i]);
    printf("\n");
    do{
    printf("Enter 1 for snacks, 2 for desserts, 3 for beverages\n");
    printf("Choose category : \n");
    scanf("%d",&ch_cat);
    switch(ch_cat)
    {
        case 1:
                printf("Enter serial no. of dish to choose: ");
                scanf("%d",&ch_item);
                printf("Enter quantity: ");
                scanf("%d",&qty);
                amt+=(snacks_pri[ch_item-1]*qty);
                break;
        case 2:
                printf("Enter serial no. of dish to choose: ");
                scanf("%d",&ch_item);
                printf("Enter quantity: ");
                scanf("%d",&qty);
                amt+=(snacks_pri[ch_item-1]*qty);
                break;
        case 3:
                printf("Enter serial no. of dish to choose: ");
                scanf("%d",&ch_item);
                printf("Enter quantity: ");
                scanf("%d",&qty);
                amt+=(snacks_pri[ch_item-1]*qty);
                break;
        default: printf("Enter valid choice ");
    }
    printf("Add another item? (1 for yes) : ");
    scanf("%d",&ans);
    }while(ans==1);
    
    printf("\nAMOUNT = %d",amt);
}

int main()
{
    struct customer c1,c;
    r1_menu();
    c1=delivery_ip(c);
    printf("Contact number: %s\n",c1.d.contact_no);
    printf("Address: %s",c1.d.add);
    return 0;
}
