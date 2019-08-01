/*
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWIeW7FakkUDFAVH

4014. [모의 SW 역량테스트] 활주로 건설
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.


  [Fig. 1] 과 같은 N * N 크기의 절벽지대에 활주로를 건설하려고 한다.
각 셀의 숫자는 그 지형의 높이를 의미한다.

                                                      

활주로를 [Fig. 2] 와 같이 가로 또는 세로 방향으로 건설할 수 있는 가능성을 확인하려고 한다.


                               활주로는 높이가 동일한 구간에서 건설이 가능하다.
높이가 다른 구간의 경우 활주로가 끊어지기 때문에 [Fig. 3] 과 같은 경사로를 설치해야만 활주로를 건설 할 수 있다.



                                                       경사로는 길이가 X 이고, 높이는 1 이다.
경사로는 높이 차이가 1 이고 낮은 지형의 높이가 동일하게 경사로의 길이만큼 연속되는 곳에 설치 할 수 있다.
  예를 들어 [Fig. 4] 는 길이가 2 이고 높이가 1 인 경사로를 설치하는 예를 보여준다.

                                   

  경사로의 길이 X 와 절벽지대의 높이 정보가 주어질 때,
활주로를 건설할 수 있는 경우의 수를 계산하는 프로그램을 작성하라.
    [예시]
지도의 한 변의 크기 N 이 6, 경사로의 길이 X 가 2 일 때,
[Fig. 5] 와 같이 지형의 높이가 주어진 경우를 생각해 보자.


                                                      


[Fig. 5] 의 지형 중 [ 3, 3, 3, 2, 1, 1 ] 의 경우 [Fig. 6] 과 같이 높이 2 인 구간이 경사로 길이보다 짧아서 활주로를 설치 할 수 없다.


                                                      

[ 3, 3, 3, 2, 2, 1 ] 의 지형은 [Fig. 7] 과 같이 경사로를 지형 밖까지 설치해야 되기 때문에 활주로를 설치할 수 없다.


                                                      

[ 2, 2, 3, 2, 2, 2 ] 지형과 [ 3, 3, 3, 2, 2, 2 ] 지형의 경우 아래 [Fig. 8-1], [Fig. 8-2] 와 같이 경사로를 설치하여 활주로를 건설할 수 있다.

                           
                            [Fig. 5] 와 같은 지형에 활주로를 건설하는 방법은
아래 [Fig. 9] 와 같이 총 7 가지 ( 가로 방향 3 가지, 세로 방향 4 가지 ) 경우가 있다.
즉, 예제에 대한 정답은 7 이 된다


                                                       [제약사항]
1. 시간제한 : 최대 50 개 테스트 케이스를 모두 통과하는 데 C / C++ / Java 모두 3 초
2. N 의 크기는 6 이상 20 이하의 정수이다. ( 6 ≤ N ≤ 20 )
3. 경사로의 높이는 항상 1 이고, 길이 X 는 2 이상 4 이하의 정수이다. ( 2 ≤ X ≤ 4 )
4. 지형의 높이는 1 이상 6 이하의 정수이다.
5. 동일한 셀에 두 개 이상의 경사로를 겹쳐서 사용할 수 없다.
( 아래 [Fig. 10] 과 같은 경우는 경사로를 설치하여 활주로를 연결 할 수 없다. )


                                            

6. 경사로는 세워서 사용할 수 없다. ( [Fig. 11] 참고 )


                                                         [입력]
입력의 맨 첫 줄에는 총 테스트 케이스의 개수 T 가 주어지고,
그 다음 줄부터 T 개의 테스트 케이스가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 지도의 한 변의 크기인 N 과 경사로의 길이 X 가 주어진다.
다음 N 개의 줄에는 N * N 크기의 지형 정보가 주어진다.
    [출력]
테스트 케이스 개수만큼 T 개의 줄에 각각의 테스트 케이스에 대한 답을 출력한다.
각 줄은 "#t" 로 시작하고 공백을 하나 둔 다음 정답을 출력한다. ( t 는 1 부터 시작하는 테스트 케이스의 번호이다. )
정답은 활주로를 건설할 수 있는 경우의 수이다.
 




     
 
입력
10
6 2
3 3 3 2 1 1
3 3 3 2 2 1
3 3 3 3 3 2
2 2 3 2 2 2
2 2 3 2 2 2
2 2 2 2 2 2
6 4
3 2 2 2 1 2
3 2 2 2 1 2
3 3 3 3 2 2
3 3 3 3 2 2
3 2 2 2 2 2
3 2 2 2 2 2
…
// 총 테스트 케이스의 개수 T = 10
// 첫 번째 테스트 케이스, N = 6, X = 2 본문 예제
// N * N 지형의 높이
//
//
//
//
//
// 두 번째 테스트 케이스, N = 6, X = 4
// N * N 지형의 높이
//
//
//
//
//
// 나머지는 sample_input.txt 참조
sample_input.txt
출력
#1 7
#2 4
#3 11
#4 11
#5 15
#6 4
#7 4
#8 1
#9 5
#10 8
sample_output.txt
*/

