/*
https://www.acmicpc.net/problem/3053

&Title
	3053번 - 택시 기하학스페셜 저지출처다국어 

&Question
19세기 독일 수학자 헤르만 민코프스키는 비유클리드 기하학 중 
택시 기하학을 고안했다.택시 기하학에서 두 점 T1(x1,y1), T2(x2,y2) 사이의 
거리는 다음과 같이 구할 수 있다.D(T1,T2) = |x1-x2| + 
|y1-y2|두 점 사이의 거리를 제외한 나머지 정의는 유클리드 기하학에서의 
정의와 같다.따라서 택시 기하학에서 원의 정의는 유클리드 기하학에서 원의 
정의와 같다.원: 평면 상의 어떤 점에서 거리가 일정한 점들의 
집합반지름 R이 주어졌을 때, 유클리드 기하학에서 원의 넓이와, 택시 
기하학에서 원의 넓이를 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 반지름 R이 주어진다. R은 10,000보다 작거나 
같은 자연수이다. 

&Output
첫째 줄에는 유클리드 기하학에서 반지름이 R인 원의 넓이를, 
둘째 줄에는 택시 기하학에서 반지름이 R인 원의 넓이를 출력한다. 
정답과의 오차는 0.0001까지 허용한다. 

&Example
-input
1

-output
3.141593
2.000000

-input
21

-output
1385.442360
882.000000

-input
42

-output
5541.769441
3528.000000


*/

/*
#include <iostream>
using namespace std;

# define M_PI 3.14159265358979323846

int main() {
	ios::sync_with_stdio(false);
	int r;
	cin >> r;
	cout << fixed;
	cout.precision(6);
	cout << r * r * M_PI << "\n";
	cout << r * r * 2.0 << endl;
	return 0;
}

*/