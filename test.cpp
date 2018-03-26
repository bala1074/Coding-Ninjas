#include <bits/stdc++.h>

struct Pos
{
	int x;
	int y;
};

using namespace std;

void printComb(Pos pos, int n, int m)
{
	vector<Pos> possible;
	Pos curr;
	curr.x = pos.x;
	curr.y = pos.y;
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

		inc_x++;
		inc_y++;
	}

	for (int i = 0; i < possible.size(); ++i)
	{
		cout << possible[i].x << " " << possible[i].y << endl;
	}
}

int main(int argc, char const *argv[])
{
	Pos pos;
	pos.x = 3;
	pos.y = 4;
	printComb(pos, 5, 10);
	return 0;
}