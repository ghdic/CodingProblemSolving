/*
https://www.acmicpc.net/problem/11066

&Title
11066번 - 파일 합치기

&Question
소설가인 김대전은 소설을 여러 장(chapter)으로 나누어 쓰는데, 각 
장은 각각 다른 파일에 저장하곤 한다. 소설의 모든 장을 
쓰고 나서는 각 장이 쓰여진 파일을 합쳐서 최종적으로 소설의 
완성본이 들어있는 한 개의 파일을 만든다. 이 과정에서 두 
개의 파일을 합쳐서 하나의 임시파일을 만들고, 이 임시파일이나 원래의 
파일을 계속 두 개씩 합쳐서 소설의 여러 장들이 연속이 
되도록 파일을 합쳐나가고, 최종적으로는 하나의 파일로 합친다. 두 개의 
파일을 합칠 때 필요한 비용(시간 등)이 두 파일 크기의 
합이라고 가정할 때, 최종적인 한 개의 파일을 완성하는데 필요한 
비용의 총 합을 계산하시오.예를 들어, C1, C2, C3, C4가 
연속적인 네 개의 장을 수록하고 있는 파일이고, 파일 크기가 
각각 40, 30, 30, 50 이라고 하자. 이 파일들을 
합치는 과정에서, 먼저 C2와 C3를 합쳐서 임시파일 X1을 만든다. 
이때 비용 60이 필요하다. 그 다음으로 C1과 X1을 합쳐 
임시파일 X2를 만들면 비용 100이 필요하다. 최종적으로 X2와 C4를 
합쳐 최종파일을 만들면 비용 150이 필요하다. 따라서, 최종의 한 
파일을 만드는데 필요한 비용의 합은 60+100+150=310 이다. 다른 방법으로 
파일을 합치면 비용을 줄일 수 있다. 먼저 C1과 C2를 
합쳐 임시파일 Y1을 만들고, C3와 C4를 합쳐 임시파일 Y2를 
만들고, 최종적으로 Y1과 Y2를 합쳐 최종파일을 만들 수 있다. 
이때 필요한 총 비용은 70+80+150=300 이다.소설의 각 장들이 수록되어 
있는 파일의 크기가 주어졌을 때, 이 파일들을 하나의 파일로 
합칠 때 필요한 최소비용을 계산하는 프로그램을 작성하시오. 

&Input
프로그램은 표준 입력에서 입력 데이터를 받는다. 프로그램의 입력은 
T개의 테스트 데이터로 이루어져 있는데, T는 입력의 맨 첫 
줄에 주어진다.각 테스트 데이터는 두 개의 행으로 주어지는데, 첫 
행에는 소설을 구성하는 장의 수를 나타내는 양의 정수 K 
(3 ≤ K ≤ 500)가 주어진다. 두 번째 행에는 
1장부터 K장까지 수록한 파일의 크기를 나타내는 양의 정수 K개가 
주어진다. 파일의 크기는 10,000을 초과하지 않는다. 

&Output
프로그램은 표준 출력에 출력한다. 각 테스트 데이터마다 정확히 
한 행에 출력하는데, 모든 장을 합치는데 필요한 최소비용을 출력한다. 


&Example
-input
2
4
40 30 30 50
15
1 21 3 4 5 35 5 4 3 5 98 21 14 17 32

-output
300
864


*/
/*
//못풀겠어서 그냥 봤음 =-= 쉣
//https://js1jj2sk3.tistory.com/3
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int cost[501]; // 비용 입력 받기
int dp[501][501]; // dp[i][j] : i번째 장부터 j번째 장까지 합치는데 최소비용
// dp[i][j] = min(i<=k<j) {dp[i][k] + dp[k+1][j]} + psum[i][j] (psum[i][j]는 cost[i][j]의 i부터 j까지의 부분합)
int sum[501];
int main() {

	int T;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		for (int i = 1; i <= N; ++i) {
			cin >> cost[i];
			sum[i] = sum[i - 1] + cost[i];
		}

		for (int i = 1; i <= N; ++i) { // 간격 1 ~ N까지 반복
			for (int j = 1; j + i <= N; ++j) {
				int temp = i + j;
				dp[j][temp] = INT_MAX;

				for (int mid = j; mid < temp; ++mid) // j를 기준으로 부분함합을 구함
					dp[j][temp] = min(dp[j][temp], dp[j][mid] + dp[mid + 1][temp] + sum[temp] - sum[j - 1]);
				// j ~i + j 만큼 반복을 돌릴껀데
				// j ~j + a까지, j + a + 1 ~i + j까지 읽은수
				// j ~i + j 더했을때 비용
			}
		}
		cout << dp[1][N] << "\n";
	}
	return 0;
}
*/

/*
// Knuth's optimization 적용
// dp[i][j] = min(i<k<j) {dp[i][k] + dp[k][j]} + psum[i][j] -> i+1부터 j까지 최소합비용
// 시간복잡도가 n^3 -> n^2
#include <cstdio>

int N;
int novel[501];
int psum[501];
int num[501][501] = {};
int dp[501][501] = {};
int main() {
	int T;
	for (scanf("%d", &T); T--;) {
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i)
			scanf("%d", &novel[i]), psum[i] = psum[i - 1] + novel[i];
		for (int i = 1; i <= N; ++i) {
			num[i - 1][i] = i;
		}
		for (int d = 2; d <= N; ++d) {
			for (int i = 0; i + d <= N; ++i) {
				int j = i + d;
				dp[i][j] = 2e9;
				for (int k = num[i][j - 1]; k <= num[i + 1][j]; ++k) {
					int v = dp[i][k] + dp[k][j] + psum[j] - psum[i];
					if (dp[i][j] > v)
						dp[i][j] = v, num[i][j] = k;
				}
			}
		}
		printf("%d\n", dp[0][N]);
	}
}
*/

/*
// cubelover님 소스
#include<cstdio>
#include<queue>

int a[555];
int d[555][555];
int v[555][555];

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		for(i=1;i<=n;i+
		int i,j,k,n;
		scanf("%d",&n);+)
		{
			scanf("%d",&a[i]);
			a[i]+=a[i-1];
			v[i-1][i]=i;
		}
		for(i=2;i<=n;i++)for(j=i;j<=n;j++)
		{
			d[j-i][j]=1e9;
			for(k=v[j-i][j-1];k<=v[j-i+1][j];k++)if(d[j-i][k]+d[k][j]<d[j-i][j])
			{
				d[j-i][j]=d[j-i][k]+d[k][j];
				v[j-i][j]=k;
			}
			d[j-i][j]+=a[j]-a[j-i];
		}
		printf("%d\n",d[0][n]);
	}
}


*/