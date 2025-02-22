# 0 또는 양의 정수가 주어졌을때 정수를 이어붙여 만들수있는 가장 큰 수?
from functools import cmp_to_key

def comp(a, b):
    x = a + b
    y = b + a
    if x < y:
        return 1
    else:
        return -1

def solution(numbers):
    numbers = [str(num) for num in numbers]
    numbers.sort(key=cmp_to_key(comp))
    answer = ''
    answer = str(int(''.join(numbers)))
    return answer

print(solution([3, 30, 34, 5, 9, 100]))