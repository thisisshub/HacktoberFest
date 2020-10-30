#include <iostream>

using namespace std;

int a[100][100], n, v[100] = {0};

void citire()
{
    cout<<"Dati numarul de varfuri: ";
    cin>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            cin>>a[i][j];
            a[j][i]=a[i][j];
        }
}

void afisare()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

void DF(int x)
{

    v[x]=1;
    cout<<x<<" ";
    for(int i=1; i<=n; i++)
    {
        if(a[x][i]==1)
            if(v[i]==0)
                DF(i);
    }
}

int main()
{
    citire();
    cout<<"\n";
    cout<<"Matricea de adiacenta este: "<<endl;
    cout<<"\n";
    afisare();
    cout<<endl;
    cout<<"\n";
    int x;
    cout<<"Dati numarul pentru care vreti sa parcurgeti in adancime: ";
    cin>>x;
    cout<<endl;
    DF(x);
    return 0;
}