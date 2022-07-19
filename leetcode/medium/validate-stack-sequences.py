class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        st = []
        pt1, pt2 = (0, 0)
        while len(pushed) != pt1:
            st.append(pushed[pt1])
            while st and st[-1] == popped[pt2]:
                st.pop()
                pt2 += 1
            pt1 += 1
        
        return False if st else True
            
