/*
https://www.acmicpc.net/problem/3078

&Title
3078번 - 좋은 친구

&Question
상근이는 환갑을 바라보던 나이에 수능 시험을 다시보고 교대에 
입학했고, 초등학교 선생님으로 취직했다.상근: 요즘 애들은 친구를 사귀지 않나봐. 
내가 앞에서 보고 있으면, 친구가 있는 학생이 별로 없는 
것 같아.??: 오빠! 오빠는 말콤의 친구와 성적이라는 책 안 
읽어 봤어? 이 책에는 성적과 친구가 무슨 관계가 있는지 
나와. 요즘 애들은 친구를 사귀기 전에 먼저 그 친구의 
반 등수를 살펴봐. 말콤은 이 연구를 하기 위해서 6년동안 
초등학교에서 선생님으로 위장 했었지. 하지만, 6년이라는 시간을 초등학교에서 보냈지만, 
그 사람은 결국 결론을 얻지 못했어.상근: 근데???: 내 말 
아직 안끝났어. 말콤이 어느 날 자신이 초등학생이 되어 학교를 
활보하는 꿈을 꾸었어. 근데 잠을 깨고 나니 내가 꿈을 
꾸고 초등학생이 된건지, 아니면 초등학생이 꿈을 꾸고 지금의 내가 
되어있는지를 모르겠는거야. 그래서 말콤은 상식적인 사고 방식에 큰 의문을 
가졌지. 그 때 말콤은 깨달았던거야. 초등학교 친구는 부질없구나. 그제서야 
알게된거야. 모든 학생은 자신과 반 등수의 차이가 K를 넘으면 
친구가 아니라는거.상근: 아? 근데 K는 어떻게 구해???: K는 문제에서 
주어지지. 근데, 더 중요한 사실이 있어. 친구와 좋은 친구의 
차이야. 말콤이 친구와 성적을 쓰고 2년 뒤에 낸 책인 
좋은 친구라는 책에는 좋은 친구는 이름의 길이가 같아야 된다는 
말이 나와.상근: 아! 그럼 난 오늘 집에 가서 우리 
반에 좋은 친구가 몇 쌍이나 있는지 구해봐야 겠어!상근이네 반의 
N명 학생들의 이름이 성적순으로 주어졌을 때, 좋은 친구가 몇 
쌍이나 있는지 구하는 프로그램을 작성하시오. 좋은 친구는 등수의 차이가 
K보다 작거나 같으면서 이름의 길이가 같은 친구이다. 

&Input
첫째 줄에 N과 K가 주어진다. (3 ≤ N 
≤ 300,000, 1 ≤ K ≤ N) 다음 N개 
줄에는 상근이네 반 학생의 이름이 성적순으로 주어진다. 이름은 알파벳 
대문자로 이루어져 있고, 2글자 ~ 20글자이다. 

&Output
첫째 줄에 좋은 친구가 몇 쌍이 있는지 출력한다. 


&Example
-input
6 3
CYNTHIA
LLOYD
STEVIE
KEVIN
MALCOLM
DABNEY

-output
2


*/

/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, k; // 3~300,000 학생수, 격차 
string s;
vector<int> students[21]; // 이름길이에 따라 성적순위 넣어줌
long long best_cnt = 0; // 최고의 친구 수
long long tmp = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		students[s.length()].push_back(i);
	}

	for (int i = 2; i <= 20; ++i) {
		int idxLen = students[i].size();
		int left = 0, right = 0;

		if (!idxLen)continue;

		// left가 해당큐의 크기에 도달할때까지 돔
		while (left < idxLen - 1) {
			// right가 끝에 도달하지 않고, 좋은친구에 해당 될 때
			if (right < idxLen - 1 && students[i][right] - students[i][left] <= k) {
				// right를 한칸 옮겨주고 ++tmp
				++right;
				++tmp;

				// right를 한칸 옮겼을 때 student[i][right] - q[i][left] == k 일 때
				if (students[i][right] - students[i][left] == k) {
					// 모아둔 tmp를 더해주고 left를 한칸 옮기기에 tmp는 하나 빼줌
					best_cnt += tmp--;
					++left;
				}
			}
			else { // 외의 경우
				// students[i][right] - students[i][left] <= k 일때만 더해준다
				if (students[i][right] - students[i][left] <= k)
					best_cnt += tmp;
				// 그게 아니라면 tmp-1을 한 값을 더해준다.
				else
					best_cnt += tmp - 1;
				--tmp;
				++left;
			}
		}
		// 해당하는 큐가 끝나면 tmp = 0 으로 초기화
		tmp = 0;
	}

	cout << best_cnt << endl;
	return 0;
}
*/