class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        ls,c=text.split(),0
        for i in ls:
            for j in brokenLetters:
                if j in i:
                    break
            else:
                c+=1
        return c