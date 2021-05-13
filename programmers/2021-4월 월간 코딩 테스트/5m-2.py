def check(a, b):
    if len(a) < len(b):
        a = a.zfill(len(b))
    cnt = 0
    for i in range(len(a)):
        if a[i] != b[i]:
            cnt += 1
    return cnt

def solution(numbers):
    answer = []
    for num in numbers:
        n = "{0:b}".format(num)
        val = num + 1
        while check(n, "{0:b}".format(val)) > 2:
            val += 1
        answer.append(val)
    return answer


print(solution([7]))