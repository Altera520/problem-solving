def solution(arr1, arr2):
    # *로 한차원 낮추고, zip하여 전치행렬
    arr2 = list(zip(*arr2))
    
    def get_acc(a, b):
        acc = 0
        for idx, item in enumerate(b):
            acc += a[idx] * item
        return acc
    
    return [[get_acc(a, b) for b in arr2] for a in arr1]
