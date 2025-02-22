# 괄호가 올바르면 true 올바르지 않으면 false
def solution(s):

    stack = []

    for i in s:
        if i == '(':
            stack.append('(')
        else:
            if not stack or stack.pop() != '(':
                return False
    return not stack
