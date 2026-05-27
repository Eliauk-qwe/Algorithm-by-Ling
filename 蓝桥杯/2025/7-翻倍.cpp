// #include <bits/stdc++.h>

// using namespace std;

// typedef long long ll;
// const ll N=2e5+10;
// vector<ll> a(N);
// int main(){
//     ll n;
//     cin >> n;
//     ll sum=0;
//     for(ll i=1;i<=n;i++){
//         cin >> a[i];
//         if(a[i]<a[i-1]){
//             ll cnt=0;
//             while(a[i]<a[i-1]){
//                 a[i]*=2;
//                 cnt++;
//             }
//             sum+=cnt;
//         }
//     }
//     cout << sum<< endl;

//     return 0;

// }

  #include <bits/stdc++.h>
  using namespace std;

  using ll = long long;

  int main() {
      ios::sync_with_stdio(false);
      cin.tie(nullptr);

      int n;
      cin >> n;

      long double pre;
      unsigned long long x;
      cin >> x;

      pre = log2((long double)x);

      long long ans = 0;

      for (int i = 2; i <= n; i++) {
          cin >> x;

          long double cur = log2((long double)x);

          if (cur < pre) {
              ll cnt = (ll)ceil(pre - cur -1e-15);
              ans += cnt;
              cur += cnt;
          }

          pre = cur;
      }

      cout << ans << '\n';

      return 0;
  }