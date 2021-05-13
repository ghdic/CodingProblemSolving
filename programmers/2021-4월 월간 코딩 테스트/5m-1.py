def solution(left, right):
    answer = 0
    if left == 1:
        answer -= 1
        left += 1
    for i in range(left, right + 1):
        cnt = 0
        for j in range(2, i):
            if i % j == 0:
                cnt += 1

        if cnt % 2:
            answer -= i
        else:
            answer += i
    return answer


print(solution(1, 2))