# N/2마리 포켓몬 가져가도 좋아
# 같은 종류의 포켓몬이 배열에 담겨있을수있음
# 최대한 많은 종류의 포켓몬을 가져갈때 최대 종류의 갯수는?

def solution(nums):
    # 1. 중복확인
    dup_check = list(set(nums))

    # 2. N/2이랑 총 포켓몬 종류수랑 비교해서 큰거 반환
    return len(nums)//2 if len(nums)//2 < len(dup_check) else len(dup_check)


nums = [3, 3, 3, 2, 2, 2]
result = 3

print(solution(nums))