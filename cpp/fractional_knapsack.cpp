#include <bits/stdc++.h>
#include <iterator>
using namespace std;

double get_optimal_value(int c, vector<int>& weights, vector<int>& values) {

  map<double,int> knap;

    for(int i=0;i<values.size();i++)
    {
        double val=values[i]/(double)weights[i];
        knap.insert({val,weights[i]});
    }
        map<double, int>::iterator itr;

        itr=knap.end();
        itr--;

        double val=0;
    while(c>0&&itr!=knap.begin())
    {
        if(itr->second<c)
           {
              val+=(itr->first*itr->second);
              c-=itr->second;
              itr--;
           }
           else
           {
                val+=(itr->first*c);
                c=0;
                itr--;
           }


    }
    if(itr->second<c)
           {
              val+=(itr->first*itr->second);
              c-=itr->second;
              itr--;
           }
           else
           {
                val+=(itr->first*c);
                c=0;
                itr--;
           }

  return val;
}

int main() {
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  cout.precision(10);
  cout <<fixed<< optimal_value <<endl;
  return 0;
}
