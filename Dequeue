/* Program of input and output restricted dequeue using array*/
# include<stdio.h>
# define MAX 5

int deque_arr[MAX];
int left = -1;
int right = -1;

main()
{
	int choice;

	printf("1.Input restricted dequeue\n");
	printf("2.Output restricted dequeue\n");
	printf("Enter your choice : ");
	scanf("%d",&choice);

	switch(choice)
	{
	 case 1 :
		input_que();
		break;
	 case 2:
		output_que();
		break;
	 default:
		printf("Wrong choice\n");
	}/*End of switch*/
}/*End of main()*/

input_que()
{
	int choice;
	while(1)
	{
		printf("1.Insert at right\n");
		printf("2.Delete from left\n");
		printf("3.Delete from right\n");
		printf("4.Display\n");
		printf("5.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			insert_right();
			break;
		 case 2:
			delete_left();
			break;
		 case 3:
			delete_right();
			break;
		 case 4:
			display_queue();
			break;
		 case 5:
			exit();
		 default:
			printf("Wrong choice\n");
		}/*End of switch*/
	}/*End of while*/
}/*End of input_que() */

output_que()
{
	int choice;
	while(1)
	{
		printf("1.Insert at right\n");
		printf("2.Insert at left\n");
		printf("3.Delete from left\n");
		printf("4.Display\n");
		printf("5.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			insert_right();
			break;
		 case 2:
			insert_left();
			break;
		 case 3:
			delete_left();
			break;
		 case 4:
			display_queue();
			break;
		 case 5:
			exit();
		 default:
			printf("Wrong choice\n");
		}/*End of switch*/
	}/*End of while*/
}/*End of output_que() */

insert_right()
{
	int added_item;
	if((left == 0 && right == MAX-1) || (left == right+1))
	{
		printf("Queue Overflow\n");
		return;
	}
	if (left == -1)  /* if queue is initially empty */
	{
		left = 0;
		right = 0;
	}
	else
	if(right == MAX-1)  /*right is at last position of queue */
		right = 0;
	else
		right = right+1;
	printf("Input the element for adding in queue : ");
	scanf("%d", &added_item);
	deque_arr[right] = added_item ;
}/*End of insert_right()*/

insert_left()
{
	int added_item;
	if((left == 0 && right == MAX-1) || (left == right+1))
	{
		printf("Queue Overflow \n");
		return;
	}
	if (left == -1)/*If queue is initially empty*/
	{
		left = 0;
		right = 0;
	}
	else
	if(left== 0)
		left=MAX-1;
	else
		left=left-1;
	printf("Input the element for adding in queue : ");
	scanf("%d", &added_item);
	deque_arr[left] = added_item ;
}/*End of insert_left()*/

delete_left()
{
	if (left == -1)
	{
		printf("Queue Underflow\n");
		return ;
	}
	printf("Element deleted from queue is : %d\n",deque_arr[left]);
	if(left == right) /*Queue has only one element */
	{
		left = -1;
		right=-1;
	}
	else
		if(left == MAX-1)
			left = 0;
		else
			left = left+1;
}/*End of delete_left()*/

delete_right()
{
	if (left == -1)
	{
		printf("Queue Underflow\n");
		return ;
	}
	printf("Element deleted from queue is : %d\n",deque_arr[right]);
	if(left == right) /*queue has only one element*/
	{
		left = -1;
		right=-1;
	}
	else
		if(right == 0)
			right=MAX-1;
		else
			right=right-1;
}/*End of delete_right() */

display_queue()
{
	int front_pos = left,rear_pos = right;
	if(left == -1)
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue elements :\n");
	if( front_pos <= rear_pos )
	{
		while(front_pos <= rear_pos)
		{
			printf("%d ",deque_arr[front_pos]);
			front_pos++;
		}
	}
	else
	{
		while(front_pos <= MAX-1)
		{
			printf("%d ",deque_arr[front_pos]);
			front_pos++;
		}
		front_pos = 0;
		while(front_pos <= rear_pos)
		{
			printf("%d ",deque_arr[front_pos]);
			front_pos++;
		}
	}/*End of else */
	printf("\n");
}/*End of display_queue() */
