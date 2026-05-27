#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N=1e5+10;
const ll MOD =1e9+7;


vector<ll>  zero(N),one(N),dp(N);


int main(){

    ll t;
    cin >> t;

    zero[1]=1;
    one[1]=0;
    dp[1]=0;


    zero[2]=0;
    one[2]=1;
    dp[2]=0;


    

        for(ll j=3;j<=N;j++){
            zero[j]=(zero[j-1]+zero[j-2])%MOD;
            one[j]=(one[j-1]+one[j-2])%MOD;

            dp[j]=(dp[j-1]+dp[j-2]+(one[j-2]*zero[j-1]))%MOD;
        }  

        

        while(t--){
            ll n;
            cin >> n;

            cout << dp[n]<< endl;

        }
    

    return 0;

}