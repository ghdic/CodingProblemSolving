# 사전에 A E I O U만 사용해 만들수있는 길이 5이하 단어 수록
# 첫번째 A, 두번째 AA .... 마지막 UUUUU일때 주어진 단어가 몇번째 단어인지 return
# A, AA, AAA, AAAA, AAAAA, AAAAE, AAAAI, AAAAO, AAAAU, AAAE AAAEA ...
# AUUU, B, BA, BAA, BAAA, BAAAAA, BB, BBA
# 시간복잡도 (알파벳수 + 1)^단어길이-1  알파벳 안고르는경우의수 때문에 +1
def solution(word):
    cur_word = []
    word_dict = {'A': 'E', 'E': 'I', 'I': 'O', 'O': 'U', 'U': 'A'}
    answer = 0

    while True:
        if ''.join(cur_word) == word:
            break

        if len(cur_word) < 5:
            cur_word.append('A')
        else:
            for i in range(5):
                w = cur_word[4 - i]
                next_w = word_dict[w]
                if w == 'U':
                    cur_word.pop()
                else:
                    cur_word[4 - i] = next_w
                    break
        answer += 1

    return answer