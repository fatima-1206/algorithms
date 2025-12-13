// cut the ribbon
#include <iostream>
#include <vector>
using namespace std;
// Example:
// Enter the length of ribbon
// 11
// Enter the 3 values of lengths allowed
// 2
// 5
// 7
// Maximum number of pieces in which the ribbon can be cut is 4
// The dp array is as follows: 
// Length 0 : 0
// Length 1 : -1
// Length 2 : 1
// Length 3 : -1
// Length 4 : 2
// Length 5 : 1
// Length 6 : 3
// Length 7 : 2
// Length 8 : 4
// Length 9 : 3
// Length 10 : 5
// Length 11 : 4
// Output: 4
int main()
{
      int i, j, k, n;
      int a, b, c;
      int x, y, z;
      cout << "Enter the length of ribbon" << endl;
      cin >> n;
      cout << "Enter the 3 values of lengths allowed" << endl;
      cin >> a >> b >> c;
      // array to memoize values
      // dp[i]=maximum number of pieces obtainable from ribbon length i
      vector<int> dp(n + 1);
      // initialize (from length 0, maximum pieces is 0)
      dp[0] = 0;
      
      for (i = 1; i <= n; i++) {
        x = y = z = -1;
        if (i >= a)
            x = dp[i - a];
        if (i >= b)
            y = dp[i - b];
        if (i >= c)
            z = dp[i - c];
        if (x == -1 && y == -1 && z == -1)
            dp[i] = -1;
        else
            dp[i] = max(max(x, y), z) + 1;
    }
    if (dp[n] == -1)
      cout << "Not possible";
    else
        cout<<"Maximum number of pieces in which the ribbon can be cut is "<<dp[n];
    // print the entire dp array
    cout << "\nThe dp array is as follows: " << endl;
    for (i = 0; i <= n; i++)
        cout << "Length " << i << " : " << dp[i] << endl;
    return 0;
}