/*
8.1 재귀 호출을 이용한 이항 계수의 계산

int bino(int n, int r) {
	//기저 사례 n = r (모든 원소를 다 고르는 경우) 혹은 r=0(고를 원소가 없는 경우)
	if (r == 0 || n == r)return 1;
	return bino(n - 1, r - 1) + bino(n - 1, r);
}


8.2 메모리제이션 이용한 이항 계수 연산

// -1로 초기화해 둔다.
int cache[30][30];
int bino2(int n, int r) {
	//기저 사례
	if (r == 0 || n == r)return 1;
	//-1이 아니라면 한번 계산 했던 값이니 곧장 반환
	if (cache[n][r] != -1)
		return cache[n][r];
	//직접 계산한 뒤 배열에 저장
	return cache[n][r] = bino2(n - 1, r - 1) + bino2(n - 1, r);
}

//8.3 메모리제이션의 사용 예
//전부 -1로 초기화해둔다.
int cache[2500][2500];
//a와 b는 각각[0, 2500) 구간 안의 정수
//반환 값은 항상 int형 안에 들어가는 음이 아닌 정수
int someObscureFunction(int a, int b) {
	//기저 사례를 처음에 처리한다
	if (...) return ...;
	//(a, b)에 대한 답을 구한적 있으면 곧장 반환
	int& ret = cache[a][b];
	if (ret != -1) return ret;
	//여기에서 답을 계산한다.
	...
		return ret;
}

int main() {
	//memset()을 이용해 cache 배열을 초기화한다.
	memset(cache, -1, sizeof(cache));
}
*/