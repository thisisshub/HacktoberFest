#include<iostream>
#include<malloc.h>
//#include<conio.h>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;

struct node
{
  unsigned long long int aadhar;
  char  gender,name[10], father[10], mother[10];
  int date,year,month;
  struct node *next;
  struct node *prev;
};
struct node   *head, *tail;
int leng=0;
bool isDuplicate(node *head,unsigned long long int aadhar){
	struct node *te=head;
	bool duplicateFound=false;
	while(te!=NULL){
		if ( te->aadhar==aadhar){
			duplicateFound=true;
			break;
		}
		te=te->next;
	}
	return duplicateFound;
}

void add(){
	struct node *start,*temp;
	head=NULL;
    char choice='y';
    while(choice=='y'){
    	start = (struct node *) malloc (sizeof (struct node));
    	do{
    	cout<<"Please enter 12-digit aadhaar number: "<<endl;
     	cin>>start->aadhar;
		}while(start->aadhar<=99999999999 || start->aadhar>999999999999||isDuplicate(head,start->aadhar));
		cout<<"Name ="<<endl;cin>>start->name;
		cout<<"Gender ( M / F ) = "<<endl;
		cin>>start->gender;
    	cout<<"Father`s name ="<<endl;cin>>start->father;
	    cout<<"Mother`s name ="<<endl;cin>>start->mother;
	    cout<<"Enter your Date of Birth"<<endl;
	    do{
		cout<<"Date(dd)=";cin>>start->date;
	   } while(start->date<=0||start->date>31);
	   do{
       cout<<"Month(mm)=";cin>>start->month;
	   } while(start->month<=0||start->month>12);
	   do{
       cout<<"Year(yyyy)=";cin>>start->year;
	   } while(start->year<=999||start->year>9999);
    	start->next = NULL;
        start->prev=NULL;
        if (head==NULL){
        	head=temp=start;
        	//hd=head->data;
        	leng++;
		}
		else{
			temp->next = start;
            start->prev=temp;
            temp = temp->next;
            tail=temp;
            //td=tail->data;
            tail->next=NULL;
            leng++;
		}
		cout<<"Do you want to enter more residents?(y/n) "<<endl;
		cin>>choice;

	}

}
bool compareAadhar(node *i1, node *i2)
{
    return (i1->aadhar < i2->aadhar);
}
void sort_list(node *head){
	node *arr[leng];
	node *ptr;
	ptr=head;
	for (int i=0;i<leng;i++){
		arr[i]=ptr;
		ptr=ptr->next;
	}

	sort(arr,arr+leng,compareAadhar);

    cout << "Sorted Elements : \n";
    for (int i=0; i<leng; i++) {
       cout<<i+1<<endl;
       cout << "Aadhar number : " << arr[i]->aadhar << ",          Name: " << arr[i]->name<<endl;
       cout<<"__________________________________________________________________________________________________"<<endl<<endl;
   }
}

