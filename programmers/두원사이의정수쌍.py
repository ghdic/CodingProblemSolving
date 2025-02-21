# 중심이 원점인 서로 다른 크기의 원 두개가 r1, r2 반지름으로 주어짐
# 두 원 사이 공간의 정수인 x, y 좌표 점의 개수 return
import math

def solution(r1, r2):
    answer = 0
    # 두 점모두 정수에 걸치지 않는 경우
    for i in range(r1):
        answer += int(math.sqrt(r2**2 - i**2)) - int(math.sqrt(r1**2 - i**2 - 1))
    # 두 점모두 정수에 걸치는 경우
    for i in range(r1, r2):
        answer += int(math.sqrt(r2**2 - i**2))

    # 사분면에 대한 점이 대칭이 됌
    answer *= 4
    return answer

print(solution(2, 3)) # 20