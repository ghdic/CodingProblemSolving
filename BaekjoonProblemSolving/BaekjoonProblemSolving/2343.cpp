/*
https://www.acmicpc.net/problem/2343

&Title
2343번 - 기타 레슨

&Question
강토는 자신의 기타 레슨 동영상을 블루레이로 만들어 판매하려고 
한다. 블루레이에는 총 N개의 레슨이 들어가는데, 블루레이를 녹화할 때, 
레슨의 순서가 바뀌면 안 된다. 순서가 뒤바뀌는 경우에는 레슨의 
흐름이 끊겨, 학생들이 대혼란에 빠질 수 있기 때문이다. 즉, 
i번 레슨과 j번 레슨을 같은 블루레이에 녹화하려면 i와 j 
사이의 모든 레슨도 같은 블루레이에 녹화해야 한다.강토는 이 블루레이가 
얼마나 팔릴지 아직 알 수 없기 때문에, 블루레이의 개수를 
가급적 줄이려고 한다. 오랜 고민 끝에 강토는 M개의 블루레이에 
모든 기타 레슨 동영상을 녹화하기로 했다. 이때, 블루레이의 크기(녹화 
가능한 길이)를 최소로 하려고 한다. 단, M개의 블루레이는 모두 
같은 크기이어야 한다.강토의 각 레슨의 길이가 분 단위(자연수)로 주어진다. 
이때, 가능한 블루레이의 크기 중 최소를 구하는 프로그램을 작성하시오. 


&Input
첫째 줄에 레슨의 수 N (1 ≤ N 
≤ 100,000)과 M (1 ≤ M ≤ N)이 주어진다. 
다음 줄에는 강토의 기타 레슨의 길이가 레슨 순서대로 분 
단위로(자연수)로 주어진다. 각 레슨의 길이는 10,000분을 넘지 않는다. 

&Output
첫째 줄에 가능한 블루레이 크기중 최소를 출력한다. 

&Example
-input
9 3
1 2 3 4 5 6 7 8 9

-output
17


*/

/*
#include <iostream>
using namespace std;

int n, m;
int arr[100000];

bool check(int mid) {
	int sum = 0, cnt = 1;
	for (int i = 0; i < n; ++i) {
		if (mid < arr[i])return false;
		else if (sum + arr[i] <= mid)
			sum += arr[i];
		else {
			++cnt;
			sum = arr[i];
		}
	}
	return cnt <= m;
}

int binarySearch(int num) {
	int l = 1, r = num;

	while (l <= r) {
		int mid = (l + r) / 2;
		
		if (check(mid)) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return l;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		sum += arr[i];
	}
	cout << binarySearch(sum) << endl;
}
*/