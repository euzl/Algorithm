def solution(s):
    answer = ''
    list = s.split(' ')
    for l in list:
        for a in range(0, len(l)):
            if a%2 == 0:
                answer += l[a].upper()
            else:
                answer += l[a].lower()
        answer += ' '
    return answer[:len(answer)-1]
