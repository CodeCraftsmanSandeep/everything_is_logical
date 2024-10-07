class Solution(object):
    def longestValidParentheses(self, s):
        count = 0
        curr_len = 0
        max_len = 0
        for ele in s:
            if ele == ')':
                count -= 1
            else:
                count += 1
            curr_len += 1
            if count == 0:
                max_len = max(max_len, curr_len)
            elif count < 0:
                count = 0
                curr_len = 0
        
        n = len(s)
        curr_len = 0
        count = 0
        for i in range(n-1, -1, -1):
            if s[i] == ')':
                count -= 1
            else:
                count += 1
            curr_len += 1
            if count == 0:
                max_len = max(max_len, curr_len)
            elif count > 0:
                count = 0
                curr_len = 0
        
        return max_len