#include <bits/stdc++.h>

using namespace std;

void dfsSCC(vector<vector<int>> edges, int start, unordered_set<int> &visited, stack<int> &finishedVertices)
{
	visited.insert(start);
	for (int i = 0; i < edges[start].size(); ++i)
	{
		if (visited.count(edges[start][i]) == 0)
		{
			dfs(edges, edges[start][i], visited, finishedVertices);
		}
	}
	finishedVertices.push(start);
}

void dfsSCC2(vector<vector<int>> edgesT, int start, unordered_set<int> *component, unordered_set<int> &visited)
{
	visited.insert(start);
	component->insert(start);
	for (int i = 0; i < edgesT[start].size(); ++i)
	{
		if (visited.count(edgesT[start][i]) == 0)
		{
			dfs2(edgesT, edgesT[start][i], component, visited);
		}
	}
}

unordered_set<unordered_set<int>*>* getSCC(vector<vector<int>> edges, vector<vector<int>> edgesT, int n)
{
	unordered_set<int> visited;
	stack<int> finishedVertices;
	for (int i = 0; i < n; ++i)
	{
		if (visited.count(i) == 0)
		{
			dfsSCC(edges, i, visited, finishedVertices);
		}
	}
	unordered_set<unordered_set<int>*>* components = new unordered_set<unordered_set<int>*>();
	visited.clear();
	while (finishedVertices.size() != 0)
	{
		int elt = finishedVertices.top();
		finishedVertices.pop();
		if (visited.count(elt) == 0)
		{
			unordered_set<int>* component = new unordered_set<int>();
			dfsSCC2(edgesT, elt, component, visited);
			components->insert(component);
		}
	}

	return components;
}

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

int getComponents(vector<int> *edges, vector<int> *edgesT, int n)
{
	int count = 0;
	bool *visited = new bool[n]();
	for (int i = 0; i < n; ++i)
	{
		if (edgesT[i].size() == 0)
		{
			dfs(edges, i, visited);
			count++;
		}
	}
	
	unordered_set<unordered_set<int>*>* components = getSCC(edges, edgesT, n);
	vector<int> *componentEdges = new vector<int>[components->size()];

	int componentIndex = 0;
	unordered_set<unordered_set<int>*>::iterator it = components->begin();
	while (it != components->end())
	{
		unordered_set<int> *component = *it;
		unordered_set<int>::iterator it2 = component->begin();
		while (it2 != component->end())
		{
			for (int i = 0; i < edges[*it2].size(); ++i)
			{
				
			}
			it2++;
		}
		cout << endl;
		delete component;
		it++;
		componentIndex++;
	}
	delete components;

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
		vector<int> *edgesT = new vector<int>[n];
		for (int i = 0; i < m; ++i)
		{
			int x,y;
			cin >> x >> y;
			edges[x-1].push_back(y-1);
			edgesT[y-1].push_back(x-1);
		}

		cout << getComponents(edges, edgesT, n);
	}
	return 0;
}