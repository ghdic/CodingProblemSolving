# 숫자 N을 사용하여 사칙연산으로 numbers를 구할때 N사용갯수 최솟값?
# 나누기연산에서는 나머지 무시
# 최솟값이 8보다 크면 -1 return
def solution(N, number):
    if N == number:
        return 1

    dp = [set() for _ in range(9)] # dp[i]: N을 i번 사용해서 만들 수 있는 숫자 집합
    for i in range(1, 9):
        dp[i].add(int(str(N) * i)) # N, NN, NNN ...

        for j in range(1, i):
            for num1 in dp[j]:
                for num2 in dp[i - j]:
                    dp[i].add(num1 + num2)
                    dp[i].add(num1 - num2)
                    dp[i].add(num1 * num2)
                    if num2 != 0:
                        dp[i].add(num1 // num2)

        if number in dp[i]:
            return i
    return -1