// 1. 두지역의 높이 차이가 2이상 나는 경우
// 2. 두 지역의 높이 차이가 1만큼 나는 경우
// 3. 두 지역의 높이 차이가 나지않는 경우
/*
#include <iostream>
using namespace std;
const int MAX_N = 20;

int map[MAX_N][MAX_N];
int height[MAX_N];
int n, x;

int abs(int a) {
	return a > 0 ? a : -a;
}

bool isFlatBetween(int s, int e) {
	// height 배열에서 index s부터 e까지 지역이 평평한지
	if (s < 0 || n <= e) {
		// 경계 값을 넘은 경우 false
		return false;
	}
	
	for (int i = s; i < e; ++i)
		if (height[i] != height[i + 1])
			return false;
	return true;
}

bool canRunaway() {
	// height 배열의 저장되어 있는 지역이 활주로가 될 수 있는가

	// case 1 두 지역으 ㅣ높이 차이가 2 이상 나는 경우
	for (int i = 0; i < n - 1; ++i) {
		if (abs(height[i] - height[i + 1]) >= 2)
			return false;
	}

	bool* upSlope = new bool[n];
	// 오른쪽으로 올라가는 경사로가 배치되어있는지 확인
	bool* downSlope = new bool[n];
	// 오른쪽으로 내려가는 경사로가 배치되어있는지 확인

	for (int i = 0; i < n; ++i)
		upSlope[i] = downSlope[i] = false;
	// case 2 높이 차이가 1 인데 경사로를 설치할 수 없는 경우
	for (int i = 0; i < n - 1; ++i)
		if (height[i] + 1 == height[i + 1]) {
			// i번째 지형이 낮은 경우
			// 경사로가 i번째부터 왼쪽으로 x개 설치되므로 시작은 i - x + 1, 끝은 i가 됨
			int s = i - x + 1;
			int e = i;

			if (isFlatBetween(s, e))
				for (int j = s; j <= e; ++j)
					upSlope[j] = true;
			else return false;
		}
		else if (height[i] - 1 == height[i + 1]) {
			// i번째 지형이 높은 경우
			int s = i + 1;
			int e = i + x;

			if (isFlatBetween(s, e))
				for (int j = s; j <= e; ++j)
					downSlope[j] = true;
			else return false;
		}

	// case 3 경사로를 설치한 위치가 겹치는 경우
	for (int i = 0; i < n; ++i)
		if (upSlope[i] && downSlope[i])return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int t = 1; t < T + 1; ++t) {
		cin >> n >> x;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> map[i][j];

		int rowCnt = 0, colCnt = 0;

		for (int i = 0; i < n; ++i) {
			// 각각 행이 활주로가 될수있는지 확인
			for (int j = 0; j < n; ++j) {
				// i값인 행 값이 고정된 상태에서 j값인 열값을 변화시키며 저장
				height[j] = map[i][j];
			}
			if (canRunaway())++rowCnt;
		}

		for (int i = 0; i < n; ++i) {
			// 각각 열이 활주로가 될수있는지 확인
			for (int j = 0; j < n; ++j)
				height[j] = map[j][i];
			if (canRunaway())++colCnt;
		}

		cout << "#" << t << " " << rowCnt + colCnt << "\n";
	}
	return 0;
}
*/