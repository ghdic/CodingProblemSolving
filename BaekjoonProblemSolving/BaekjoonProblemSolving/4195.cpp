/*
https://www.acmicpc.net/problem/4195

&Title
4195번 - 친구 네트워크

&Question
민혁이는 소셜 네트워크 사이트에서 친구를 만드는 것을 좋아하는 
친구이다. 우표를 모으는 취미가 있듯이, 민혁이는 소셜 네트워크 사이트에서 
친구를 모으는 것이 취미이다.어떤 사이트의 친구 관계가 생긴 순서대로 
주어졌을 때, 두 사람의 친구 네트워크에 몇 명이 있는지 
구하는 프로그램을 작성하시오.친구 네트워크란 친구 관계만으로 이동할 수 있는 
사이를 말한다. 

&Input
첫째 줄에 테스트 케이스의 개수가 주어진다. 각 테스트 
케이스의 첫째 줄에는 친구 관계의 수 F가 주어지며, 이 
값은 100,000을 넘지 않는다. 다음 F개의 줄에는 친구 관계가 
생긴 순서대로 주어진다. 친구 관계는 두 사용자의 아이디로 이루어져 
있으며, 알파벳 대문자 또는 소문자로만 이루어진 길이 20 이하의 
문자열이다. 

&Output
친구 관계가 생길 때마다, 두 사람의 친구 네트워크에 
몇 명이 있는지 구하는 프로그램을 작성하시오. 

&Example
-input
2
3
Fred Barney
Barney Betty
Betty Wilma
3
Fred Barney
Betty Wilma
Barney Betty

-output
2
3
4
2
2
4


*/

/*
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int t, f;
unordered_map<string, int> um;
int relation[200001], amount[200001];
int pos;

int find(int num) {
	if (relation[num] == num)return num;
	return relation[num] = find(relation[num]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		um.clear();
		pos = 1;
		cin >> f;
		string a, b;
		int y, x;
		for (int i = 1; i <= f; ++i) {
			cin >> a >> b;
			if (um.find(a) != um.end()) {
				y = find(um[a]);
			}
			else {
				relation[pos] = pos;
				y = pos;
				amount[pos] = 1;
				um[a] = pos++;
			}

			if (um.find(b) != um.end()) {
				x = find(um[b]);
			}
			else {
				relation[pos] = pos;
				x = pos;
				amount[pos] = 1;
				um[b] = pos++;
			}
			if (y == x) {
				cout << amount[x] << '\n';
			}
			else if (y < x) {
				relation[x] = y;
				amount[y] += amount[x];
				cout << amount[y] << '\n';
			}
			else {
				relation[y] = x;
				amount[x] += amount[y];
				cout << amount[x] << '\n';
			}
		}
	}
	return 0;
}
*/