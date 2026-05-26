#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=17600;
const ll MOD=1e9+7;

vector<bool> isprime;
int main()
{
    vector<bool> isprime(N+1,true);
    isprime[0]=isprime[1]=false;

    for(ll i=2;i*i<=N;i++){
        if(isprime[i]){
            for(ll j=i*i;j<=N;j+=i){
                isprime[j]=false;
            }
        }
    }


    ll ans=1;


    for(ll i=2;i<=N;i++){
        if(isprime[i]){
            ll cnt=0;

            ll t=i;
            while(t<=N){
                cnt++;
                t=t*i;
            }

            ans=ans*cnt%MOD;
        }
    }

    cout << ans;

  
    return 0;
}