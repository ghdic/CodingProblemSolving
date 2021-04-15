left = ['[', '(', '{']
right = [']', ')', '}']
d = dict(zip(right, left))

def check(s):
    stack = [-1]
    for c in s:
        if c in left:
            stack.append(c)
        elif c in right:
            if stack[-1] == d[c]:
                stack.pop()
            else:
                return False
    return len(stack) == 1

def solution(s):
    answer = 0
    l = len(s)
    for i in range(l):
        answer += check(s)
        s = s[-1] + s[:-1]

    return answer


print(solution("[](){}"))