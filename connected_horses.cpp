#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--)
	{
		int n,m;
		cin >> n >> m;
		int **board = new int[n]();
		for (int i = 0; i < n; ++i)
		{
			board[i] = new int[m]();
			for (int j = 0; j < m; ++j)
			{
				board[i][j] = -1;
			}
		}
		int q;
		cin >> q;
		for (int i = 0; i < q; ++i)
		{
			int x,y;
			cin >> x >> y;
			board[x][y] = 0;
		}

		vector<int> components(q);
		int serial = 1;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (board[i][j] != -1)
				{
					int set;
					if (board[i][j] == 0)
					{
						board[i][j] = serial;
						set = serial;
					}
					else
					{
						set = board[i][j];
					}
					
					int count = 0;
					if (board[i+2][j+1] == 0)
					{
						board[i+2][j+1] = serial;
						count++;
					}
				}
			}
		}
	}
	return 0;
}