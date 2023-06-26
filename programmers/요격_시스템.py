# a ->  b 전략자원 아이시긋 군사 기지에 집중 융단폭격을 가함
# b나라는 이 포격을 요격하려고함 2차원으로 이뤄져 있고 해당 x좌표에 걸쳐있는 모든 폭격 요격
# e가 순으로 내림차순 정렬후 그리디

def solution(targets):
    targets.sort(key=lambda x: -x[1])
    answer = 0
    prev_s = 100000000
    for s, e in targets:
        if prev_s >= e:
            prev_s = s
            answer += 1
        elif prev_s < s:
            prev_s = s
    return answer
