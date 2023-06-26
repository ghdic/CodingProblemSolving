def solution(new_id):
    new_id = str.lower(new_id)  # step 1

    next_id = ''
    for c in new_id:  # step2
        if c.islower() or c.isdigit() or c in ['-', '_', '.']:
            next_id += c
    new_id = ''
    prev = ' '
    for c in next_id:
        if c == '.' and prev == '.': continue
        new_id += c
        prev = c
    while len(new_id) and new_id[0] == '.':  # step4
        new_id = new_id[1:]
    while len(new_id) and new_id[-1] == '.':
        new_id = new_id[:-1]
    
    if len(new_id) == 0:  # step5
        new_id = 'a'

    new_id = new_id[:15]  # step6
    while len(new_id) and new_id[0] == '.':  # step4
        new_id = new_id[1:]
    while len(new_id) and new_id[-1] == '.':
        new_id = new_id[:-1]

    while len(new_id) < 3:  # steop7
        new_id += new_id[-1]
    return new_id

print(solution('......-.........b'))