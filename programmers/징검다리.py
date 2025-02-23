# 출발지점에서 distance만큼 떨어진 목적지 사이 바위가 있어 제거하려함
# n개의 바위를 제거한 뒤 각 지점 사이의 거리의 최솟값?
def solution(distance, rocks, n):
    rocks.sort()  # 바위 위치 정렬
    rocks.append(distance)  # 도착 지점을 바위처럼 처리
    left, right = 1, distance  # 최소 거리 범위 설정

    while left <= right:
        mid = (left + right) // 2  # 현재 최소 거리(mid)를 설정
        prev = 0  # 출발점 위치
        removed_rocks = 0  # 제거한 바위 개수

        for rock in rocks:
            if rock - prev < mid:  # 현재 바위와 이전 위치의 거리가 mid보다 작으면 제거
                removed_rocks += 1
                if removed_rocks > n:
                    break  # 제거할 수 있는 바위 개수 초과 시 종료
            else:
                prev = rock  # 현재 바위를 유지 (기준점 변경)

        if removed_rocks > n:  # 너무 많이 제거했다면, mid를 줄여야 함
            right = mid - 1
        else:  # n개 이하로 제거했다면, 더 큰 거리도 가능!
            left = mid + 1

    return right
