#include<bits/stdc++.h>

using namespace std;

int lcs2(vector<int> &a, vector<int> &b) {
  int m=a.size();
    int n=b.size();
  int i,j,d[m+1][n+1];
  for (i = 0; i <= m; i++)
	{
		for (j = 0; j <= n; j++)
		{
		if (i == 0 || j == 0)
			d[i][j] = 0;

		else if (a[i - 1] == b[j - 1])
			d[i][j] = d[i - 1][j - 1] + 1;

		else
			d[i][j] = max(d[i - 1][j], d[i][j - 1]);
		}
	}


  return d[m][n];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
