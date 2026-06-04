#include <bits/stdc++.h>

using namespace std;

typedef long long ll;



int main()
{
    ll n,m;
    cin >> n >>  m;

    string s;
    cin >> s;
    string t;
    cin >> t;

    vector<ll> cnt(26,0);

    for(auto x :t){
        cnt[x-'a']++;
    }

    vector<char> minnchar(n+1);

    minnchar[n]='{';

    for(ll i=n-1;i>=0;i--){
        minnchar[i]=min(s[i],minnchar[i+1]);
    }

    string ans;

    for(ll i=0;i<n;i++){
        ll x=s[i]-'a';

        for(ll ch=0;ch<x;ch++){
            while(cnt[ch]>0){
                ans+=char(ch+'a');
                cnt[ch]--;
            }
        }

        if(minnchar[i+1]>=s[i]){
            while(cnt[x]>0){
                ans+=char(x+'a');
                cnt[x]--;
            }
            
        }

        ans+=s[i];

        
    }



    for(ll ch=0;ch<26;ch++){
            while(cnt[ch]>0){
                ans+=char(ch+'a');
                cnt[ch]--;
            }

        }

    cout << ans;

    return 0;
}