#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<vector<string>> workDays;
	int months[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int opSize;

	//vector initialization for all months
	cin >> opSize;
	int curMonth = 0; //select the first mouth as January
	workDays.resize(months[curMonth]);
	for (int i = 0; i < opSize; i++)
	{
		string opName;
		cin >> opName;
		if (opName == "ADD")
		{
			//add thing for special op day
			int day;
			cin >> day;
			if ((day - 1) < months[curMonth])
			{
				string task;
				cin >> task;
				workDays[day - 1].push_back(task);
			}
			else
			{
				//error nothing to do
			}
		}
		else if (opName == "DUMP")
		{
			int day;
			cin >> day;
			if ((day - 1) < months[curMonth])
			{
				cout << workDays[day - 1].size() << " ";
				for (string work : workDays[day - 1])
				{
					cout << work << " ";
				}
				cout << endl;
			}
		}
		else if (opName == "NEXT")
		{
			int tmp = curMonth++;
			if (curMonth > 11)
				curMonth = 0;
			if (months[curMonth] > months[tmp])
			{
				//clean the things for all new days
				for (int i = months[tmp]; i < months[curMonth]; i++)
					workDays[i].clear();
			}
			else
			{
				vector<string>& lastDay = workDays[months[curMonth] - 1];
				for (int i = months[curMonth]; i < months[tmp]; i++)
					lastDay.insert(end(lastDay), begin(workDays[i]), end(workDays[i]));
			}
		}
	}
	return 0;
}
