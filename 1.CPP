#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1005;

ll a[N][N],diff[N][N];


int main(){
    ll n,m;
    cin >> n >> m;

    for(ll i=1;i<=m;i++){
        ll x1,y1,x2,y2;
        cin >> x1>>y1>>x2>>y2;

        diff[x1][y1]+=1;
        diff[x2+1][y1]-=1;
        diff[x1][y2+1]-=1;
        diff[x2+1][y2+1]+=1;
    }


     for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            diff[i][j] = diff[i][j]
                       + diff[i - 1][j]
                       + diff[i][j - 1]
                       - diff[i - 1][j - 1];

            cout << diff[i][j] << " ";
        }
        cout << '\n';
    }



    


    return 0;
}