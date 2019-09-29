class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = {}
        
    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        node = self.root
        for i in word:
            if i in node.keys():
                node = node[i]
            elif i not in node.keys():
                node[i] = {}
                node = node[i]
        node['isTrue'] = True

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        node = self.root
        for i in word:
            if i in node.keys():
                node = node[i]
            elif i not in node.keys():
                return False
        if 'isTrue' not in node.keys():
            return False
        else:
            return True
        
    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        node = self.root
        for i in prefix:
            if i in node.keys():
                node = node[i]
            elif i not in node.keys():
                return False
        return True
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
