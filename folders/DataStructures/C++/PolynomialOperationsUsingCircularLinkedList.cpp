#include<stdio.h>			//Main Header Function
#include<stdlib.h>

struct node					//Structure Node Created
{
             int coef;			//Variable Declaration
             int exp;
             struct node *link;
};
typedef struct node *node_op;	//pointer to node

node_op get()					//Get Node Operation Intialized
{
            node_op n;				//Node Declaration
            n = (node_op) malloc(sizeof(struct node));		//sizeof() code
            return n;			// return size value 
}

node_op join(int coef, int exp, node_op head)		//Join Node Operation Intilaized
{
            node_op n1,temp;			//Node Declaration
            temp = get();
            temp->coef = coef;			//Condition
            temp->exp = exp;
            n1 = head->link;
            while(n1->link != head)			//while loop
            {
                        n1 = n1->link;
            }
            n1->link = temp;
            temp->link = head;
            return head;   			//reuturn value
}

node_op  in_poly(node_op head)			//Accept Polynomial Operation Intialized
{
            int coef, exp,j=1;			//Node Declaration
            printf("\nEnter The Polynomial Values,to exit type -1");
            while(1)									//while loop 
            {
                        printf("\n\nEnter the %d term:\n",j++);
                        printf("\n\tCo-eficient Value= ");
                        scanf("%d", &coef);
                        if(coef == -1)							//if statement
                            break;								//break if loop
                        printf("\tPower^x= ");
                        scanf("%d", &exp);
                        head = join(coef, exp, head);
            }
              return head;					//return value
}

node_op addition(node_op value1, node_op value2, node_op value3)   //Polynomial Addition Operation Intialized
{
            node_op x,y;					//Node Declaration
            int coef;						
            x = value1->link;
            y = value2->link;
            while(x!=value1 && y!=value2)			//while loop
            {
                        if(x->exp==y->exp)			//if else statement
                        {
                                    coef = x->coef + y->coef;
                                    if(coef != 0)					//inner if loop
                                                value3 = join(coef, x->exp, value3);
                                    x=x->link;
                                    y=y->link;
                        }
                        else if(x->exp > y->exp)
                        {
                                     value3 = join(x->coef, x->exp, value3);
                                    x=x->link;
                        }
                        else
                        {
                                    value3 = join(y->coef, y->exp, value3);
                                    y=y->link;
                        }
            }
            while(x!=value1)				//while loop intialized
            {
                        value3 = join(x->coef, x->exp, value3);
                        x=x->link;
            }
            while(y != value2)				//while loop intialized
            {	
                        value3 = join(y->coef, y->exp, value3);
                        y=y->link;
            }
            return value3;				//return value
}

node_op multiply(node_op value1, node_op value2, node_op value3)		//Polynomial Multiplication Operation Intialized
{
            node_op x, y;									//Node Declaration
            if(value1->link == value1 || value2->link == value2)		//if statement
            {
                        printf("\nMultiplication Result is Zero Polynomial");
            			
            }
            x = value1->link;
            while(x != value1)				//while loop
            {
                        y = value2->link;
                        while(y!=value2)			//inner while loop
                        {
                                    value3 =join(x->coef*y->coef, x->exp+y->exp, value3);
                                   y=y->link;
                        }
                        x=x->link;
            }
            return value3;				//return value
}

void display(node_op head)			//Polynomial Display Operation Intialized
{
            node_op temp;				//Node Declaration
            if(head->link == head)		//if statement
            {
                         printf("\nPolynomial doesn't exist");
                         return;
            }
            temp = head->link;
            while(temp != head)			//whlie loop
            {
                         printf("%dx^%d",temp->coef, temp->exp);
                         temp = temp->link;
                         if(temp != head)
                                    printf(" + ");
            }
}

int main()							//Main Function
{
            node_op value1, value2, value3;		
            int ch;									//Variable Declaration
            value1 = get();
            value2 = get();
            value3 = get();
            value1->link=value1;
            value2->link=value2;
            value3->link=value3;
            printf("<-----Disease Information System using Polynomial Operation in Circular Linked List----->\n");
			do																	//do while statement
			{
            printf("\nFor Polynomial 1: \n");
            value1 = in_poly(value1);
            printf("\nFor Polynomial 2 \n");
            value2 = in_poly(value2);
            printf("\nEnter Polynomial Operation Choice:-\n1.Addition\n2.Multiplication\n3.Exit\n");
            scanf("%d",&ch);
            if(ch==1)											//if Statement
            	value3 = addition(value1, value2, value3);
            if(ch==2)											//if Statement
			    value3=multiply(value1, value2, value3);	
            printf("\nPolynomial 1:\t");
            display(value1);
            printf("\nPolynomial 2:\t");
            display(value2);
            printf("\nPolynomial Result:\t");
            display(value3);
            }while(ch!=3);									//while condition
return 0;
}
