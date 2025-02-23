def solution(brown, yellow):
    answer = []
    가로_세로_합 = (brown + 4) // 2
    total_size = brown + yellow
    for i in range(1, 가로_세로_합):
        if i * (가로_세로_합 - i) == total_size:
            return [가로_세로_합 - i, i]
    return answer