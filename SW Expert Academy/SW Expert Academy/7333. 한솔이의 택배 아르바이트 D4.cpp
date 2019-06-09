/*
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWmYaDf6AWQDFAV3&categoryId=AWmYaDf6AWQDFAV3&categoryType=CODE

7333. 한솔이의 택배 아르바이트 D4
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.


한솔이는 힘이 매우 쌔다. 그래서 악덕사장 현규는 한솔이에게 모든 박스를 트럭에 실어두라고 말했다.

옮겨야 할 박스는 총 N개 있으며 이 박스들은 외형들은 모두 같지만, 무게는 서로 다를 수 있다.

허리가 좋지 않은 한솔이는 너무 무리하면 안되기 때문에 최대한 오랫동안 상자를 옮겨야 한다.

한솔이가 한 번 상자를 옮길 때는, 옮기고 싶은 상자를 몇 개 쌓아서 한번에 옮긴다.

그리고 상자를 옮길 때 상자가 올려둔 곳 위에 또 올리지 않고 트럭 구석으로 민 다음에 트럭에 싣는다.

한솔이는 최대한 천천히 옮기고 싶지만, 돈을 주는 입장인 현규는 그런 꼴을 보기 싫어한다.

그래서 상자를 트럭 안으로 쌓으면 현규가 잠시 와서 한솔이가 재대로 일을 하고 있는지 확인한다.

하지만, 현규는 힘이 없어 가장 위에 있는 상자가 아니면 무게 검사하기 힘들기 때문에,

꼼수로 가장 위의 상자의 무게를 검사한 다음 밑에 있는 상자도 무게가 모두 같은 거라고 생각하고 검사를 한다.


예를 들어, 가장 위에 있는 상자의 무게가 w이고, 상자의 개수가 n개라면 상자의 총 무게를 w*n 이라고 생각한다.

현규는 한번 옮긴 상자의 무게가 50kg 이상이면 한솔이가 재대로 싣고 있구나 라고 생각한다.

N개 상자의 무게가 주어질 때, 한솔이가 무리하지 않도록 한솔이에게 N개의 상자를 최대 몇 번 만에 옮길 수 있는 지 알려주자!


[입력]

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 하나의 정수 N(1 ≤ N ≤ 100) 이 주어진다.

다음 N개의 줄의 i번째 줄에는 i번째 짐의 무게를 나타내는 정수 Wi (1 ≤ Wi ≤ 100) 가 주어진다.

무게의 단위는 kg로 생각한다. 모든 상자의 무게 합은 50kg이상이다.


[출력]

각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,

정우가 N개의 상자를 최대 몇 번에 옮길 수 있는지 출력한다.
입력
3
4
1
3
27
29
3
23
22
21
4
55
48
50
49 // 테스트 케이스 개수
// 첫 번째 테스트 케이스, N = 4




// 두 번째 테스트 케이스, N = 3



// 세 번째 테스트 케이스, N = 4



  sample_input.txt
출력
#1 2
#2 1
#3 3 // 첫 번째 테스트 케이스 결과
// 두 번째 테스트 케이스 결과
// 세 번째 테스트 케이스 결과
sample_output.txt
*/

/*
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T, N, arr[100];
	setbuf(stdout, NULL);
	ios::sync_with_stdio(false);
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> arr[i];
		sort(arr, arr + N);
		int left = 0, right = N - 1, count = 0;
		while (left <= right) {
			if (arr[right] / 50) {
				right--;
			}
			else {
				int res = 50 / arr[right] + (50 % arr[right] ? 1 : 0);
				if (right - left + 1 < res)break;
				left += res - 1;
				right--;
			}
			count++;
		}
		cout << "#" << t + 1 << " " << count << "\n";
	}
	return 0;
}

*/

/*
&Solution
처음으로 남에 소스 볼 수 있는 문제가 나왔네 ㅇㅂㅇ
ceil 함수 math.h에 내장 되어있으며 올림 해줌 내가 res 구하는 부분임
좀 푸는 방식이 희한하다 했더니 조건부터가 다르네..?
난 mv+=bx-1; 을 했는데 여긴 -1을 안함
break 조건 또한 mv > N || tp < 0 이네...?
결국 박스를 다 사용한거를 측정하려고 mv, tp를 쓴거임.. 사고가 특이하네
근데 빠름 ㅋㅋ
```
#include <stdio.h>
#include <algorithm>
#include <math.h>

int T, N, W[100], R;

int main() {
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		R = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) scanf("%d", W + i);
		std::sort(W, W + N);
		for (int tp = N - 1, mv = 0; ; ) {
			int bx = ceil(50.0 / W[tp]);

			mv += bx;
			if (mv > N || tp < 0)
				break;
			tp--, R++;
		}
		printf("#%d %d\n", t, R);
	}
}
```
*/