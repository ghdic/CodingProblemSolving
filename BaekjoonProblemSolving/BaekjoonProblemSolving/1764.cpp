/*
https://www.acmicpc.net/problem/1764

&Title
1764번 - 듣보잡

&Question
김진영이 듣도 못한 사람의 명단과, 보도 못한 사람의 
명단이 주어질 때, 듣도 보도 못한 사람의 명단을 구하는 
프로그램을 작성하시오. 

&Input
첫째 줄에 듣도 못한 사람의 수 N, 보도 
못한 사람의 수 M이 주어진다. 이어서 둘째 줄부터 N개의 
줄에 걸쳐 듣도 못한 사람의 이름과, N+2째 줄부터 보도 
못한 사람의 이름이 순서대로 주어진다. 이름은 띄어쓰기 없이 영어 
소문자로만 이루어지며, 그 길이는 20 이하이다. N, M은 500,000 
이하의 자연수이다. 

&Output
듣보잡의 수와 그 명단을 사전순으로 출력한다. 

&Example
-input
3 4
ohhenrie
charlie
baesangwook
obama
baesangwook
ohhenrie
clinton

-output
2
baesangwook
ohhenrie


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v;
vector<string> result;
int main() {
	int N, M;
	cin >> N >> M;
	v.resize(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		if (binary_search(v.begin(), v.end(), s)) {
			result.push_back(s);
		}
	}
	sort(result.begin(), result.end());
	
	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << endl;
	return 0;
}
*/