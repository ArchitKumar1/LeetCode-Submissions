// https://leetcode.com/problems/prefix-and-suffix-search

class WordFilter:
    
    class Node():
        def __init__(self):
            self.next = {}
            self.indexes = []
        
    def add(self,node,word,idx):
        for w in word:
            
            i = ord(w) - 97
            if i not in node.next:
                newnode = self.Node()
                node.next[i] = newnode
            
            node = node.next[i]
            print(node.next,node.indexes,word,idx,i)
            node.indexes.append(idx)
    
    
    def search(self,node,patt):
        for w in patt:
            i = ord(w) - 97
            if i not in node.next:
                self.empty.append(-1)
                return 

            node = node.next[i]
        return node.indexes
            
            
    def __init__(self, words: List[str]):
        self.pref = self.Node()
        self.suff = self.Node()
        self.empty = []
        
        for i,w  in enumerate(words,0):
            self.add(self.pref,w,i)
        
        for i,w  in enumerate(words,0):
            rev = ''.join(list(w)[::-1])
            print(rev)
            self.add(self.suff,rev,i)
        

    def f(self, prefix: str, suffix: str) -> int:
        first = self.search(self.pref,prefix)
        second = self.search(self.suff,suffix)
        
        print(first,second)
        if len(self.empty) > 0:
            empty = []
            return -1
        else:
            return max(list(set(first).intersection(set(second))))


# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(prefix,suffix)