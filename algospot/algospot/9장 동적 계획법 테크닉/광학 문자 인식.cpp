// 9.4 광학 문자 인식 OCR (상)
// https://algospot.com/judge/problem/read/OCR
/*
#include <iostream>
#include <string>
#include <cmath> //log
using namespace std;

//문장을 구성하는 단어의 개수, 단어의 수, 처리할 문장의 수
int composition, wordNum, sentenceNum;
//분류기가 반환한 문장, 단어 번호로 변환되어 있음
int classified[100];
//Begin[i] i번째 단어가 첫 단어로 나올 확률
double Begin[501];
//rightAfter[i][j]=i 단어 이후에 j 단어가 나올 확률의 로그값
double rightAfter[501][501];
//missMatched[i][j]=i 단어가 j 단어로 분류될 확률의 로그값
double missMatched[501][501];
int choice[102][502];
double cache[102][502]; //1로 초기화
string word[501]; //입력받은 단어들의 목록

//Q[segment] 이후를 채워서 얻을 수 있는 최대 g() 곱의 로그값 반환
//Q[segment-1]==previousMatch라 가정
double recognize(int segment, int previousMatch)
{
	if (segment == composition)
		return 0;
	double& result = cache[segment][previousMatch];
	if (result != 1.0)
		return result;
	result = -1e200; //log(0)=음의 무한대
	int& choose = choice[segment][previousMatch];
	//classified[segment]에 대응되는 단어
	for (int thisMatch = 1; thisMatch <= wordNum; thisMatch++)
	{
		//문장 R이 주어질 때 조건부확률 P(Q|R)을 최대화하는 원문 Q를 찾는 알고리즘
		//P(Q|R)=(P(R|Q)*P(Q))/P(R) => 여기서 P(Q|R)이란 P(Q∩R)/P(R)
		//P(R|Q)는 원문이 Q일 때 분류기가 R을 반환할 확률: 따라서 P(R|Q)=∏[M(Q[i], R[i])] => 여기서 M(a, b)=단어 a를 b로 분류할 확률
		//P(Q)=Begin(Q[0])*∏[rightAfter(Q[i-1], Q[i])]
		//f(Q)=P(R|Q)*P(Q)=∏[missMatched(Q[i], R[i])*rightAfter(Q[i-1], Q[i])]=∏g(Q[i])
		//g(thisMatch)=rightAfter(previousMatch, thisMatch)*missMatched(thisMatch, R[segment])
		double candidate = rightAfter[previousMatch][thisMatch] + missMatched[thisMatch][classified[segment]] + recognize(segment + 1, thisMatch);

		if (result < candidate)
		{
			result = candidate;
			choose = thisMatch;
		}
	}
	return result;
}



//광학 문자 인식 문제의 실제 답 계산하기
string reconstruct(int segment, int previousMatch)
{
	int choose = choice[segment][previousMatch];
	string result = word[choose];
	if (segment < composition - 1)
		result = result + " " + reconstruct(segment + 1, choose);
	return result;
}

//캐시 초기화
void initialize()
{
	for (int i = 0; i < composition; i++)
		for (int j = 0; j <= wordNum; j++)
			cache[i][j] = 1.0;
}

int main(void)
{
	cin >> wordNum >> sentenceNum;
	if (wordNum < 1 || wordNum>500 || sentenceNum < 1 || sentenceNum>100)
		exit(-1);
	for (int i = 1; i <= wordNum; i++)
		cin >> word[i];
	for (int i = 1; i <= wordNum; i++)
	{
		cin >> Begin[i];
		Begin[i] = log(Begin[i]); //log로 변환
	}
	for (int i = 0; i <= wordNum; i++)
		for (int j = 1; j <= wordNum; j++)
		{
			//책의 트릭을 이용하여 시작단어를 [0][j] 인덱스에 저장
			//즉, Q[0]가 항상 시작단어라고 지정
			//그렇게 하면 P(Q)=∏(rightAfter(Q[i-1], Q[i])) => Begin(Q[0])*∏(rightAfter(Q[i-1], Q[i]))보다 간단해졌다
			if (i == 0)
				rightAfter[i][j] = Begin[j];
			else
			{
				cin >> rightAfter[i][j];
				rightAfter[i][j] = log(rightAfter[i][j]);
			}
		}
	for (int i = 1; i <= wordNum; i++)
		for (int j = 1; j <= wordNum; j++)
		{
			cin >> missMatched[i][j];
			missMatched[i][j] = log(missMatched[i][j]);
		}
	for (int i = 0; i < sentenceNum; i++)
	{
		cin >> composition;
		if (composition < 1 || composition>100)
			exit(-1);
		initialize();
		for (int i = 0; i < composition; i++)
		{
			string input;
			cin >> input;
			for (int j = 1; j <= wordNum; j++)
				if (input == word[j])
				{
					classified[i] = j;
					break;
				}
		}
		recognize(0, 0);
		cout << reconstruct(0, 0) << endl;
	}
	return 0;
}
*/