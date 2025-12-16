// C++ program to find maximum
// profit from rod of size n 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cutRod(int n, vector<int> &price) {
    
    // Base case
    if (n==0) return 0;

    int ans = 0;
    
    // Find maximum value for each cut.
    // Take value of rod of length j, and
    // recursively find value of rod of
    // length (n-j).
    for (int i=1; i<=n; i++) 
        ans = max(ans, price[i-1]+cutRod(n-i, price));
    
    return ans;
}



int main() {
    vector<int> price =  { 1, 5, 8, 9, 10, 17, 17, 20};
    cout << cutRod(price.size(), price) << '\n';
    return 0;
}