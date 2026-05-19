#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[125][125];
    int sum[125][125];

    int ans=INT_MIN;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >>a[i][j]; 

            sum[i][j]=a[i][j]+sum[i][j-1]+sum[i-1][j]-sum[i-1][i-1];
    
            
        }
        
    }

    // 枚举所有矩形
    for (int x1 = 1; x1 <= n; x1++) {
        for (int y1 = 1; y1 <= n; y1++) {
            for (int x2 = x1; x2 <= n; x2++) {
                for (int y2 = y1; y2 <= n; y2++) {
                    int rect_sum = sum[x2][y2] 
                                 - sum[x1-1][y2] 
                                 - sum[x2][y1-1] 
                                 + sum[x1-1][y1-1];
                    ans = max(ans, rect_sum);
                }
            }
        }
    }

    

    cout << ans;
    
}