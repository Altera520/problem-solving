def search(a, num):
    st, ed = (0, len(a) - 1)
    
    while st <= ed:
        mid = (st + ed) // 2
        if a[mid] == num:
            return 1
        if a[mid] < num:
            st = mid + 1
        else:
            ed = mid - 1
    return 0
    

def solution(n, a, m, nums):
    a = sorted(a)
    
    for num in nums:
        print(search(a, num))
        
if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().split()))
    m = int(input())
    nums = list(map(int, input().split()))
    
    solution(n, a, m, nums)
    
