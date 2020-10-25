#include<iostream>
using namespace std;
class worker
{
public:
  int id,year;
  string name,dept,post;

public:
  void data_new (int d)
  {
    cout << "enter name of employes " << endl;
    cin >> name;

    cout << "enter id of employes" << endl;
    cin >> id;

    cout << "enter department of employes " << endl;
    cin >> dept;

    cout << "enter position of employe in company " <<  endl;
    cin >> post;
    
    cout<<"enter experince year";
    cin>>year;
  }
  void print()
  {
      cout<<name<<" "<<id<<" "<<dept;
  }
  void salary (int check)
  {
    cout << "his current salary is \n";
    
    if (check< 5)
      cout << "$1000";
    else if (check >= 5 && check < 10)
      cout << "$1750";
    else if(check >= 10 && check < 18)
      cout << "$3000";
    else
      cout << "$5000";
      
    }
    
};

int
main ()
{
  int n,di,d=1,check;
  
  worker k[25],total;
   cout << "enter number of employes \n";
    cin >> n;
  for (int i = 0; i < n; i++)
    {
      k[i].data_new(d);
      d=d+1;
    }
    for (int i = 0; i < n; i++)
    {
      k[i].print();
      cout<<endl;
    }
cout<<"whose details you want";
cin>>di;
 for (int i = 0; i < n; i++)
    {
      if(di==k[i].id)
      check=i;
    }
    k[check].print();
    total.salary(k[check].year);
    
  return 0;
}


