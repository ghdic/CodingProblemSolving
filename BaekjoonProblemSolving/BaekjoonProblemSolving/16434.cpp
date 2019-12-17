/*
https://www.acmicpc.net/problem/16434

&Title
16434번 - 드래곤 앤 던전

&Question
용사는 공주를 구하기 위해 무시무시한 용이 있는 던전으로 
향하기로 하였습니다. 우선 용사는 용사 자신과 던전을 분석하였습니다.용사에게는 세 
종류의 능력치가 있습니다. HMaxHP : 용사의 최대 생명력입니다. 이 
값은 1이상이어야 하며 던전에 들어간 이후로 변하지 않습니다.HCurHP : 
현재 용사의 생명력입니다. 던전에 들어가기 전 이 값은 용사의 
최대 생명력 HMaxHP와 같습니다. 이 값은 HMaxHP보다 커질 수 
없습니다.HATK : 용사의 공격력입니다.던전은 총 N개의 방으로 이루어져 있고 
i번째 방을 통해서만 i+1번째 방으로 이동 할 수 있습니다. 
방에는 포션이 있거나 몬스터가 있는데 몬스터가 있을 경우 몬스터를 
쓰러트려야지 다음방으로 이동 할 수 있습니다. N번째 방에는 공주와 
용이 있고, 용을 무찌르면 공주를 구할 수 있습니다.몬스터가 있는 
방에 올 경우 다음과 같이 전투가 진행됩니다.용사의 공격력 HATK만큼 
몬스터의 생명력을 깎습니다.몬스터의 생명력이 0 이하이면 전투가 종료되고 용사는 
다음 방으로 이동합니다.몬스터의 공격력만큼 용사의 생명력 HCurHP를 깎습니다.용사의 생명력이 
0 이하이면 전투가 종료되고 용사는 사망합니다.다시 1부터 진행합니다.포션이 있는 
방에 올 경우 포션을 마셔서 현재 용사의 생명력 HCurHP가 
일정량 회복되고 공격력 HATK도 일정량만큼 증가됩니다. 회복된 생명력이 최대 
생명력 HMaxHP보다 큰 경우 용사의 현재 생명력 HCurHP가 최대 
생명력 HMaxHP와 같아집니다.용사는 던전으로 향하기 전에 만반의 준비를 하고 
있습니다. 용사는 수련을 하면 최대 생명력 HMaxHP를 늘릴 수 
있는데 얼마나 수련해야 할지 고민입니다.용사는 N번 방에 있는 용을 
쓰러트리기 위한 최소의 HMaxHP를 여러분이 계산해주면 좋겠다고 합니다. 

&Input
첫 번째 줄에 방의 개수 N (1 ≤ 
N ≤ 123,456) 과 용사의 초기 공격력 HATK (1 
≤ HATK ≤ 1,000,000) 가 주어집니다.i+1번째 줄엔 i번째 방의 
정보를 나타내는 세개의 정수 ti, ai, hi (ti ∈ 
{1, 2}, 1 ≤ ai, hi ≤ 1,000,000) 가 
주어집니다. ti가 1인 경우 공격력이 ai이고 생명력이 hi인 몬스터가 
있음을 나타내고, ti가 2인 경우 용사의 공격력 HATK를 ai만큼 
증가시켜주고 용사의 현재 생명력 HCurHP를 hi만큼 회복시켜주는 포션이 있음을 
나타냅니다. 

&Output
용사가 N번째 방에 있는 용을 쓰러트리기 위한 최소의 
HMaxHP를 출력합니다. 

&Example
-input
3 3
1 1 20
2 3 10
1 3 100
-output
49
-input
1 1
1 1000000 1000000
-output
999999000001

*/

/*
#include <iostream>
#include <algorithm>
using namespace std;

struct info {
	int t, a, h;
};
int n, attack;
info map[123456];

bool canRescue(long long int maxHp){
	long long int curHp = maxHp, curAttack = attack;

	for(int i = 0; i < n; ++i) {
		if (map[i].t == 1) {
			if ((map[i].h - 1) / curAttack > (curHp - 1) / map[i].a)
				return false;
			curHp -= (map[i].h - 1) / curAttack * map[i].a;
		}
		else {
			// 용사의 공격력을 높여주고 회복
			curAttack += map[i].a;
			curHp = min(maxHp, curHp + map[i].h);
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> attack;
	for (int i = 0; i < n; ++i) {
		cin >> map[i].t >> map[i].a >> map[i].h;
	}
	long long int l = 1, r = 1e18;

	while (l <= r) {
		long long int mid = (l + r) / 2;
		if (canRescue(mid)) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << l << endl;
	return 0;
}
*/

/*
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	long long n, attack;
	long long cur = 0, mx = 0;
	cin >> n >> attack;

	while (n--) {
		int t, a, h;
		cin >> t >> a >> h;
		if (t == 1) {
			long long damage = a * (ceil((double)h / attack) - 1);
			if (damage > cur)mx += damage - cur, cur = 0;
			else cur -= damage;
		}
		else {
			attack += a;
			cur += h;
			if (cur > mx)cur = mx;
		}
	}
	cout << mx + 1 << endl;
}
*/