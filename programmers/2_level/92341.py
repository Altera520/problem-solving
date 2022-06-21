from collections import defaultdict as dd

class log:
    def __init__(self, record):
        record = record.split()
        h, m = record[0].split(':')
        self.vehicle_no = record[1]
        self.seconds = int(h) * 60 * 60 + int(m) * 60 
        self.type = record[2]


def solution(fees, records):
    base_m, base_fee, unit_m, unit_fee = fees
    base_m = base_m * 60
    unit_m = unit_m * 60
    
    
    def get_fee(seconds):
        seconds -= base_m
        if seconds <= 0:
            return base_fee
        return (seconds // unit_m + (1 if seconds % unit_m != 0 else 0)) * unit_fee + base_fee
    
    ans = []
    group = dd(list)
    
    for record in records:
        l = log(record)
        group[l.vehicle_no].append(l)
    
    for vehicle_no, logs in group.items():
        sz = len(logs)
        if sz % 2 != 0:
            logs.append(log(f'23:59 {vehicle_no} OUT'))
        total_seconds = sum([logs[i + 1].seconds - logs[i].seconds for i in range(0, len(logs), 2)])
        ans.append((vehicle_no, get_fee(total_seconds)))
        
    return [fee for _, fee in sorted(ans)]


