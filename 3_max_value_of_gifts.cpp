// Maximum Value of Gifts Problem
#include <iostream>
#include <vector>
using namespace std;
// Example:
// Sample Input:
// 4 4
// 1 10 3 8
// 12 2 9 6
// 5 7 4 11
// 3 7 16 5 

// Sample Output:
// 1 11 14 22 
// 13 15 24 30 
// 18 25 29 41 
// 21 32 48 53 
// Max Value Gifts: 53

int maxGifts(int n, int m, vector<vector<int>> gifts) {
    //vector to store results
    vector<vector<int> > dp(n+1,vector<int>(m+1, 0));
    //dp[i][j]=maximum attainable value of gifts for the matrix of rows i and columns j only
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            //There are two ways to reach colums (i,j)
            //one from above and one from left
            //choose the one which gives more value 
            dp[i][j]=max(dp[i][j-1],dp[i-1][j])+gifts[i][j];
        }
    }
    // make it print the dp
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[n][m];
}

int main()
{
    // sample
    vector<vector<int> > gifts1 = {
        {0, 0, 0, 0, 0},
        {0, 1, 10, 3, 8},
        {0, 12, 2, 9, 6},
        {0, 5, 7, 4, 11},
        {0, 3, 7, 16, 5}
    };
    int n = 4; // number of rows
    int m = 4; // number of columns
    cout<<"maximum attainable value of gifts is "<<endl;
    cout<<maxGifts(n,m,gifts1);
    cout<<endl;

    cout<<"Enter the number of rows and columns"<<endl;
    cin>>n>>m;
    vector<vector<int> > gifts(n+1,vector<int>(m+1));
    cout<<"Enter the values of gifts in cells"<<endl;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>gifts[i][j];

    cout<<"maximum attainable value of gifts is "<<endl;
    cout<<maxGifts(n,m,gifts);

    cout<<endl;
    return 0;
}