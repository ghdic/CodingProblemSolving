////https://algospot.com/judge/problem/read/WILDCARD
//
///*
//
//와일드 카드는 다양한 운영체제에서 파일 이름의 일부만으로 파일 이름을 지정하는 방법이다.
//와일드카드 패턴을 앞에서 한 글자씩 파일명과 비교해서 모든 글자가 일치했을 때
//해당 와일드카드 패턴이 파일명과 대응된다고 말한다.
//단, 와일드카드 패턴에 포함된 ?는 어떤 글자와도 대응된다고 가정하며,
//*는 0글자 이상의 어떤 문자열에도 대응된다고 가정한다
//와일드카드 패턴과 함께 파일명의 집합이 주어질 때,
//그 중 패턴에 대응되는 파일명들을 찾아내는 프로그램을 작성하시오
//*/
//
//#include <iostream>
//#include <cstring>
//#include <vector>
//#include <algorithm>
//#include <string>
//using namespace std;
//
////-1은 아직 답이 계산되지 않았음을 의미
////1은 해당 입력들이 서로 대응됨을 의미
////0은 해당 입력들이 서로 대응되지 않음을 의미
//int cache[101][101]; //최대 길이가 100이므로 '\n' 포함
//string wildCard, fileName;
////완전 탐색 알고리즘을 이용(시간 초과)
///*
////와일드카드 패턴 w가 문자열 s에 대응되는지 여부를 반환
//bool match(const string &w, const string &s)
//{
////w[pos]와 s[pos]를 맞춰나간다
//int pos = 0;
//while (pos < s.size() && pos < w.size() && (w[pos] == '?' || w[pos] == s[pos]))
//pos++;
//
////더 이상 대응할 수 없으면 왜 while문이 끝났는지 확인
////패턴 끝에 도달해서 끝난 경우: 문자열도 끝났어야 대응됨
//if (pos == w.size())
//return pos == s.size();
////*를 만나서 끝난 경우: *에 몇 글자를 대응해야 할지 재귀 호출하면서 확인
//if (w[pos] == '*')
//for (int skip = 0; pos + skip <= s.size(); skip++)
//if (match(w.substr(pos + 1), s.substr(pos + skip)))
//return true;
////이 외의 경우에는 모두 대응되지 않는다
//return false;
//}
//*/
//
////동적계획법 이용
//int matchMemoized(int w, int f)
//{
//	//메모이제이션
//	int &result = cache[w][f];
//	if (result != -1)
//		return result;
//	//wildCard[w]와 fileName[f] 맞춰나감
//	//1번째 방법
//	/*
//	while (f < fileName.size() && w < wildCard.size() && (wildCard[w] == '?' || wildCard[w] == fileName[f]))
//	{
//	w++;
//	f++;
//	}
//	*/
//	//2번째 방법
//	if (w < wildCard.size() && f < fileName.size() && (wildCard[w] == '?' || wildCard[w] == fileName[f]))
//		return result = matchMemoized(w + 1, f + 1);
//	//더 이상 대응할 수 없으면 왜 while문이 끝났는지 확인
//	//패턴 끝에 도달해서 끝난 경우: 문자열도 끝났어야 한다
//	if (w == wildCard.size() && f == fileName.size())
//		return result = 1;
//
//	//*를 만나서 끝난 경우: *에 몇 글자를 대응해야 할지 재귀호출하면서 확인
//	//1번째 방법
//	/*
//	if (wildCard[w] == '*')
//	for (int skip = 0; skip + f <= fileName.size(); skip++)
//	if (matchMemoized(w + 1, f + skip))
//	return result = 1;
//	*/
//
//	//2번째 방법
//	if (wildCard[w] == '*')
//	{
//		if (matchMemoized(w + 1, f) || (f < fileName.size() && matchMemoized(w, f + 1))) //*에 문자를 대응하지 않을지 아니면 한 글자 더 대응할지
//			return result = 1;
//	}
//	//이 외의 경우에는 모두 대응되지 않는다
//	return result = 0;
//}
//
//int main(void)
//{
//	int test_case;
//	cin >> test_case;
//	if (test_case < 1 || test_case>10)
//		exit(-1);
//	for (int i = 0; i < test_case; i++)
//
//	{
//		vector<string> v;
//		cin >> wildCard;
//		int fileNum;
//		cin >> fileNum;
//		if (fileNum < 1 || fileNum>50)
//			exit(-1);
//
//		for (int j = 0; j < fileNum; j++)
//		{
//			memset(cache, -1, sizeof(cache));
//			cin >> fileName;
//			if (matchMemoized(0, 0) == 1) //조건 성립할 때만 벡터에 삽입
//				v.push_back(fileName);
//		}
//		sort(v.begin(), v.end()); //정렬을 하고
//
//		for (int j = 0; j < v.size(); j++) //출력
//			cout << v[j] << endl;
//		cout << endl;
//	}
//	return 0;
//}