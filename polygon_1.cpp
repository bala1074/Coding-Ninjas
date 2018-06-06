#include <bits/stdc++.h>
using namespace std;
typedef double d;
 
double polygonArea(double *X, double *Y, int n)
{
    double area = 0.0;
 
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        area += (X[j] + X[i]) * (Y[j] - Y[i]);
        j = i;
    }
 
    return abs(area / 2.0);
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	d *x = new d[n]();
	d *y = new d[n]();
	for (int i = 0; i < n; ++i)
	{
		cin >> x[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> y[i];
	}

	//printf("%0.9f", polygonArea(x,y,n));
  	cout << polygonArea(x,y,n);

	return 0;
}