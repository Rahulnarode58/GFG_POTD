#Check if a string is repetition of its substring of k-length
# POTD Date 29-12-2023 
# Coding_with_rahul

'''
Given a string s, check if it is possible to convert it into a string that is the repetition of a substring of length k. To convert, we will select two substrings, of length k starting at index i and j (zero-based indexing) such that i and j are divisible by k, and we will replace one substring with the other.

Example 1:

Input:
N = 4
K = 2
S = "bdac"
Output: 1
Explanation: We can replace either
"bd" with "ac" or "ac" with "bd" 
'''

class Solution:
   def kSubstrConcat(self, n: int, s: str, k: int) -> int:
       """Converts the given C++ code to Python."""

       if n % k != 0:  # Check for divisibility condition
           return 0

       substring_counts = {}  # Use a dictionary to store substring counts
       temp_substring = ""  # Initialize a temporary substring

       for i in range(n):
           temp_substring += s[i]
           if (i + 1) % k == 0:  # Process substring after every k characters
               substring_counts[temp_substring] = substring_counts.get(temp_substring, 0) + 1
               temp_substring = ""  # Reset temporary substring

       # Final substring (if n is not a multiple of k)
       if temp_substring:
           substring_counts[temp_substring] = substring_counts.get(temp_substring, 0) + 1

       return 1 if len(substring_counts) <= 2 else 0