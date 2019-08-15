/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWwtU7XqhL0DFAWU&categoryId=AWwtU7XqhL0DFAWU&categoryType=CODE

8189. 우편함 D4
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.


최고의 인기남 선표에게는 많은 팬들이 있고, 이 팬들은 하루에 수십 통의 팬레터를 보낸다.

처음에는 열과 성의를 다해 팬레터를 확인했던 선표지만, 몇 년 동안 계속해서 우편을 확인하면서 너무 지쳐버렸다.

그래서 요즘에는 가끔씩 우편함을 비워줄 뿐이다.

선표는 우편함에 쌓인 편지의 개수가 A개 이상이거나, 가장 오래 기다린 편지가 정확히 B시간 전에 온 편지면 우편함을 비우러 간다.

우편함을 한 번 비울 때, 우편함에 있는 모든 편지를 보는 것은 귀찮기 때문에, 절반 정도의 편지를 확인한다.

정확히 말하자면, 우편함에 편지가 k개 있을 때, 정확히  ⌈k/2⌉개의 편지를 확인한다. 확인하는 편지를 확인할 때는 받은 지 가장 오래된 것부터 확인한다. ( ⌈ ⌉ 기호는 올림을 뜻한다)

선표는 읽는 속도가 매우 빠르기 때문에 편지 읽는 시간은 0이다.

각 편지가 오는 시간이 주어질 때, 각 편지를 선표가 확인하는 시간을 구하는 프로그램을 작성하라.


[입력]

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 세 정수 N, A, B(1 ≤ N, A ≤ 100, 1 ≤ B ≤ 1,000)이 공백 하나로 구분되어 주어진다.

N은 오늘 오는 편지의 개수를 나타낸다.

두 번째 줄에는 N개의 정수 t1, t2, ⋯, tN (1 ≤ t1 < t2 < ⋯ < tN ≤ 1,000)이 공백 하나로 구분되어 주어진다.

ti는 i번째 편지가 온 시간이고, 같은 시간에 도착하는 편지는 없다.


[출력]

각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,

각 테스트 케이스마다 N개의 정수를 공백 하나로 구분하여 출력한다.

i번째 정수는 i번째 편지를 확인하는 시간이어야 한다.
 
입력
2
4 100 10
1 2 3 4
8 4 50
1 2 3 4 50 90 91 100  // 테스트 케이스 개수
// 1th TC, 편지 개수 4(N), 100(A)개 이상 또는 10(B)시간
// 1시간, 2시간, 3시간, 4시간에 도착
// 2nd TC, 편지 개수 8(N), 4(A)개 이상 또는 50(B)시간
// 1시간, 2시간, …., 100시간에 도착
sample_input.txt
출력
#1 11 11 13 14
#2 4 4 53 53 100 100 141 150 // 첫 번째 테스트 케이스 결과
  sample_output.txt
*/

#include <iostream>
using namespace std;

int n, a, b; // 1<=n:편지개수 a:최대쌓일수있는편지수<=100, 1<=b:가장오래기다릴수있는편지시간<=1000
int mails[102]; // 1~1000 mails[i]:i번째 편지가 온 시간, 같은 시간 도착 x
int output[102]; // 읽는 시간 저장

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int t = 1; t < T + 1; ++t) {
		cin >> n >> a >> b;
		for (int i = 1; i < n + 1; ++i)cin >> mails[i];
		int front = 1, back = 1, front_time = mails[1] + b, cnt = 0, pos = 1;
		for(int time = 1; time != 2001; ++time){
			if(mails[back] == time) {
                ++back;
                ++cnt;
			}
			if(front_time == time || cnt == a){
				int mid = front + cnt / 2 + (cnt & 1);
				while(front < mid){
					output[pos++] = time;
					++front;
				}
				front_time = mails[front] + b;
				cnt = back - front;
			}
		}
		cout << "#" << t << " ";
		for (int i = 1; i < n; ++i)cout << output[i] << " ";
		cout << output[n] << "\n";
	}
	return 0;
}
