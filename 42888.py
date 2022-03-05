def solution(records):
    parse = {
        'Enter': '들어왔습니다.',
        'Leave': '나갔습니다.'
    }
    user = {}
    tmp = []
    answer = []
    
    for record in records:
        words = record.split()
        
        if words[0] in ['Enter', 'Change']:
            _, uid, uname = words
            user[uid] = uname
            
        if words[0] == 'Change':
            continue
            
        tmp.append((words[0], words[1]))
        
    for op, uid in tmp:
        answer.append(f'{user[uid]}님이 {parse[op]}')
    
    return answer
