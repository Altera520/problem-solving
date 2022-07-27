class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        ans = 0
        basket = {}
        st, ed = (0, 0)
        
        for i, fruit in enumerate(fruits):
            if fruit in basket:
                basket[fruit] = i
            elif fruit not in basket and len(basket) < 2:
                basket[fruit] = i
            else:
                tmp = min(basket, key=basket.get)
                st = basket[tmp] + 1
                del basket[tmp]
                basket[fruit] = i
            ed += 1
            ans = max(ans, ed - st)
            
        return ans
            
