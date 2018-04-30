/*
https://www.acmicpc.net/problem/2448

&Title
2448번 - 별찍기 - 11

&Question
예제를 보고 별찍는 규칙을 유추한 뒤에 별을 찍어
보세요.

&Input
첫째 줄에 N이 주어진다. N은 항상 3*2^k 수이다.
(3, 6, 12, 24, 48, ...) (k<=10)

&Output
첫째 줄부터 N번째 줄까지 별을 출력한다.

&Example
-input
24
-output
					   *
					  * *
					 *****
					*     *
				   * *   * *
				  ***** *****
				 *           *
				* *         * *
			   *****       *****
			  *     *     *     *
			 * *   * *   * *   * *
			***** ***** ***** *****
		   *                       *
		  * *                     * *
		 *****                   *****
		*     *                 *     *
	   * *   * *               * *   * *
	  ***** *****             ***** *****
	 *           *           *           *
	* *         * *         * *         * *
   *****       *****       *****       *****
  *     *     *     *     *     *     *     *
 * *   * *   * *   * *   * *   * *   * *   * *
***** ***** ***** ***** ***** ***** ***** *****

*/

/*
#include <iostream>
void star(int n, int x, int y);

using namespace std;

char arr[3072][6144];

int main() {
	int n, i, j;

	cin >> n;
	//배열의 쵝화
	//각 높이의 행의 요소들을 공백으로, 행의 끝부분만 null로 초기화한다.
	for (i = 0; i < n; i++) {
		for (j = 0; j < 2 * n; j++) {
			if (j == 2 * n - 1)arr[i][j] = '\0';
			else arr[i][j] = ' ';
		}
	}
	star(n, n - 1, 0); //삼각형의 높이와, 삼각형 맨 위 꼭지점 좌표를 매개변수로 넘긴다.

	//삼각형 출력
	for (i = 0; i < n; i++) {
		for (j = 0; j < 2 * n - 1; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
	return 0;
}

void star(int n, int x, int y) {
	if (n == 3) {//높이가 3이라면 별을 만들어 출력한다.
		//별을 그린다.
		arr[y][x] = '*';
		arr[y + 1][x - 1] = '*';
		arr[y + 1][x + 1] = '*';
		arr[y + 2][x - 2] = '*';
		arr[y + 2][x - 1] = '*';
		arr[y + 2][x] = '*';
		arr[y + 2][x + 1] = '*';
		arr[y + 2][x + 2] = '*';
		return;
	}
	star(n / 2, x, y); //위의 삼각형 높이와 맨 꼭대기 좌표를 보낸다.
	star(n / 2, x - (n / 2), y + (n / 2)); //왼족 하단 삼각형 높이와 맨 위 꼭대기 좌표를 보낸다.
	star(n / 2, x + (n / 2), y + (n / 2)); //오른쪽 하단 삼각형 높이와 맨 위 꼭대기 좌표를 보낸다.
}
*/

/*
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	string *arr = new string[n];

	arr[0] = "  *  ";
	arr[1] = " * * ";
	arr[2] = "*****";


	for (int i = 1; 3 * (int)pow(2, i) <= n; i++) {
		int border = 3 * (int)pow(2, i);
		int half = border / 2;

		//아래 삼각형을 만들어준다.
		for (int j = border - 1; j >= half; j--) {
			arr[j] = arr[j - half] + " " + arr[j - half];
		}

		//위의 삼각형을 밀어준다.
		string space = "";
		while (space.length() < half) {
			space += " ";
		}
		for (int j = half - 1; j >= 0; j--) {
			arr[j] = space + arr[j] + space;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}
}
*/