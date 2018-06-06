#include <bits/stdc++.h>

using namespace std;

struct Friend
{
	int start;
	int end;
	int index;
};

int time2min(string time)
{
	return stoi(time.substr(0,2)) * 60 + stoi(time.substr(3));
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	for (int c = 0; c < t; c++)
	{
      	cout << "Case " << c+1 << ": ";
		int n;
		cin >> n;
		Friend *friends = new Friend[n]();
		string inTimeStr, wakeUpStr, storeOpenStr;
		cin >> inTimeStr >> wakeUpStr >> storeOpenStr;
		int inTime = time2min(inTimeStr);
		int wakeUp = time2min(wakeUpStr);
		int storeOpen = time2min(storeOpenStr);
		int r,s;
		cin >> r >> s;
		for (int i = 0; i < n; ++i)
		{
			string startTime, endTime;
			cin >> startTime >> endTime;
			friends[i].start = time2min(startTime);
			friends[i].end = time2min(endTime);
			friends[i].index = i;
		}

		int minTime = INT_MAX;
		int leaveTime = (wakeUp < storeOpen-r) ? storeOpen-r : wakeUp;
		int retTime = (wakeUp < storeOpen-r) ? storeOpen+r+s : wakeUp+2*r+s;
		if (retTime > inTime)
		{
			cout << "-1\n";
			continue;
		}

		int finalInTime = INT_MAX;
		int finalIndex = -1;
		for (int i = 0; i < n; ++i)
		{
			if ((leaveTime <= friends[i].start and retTime <= friends[i].start) or
				(leaveTime >= friends[i].end and retTime >= friends[i].end))
			{
				if (finalInTime > retTime)
				{
					finalInTime = retTime;
					finalIndex = i;
				}
			}
			else
			{
				int newLeaveTime = friends[i].end;
				int newRetTime = newLeaveTime + 2*r + s;
				if (newRetTime <= inTime and finalInTime > newRetTime)
				{
					finalInTime = newRetTime;
					finalIndex = i;
				}
			}
		}

		cout << finalIndex+1 << endl;
	}
	return 0;
}