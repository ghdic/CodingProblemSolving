# https://school.programmers.co.kr/learn/courses/30/lessons/81305
# 이진트리를 k개의 그룹으로 나누어 트래픽의합이 최소가 되게 하기

# 1.각 노드들이 연결되어있게 세팅
# 2. 연결을 끊는 로직
# 3. 연결을 끊었을때 각 그룹의 트래픽이 최소가 되게하기

# def run(k, num, links):
#     result = 0
#
#     def get_root_nodes():
#         """ 그룹의 root node들을 찾아낸다 """
#         n = len(num)
#         check_linking = [False] * n
#         for link in links:
#             for i in link:
#                 if i != -1:
#                     check_linking[i] = True
#         return [idx for (idx, check) in enumerate(check_linking) if not check]
#
#
#     def get_group_sum(node):
#         """ 그룹의 트래픽 합을 구한다 """
#         sum = num[node]
#         for next_node in links[node]:
#             if next_node != -1:
#                 sum += get_group_sum(next_node)
#         return sum
#
#     def split_group(node):
#         """ 해당 그룹에서 그룹을 나누었을때 트래픽이 최소가 되는 links를 찾는다(핵심로직) """
#
#
#     return result
#
# def solution(k, num, links):
#     answer = run(k, num, links)
#     return answer


def find_root(links):
    """O(N) 시간 복잡도로 루트 노드를 찾는 함수"""
    n = len(links)
    has_parent = [False] * n

    for left, right in links:
        if left != -1:
            has_parent[left] = True
        if right != -1:
            has_parent[right] = True

    # 부모가 없는 노드를 찾아서 반환
    return has_parent.index(False)

def search(node, target, num, links, memo):
    """DFS 기반으로 트래픽을 그룹으로 나누며, 메모이제이션 적용"""
    if node == -1:
        return 0, 0

    if node in memo:  # 메모이제이션 활용하여 중복 연산 방지
        return memo[node]

    left, right = links[node]
    left_cnt, left_val = search(left, target, num, links, memo)
    right_cnt, right_val = search(right, target, num, links, memo)
    tot_cnt = left_cnt + right_cnt
    result_sum = left_val + right_val + num[node]

    if result_sum <= target:
        memo[node] = (tot_cnt, result_sum)
        return memo[node]

    if min(left_val, right_val) + num[node] <= target:
        memo[node] = (tot_cnt + 1, min(left_val, right_val) + num[node])
        return memo[node]

    memo[node] = (tot_cnt + 2, num[node])
    return memo[node]

def binary_search(root, start, end, k, num, links):
    """이진 탐색을 통해 최소한의 최대 그룹 크기를 찾는 함수"""
    result = end
    while start <= end:
        mid = (start + end) // 2
        memo = {}  # 검색 결과 캐싱
        div_cnt, _ = search(root, mid, num, links, memo)

        if div_cnt > k - 1:
            start = mid + 1
        else:
            result = min(result, mid)
            end = mid - 1

    return result

def solution(k, num, links):
    """최적의 그룹을 나누는 과정"""
    root = find_root(links)
    start, end = max(num), sum(num)
    return binary_search(root, start, end, k, num, links)