class Solution:
    
    def combination(self, start, target, candidates, tmp, answer):
            if target == 0:
                answer.append(tmp[:])
            if target <= 0:
                return answer
        
            for i in range(start, len(candidates)):
                elem = candidates[i]
                tmp.append(elem)
                answer = self.combination(i, target - elem, candidates, tmp, answer)
                tmp.pop()
            return answer
    
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        return self.combination(0, target, candidates, [], [])
