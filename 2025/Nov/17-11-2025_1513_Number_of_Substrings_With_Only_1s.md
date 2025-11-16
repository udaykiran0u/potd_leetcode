# My solution
```cpp
class Solution {
public:
    int numSub(string s) {
        long total = 0;
        int  M = 1e9+7;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                long cnt = 0;
                while(s[i]=='1'){
                    cnt++;
                    i++;
                }
                total += (cnt*(cnt+1))/2;
                total = total%M;
            }
        }
        return int(total%M);
    }
};
```

# description
```
1513. Number of Substrings With Only 1s
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given a binary string s, return the number of substrings with all characters 1's. Since the answer may be too large, return it modulo 109 + 7.

 

Example 1:

Input: s = "0110111"
Output: 9
Explanation: There are 9 substring in total with only 1's characters.
"1" -> 5 times.
"11" -> 3 times.
"111" -> 1 time.
Example 2:

Input: s = "101"
Output: 2
Explanation: Substring "1" is shown 2 times in s.
Example 3:

Input: s = "111111"
Output: 21
Explanation: Each substring contains only 1's characters.
 

Constraints:

1 <= s.length <= 105
s[i] is either '0' or '1'.
```