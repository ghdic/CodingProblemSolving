# 어떤숫자에서 k개의 수를 제거 했을때 얻을수있는 가장 큰 숫자??
# 그냥 작은숫자 없애면 되는거 아님?
def solution(number, k):
    stack = []  # 결과를 저장할 스택

    for digit in number:
        while stack and k > 0 and stack[-1] < digit:
            stack.pop()  # 이전 숫자가 현재 숫자보다 작으면 제거
            k -= 1  # 제거할 횟수 감소
        stack.append(digit)  # 현재 숫자 추가

    return ''.join(stack[:len(stack) - k])  # 아직 제거할 게 남았다면 뒤에서 제거