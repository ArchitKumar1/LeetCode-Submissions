// https://leetcode.com/problems/number-of-valid-words-in-a-sentence

class Solution:
    def countValidWords(self, sentence: str) -> int:
        words = sentence.split()
        valid_words = []
        
        pun = "!?.,"
        for word in words:
            safe = True
            for i,c in enumerate(word):
                if c >= '0' and c <= '9':
                    safe = False
                if c in pun and i != (len(word)-1):
                    safe = False
                
            counts = word.count("-")
            if(counts > 1): safe = False
            if(counts == 1):
                idx = word.find("-")
                if( idx-1 < 0 or idx+1 >= len(word) or not word[idx-1].isalpha() or not word[idx+1].isalpha()):
                    safe = False
            if safe: valid_words.append(word)
        return len(valid_words)
                
            