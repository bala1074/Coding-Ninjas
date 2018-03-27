#include <bits/stdc++.h>

using namespace std;

void dfs(vector<int> *edges, int start, bool *visited)
{
	visited[start] = true;
	for (int i = 0; i < edges[start].size(); ++i)
	{
		if (!visited[edges[start][i]])
		{
			dfs(edges, edges[start][i], visited);
		}
	}
}

int getComponents(vector<int> *edges, int n)
{
	int count = 0;
	bool *visited = new bool[n]();
	for (int i = 0; i < n; ++i)
	{
		if (!visited[i])
		{
			dfs(edges, i, visited);
			count++;
		}
	}

	return count;
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--)
	{
		int n,m;
		cin >> n >> m;
		vector<int> *edges = new vector<int>[n];
		for (int i = 0; i < m; ++i)
		{
			int x,y;
			cin >> x >> y;
			edges[x-1].push_back(y-1);
		}

		cout << getComponents(edges, n) << endl;
	}
	return 0;
}