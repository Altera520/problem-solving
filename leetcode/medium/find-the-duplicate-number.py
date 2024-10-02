class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        # floyd's cycle
        # 배열 값을 포인터로 가정, 링크드 리스트로 취급
        # 배열 값이 (배열의 길이 -1)이라서 사용 가능한 알고리즘

        slowptr = nums[0]
        fastptr = nums[0]

        while True:
            slowptr = nums[slowptr]         # 1칸 이동
            fastptr = nums[nums[fastptr]]   # 2칸 이동

            if slowptr == fastptr:  # 두 포인터가 만나면(사이클이 발견)
                break

        slowptr = nums[0]
        while slowptr != fastptr:   # slow, fast가 같아질때까지 1칸 이동
            slowptr = nums[slowptr]
            fastptr = nums[fastptr]

        return slowptr

        # [1, 3, 4, 2, 2]
        # 1 -> 3 -> 2 -> 4 -> 2 -> 4 -> 2 -> ...