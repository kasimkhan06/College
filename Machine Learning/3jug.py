import queue as Queue
def genSucc(curr):
    A , B , C = curr
    succ = []
    # A -> B
    if(A > 0):
        if(A+B <= 5):
            succ.append((0 , A+B , C))
        else:
            succ.append((A+B-5 , 5 , C))

    # A -> C
    if(A > 0):
        if(A+C <= 3):
            succ.append((0 , B , A+C))
        else:
            succ.append((A+C-3 , B , 3))

    # B -> A
    if(B > 0):
        if(A+B <= 8):
            succ.append((A+B , 0 , C))
        else:
            succ.append((8 , A+B-8 , C))
            
    # B -> C
    if(B > 0):
        if(B+C <= 3):
            succ.append((A , 0 , B+C))
        else:
            succ.append((A , B+C-3 , 3))
        
    # C -> A
    if(C > 0):
        if(A+C <= 8):
            succ.append((A+C , B , 0))
        else:
            succ.append((8 , B , A+C-8))

    # C -> B
    if(C > 0):
        if(B+C <= 5):
            succ.append((A , B+C , 0))
        else:
            succ.append((A , 5 , B+C-5))
        
    return succ


def bfs(start , end):
    # Initialize the queue
    q = Queue.Queue()
    mp = {}
    visited = set()

    q.put(start)
    visited.add(start)

    while(not q.empty()):
        curr = q.get()
        if(curr == end):
            return mp
        succ = genSucc(curr)
        for s in succ:
            if(s not in visited):
                visited.add(s)
                q.put(s)
                mp[s] = curr    


start = (8 , 0 , 0)
end = (4 , 4 , 0)
mp = bfs(start , end)
path = []
while(end != start):
    path.append(end)
    end = mp[end]
path.append(start)
path.reverse()
print(path)
