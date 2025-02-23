# 지갑을 만들려고 하는데 명함을 집어넣을 수있어야됌
# 명함의 가로세로 길이가 주어질때 모든 명함을 넣을수이쓴ㄴ 지갑의 크기는?
def solution(sizes):
    new_sizes = [[x, y] if x < y else [y, x] for x, y in sizes]
    w, h = zip(*new_sizes)
    max_w = max(w)
    max_h = max(h)

    return max_w * max_h
