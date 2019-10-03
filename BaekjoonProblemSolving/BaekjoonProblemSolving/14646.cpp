/*
https://www.acmicpc.net/problem/14646

&Title
14646번 - 욱제는 결정장애야!!

&Question
욱제는 매일 세계사에 한 획을 그을만한 심각한 비결정론적 
문제에 직면한다. 그렇다. 바로 저녁메뉴를 고르는 것이다. 매일 반복되는 
중대한 선택에 지친 욱제는 N일 동안의 저녁메뉴를 미리 골라두기로 
했다.욱제는 N개의 중복되지 않는 메뉴들과 커다란 돌림판을 준비했다. 그러고는 
돌림판을 N개의 칸으로 균일하게 나눈 뒤, N개의 메뉴를 각각 
한 번씩 써넣었다. 하나의 칸에는 정확히 하나의 메뉴만 적히며, 
하나의 메뉴는 정확히 하나의 칸에만 적힌다.'돌려돌려~ 돌림판~'돌림판을 돌리고 돌림판에 
걸린 칸을 확인한다.걸린 칸에 스티커가 붙어있지 않다면, 스티커를 하나 
붙인다.걸린 칸에 스티커가 붙어있다면, 식단표에 해당하는 메뉴를 적어넣고 그 
칸을 제거한다. (스티커도 떼어낸다) 욱제의 돌림판은 특별해서 어떤 칸이 
제거되면 다음부터는 그 칸에 절대로 멈추지 않는 마법이 걸려있다. 
(!)모든 칸이 제거될 때 까지 (0, 1, 2)을 반복한다.따라서 
욱제는 2N번 돌림판을 돌리면 N일 동안의 메뉴를 모두 정할 
수 있게 된다! 욱제가 돌림판을 돌린 결과가 순서대로 주어진다. 
돌림판에는 최대 몇 개의 스티커가 붙어있을 수 있을까? 

&Input
첫째 줄에 메뉴의 개수 N이 주어진다. (1 <= 
N <= 100,000)둘째 줄에 욱제가 뽑은 순서대로 해당 칸에 
적힌 메뉴 번호가 주어진다. 메뉴는 1부터 N까지의 자연수로 주어진다. 
(1 <= 메뉴 <= N) 

&Output
돌림판에 붙어있을 수 있는 스티커의 최대 개수를 출력한다. 


&Example
-input
3
1 3 3 2 1 2

-output
2

-input
5
1 1 2 2 3 3 4 4 5 5

-output
1


*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> wheel;
bool selected[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int result = 0;
	int erase = 0;
	for (int i = 0; i < 2 * n; ++i) {
		int num;
		cin >> num;
		if (!selected[num]) {
			wheel.push_back(num);
			selected[num] = true;
		}
		else
			erase++;
		result = max(result, (int)wheel.size() - erase);
	}
	cout << result << endl;
	return 0;
}
*/