def solution(emergency):
    arr = []
    
    for i in emergency:
        idx = 1
        
        for j in emergency:
            if i < j:
                idx += 1
        arr.append(idx)
        
    return arr