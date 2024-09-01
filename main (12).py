def expandAroundCenter (s, left, right):
    while left >= 0 and right < len(s) and s[left] == s[right]:
        left -= 1
        right += 1
    return s[left + 1:right]

def longestPalindrome(s):
    if len(s) == 0:
        return ""
    
    longest = ""
    
    for i in range(len(s)):
        
        odd_palindrome = expandAroundCenter(s, i, i)
        if len(odd_palindrome) > len(longest):
            longest = odd_palindrome
        
        
        even_palindrome = expandAroundCenter(s, i, i + 1)
        if len(even_palindrome) > len(longest):
            longest = even_palindrome
    
    return longest


s = "babad"
n="maryam"
j="mohmmed"
print (longestPalindrome(j))
print (longestPalindrome(n))
print(longestPalindrome(s))  
