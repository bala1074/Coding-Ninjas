#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char const *argv[])
{
	ll n,m;
	cin >> n >> m;
	ll a,b;
	cin >> a >> b;
	ll *x = new ll[n];
	ll *diff = new ll[n-1];
	x[0] = 0;
  	ll exp = ll(pow(2,32));
  	ll reduce = ll(pow(2,8));
  	for (int i = 1; i < n; ++i)
  	{
  		x[i] = (((a % exp) * (x[i-1] % m) % exp) % exp + b % exp) % exp;
  		diff[i-1] = (x[i] - x[i-1]) / reduce;
  	}

  	ll totalProfit = 0;
  	for (int i = 0; i < n-1; ++i)
  	{
  		if (diff[i] > 0)
  		{
  			totalProfit += diff[i];
  		}
  	}
	cout << totalProfit;
	return 0;
}