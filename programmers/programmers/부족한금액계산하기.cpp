// https://programmers.co.kr/learn/courses/30/lessons/82612

/*
using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;

    for (int i = 1; i <= count; i++)
        answer += i * price;

    if (money - answer < 0)
        answer -= money;
    else
        answer = 0;

    return answer;
}
*/