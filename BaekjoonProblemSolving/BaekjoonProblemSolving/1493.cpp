/*
https://www.acmicpc.net/problem/1493

&Title
1493번 - 박스 채우기

&Question
세준이는 length * width * height 크기의 박스를 
가지고 있다. 그리고 세준이는 이 박스를 큐브를 이용해서 채우려고 
한다. 큐브는 정육면체 모양이며, 한 변의 길이는 2의 제곱꼴이다. 
(1*1*1, 2*2*2, 4*4*4, 8*8*8, ...)세준이가 가지고 있는 박스의 종류와 
큐브의 종류와 개수가 주어졌을 때, 박스를 채우는데 필요한 큐브의 
최소 개수를 출력하는 프로그램을 작성하시오. 

&Input
첫째 줄에 length width height가 주어진다. 이 모든 
값은 10^6보다 작거나 같은 자연수이다. 둘째 줄에 세준이가 가지고 
있는 큐브의 종류의 개수 N이 주어진다. N은 20보다 작거나 
같은 자연수이다. 셋째 줄부터 총 N개의 줄에 큐브의 종류 
개수 순서대로 주어진다. 큐브의 종류는 한 변의 길이를 나타낼 
때 쓰는 2^i에서 i이다. 개수는 10^6보다 작거나 같은 음이아닌 
정수이다. 

&Output
첫째 줄에 필요한 큐브의 개수의 최소값을 출력한다. 만약 
채울 수 없다면 -1을 출력한다. 

&Example
-input
4 4 8
3
0 10
1 10
2 1

-output
9


*/

/*
//원리는 큰박스부터 채워나가며 최종적으로 박스가 다 채워졌는지 안채워졌는지 확인
//3차원상으로 생각하면 어렵지만, 2차원 단면 채우기 한다고 생각하면 이해하기 더 쉬움
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int ary[20] = { }, ans = 0, impossible = 0;	//ans : 답, impossible : 다채워질수있는가 없는가
void divide(int L, int W, int H)
{
	if (impossible) return;
	int m = 2, p = 0, num, lwh[3];	//m은 밑, p는 지수
	lwh[0] = L, lwh[1] = W, lwh[2] = H;
	sort(lwh, lwh + 3);
	while (pow(m, p + 1) <= lwh[0])	//L,W,H중 가장 작은걸 기준으로
	{
		p++;	//들어갈 수 있는 최대 크기의 상자 지수를 구한다.
	}
	while (ary[p] == 0 && p >= 0)	//p타입의 상자가 0개이거나 p가 음수일때 --함
	{
		p--;
	}
	if (p < 0)	//p가 음수이면 더이상 입력 받은 인수가 없으므로 불가능 판정을 내림
	{
		impossible = 1;	//전체 상자 크기를 만족하면 재귀문이 더이상 돌아가지 않기때문에 impossible은 되지않음
		return;
	}
	num = pow(m, p);	//넣을 상자 크기
	m = min(lwh[2] / num, ary[p]);	//가장큰 변 기준으로 상자크기로 나눳을때 들어갈수 있는
									//개수 vs 현재 갖고 있는 해당 타입의 상자 개수 최소값
	ary[p] -= m;	//쓴 상자 만큼 뺌
	ans += m;
	if (lwh[2] - m * num != 0) divide(num, num, lwh[2] - m * num);	//상자를 넣고 나머지 부분에 대해서 재귀문을 돌린다.
	if (lwh[0] - num != 0) divide(lwh[0] - num, num, lwh[2]);
	if (lwh[1] - num != 0) divide(lwh[0], lwh[1] - num, lwh[2]);
}

int main()
{
	int L, W, H, N, a, b;
	scanf("%d %d %d %d", &L, &W, &H, &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d%d", &a, &b);
		ary[a] = b;//pair대신 인자 값을 종류, 값을 개수로 씀
	}
	divide(L, W, H);
	if (impossible) printf("-1\n");
	else printf("%d\n", ans);

	return 0;
}
*/

/*
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int N, L, W, H;
	pair <int, int> p[21];
	cin >> L >> W >> H;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p[i].first >> p[i].second;
	}
	sort(p, p + N);
	long long cnt = 0, ans = 0, temp;//L,W,H최댓값이 10^6이므로 long long 사용
	p[N] = make_pair(0, 0);	//처음에 8배하는 조건문 탈출하기 위한 초기화
	for (int i = N - 1; i >= 0; i--) {//큰놈부터 끼워 넣음
		for(int j=p[i+1].first;j>p[i].first;j--)
			cnt <<= 3;	//큰놈부터 한다 가정하였으므로 2^3을 곱해줌


		temp = min((long long)p[i].second,	// 왼쪽 인자 갖고있는 큐브 개수, 오른쪽 인자 빈공간을 최대한 메꿀수 있는 큐브 개수
			(long long)(L >> p[i].first)*(W >> p[i].first)*(H >> p[i].first) - cnt);
		//각 L,W,H에 대해 2^p[i].first 로 나눠줌

		cnt += temp, ans += temp;//temp는 해당 종류의 선택 개수
		if (i == 0) {//p[0].first가 0이 아닐경우 나머지 처리
			for (int j = p[i].first; j > 0; j--)
				cnt <<= 3;
		}
	}
	long long result = cnt == (L * W * H) ? ans : -1;
	cout << result << endl;
	return 0;
}
*/