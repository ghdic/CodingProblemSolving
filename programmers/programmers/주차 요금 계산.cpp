/*
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <stack>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

int totalTime[1010];
int totalCarNum;
int carList[1010];
map<string, int> carNum_Map;

bool Cmp(pair<int, int> A, pair<int, int> B) {
	return A.second  < B.second  ? true  : false;
}

int invertTime(string time) {
	string sHour  = time.substr(0, 2);
	string sMinute  = time.substr(3, 2);
	int hour  = stoi(sHour) * 60;
	int minute  = stoi(sMinute);
	return hour  + minute;
}

void findEntranceTime(vector<string> records) {
	int num  = 1;
	stack<int> carStack[1010];
	for (auto str : records) {
		stringstream streamStr(str);
		string stime;
		string scarNum;
		string state;
		streamStr  >> stime  >> scarNum  >> state;

		if (carNum_Map[scarNum] == 0) {
			carList[num] = stoi(scarNum);
			carNum_Map[scarNum] = num++;
		}

		int time  = invertTime(stime);

		if (state  == "IN") {
			carStack[carNum_Map[scarNum]].push(time);
		} else {
			int entranceTime  = carStack[carNum_Map[scarNum]].top();
			int resultTime  = time  - entranceTime;
			totalTime[carNum_Map[scarNum]] += resultTime;
			carStack[carNum_Map[scarNum]].pop();
		}
	}

	for (int i  = 1; i  < num; i++) {
		if (carStack[i].empty() == true) {
			continue;
		}

		int resultTime  = invertTime("23:59") - carStack[i].top();
		totalTime[i] += resultTime;
		carStack[i].pop();
	}

	totalCarNum  = num;
}

vector<int> findAnswer(vector<int> fees) {
	vector<pair<int, int>> res;

	for (int i  = 1; i  < totalCarNum; i++) {
		int time  = totalTime[i];
		if (time  <= fees[0]) {
			res.push_back(make_pair(fees[1], carList[i]));
		} else {
			int overTime  = time  - fees[0];
			int overCost  = overTime  % fees[2] == 0 ? (overTime / fees[2]) * fees[3] : ((overTime  / fees[2]) + 1) * fees[3];
			int totalcost  = overCost  + fees[1];
			res.push_back(make_pair(totalcost, carList[i]));
		}
	}
	sort(res.begin(), res.end(), Cmp);
	vector<int> answer;
	for (auto data : res) {
		answer.push_back(data.first);
	}
	return answer;
}

vector<int> solution(vector<int> fees, vector<string> records) {
	vector<int> answer;
	findEntranceTime(records);
	answer = findAnswer(fees);
	return answer;
}


#include <iostream>

void main() {
	vector<int> fees = { 180, 5000, 10, 600 };
	vector<string> records = { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" };


	for (int item : solution(fees, records)) {
		cout << item << "\n";
	}
}
*/