void find(){
	unsigned long long int id;
	struct node *start,*temp;
	char choice ='y';

	while (choice=='y')
	{
		struct node *ptr;
		ptr=head;
    	int flag;
	do{
    	cout<<"Please enter 12-digit aadhaar number of the resident : "<<endl;
     	cin>>id;
		}while(id<=99999999999 || id>999999999999);
		if (head==NULL){
			cout<<"Please enter details of a resident"<<endl;
     	}

	else{

		while (ptr!=NULL)
        {
            if(ptr->aadhar == id)
            {
                cout<<"Details of Resident having aadhar number "<<id<< " are: "<<endl;
				cout << "Name =  "<<ptr->name<<endl;
				cout<<"Father`s name =  "<<ptr->father<<endl;
				cout<<"Mother`s name =  "<<ptr->mother<<endl;
				cout<<"Gender =  "<<ptr->gender<<endl;
				cout<<"Date Of Birth:"<<endl;
				cout<<"Date(dd)=	"<<ptr->date;    cout<<"		Month(mm)=	"<<ptr->month;   cout<<"		Year(yyyy)= 	"<<ptr->year<<endl;
                flag=0;
                break;
            }
            else
            {
                flag=1;
            }
            ptr = ptr -> next;
        }
        if(flag==1)
        {
            cout<<"\nItem not found\n";
        }


	}
	cout<<"Do you want to find the detalis of any other resident?(y/n)"<<endl;
	cin>>choice;
}
}
void update(){
	unsigned long long int id;
	struct node *start,*temp;
	char choice ='y';

	while (choice=='y')
	{
		struct node *ptr;
		ptr=head;
    	int flag;
	do{
    	cout<<"Please enter 12-digit aadhaar number of the resident whose details are to be updated: "<<endl;
     	cin>>id;
		}while(id<=99999999999 || id>999999999999);
		if (head==NULL){
			cout<<"Please enter details of an employee"<<endl;
     	}

	else{

		while (ptr!=NULL)
        {
            if(ptr->aadhar == id)
            {   cout<<"Name ="<<endl;cin>>ptr->name;
                cout<<"Gender ( M / F ) = "<<endl;
				cin>>ptr->gender;
		    	cout<<"Father`s name ="<<endl;cin>>ptr->father;
			    cout<<"Mother`s name ="<<endl;cin>>ptr->mother;
			    cout<<"Enter your Date of Birth"<<endl;
			    do{
				cout<<"Date(dd)=";cin>>ptr->date;
			   } while(ptr->date<=0||ptr->date>31);
			   do{
		       cout<<"Month(mm)=";cin>>ptr->month;
			   } while(ptr->month<=0||ptr->month>12);
			   do{
		       cout<<"Year(yyyy)=";cin>>ptr->year;
			   } while(ptr->year<=999||ptr->year>9999);
                flag=0;
                break;
            }
            else
            {
                flag=1;
            }
            ptr = ptr -> next;
        }
        if(flag==1)
        {
            cout<<"\nItem not found\n";
        }


	}
	cout<<"Do you want to update the detalis of any other resident?(y/n)"<<endl;
	cin>>choice;
}
}
void gen_list(){
	struct node *ptr,*st,*hd,*tp;
	hd=NULL;
	ptr=head;
	int i=1;
	string name;
	char choice ='y';
	while (choice=='y')
	{
		struct node *ptr;
		ptr=head;
    	int flag;
    	cout<<"Please enter a name to generate a list  : "<<endl;
     	cin>>name;
		if (head==NULL){
			cout<<"Please enter details of an employee"<<endl;
     	}

	else{

		while (ptr!=NULL)
        {
            if(ptr->name == name)
            {  cout<<"------------------------------------------------------------------------------------------------";
                cout<<endl<<endl<<i<<endl;
                cout<<"Details of Resident having aadhar number "<<ptr->aadhar<< " are: "<<endl;
				cout << "Name =  "<<ptr->name<<endl;
				cout<<"Father`s name =  "<<ptr->father<<endl;
				cout<<"Mother`s name =  "<<ptr->mother<<endl;
				cout<<"Gender =  "<<ptr->gender<<endl;
				cout<<"Date Of Birth:"<<endl;
				cout<<"Date(dd)=	"<<ptr->date;    cout<<"		Month(mm)=	"<<ptr->month;   cout<<"		Year(yyyy)= 	"<<ptr->year<<endl<<endl;
                flag=0;
				i++;
				st = (struct node *) malloc (sizeof (struct node));
				st->aadhar=ptr->aadhar;
				st->gender=ptr->gender;
				strcpy(st->name,ptr->name);
				strcpy(st->father,ptr->father);
				strcpy(st->mother,ptr->mother);
				st->date=ptr->date;
				st->month=ptr->month;
				st->year=ptr->year;
				if (hd==NULL){
                 hd=tp=st;
				}
				else{
					tp->next = st;
		            st->prev=tp;
		            tp = tp->next;
		            //tl=tp;
		            //tl->next=NULL;
				}
            }
	            else
	            {
	                flag=1;
	            }
	            ptr = ptr -> next;
		        }
		        if(flag==1)
		        {
		            cout<<"\nItem not found\n";
		        }


	}
	cout<<"Do you want to find the detalis of any other resident?(y/n)"<<endl;
	cin>>choice;
}
}
void insert_beg(){
	struct node *start;
	start = (struct node *) malloc (sizeof (struct node));
	do{
    	cout<<"Please enter 12-digit aadhaar number: "<<endl;
     	cin>>start->aadhar;
		}while(start->aadhar<=99999999999 || start->aadhar>999999999999||isDuplicate(head,start->aadhar));
		cout<<"Name ="<<endl;cin>>start->name;
		cout<<"Gender ( M / F ) = "<<endl;
		cin>>start->gender;
    	cout<<"Father`s name ="<<endl;cin>>start->father;
	    cout<<"Mother`s name ="<<endl;cin>>start->mother;
	    cout<<"Enter your Date of Birth"<<endl;
	    do{
		cout<<"Date(dd)=";cin>>start->date;
	   } while(start->date<=0||start->date>31);
	   do{
       cout<<"Month(mm)=";cin>>start->month;
	   } while(start->month<=0||start->month>12);
	   do{
       cout<<"Year(yyyy)=";cin>>start->year;
	   } while(start->year<=999||start->year>9999);;
	start->next = NULL;
    start->prev=NULL;
    head->prev= start;
    start->next=head;
    head= start;
   // hd=head->data;
    leng++;
}
void insert_end(){
	struct node *start;
	start = (struct node *) malloc (sizeof (struct node));
	do{
    	cout<<"Please enter 12-digit aadhaar number: "<<endl;
     	cin>>start->aadhar;
		}while(start->aadhar<=99999999999 || start->aadhar>999999999999||isDuplicate(head,start->aadhar));
		cout<<"Name ="<<endl;cin>>start->name;
		cout<<"Gender ( M / F ) = "<<endl;
		cin>>start->gender;
    	cout<<"Father`s name ="<<endl;cin>>start->father;
	    cout<<"Mother`s name ="<<endl;cin>>start->mother;
	    cout<<"Enter your Date of Birth"<<endl;
	    do{
		cout<<"Date(dd)=";cin>>start->date;
	   } while(start->date<=0||start->date>31);
	   do{
       cout<<"Month(mm)=";cin>>start->month;
	   } while(start->month<=0||start->month>12);
	   do{
       cout<<"Year(yyyy)=";cin>>start->year;
	   } while(start->year<=999||start->year>9999);
	start->next = NULL;
    start->prev=NULL;
    tail->next= start;
    start->prev=tail;
    tail= start;
    tail->next=NULL;
	//td=tail->data;
    leng++;
}
void insert_before(){
	struct node *start,*temp;
	unsigned long long int ele;
	do{
		cout<<"Enter the element before which a new node is to be inserted:"<<endl;
		cin>>ele;
	}while(ele<=99999999999|| ele>999999999999);
	start = (struct node *) malloc (sizeof (struct node));
        do{
    	cout<<"Please enter 12-digit aadhaar number: "<<endl;
     	cin>>start->aadhar;
		}while(start->aadhar<=99999999999 || start->aadhar>999999999999||isDuplicate(head,start->aadhar));
		cout<<"Name ="<<endl;cin>>start->name;
		cout<<"Gender ( M / F ) = "<<endl;
		cin>>start->gender;
    	cout<<"Father`s name ="<<endl;cin>>start->father;
	    cout<<"Mother`s name ="<<endl;cin>>start->mother;
	    cout<<"Enter your Date of Birth"<<endl;
	    do{
		cout<<"Date(dd)=";cin>>start->date;
	   } while(start->date<=0||start->date>31);
	   do{
       cout<<"Month(mm)=";cin>>start->month;
	   } while(start->month<=0||start->month>12);
	   do{
       cout<<"Year(yyyy)=";cin>>start->year;
	   } while(start->year<=999||start->year>9999);
	temp=head;
	if (ele==head->aadhar)
	{
		start->next = NULL;
        start->prev=NULL;
        head->prev= start;
        start->next=head;
        head= start;
        leng++;
	}
	else {
		while(temp!=NULL && ele!=temp->aadhar)
		{
			temp=temp->next;
		}
		if (temp==NULL){
			cout<<"Node not Found"<<endl;
			free(start);
			exit;
		}

		start->next=temp;
		start->prev=temp->prev;
		temp->prev=start;
		start->prev->next=start;
		leng++;
	}

}
void insert_after(){
	struct node *temp,*start;
	unsigned long long int ele;
	do{
		cout<<"Enter the aadhar number after which a new record is to be inserted:"<<endl;
		cin>>ele;
	}while(ele<=99999999999|| ele>999999999999);
	start = (struct node *) malloc (sizeof (struct node));
    do{
    	cout<<"Please enter 12-digit aadhaar number: "<<endl;
     	cin>>start->aadhar;
		}while(start->aadhar<=99999999999 || start->aadhar>999999999999||isDuplicate(head,start->aadhar));
		cout<<"Name ="<<endl;cin>>start->name;
		cout<<"Gender ( M / F ) = "<<endl;
		cin>>start->gender;
    	cout<<"Father`s name ="<<endl;cin>>start->father;
	    cout<<"Mother`s name ="<<endl;cin>>start->mother;
	    cout<<"Enter your Date of Birth"<<endl;
	    do{
		cout<<"Date(dd)=";cin>>start->date;
	   } while(start->date<=0||start->date>31);
	   do{
       cout<<"Month(mm)=";cin>>start->month;
	   } while(start->month<=0||start->month>12);
	   do{
       cout<<"Year(yyyy)=";cin>>start->year;
	   } while(start->year<=999||start->year>9999);
	temp=head;
	if (ele==tail->aadhar)
	{
		start->next = NULL;
        start->prev=NULL;
        tail->next= start;
        start->prev=tail;
        tail= start;
        leng++;
	}
	else {
		while(temp!=NULL && ele!=temp->aadhar)
		{
			temp=temp->next;
		}
		if (temp==NULL){
			cout<<"Node not Found"<<endl;
		}
		start->prev=temp;
		start->next=temp->next;
		temp->next=start;
		start->next->prev=start;
		leng++;
	}

}
void delete_beg(){
	struct node *t;
	if (head==NULL){
		cout<<"List is Empty"<<endl;
	}
	else{
		t=head;
		head=head->next;
		head->prev=NULL;
		leng--;
		free(t);
	}
}
void delete_end(){
	struct node *t;
	if (tail==NULL){
		cout<<"List is Empty"<<endl;
	}
	else{
		t=tail;
	    tail->prev->next=NULL;
	    tail=tail->prev;
	    leng--;
		free(t);
	}
}

