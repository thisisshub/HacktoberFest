#include<iostream>
using namespace std;
int main()
{
	int rounds;
	cin>>rounds;

	int player1_lead = 0, player2_lead = 0 , score1 = 0, score2 = 0 , temp ;

	for(int i = 0 ; i<rounds ; i++)
	{

		cin>>temp;
		score1+=temp;
		cin>>temp;
		score2+=temp;

		if( score1>=score2 && player1_lead<score1-score2 )
		{
				player1_lead = score1-score2;
		}
		else if( score2>score1 && player2_lead<score2-score1 )
		{
					player2_lead = score2-score1;
		}
	}

	if(player1_lead>player2_lead)
		cout<<"1 "<<player1_lead; 
	else if(player2_lead>player1_lead)
		cout<<"2 "<<player2_lead; 

	return 0;
}
