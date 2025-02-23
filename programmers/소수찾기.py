# 한자리 숫자가 적힌 종이 조각이 흩어져있다
# 이 종이조각을 붙여 소수 몇개 만들수있을까?
def solution(numbers):
    primes = [True] * 10000000
    primes[0] = primes[1] = False

    for i in range(2, int(10000000 ** 0.5)):
        if primes[i]:  # i가 소수이면
            for j in range(i * i, 10000000, i):
                primes[j] = False
    unique_num = set()

    def dfs(num, num_counter):
        if primes[num]:
            unique_num.add(num)
        for key in num_counter:
            if num_counter[key] > 0:
                num_counter[key] -= 1
                dfs(num * 10 + key, num_counter)
                num_counter[key] += 1

    num_counter = {}
    for n in numbers:
        m = int(n)
        num_counter[m] = num_counter.get(m, 0) + 1

    dfs(0, num_counter)

    return len(unique_num)

print(solution("17"))