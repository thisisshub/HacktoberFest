/* A C++ program of a  calculator for simple arithmetic operators (+, -,
*, /). The program should take two operands from user and perform the
operation on those two operands depending upon the operator entered by
user. */
#include<bits/stdc++.h>
using namespace std;
int main(){
	cout<<"\nWelcome to Calculator.\n Please enter data in the following format:-\n"; 
	cout<<"(num1)(space)(operator)(space)(num2) \n";
	float num1,num2,num3;
	char op,a;	
	do{
		cin>>num1>>op>>num2;
		switch(op){
			case '+':
				num3=num1+num2;
				break;
			case '-':
				num3=num1-num2;
				break;
			case '*':
				num3=num1*num2;
				break;
			case '/':
				if(num2==0)
				{cout<<"Numbers invalid for operation, please try again.";
				break;}
				else
				{numr3=num1/num2;
				break;}
			case '^':
				num3=pow(num1,num2);
				break;
			default:
				cout<<"Operator not recognised. Please try again.";
			}
		cout<<"Answer: \t"<<numb3<<endl;
		cout<<"Do you want to try again?(y/n)\n";
		cin>>a;
	}while(a=='y');
	return 0;
}
