// <======== MY SOLUTION =========>
class Solution {
public:
    int dp[601][101][101];
    int dpHelper(vector<pair<int,int>>& zoCnt, int m, int n, int i){
        if(i == zoCnt.size() || (m==0 && n==0)) return 0;
        if(dp[i][m][n] != -1) return dp[i][m][n];
        int res = 0;
        int zCnt = zoCnt[i].first;
        int oCnt = zoCnt[i].second;
        if(zCnt<=m && oCnt<=n){
            res = dpHelper(zoCnt,m-zCnt,n-oCnt,i+1) + 1;
        }
        res= max(res, dpHelper(zoCnt,m,n,i+1));
        dp[i][m][n] = res;
        return dp[i][m][n];
    }


    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        vector<pair<int,int>> zoCount;
        for(string& str:strs){
            int zCnt = std::count(str.begin(),str.end(),'0');
            int oCnt = str.size() - zCnt;
            zoCount.push_back({zCnt,oCnt});
        }

        int res = dpHelper(zoCount,m,n,0);
        return res;
    }
};












// <======== PROBLEM DESCRIPTION =============>

// 474. Ones and Zeroes
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// You are given an array of binary strings strs and two integers m and n.

// Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

// A set x is a subset of a set y if all elements of x are also elements of y.

 

// Example 1:

// Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
// Output: 4
// Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
// Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
// {"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
// Example 2:

// Input: strs = ["10","0","1"], m = 1, n = 1
// Output: 2
// Explanation: The largest subset is {"0", "1"}, so the answer is 2.
 

// Constraints:

// 1 <= strs.length <= 600
// 1 <= strs[i].length <= 100
// strs[i] consists only of digits '0' and '1'.
// 1 <= m, n <= 100