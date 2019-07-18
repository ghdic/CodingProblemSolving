/*
https://www.acmicpc.net/problem/2853

&Title
2853번 - 배

&Question
해빈이는 배가 한 척이라도 올까 말까 한 작은 
항구 마을에 산다. 그런데 어느 날, 마을을 방문한 적이 
있는 모든 배가 한꺼번에 마을을 방문한 날이 있었다. 해빈이는 
이 날을 기념해 1일로 센다. 그리고 배가 한 척이라도 
마을에 온 날을 신나는 날이라고 하고 특별히 리스트에 기록해두었다.해빈이는 
마을에 방문하는 배들을 관찰한 결과, 이들이 일정한 날자 간격을 
두고 주기적으로 항구를 방문한다는 사실을 알아차렸다. 예를 들어, 간격이 
3인 배는 1일, 4일, 7일, 10일 등에 해빈이의 마을에 
온다.오늘은 신나는 날이다. 오늘을 포함해서 해빈이의 신나는 날 리스트가 
주어질 때, 방문한 배의 최소 수를 구하라. (해빈이는 모든 
신나는 날을 리스트에 정확히 적어두었다. 따라서 항상 답이 존재한다.) 


&Input
입력의 첫 줄에 정수 신나는 날의 개수 N 
(2 ≤ N ≤ 5000)이 주어진다.다음 N줄에는 신나는 날의 
번호가 오름차순으로 한 줄에 하나 씩 주어진다. 첫 번째 
수와 마지막 수는 각각 해빈이가 관찰을 시작한 날, 그리고 
해빈이가 매긴 오늘의 번호이다. 즉, 첫 번째 줄은 항상 
1이다. 마지막 수(오늘의 번호)는 10^9보다 작다. 

&Output
가능한 배의 최소 수를 출력한다. 

&Example
-input
3
1
3
4

-output
2


*/

/*
#include <iostream>
using namespace std;

int n; // 신나는 날의 개수 2~5000
int happyday[5001]; // 오름차순으로 주어짐
// 첫째 수는 해빈이가 관찰 시작한 날, 마지막 수는 오늘 매긴 번호
// 첫째 수는 항상 1, 마지막은 10^9보다 작음
int gap[5001]; // 배들이 오는 간격
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> happyday[i];
	int ships = 0;
	for (int i = 1; i < n; ++i) {
		bool check = false;
		for (int j = 0; j < ships; ++j) {
			if (((happyday[i]-1) % gap[j]) == 0) {
				check = true;
				break;
			}
		}
		if (!check) {
			gap[ships++] = happyday[i] - 1;
		}
	}
	cout << ships << endl;
	return 0;
}
*/

/*
#include <cstdio>
#include <algorithm>
#include <unordered_map>
using namespace std;
int n;
int arr[5001];
bool check[5001];
unordered_map<int, int> save;
int answer, cnt;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)scanf("%d", &arr[i]), save[arr[i]] = i;
	check[0] = true;
	for (int i = 1; i < n; ++i) {
		if (check[i]) continue;
		int dif = arr[i] - 1;
		++answer;
		for (int j = arr[i]; j <= arr[n - 1]; j += dif) {
			int idx = save[j]; // 만약 해당하는 key에 대한 순서가 있을 경우 val반환 없을 경우 0 반환한다.
			if (!check[idx]) { // 결국 0을 반환하지 않았을때 해당 날짜부분을 check해주는 것이다.
				check[idx] = true;
				++cnt;
			}
		}
		if (cnt == n - 1)break;
	}
	printf("%d\n", answer);
	return 0;
}
*/