void del_pos(){
	unsigned long long int ele;
	struct node *t;
	struct node *start;
	t=head;
	do{
		cout<<"Enter the record's aadhar number you wish to delete"<<endl;
	    cin>>ele;
	}while(start->aadhar>99999999999 || start->aadhar<=999999999999);
	if(ele==head->aadhar)
	{
		delete_beg();
	}
	else if(ele==tail->aadhar)
	{
		delete_end();
    }
	else
	{

		while(t!=NULL && ele!=t->aadhar)
		{
			t=t->next;
		}
		if(t==NULL){
			cout<<"Invalid input"<<endl;
			exit;
		}
		t->prev->next=t->next;
		t->next->prev=t->prev;
		free(t);
		leng--;
	}

}

void display_end()
{
    struct node *temp;
    temp=tail;
    cout << endl << "Display from last:" << endl;
	while (temp != NULL)
    {
      cout << temp->aadhar << "   ";
      cout<<temp->name<<"   ";
      //      cout<<temp->student_name;
      temp = temp->prev;
      cout << endl;
    }
}

void display_start(){
	struct node *temp;
   temp = head;
  cout << endl << "Display from beginning:" << endl;
  while (temp != NULL)
    {
      cout << temp->aadhar << "   ";
      cout<<temp->name;
      temp = temp->next;
      cout << endl;
  }
}
int main(){
menu:
    int a;
	cout <<"                               Resident's  Database"<<endl<<endl;
	cout<<"1. Add Resident "<<endl;
	cout<<"2. Delete Residents "<<endl;
	cout<<"3. Insert Residents "<<endl;
	cout<<"4. Find Details of a resident"<<endl;
	cout<<"5. Update the details of a resident "<<endl;
	cout<<"6. Dispaly and Generate New List according to names"<<endl;
	cout<<"7. Sort Residents according to Aadhar Numbers"<<endl;
	cout<<"8. Exit"<<endl;
	cout<<"Enter your choice: "<<endl;
	cin>>a;

switch(a){
	case 1:
	    system("cls");
    	add();
    	goto menu;
    	break;
del:
    case 2:
    	system("cls");
    	int b;
    	cout<<"                                  Delete Elements "<<endl;
    	cout<<"1. Delete First Resident "<<endl;
    	cout<<"2. Delete Last Resident"<<endl;
	    cout<<"3. Delete Resident"<<endl;
	    cout<<"4. Main Menu"<<endl;
	    cout<<"Enter your choice: "<<endl;
	    cin>>b;
    	switch(b){
    		case 1:
		        system("cls");
	    	    delete_beg();
	    	    goto del;
	    	    break;
	    	case 2:
		        system("cls");
	    	    delete_end();
	    	    goto del;
	    	    break;
			case 3:
		        system("cls");
	    	    del_pos();
	    	    goto del;
	    	    break;
			case 4:
			    system("cls");
				goto menu;
				break;
		}
insert:
    case 3:
	    system("cls");
    	int c;
    	cout<<"                                  Insert Elements "<<endl;
    	cout<<"1. Insert Resident Before"<<endl;
		cout<<"2. Insert Resident After"<<endl;
		cout<<"3. Insert at the End "<<endl;
		cout<<"4. Insert in the Beginning"<<endl;
	    cout<<"5. Main Menu"<<endl;
	    cout<<"Enter your choice: "<<endl;
	    cin>>c;
    	switch(c){
    		case 1:
		        system("cls");
	    	    insert_before();
	    	    goto insert;
	    	    break;
	    	case 2:
		        system("cls");
	    	    insert_after();
	    	    goto insert;
	    	    break;
			case 3:
		        system("cls");
	    	    insert_end();
	    	    goto insert;
	    	    break;
			case 4:
		        system("cls");
	    	    insert_beg();
	    	    goto insert;
	    	    break;
			case 5:
			    system("cls");
				goto menu;
				break;
		}
	case 4:
        system("cls");
	    find();
	    goto menu;
	    break;
	case 5:
        system("cls");
	    update();
	    goto menu;
	    break;
display:
    case 6:
	    system("cls");
    	int d;
    	cout<<"                                  Display Elements "<<endl;
        cout<<"1. Display List of the residents with names and generate a list "<<endl;
		cout<<"2. Display List"<<endl;
		cout<<"3. Display Reverse List"<<endl;
	    cout<<"4. Main Menu"<<endl;
	    cout<<"Enter your choice: "<<endl;
	    cin>>d;
    	switch(d){
    		case 1:
		        system("cls");
	    	    gen_list();
	    	    goto display;
	    	    break;
	    	case 2:
		        system("cls");
	    	    display_start();
	    	    cout<<"Press any key"<<endl;
	    	    getchar();
	    	    goto display;
	    	    break;
			case 3:
		        system("cls");
	    	    display_end();
	    	    cout<<"Press any key"<<endl;
	    	    getchar();
	    	    goto display;
	    	    break;
			case 4:
			    system("cls");
				goto menu;
				break;
		}
	case 7:
        system("cls");
        sort_list(head);
        cout<<"Press any key"<<endl;
	    getchar();
	    goto menu;
	    break;
	case 8:
		system ("cls");
		cout<<"              Thank You "<<endl;
	    exit(0);
		getchar();
}
}
