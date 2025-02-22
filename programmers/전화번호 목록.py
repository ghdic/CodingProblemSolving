# 전화번호부에 적힌 전화번호중 한번호가 다른 번호의 접두어인 경우가 있는지 확인하려한다
# phone_book 리스트가 주어질때 어떤번호가 다른 번호의 접우어인 경우가 있으면 false 없으면 true 반환
def solution(phone_book):
    phone_book.sort()

    for i in range(len(phone_book) - 1):
        if phone_book[i + 1].startswith(phone_book[i]):
            return False
    return True

print(solution(["119", "97674223", "119553422"]))