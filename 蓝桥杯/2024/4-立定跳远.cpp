#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N=1e5+10;
vector<ll> a(N,0);
ll n,m;


bool check(ll l){
    ll need=0;
    bool cansave=false;

    ll start=0;

    for(ll i=1;i<=n;i++){
        ll d=a[i]-start;
        start=a[i];

        if(d==0) continue;

        need+=(d-1)/l;

        if(d>l) cansave=true;

        if(need >m +1) return false;

    }

    if(cansave) need--;

    return need<=m;
}

int main()
{
    cin >> n >> m;

    for(ll i=1;i<=n;i++) cin >> a[i];

    ll minn=1;
    ll maxn=a[n];
    ll res=maxn;

    while(minn<=maxn){
        ll mid=(minn+maxn)/2;

        if(check(mid)){
            res=mid;
            maxn=mid-1;
        }else{
            minn=mid+1;
        }
    }

    cout << res;

    



    return 0;
}