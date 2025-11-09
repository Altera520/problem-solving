class Solution:
    def minSideJumps(self, obstacles: List[int]) -> int:
        # dp[i]는 i번 레인에 도달하는데 필요한 최소 점프 수
        f = [1, 0, 1]  # 초기: 레인 2에서 시작 (0-indexed)
        
        for v in obstacles[1:]:
            # 장애물이 있는 레인을 무한대로 설정
            if v > 0:
                f[v - 1] = float('inf')
            
            # 최소값 + 1이 이동 비용
            x = min(f) + 1
            
            # 각 레인 업데이트
            for j in range(3):
                if v != j + 1:
                    f[j] = min(f[j], x)
        
        return min(f)
