# 모든음식의 스코빌 지수를 K이상으로 만들고 싶다
# 섞은 음식의 스코빌 지수 = 가장 맵지 않은 스코빌 지수 + (두번째로 맵지 안흥ㄴ 음식의 스코빌 지수 * 2)
# 위 공식을 써서 새로운음식을 만들수있다
# 모든 음식의 스코빌 지수가 K이상이 될때까지 반복하여 섞자
import heapq

def solution(scoville, K):
    heapq.heapify(scoville)
    result = 0

    while len(scoville) >= 2:
        item = heapq.heappop(scoville)
        if item >= K:
            return result

        heapq.heappush(scoville, item + heapq.heappop(scoville)*2)
        result += 1

    # 마지막으로 남은 원소가 K 이상인지 체크
    return result if scoville[0] >= K else -1