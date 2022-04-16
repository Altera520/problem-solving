def solution(nums, queries):
    nums = [0] + nums
    for i in range(1, len(nums)):
        nums[i] = nums[i] + nums[i - 1]
        
    return [str(nums[dst] - nums[src - 1]) for src, dst in queries]

        
if __name__ == '__main__':
    n, m = map(int, input().split())
    nums = list(map(int, input().split()))
    queries = [map(int, input().split()) for _ in range(m)]
    
    print('\n'.join(solution(nums, queries)))
    
