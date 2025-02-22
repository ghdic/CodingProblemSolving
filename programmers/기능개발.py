# 기능 개발 수행중, 기능 100%일때 서비스 반영 가능
# 개발속도는 모두 달라 뒤에있는 기능이 앞에 있는 기능보다 먼저 개발완료 가능
# 이때 뒤에 있는 기능은 앞에 있는 기능이 배포될 때 함께 배포된다
# 작업진도가 적힌 prgoresses 배열과 작업개발 속도가 적힌 speeds 배열이 주어진다
# 각 배포마다 몇 개의 기능이 배포되는지 return해라
import math

def solution(progresses, speeds):
    # 며칠걸리는지 미리 구해두면 되지않을까?
    progress_durations = [math.ceil((100 - p) / s) for p, s in zip(progresses, speeds)]
    result = []
    cur_duration = progress_durations[0]
    cur_cnt = 0
    for duration in progress_durations:
        if cur_duration >= duration:
            cur_cnt += 1
        else:
            result.append(cur_cnt)
            cur_duration = duration
            cur_cnt = 1
    result.append(cur_cnt)

    return result

print(solution([93, 30, 55], [1, 30, 5]))