# 한번에 하나의 작업을 수행하는 디스크
# 우선순위 디스크 컨트롤러라는 가상 장치 이용
# 1. 작업 요청시 작업번호, 작업 요청시각, 작업의 소요 시간을 저장해두는 대기큐가 저장됌
# 2. 가장 우선순위가 높은 작업을 대기 큐에서 꺼내 작업 진행 소요시간 짧은것 > 요청시각 빠른것 > 작업 번호 작은것 우선순위를 가짐
# 3. 작업은 한번시작하면 마칠때까지 그 작업 수행
# 4. 작업 마치는 시점과 요청시점이 겹치면 대기큐에 넣는게 우선, 작업교체에 걸리는시간은 0이라 가정
# 모든 작업을 반환시간의 평균의 정수부분을 return하는 함수?(반환시간=작업종료시간 - 요청시각)
import heapq


def solution(jobs):
    # 요청 시각 기준으로 정렬
    jobs = sorted(enumerate(jobs), key=lambda x: x[1][0])  # (작업번호, [요청 시각, 소요 시간]) 형태로 변환

    # 소요 시간, 요청 시각, 작업 번호 기준으로 정렬
    min_heap = []

    answer = 0
    cur_time = 0  # 현재 시간
    cur_idx = 0  # 현재 jobs 인덱스
    job_count = len(jobs)

    while cur_idx < job_count or min_heap:
        # 현재 시간보다 작거나 같은 요청을 큐에 삽입
        while cur_idx < job_count and jobs[cur_idx][1][0] <= cur_time:
            job_num, (request_time, job_length) = jobs[cur_idx]
            heapq.heappush(min_heap, (job_length, request_time, job_num))  # (소요 시간, 요청 시각, 작업 번호) 추가
            cur_idx += 1

        # 큐가 비어 있다면 현재 시간을 조정
        if not min_heap:
            cur_time = max(cur_time, jobs[cur_idx][1][0])
        else:
            job_length, request_time, job_num = heapq.heappop(min_heap)
            cur_time += job_length
            answer += cur_time - request_time

    return answer // job_count