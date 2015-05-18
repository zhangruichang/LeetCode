__author__ = 'richard'
class TrieNode:
    # Initialize your data structure here.
    def __init__(self):
        self.isWord=False
        self.Child=[None]*26

class Trie:

    def __init__(self):
        self.root = TrieNode()

    # @param {string} word
    # @return {void}
    # Inserts a word into the trie.
    def insert(self, word):
        p=self.root
        for e in word:
            index=ord(e)-ord('a')
            if p.Child[index] is None:
                p.Child[index]=TrieNode()
            p=p.Child[index]
        p.isWord=True

    # @param {string} word
    # @return {boolean}
    # Returns if the word is in the trie.
    def search(self, word):
        p=self.root
        for e in word:
            index=ord(e)-ord('a')
            if p.Child[index] is None:
                return False
            p=p.Child[index]
        return p.isWord

    # @param {string} prefix
    # @return {boolean}
    # Returns if there is any word in the trie
    # that starts with the given prefix.
    def startsWith(self, prefix):
        p=self.root
        for e in prefix:
            index=ord(e)-ord('a')
            if p.Child[index] is None:
                return False
            p=p.Child[index]
        return True

# Your Trie object will be instantiated and called as such:
# trie = Trie()
# trie.insert("somestring")
# trie.search("key")
s='a'

T=Trie()
TN=TrieNode()
