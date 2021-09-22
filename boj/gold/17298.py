class stack:
    def __init__(self):
        self.items = []
    def push(self, item):
        self.items.append(item)
    def pop(self):
        return self.items.pop()
    def peek(self):
        return self.items[-1]
    def is_empty(self):
        return not self.items

st = stack()
cnt = int(input())
arr = list(map(int, input().split()))
ans = []

arr.reverse()

for item in arr:
    while True:
        if st.is_empty():
            ans.append(-1)
            st.push(item)
            break
        if st.peek() <= item:
            st.pop()
        else:
            ans.append(st.peek())
            st.push(item)
            break

ans.reverse()
print(*ans)