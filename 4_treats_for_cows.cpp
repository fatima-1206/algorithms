#include <iostream>
#include <vector>
using namespace std;
// Example:Enter the number of treats 5
// Enter the values of treats
// 1 3 1 5 2
// The dp table is as follows: 
// 5 19 22 40 43 
// 0 15 19 38 42 
// 0 0  5  29 36 
// 0 0  0  25 33 
// 0 0  0  0  10 
// 43
int solve(int n, vector<int> a) {
    vector<vector<int> > dp(n, vector<int>(n));
    int i,j;
    int day;
    //initialization
    for(i=0;i<n;i++)
        dp[i][i]=n*a[i];

    for(int len=2;len<=n;len++) {
        day=n-len+1;
        for(i=0;i<(n-len+1);i++) {
            j=i+len-1;
            dp[i][j]=max(day*a[i]+dp[i+1][j],dp[i][j-1]+day*a[j]);
        }
    }
    // print the dp table
    cout << "The dp table is as follows: " << endl;
    for (i = 0; i < n; i++) {   
        for (j = 0; j < n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[0][n-1];
}

int main()
{
    int n,i;
    cout<<"Enter the number of treats ";
    cin>>n;
    vector<int> a(n);

    cout<<"Enter the values of treats "<<endl;
    for(i=0;i<n;i++)
        cin>>a[i];

    cout<<"The maximum revenue that can be obtained by selling the treats is "<<endl;
    cout<<solve(n,a)<<endl;

    return 0;
}