#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// convert s1 to s2 using minimum number of operations
// Example: s1: "quiz", s2: "quick"
// Operations allowed: insert, delete, replace
// Output: 2
// Explanation:
// The dp table is as follows: 
//     q u i c k 
//   0 1 2 3 4 5 
// q 1 0 1 2 3 4 
// u 2 1 0 1 2 3 
// i 3 2 1 0 1 2 
// z 4 3 2 1 1 2 

int editDistance(string &s1, string &s2) {
  
    int m = s1.length();
    int n = s2.length();

    // Create a table to store results of subproblems
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // Fill the known entries in dp[][]
    // If one string is empty, then answer 
    // is length of the other string
    for (int i = 0; i <= m; i++) 
        dp[i][0] = i;
    for (int j = 0; j <= n; j++) 
        dp[0][j] = j; 

    // Fill the rest of dp[][]
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i][j - 1],  
                                 dp[i - 1][j],   
                                 dp[i - 1][j - 1]});
        }
    }
    // print the dp table
    cout << "The dp table is as follows: " << endl;
    // print the s2 word first
    cout << "    ";
    for (int j = 0; j < n; j++) {
        cout << s2[j] << " ";
    }
    cout << endl;
    for (int i = 0; i <= m; i++) {
        // print the s1 word first
        if (i > 0)
            cout << s1[i - 1] << " ";
        else
            cout << "  ";
        for (int j = 0; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
        cout << endl;

    return dp[m][n];

}

int main() {
    string s1 = "quiz";
    string s2 = "quick";

    cout << editDistance(s1, s2);

    return 0;
}