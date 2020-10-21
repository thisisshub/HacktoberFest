#include <stdio.h>
#include <stdlib.h>

/* Structure of a node */
struct node {
    int data;          // Data 
    struct node *next; // Address 
}*head;


void createList(int n);
void add_after(int pos, int data);
void displayList();


int main()
{
	char ch;
    int n, data, pos;

    /*
     * Create a singly linked list of n nodes
     */
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);

    printf("\nData in the list \n");
    displayList();

    /*
     * Insert data at the beginning of the singly linked list
     */
    printf("\nEnter data to insert in the desired position of the list: ");
    scanf("%d", &data);
    printf("\nEnter desired position in the list, where you want to insert a node: ");
    scanf("%d",&pos);
    add_after(data,pos);

    printf("\nData in the list \n");
    displayList();
    
    printf("\n Do you want to perform another operation(Y/N):");
    	scanf("%c",&ch);
    	
    	if(ch == 'y' | ch == 'Y')
    	displayList();
    	else 
    	printf("\n Error");

    return 0;
}


/*
 * Create a list of n nodes
 */
void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    /*
     * If unable to allocate memory for head node
     */
    if(head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        /*
         * Input data of node from the user
         */
        printf("Enter the data of node 1: ");
        scanf("%d", &data);

        head->data = data; // Link data field with data
        head->next = NULL; // Link address field to NULL

        temp = head;

        /*
         * Create n nodes and adds to linked list
         */
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            /* If memory is not allocated for newNode */
            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);

                newNode->data = data; // Link data field of newNode with data
                newNode->next = NULL; // Link address field of newNode with NULL

                temp->next = newNode; // Link previous node i.e. temp to the newNode
                
                temp = temp->next; 
            }
        }

        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}//Add a new node
void add_after(int num,int pos)
{
	struct node *temp,*nw;
	temp=head;
	int i;
	for(i=2;i<pos;i++)
	{
		temp = temp->next;
		if(temp==NULL)
		{
			printf("\n The list has less than %d elements",pos);
			return;
		}
		
   }
		
	nw = (struct node *)malloc(sizeof(struct node));
	nw->data=num;
	nw->next = temp->next;
	temp->next=nw;
		
	printf("DATA INSERTED SUCCESSFULLY\n");
	}
	




void displayList()
{
    struct node *temp;

    /*
     * If the list is empty i.e. head = NULL
     */
    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("Data = %d\n", temp->data); // Print data of current node
            temp = temp->next;                 // Move to next node
        }
    }
}  

