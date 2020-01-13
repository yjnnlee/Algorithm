def solution(array, commands):
    answer = []

    for i in range(0,len(commands)):
        newarr = sorted([array[k] for k in range(commands[i][0], commands[i][1]+1)])
        answer.append(newarr[commands[i][2]])

    return answer

'''
#다른 풀이

def solution(array, commands):
    answer = []
    for com in commands:
        answer.append(sorted(array[com[0]-1:com[1]])[com[2]-1])
    return answer


def solution(array, commands):
    return list(map(lambda x:sorted(array[x[0]-1:x[1]])[x[2]-1], commands))
'''
