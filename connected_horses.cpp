#include <bits/stdc++.h>

using namespace std;

struct Pos
{
	int x;
	int y;
};

int dfs(Pos *pos, int start, bool *visited, int n, int m, int q)
{
	visited[start] = true;
	vector<Pos> possible;
	Pos curr;
	curr.x = pos[start].x;
	curr.y = pos[start].y;
	int inc_x = 0;
	int inc_y = 1;
	int itr = 2;
	while (itr--)
	{
		Pos temp;
		temp.x = curr.x + (inc_x % 2) + 1;
		temp.y = curr.y + (inc_y % 2) + 1;
		if (temp.x < n and temp.y < m and temp.x > -1 and temp.y > -1)
		{
			possible.push_back(temp);
		}
		temp.x = curr.x - (inc_x % 2) - 1;
		temp.y = curr.y - (inc_y % 2) - 1;
		if (temp.x < n and temp.y < m and temp.x > -1 and temp.y > -1)
		{
			possible.push_back(temp);
		}		
		temp.x = curr.x + (inc_x % 2) + 1;
		temp.y = curr.y - (inc_y % 2) - 1;
		if (temp.x < n and temp.y < m and temp.x > -1 and temp.y > -1)
		{
			possible.push_back(temp);
		}		
		temp.x = curr.x - (inc_x % 2) - 1;
		temp.y = curr.y + (inc_y % 2) + 1;
		if (temp.x < n and temp.y < m and temp.x > -1 and temp.y > -1)
		{
			possible.push_back(temp);
		}	
	}

	int count = 1;
	for (int i = 0; i < q; ++i)
	{
		if (!visited[i] and find(possible.begin(), possible.end(), pos[i]) != possible.end())
		{
			visited[i] = true;
			count += dfs(pos, i, visited, n, m, q);
		}
	}

	return count;
}

int config(int *pos, int n, int m, int q)
{
	bool *visited = new bool[q]();
	vector<int> counts;
	for (int i = 0; i < q; ++i)
	{
		if (!visited[i])
		{
			int count = dfs(pos, i, visited, n, m, q);
			counts.push_back(count);
		}
	}

	for (int i = 0; i < counts.size(); ++i)
	{
		cout << counts[i] << " ";
	}
	cout << endl;

	return 0;
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--)
	{
		int n,m,q;
		cin >> n >> m >> q;
		Pos *pos = new Pos[q]();

		for (int i = 0; i < q; ++i)
		{
			int x,y;
			cin >> x >> y;
			pos[q].x = x;
			pos[q].y = y;
		}

		cout << config(pos, n, m, q);
	}
	return 0;
}