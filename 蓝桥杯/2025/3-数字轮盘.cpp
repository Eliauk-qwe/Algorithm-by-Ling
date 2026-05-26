// 初始是 1 2 3 ... N
//   先顺时针转 K 次，相当于整体右移 K 位
//   每次恢复操作，相当于整体右移 2 位
//   问最少操作几次后，整体回到原样



// 初始旋转了 K 次，相当于右移 K 位。
//   每操作一次，又右移 2 位。

//   要恢复初始状态，需要：

//   K + 2x 是 N 的倍数


// #include <bits/stdc++.h>

// typedef long long ll;

// using namespace std;

// int main(){
//     ll t;
//     cin >> t;
//     for(ll j=1;j<=t;j++){
//         ll n,k;
//         cin >> n>> k;

//         int flag=0;
//         for(ll i=0;i<=1e5;i++){
//             ll m=k+2*i;
//             if(m%n==0){
//                 cout << i<< endl;
//                 flag=1;
//                 break;
//             }
//         }
//         if(flag==0){
//             cout << -1 << endl;
            

//         }
//     }
//     return 0;
// }


  #include <bits/stdc++.h>
  using namespace std;

  using ll = long long;

  int main() {
      ios::sync_with_stdio(false);
      cin.tie(nullptr);

      int T;
      cin >> T;

      while (T--) {
          ll N, K;
          cin >> N >> K;

          K %= N;

          if (K == 0) {
              cout << 0 << '\n';
          } else if ((N - K) % 2 == 0) {
              cout << (N - K) / 2 << '\n';
          } else if ((2 * N - K) % 2 == 0) {
              cout << (2 * N - K) / 2 << '\n';
          } else {
              cout << -1 << '\n';
          }
      }

      return 0;
  }