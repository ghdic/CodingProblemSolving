# 단속용 카메라를 한번은 만나도록 카메라 설치
# 차량의 경로 routes, 모든 차량 단속하려면 최소 몇대의 카메라를 설치해야 할까?
# [[-20,-15], [-14,-5], [-18,-13], [-5,-3]]
# [[-18, -16], [-20, -15], [-14, -5], [-5, -3]]
def solution(routes):
    # 1️⃣ 차량을 진출 지점 기준으로 정렬
    routes.sort(key=lambda x: x[1])

    cameras = 0  # 카메라 개수
    last_camera = -30001  # 초기값 (-30,000 이하)

    # 2️⃣ 각 차량의 경로를 확인하면서 카메라 배치
    for start, end in routes:
        # 현재 차량이 기존 카메라에 단속되지 않는다면 새 카메라 설치
        if start > last_camera:
            cameras += 1  # 새로운 카메라 추가
            last_camera = end  # 새로운 카메라는 이 차량의 종료 지점에 설치

    return cameras

print(solution([[-20, -15], [-18, -16], [-15, -8]]))