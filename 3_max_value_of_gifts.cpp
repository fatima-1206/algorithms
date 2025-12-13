// Maximum Value of Gifts Problem
#include <iostream>
#include <vector>
using namespace std;
int maxGifts(int n, int m, vector<vector<int> > gifts) {
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

    return dp[n][m];
}

int main()
{
        int n,m;
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