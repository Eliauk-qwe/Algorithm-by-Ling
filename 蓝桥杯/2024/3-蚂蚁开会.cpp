#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<ll,ll> cnt;

ll encode(ll x,ll y){
    return x*10000+y;
}
int main(){
    ll n;
    cin >> n;

    while(n--){
        ll x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2>>y2;

        ll dx=x2-x1;
        ll dy=y2-y1;

        ll g=gcd(abs(dx),abs(dy));

        ll stepx=dx/g;
        ll stepy=dy/g;

        ll x=x1;
        ll y=y1;


        for(ll i=0;i<=g;i++){
            cnt[encode(x,y)]++;
            x+=stepx;
            y+=stepy;
            
        }
    }
    ll res=0;
    for(auto it :cnt){
        if(it.second>=2){
            res++;
        }
    }


    cout << res;



    return 0;
}