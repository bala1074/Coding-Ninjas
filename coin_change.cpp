#include <bits/stdc++.h>

using namespace std;

int countWaysToMakeChange(int denominations[], int numDenominations, int value)
{
	int table[value+1][numDenominations];
	for(int i = 0; i < numDenominations; i++)
	{
		table[0][i] = 1;
	}

	for(int i = 1; i < value+1; i++)
	{
		for(int j = 0; j < numDenominations; j++)
		{
			int x = (i-denominations[j] >= 0) ? table[i-denominations[j]][j] : 0;
			int y = (j >= 1) ? table[i][j-1] : 0;

			table[i][j] = x+y;
		}
	}

	return table[value][numDenominations-1];
}

int main()
{
	int n;
	cin >> n;
	int *denominations = new int[n];
	for(int i = 0; i < n; i++)
	{
		cin >> denominations[i];
	}
	int v;
	cin >> v;
	cout << countWaysToMakeChange(denominations,n,v);
}