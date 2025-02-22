class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left, right = 0, 0
        n = len(s)
        res = 0
        container = set()
        while right < n:
            item = s[right]
            if item in container:
                while item in container:
                    present = right - left
                    res = max(res, present)
                    container.remove(s[left])
                    left += 1
            right += 1
            container.add(item)
        res = n if res == 0 else res
        return res


print(Solution().lengthOfLongestSubstring("bbbbbb")) # 1
print(Solution().lengthOfLongestSubstring("abcabcbb")) # 3