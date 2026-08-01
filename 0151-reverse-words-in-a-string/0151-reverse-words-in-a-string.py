class Solution:
    def reverseWords(self, s: str) -> str:
        s = s[::-1]

        n = len(s)
        l = 0
        result = []

        while l < n:
            # Skip spaces
            if s[l] == ' ':
                l += 1
                continue

            # Find the end of the word
            r = l
            while r < n and s[r] != ' ':
                r += 1

            # Extract the word and reverse it
            word = s[l:r][::-1]

            # Add space only between words
            if result:
                result.append(' ')

            result.append(word)

            # Move to the next word
            l = r

        return ''.join(result)