class CustomStack:

    def __init__(self, maxSize: int):
        self.st = []
        self.limit = maxSize
        self.size = 0
        

    def push(self, x: int) -> None:
        if self.size == self.limit:
            return
        self.size += 1
        self.st.append(x)
        

    def pop(self) -> int:
        if self.size == 0:
            return -1
        self.size -= 1
        return self.st.pop()

    def increment(self, k: int, val: int) -> None:
        for i in range(min(k, self.size)):
            self.st[i] += val


# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)
