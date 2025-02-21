# t초 붕대감으면 1초마다 x만큼 회복
# t초 연속으로 붕대 감으면 y추가체력 회복
# 최대체력을 넘게 회복할수없음
# 공격당하면 기술취소, 체력0되면 game over
# 모든 공격이 끝난후 체력return, 죽으면 -1

def regen(cur_health, gen_health, max_health):
    return min(cur_health + gen_health, max_health)

# bandage [시전시간, 초당회복량, 추가회복량]
# attack [[공격시간, 피해량],]
def solution(bandage, health, attacks):
    cool_down, regen_per_sec, add_regen = bandage
    cur_health = health
    t = attacks[-1][0] + 1
    seq = 0
    cur_attack_index = 0
    for i in range(t):
        seq += 1
        if attacks[cur_attack_index][0] == i:
            seq = 0
            cur_health -= attacks[cur_attack_index][1]
            cur_attack_index += 1
            if cur_health <= 0:
                return -1
        else:
            if seq == cool_down:
                cur_health = regen(cur_health, add_regen, health)
                seq = 0
            cur_health = regen(cur_health, regen_per_sec, health)
    return cur_health

print(solution([5, 1, 5], 30, [[2, 10], [9, 15], [10, 5], [11, 5]]))