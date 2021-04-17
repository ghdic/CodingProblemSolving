from functools import cmp_to_key

def comp(a, b):
    x = a + b
    y = b + a

def solution(numbers):
    str_number = [str(s) for s in numbers]
    str_number = sorted(str_number, key=cmp_to_key(comp))
    answer = ''
    answer = str(int(''.join(str_number)))
    return answer

print(solution([12, 121])



# def solution(numbers):
#     numbers = list(map(str, numbers))
#     numbers.sort(key=lambda x: x*3, reverse=True)
#     return str(int(''.join(numbers)))