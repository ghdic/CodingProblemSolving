/*
https://www.acmicpc.net/problem/1449

&Title
1449번 - 수리공 항승

&Question
항승이는 품질이 심각하게 나쁜 수도 파이프 회사의 수리공이다. 
항승이는 세준 지하철 공사에서 물이 샌다는 소식을 듣고 수리를 
하러 갔다.파이프에서 물이 새는 곳은 신기하게도 가장 왼쪽에서 정수만큼 
떨어진 거리만 물이 샌다.항승이는 길이가 L인 테이프를 무한개 가지고 
있다.항승이는 테이프를 이용해서 물을 막으려고 한다. 항승이는 항상 물을 
막을 때, 적어도 그 위치의 좌우 0.5만큼 간격을 줘야 
물이 다시는 안 샌다고 생각한다.물이 새는 곳의 위치와, 항승이가 
가지고 있는 테이프의 길이 L이 주어졌을 때, 항승이가 필요한 
테이프의 최소 개수를 구하는 프로그램을 작성하시오. 테이프를 자를 수 
없고, 테이프를 겹쳐서 붙이는 것도 가능하다. 

&Input
첫째 줄에 물이 새는 곳의 개수 N과 테이프의 
길이 L이 주어진다. 둘째 줄에는 물이 새는 곳의 위치가 
주어진다. N과 L은 1,000보다 작거나 같은 자연수이고, 물이 새는 
곳의 위치는 1,000보다 작거나 같은 자연수이다. 

&Output
첫째 줄에 항승이가 필요한 테이프의 개수를 출력한다. 

&Example
-input
4 2
1 2 100 101

-output
2

*/


/*
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, L, arr[1000] = {}, need = 0;
	cin >> N >> L;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	int temp = arr[0];
	for (int i = 0; i < N; i++) {
		if (arr[i] <= L - 1 + temp)continue;
		need++;
		temp = arr[i];
	}
	cout << ++need << endl;
	return 0;
}
*/