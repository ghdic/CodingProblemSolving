# 배열은 0~9로 이루어짐, 연속적으로 나타나는 숫자는 하나만 남기고 제거(순서유지)
def solution(arr):
    prev_num = -1
    answer = []
    for a in arr:
        if prev_num != a:
            answer.append(a)
        prev_num = a
    return answer

arr = [1,1,3,3,0,1,1]
print(solution(arr))