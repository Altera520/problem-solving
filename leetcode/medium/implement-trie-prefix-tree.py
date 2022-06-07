class Node:
    def __init__(self, key, data=None):
        self.key = key
        self.data = data
        self.children = {}


class Trie:

    def __init__(self):
        # dummy
        self.head = Node(None)

    def insert(self, word: str) -> None:
        cur = self.head
        
        for char in word:
            if char not in cur.children:
                cur.children[char] = Node(char)
            cur = cur.children[char]
        # 문자열의 종료를 알리는 flag, True/False로 해도되나, 돌아가는일 없게 전체 문자열 저장
        cur.data = word
        

    def search(self, word: str) -> bool:
        cur = self.head
        
        for char in word:
            if char not in cur.children:
                return False
            cur = cur.children[char]
        
        return cur.data is not None
        

    def startsWith(self, prefix: str) -> bool:
        cur = self.head
        
        for char in prefix:
            if char not in cur.children:
                return False    
            cur = cur.children[char]
        return True
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
