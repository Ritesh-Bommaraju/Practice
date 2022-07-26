class Solution(object):
    def minimumBuckets(self, S):
        if len(S) == 1 and S[0] == '.':
            return 0
        if len(S) == 1:
            return -1
        total = 0
        ind_last = len(S)
        for index in range(len(S)):
            prev = False
            next = False
            if S[index] == "H":    
                if index != 0 and S[index-1] == '.':
                    prev = True
                if index != len(S) - 1 and S[index+1] == '.':
                    next = True
                if not (prev or next):
                    return -1
                if next and (index - 1 != ind_last or not prev):
                    total += 1
                    ind_last = index + 1
                if prev and not next and ind_last != index - 1:
                    total += 1
                    ind_last = index - 1
        return total

        