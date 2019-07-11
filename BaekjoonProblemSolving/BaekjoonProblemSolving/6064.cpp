/*
https://www.acmicpc.net/problem/6064

&Title
6064번 - 카잉 달력

&Question
최근에 ICPC 탐사대는 남아메리카의 잉카 제국이 놀라운 문명을 
지닌 카잉 제국을 토대로 하여 세워졌다는 사실을 발견했다. 카잉 
제국의 백성들은 특이한 달력을 사용한 것으로 알려져 있다. 그들은 
M과 N보다 작거나 같은 두 개의 자연수 x, y를 
가지고 각 년도를 <x:y>와 같은 형식으로 표현하였다. 그들은 이 
세상의 시초에 해당하는 첫 번째 해를 <1:1>로 표현하고, 두 
번째 해를 <2:2>로 표현하였다. <x:y>의 다음 해를 표현한 것을 
<x':y'>이라고 하자. 만일 x < M 이면 x' = 
x + 1이고, 그렇지 않으면 x' = 1이다. 같은 
방식으로 만일 y < N이면 y' = y + 
1이고, 그렇지 않으면 y' = 1이다. <M:N>은 그들 달력의 
마지막 해로서, 이 해에 세상의 종말이 도래한다는 예언이 전해 
온다. 예를 들어, M = 10 이고 N = 
12라고 하자. 첫 번째 해는 <1:1>로 표현되고, 11번째 해는 
<1:11>로 표현된다. <3:1>은 13번째 해를 나타내고, <10:12>는 마지막인 60번째 
해를 나타낸다. 네 개의 정수 M, N, x와 y가 
주어질 때, <M:N>이 카잉 달력의 마지막 해라고 하면 <x:y>는 
몇 번째 해를 나타내는지 구하는 프로그램을 작성하라. 

&Input
입력 데이터는 표준 입력을 사용한다. 입력은 T개의 테스트 
데이터로 구성된다. 입력의 첫 번째 줄에는 입력 데이터의 수를 
나타내는 정수 T가 주어진다. 각 테스트 데이터는 한 줄로 
구성된다. 각 줄에는 네 개의 정수 M, N, x와 
y가 주어진다. (1 ≤ M, N ≤ 40,000, 1 
≤ x ≤ M, 1 ≤ y ≤ N) 
여기서 <M:N>은 카잉 달력의 마지막 해를 나타낸다. 

&Output
출력은 표준 출력을 사용한다. 각 테스트 데이터에 대해, 
정수 k를 한 줄에 출력한다. 여기서 k는 <x:y>가 k번째 
해를 나타내는 것을 의미한다. 만일 <x:y>에 의해 표현되는 해가 
없다면, 즉, <x:y>가 유효하지 않은 표현이면, -1을 출력한다. 

&Example
-input
3
10 12 3 9
10 12 7 2
13 11 5 6

-output
33
-1
83


*/

/*
#include <iostream>
using namespace std;

int GCD(int a, int b) {
	if (b == 0)return a;
	return GCD(b, a % b);
}
int main() {
	int T;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		int M, N, x, y; // 1~40000, 1~40000 , 1~M, 1~N
		cin >> M >> N >> x >> y;
		
		// tx == x 라고 가정하고 ty == y 인경우를 찾는다.
		int b = x, cnt = x;
		for (int i = 0; i < N; ++i) {
			int ty = b % N == 0 ? N : b % N;
			if (ty == y)break;
			b = ty + M; // x값이 고정이므로 M씩증가
			cnt += M;
		}
		int result = cnt > M*N/GCD(M, N) ? -1 : cnt;
		cout << result << endl;
	}
	return 0;
}
*/
// 첨엔 최대공약수로 모든 경우의수를 구해서 비교하려 했는데 생각보다 힘들고 귀찮았다..
// 최소공배수를 넘어갈때까지 일치하는 패턴이 없으면 유효하지 않다는걸 알면 쉽게 풀 수 있다..


// 위 풀이는 % 연산자의 남발이 너무 심하다
// 아래 소스가 내가 머리속에선 짜고 싶었던 소스가 아닐까? (아마도)
// 내 머리가 못떠올림 ㅠㅠ
/*
#include <stdio.h>
int gcd(int a, int b){
	int c;
	while(b != 0){
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
int lcm(int a, int b){
	return a * b / gcd(a, b);
}
int main(){
	int T, M, N, x, y;
	scanf("%d", &T);
	while(T--){
		int ans = -1;
		bool getAns = 0;
		scanf("%d %d %d %d", &M, &N, &x, &y);
		int l = lcm(M, N);
		int g = 0;
		int c = 0;
		while(g*M + x < l){ // 최소공배수 벗어나면 out
			if(getAns) break;
			while(c*N + y <= g*M + x){ // 재밌는게 days에 대한 두 방정식을 비교하는 식으로 해결한다
				if(c*N + y == g*M + x) {
					ans = c*N + y;
					getAns = 1;
					break;
				}
				c++;
			}
			g++;
		}
		if(getAns) printf("%d\n", ans);
		else printf("-1\n");
	}
	return 0;
}
*/