#include<iostream>
using namespace std;

void showMenu(){
	cout << "------------MENU--------------" << endl;
	cout << "1. Check Balance" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Withdraw" << endl;
	cout << "4. Exit" << endl;
	cout << "------------------------------" << endl;
}

int main()
{
	int option;
	int pin;
	double balance=200;
	
	cout << "Enter your ATM PIN: " << endl;  //assume pin as 1111
	cin >> pin;
	int def_pin{1111};
	if(pin == def_pin){
		do{
		showMenu();
			cout << "Choose an option : " << endl << endl;
			cin >> option;
			system("cls");
			
			switch(option){
				case 1:
					cout << "Balance is: " << balance << endl; 
					break;
				case 2:
					cout << "Deposit Amount: ";
					double depositAmount;
					cin >> depositAmount;
					balance += depositAmount;
					break;
				case 3:
					cout << "Withdraw Amount: ";
					double withdrawAmount;
					cin >> withdrawAmount;
					if(withdrawAmount <= balance)
					{
					balance -= withdrawAmount;
					}
					else
					cout<< "Not enough money" << endl;
					break;
			}
		} while(option!=4);
	}
	else{
		cout<<"The PIN is incorrect. \n Please enter the correct PIN" << endl;
	}
		
}
