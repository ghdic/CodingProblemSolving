# 학생들의 번호는 체격순이라 바로 앞뒤 번호 학생에게만 체육복을 빌려줄수있다
# 체육복 없으면 수업 못들어서 최대한 많은학생이 체육복을 빌려서 수업을 들어야된다
# 전체학생수 n, 도난당한학생들번호배열 lost, 여벌의 체육복 가져온 학생 번호배열 reserve
# 체육수업 들을수있는 학생의 최댓값은?
# 도난당한 학생 중복된번호 x, 여벌 체육복 가져온 학생도 도난당했을수있음 이때는 다른학생한테 못빌려줌
def solution(n, lost, reserve):
    lost.sort()
    reserve_set = set(reserve) - set(lost)
    lost = [s for s in lost if s not in reserve]

    final_lost = []
    for s in lost:
        if s - 1 in reserve_set:
            reserve_set.remove(s - 1)
        elif s + 1 in reserve_set:
            reserve_set.remove(s + 1)
        else:
            final_lost.append(s)

    return n - len(final_lost)