/*
https://www.acmicpc.net/problem/7785

&Title
7785번 - 회사에 있는 사람

&Question
상근이는 세계적인 소프트웨어 회사 기글에서 일한다. 이 회사의 
가장 큰 특징은 자유로운 출퇴근 시간이다. 따라서, 직원들은 반드시 
9시부터 6시까지 회사에 있지 않아도 된다.각 직원은 자기가 원할 
때 출근할 수 있고, 아무때나 퇴근할 수 있다.상근이는 모든 
사람의 출입카드 시스템의 로그를 가지고 있다. 이 로그는 어떤 
사람이 회사에 들어왔는지, 나갔는지가 기록되어져 있다. 로그가 주어졌을 때, 
현재 회사에 있는 모든 사람을 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 로그에 기록된 출입 기록의 수 n이 
주어진다. (2 ≤ n ≤ 106) 다음 n개의 줄에는 
출입 기록이 순서대로 주어지며, 각 사람의 이름이 주어지고 "enter"나 
"leave"가 주어진다. "enter"인 경우는 출근, "leave"인 경우는 퇴근이다.회사에는 동명이인이 
없으며, 대소문자가 다른 경우에는 다른 이름이다. 

&Output
현재 회사에 있는 사람의 이름을 사전 순의 역순으로 
한 줄에 한 명씩 출력한다. 

&Example
-input
4
Baha enter
Askar enter
Baha leave
Artem enter

-output
Askar
Artem


*/

/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n;
unordered_map<string, string> um;
string a, b;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> a >> b;
		if (b == "enter") {
			um[a] = a;
		}
		else {
			um.erase(a);
		}
	}
	vector<string> res(um.size());
	auto value_selector = [](auto pair) {return pair.second; };
	transform(um.begin(), um.end(), res.begin(), value_selector);
	sort(res.begin(), res.end(), greater<string>());
	for (auto k : res)
		cout << k << '\n';
	return 0;
}
*/

// 천잰가 이사람?
/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(int argc, const char * argv[]) {
	ios_base::sync_with_stdio(false);
	vector<string> enter;
	vector<string> leave;
	int inNum,n=0;
	string inStr1,inStr2;

	cin>>inNum;

	while(inNum--){
		cin>>inStr1;
		cin>>inStr2;
		if(inStr2=="enter")
			enter.emplace_back(inStr1);
		else
			leave.emplace_back(inStr1);
	}
	sort(enter.begin(),enter.end());
	sort(leave.begin(),leave.end());

	for(int i=0;i<enter.size();i++){
		if(n==leave.size()){
			cout<<enter[enter.size()-i-1]<<'\n';
			continue;
		}
		if(leave[leave.size()-n-1]!=enter[enter.size()-i-1])
			cout<<enter[enter.size()-i-1]<<'\n';
		else
			n+=1;
	}

	return 0;
}

*/