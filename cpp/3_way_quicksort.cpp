
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector <int> partition2(vector<int> &a, int l, int r) {
  int x = a[r];
  vector <int> arr;
  int j = l;

if (r - l<= 1)
    {
        if (a[r] < a[l])
            swap(a[l], a[r]);
         arr.push_back(l);
         arr.push_back(r);
         return arr;
    }


    while (j <= r)
    {
        if (a[j]<x)
            swap(a[l++], a[j++]);
        else if (a[j]==x)
            j++;
        else if (a[j]>x)
            swap(a[j], a[r--]);
    }
  arr.push_back(l-1);
  arr.push_back(j);

  return arr;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  vector<int> m= partition2(a, l, r);

  randomized_quick_sort(a, l, m[0]);
  randomized_quick_sort(a, m[1], r);
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
