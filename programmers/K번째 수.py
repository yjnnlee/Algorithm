def solution(array, commands):
    answer = []
    
    for i in range(0,len(commands)):
        newarr = sorted([array[k-1] for k in range(commands[i][0], commands[i][1]+1)])
        answer.append(newarr[commands[i][2]-1])

    return answer
