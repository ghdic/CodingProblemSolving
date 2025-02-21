# 과제는 한시각이 되면 시작
# 새로운 과제를 시작할 시각이 되면 기존 과제를 멈추고 새과제 시작
# 과제 끝난 후 멈췄던 과제 이어 진행
# 새로운과제, 가장 최근 멈춘 과제 순으로 우선권가짐
# [name, start, playtime] 구조로 배열이 주어짐
# 배열을 시간순으로 정렬되어있지않음

def add_time_str(time, add_minutes):
    hour, minute = map(int, time.split(":"))
    minute += add_minutes
    hour += minute // 60
    minute %= 60
    return f'{str(hour)}:{str(minute)}'

def solution(plans):
    answer = []
    # [name, rest_time]
    st = []
    plans.sort(key=lambda x: x[1])
    answer.append(plans[0])
    finish_time = add_time_str(plans[0][1], plans[0][2])
    for name, start, playtime in plans[1:]:



    return answer