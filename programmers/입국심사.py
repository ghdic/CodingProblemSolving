# n명이 입국심사 줄서는중 심사관마다 심사걸리는시간 다름
# 처음엔 모든 심사대가 비어있음
# 가장 앞에서있는사람이 비어있는 심사대로 가서 받을수있으며, 더 빨리 끝나는 심사대가 있으면 기다렸다가 갈수도있음
# 모든 심사가 받는데 걸리는 시간을 최소로 하고 싶음
# n = 6, times = [7, 10]
# 28 4사람 + 2사람 처리
# 즉 심사하는데 걸리는 시간의 최적값을 이분탐색으로 찾자
def solution(n, times):
    max_time = max(times) * n // len(times) + 1

    left, right = 0, max_time
    while left <= right:
        mid = (left + right) // 2
        total = sum(mid // t for t in times)
        if total < n:
            left = mid + 1
        else:
            right = mid - 1

    return left

print(solution(6, [7, 10]))