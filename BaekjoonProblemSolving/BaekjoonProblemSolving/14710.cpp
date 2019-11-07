/*
https://www.acmicpc.net/problem/14710

&Title
14710번 - 고장난 시계

&Question
논산훈련소에 간 불쌍한 상언이는 첫날 훈련소에서 다쳐 먼 
거리를 이동할 때 버스를 타고 다녔다. 어느 날 버스를 
탄 상언이는 훈련소 버스 앞에 붙어있는 아날로그 시계를 보게 
되었는데, 시계가 이상해 보인다는 사실을 관찰했다. 일반적인 시계라면 가리킬 
수 없는 시간을 가리키고 있던 것이다. 이 시계를 본 
상언이는 어떤 시계의 시침과 분침이 가리키는 방향을 보면 그 
시계가 고장 났는지 정상인지 판단할 수 있을 거라 생각했지만, 
귀찮아서 생각을 그만두기로 했다. 상언이를 대신해서 시계가 정상인지 이상한지 
알려주자.정상적인 시계는 12시 정각에 시침과 분침이 둘 다 정확히 
12시 방향을 가리키며, 시침은 12시간에 한 바퀴, 분침은 1시간에 
한 바퀴를 시계 방향으로 등속도로 움직인다. 

&Input
첫 번째 줄에 시침의 각도 θ1, 분침의 각도 
θ2 (0 ≤ θ1, θ2 ≤ 359)가 정수로 주어진다. 
시침, 분침의 각도는 12시 방향을 기준으로 시계방향으로 잰다. 예를 
들어 3시 방향은 90, 9시 방향은 270 이다. 

&Output
첫 번째 줄에 시계의 각도가 정상인 경우 O를, 
그렇지 않을 경우 X를 출력한다. 

&Example
-input
180 0

-output
O

-input
0 180

-output
X


*/

/*
#include <iostream>
using namespace std;

int h, m;
int main() {
	ios::sync_with_stdio(false);
	cin >> h >> m;
	int k = h % 30;
	if (k * 12 == m)
		cout << "O" << endl;
	else
		cout << "X" << endl;
	return 0;
}
*/