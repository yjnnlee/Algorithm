import sys 

CmdCnt = int(input())
st = list()

for _ in range(CmdCnt):
    cmds = sys.stdin.readline()
    
    cmd = cmds.split()[0]
    
    if cmd == "top":
        if len(st) == 0:
            print("-1")
        else:
            print(st[-1])
    elif cmd == "empty":
        if len(st) == 0 :
            print("1")
        else:
            print("0")
            
    elif cmd == "size":
        print(len(st))
    
    elif cmd == "pop":
        if len(st) == 0:
            print("-1")
        else:
            print(st.pop())
    
    elif cmd == "push":
        st.append(cmds.split()[1])
