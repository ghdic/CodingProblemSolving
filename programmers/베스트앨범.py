# 장르별로 가장 많이 재생된 노래를 두개씩 모아서 베스트 앨범 출시
# 1. 속한 노래가 많이 재생된 장르
# 2. 장르 내에서 많이 재생된 노래
# 3. 장르 내에서 재생 횟수가 같은 노래 중에서 고유 번호가 낮은 노래를 먼저 수록
# 장르에 속한곡이 하나라면 하나의 곡만 선택
from collections import defaultdict

def solution(genres, plays):
    genre_group = defaultdict(list)
    genre_play_count = defaultdict(int)

    for i, (genre, play) in enumerate(zip(genres, plays)):
        genre_group[genre].append((play, i))
        genre_play_count[genre] += play

    genre_order = sorted(genre_play_count.keys(), key=lambda x: -genre_play_count[x])

    result = []

    for genre in genre_order:
        top_songs = sorted(genre_group[genre], key=lambda x: (-x[0], x[1]))[:2]
        result.extend([song[1] for song in top_songs])
    return result


genres = ["classic", "pop", "k-pop", "classic", "classic", "pop", "rock"]
plays = [500, 600, 5000, 150, 800, 2500, 3000]
print(solution(genres, plays))