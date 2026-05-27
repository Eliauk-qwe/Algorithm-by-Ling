  #include <bits/stdc++.h>
  using namespace std;

  using ll = long long;

  int main() {
      ios::sync_with_stdio(false);
      cin.tie(nullptr);

      ll N;
      cin >> N;

      vector<ll> pow5(25, 1);
      for (int i = 1; i < 25; i++) {
          pow5[i] = pow5[i - 1] * 5;
      }

      int len = 2;

      // 找答案是几位数
      while (true) {
          ll cnt = 9 * pow5[len - 1];

          if (N > cnt) {
              N -= cnt;
              len++;
          } else {
              break;
          }
      }

      // 改成从 0 开始数，方便整除取下标
      N--;

      string ans;
      int last = -1;

      for (int pos = 0; pos < len; pos++) {
          vector<int> cand;

          if (pos == 0) {
              // 第一位可以是 1~9
              for (int d = 1; d <= 9; d++) {
                  cand.push_back(d);
              }
          } else {
              // 后面的位必须和上一位奇偶不同
              if (last % 2 == 0) {
                  // 上一位是偶数，这一位只能是奇数
                  cand = {1, 3, 5, 7, 9};
              } else {
                  // 上一位是奇数，这一位只能是偶数
                  cand = {0, 2, 4, 6, 8};
              }
          }

          // 如果当前位选定一个数字，后面还有 rem 位
          // 每一位都有 5 种选择，所以每个候选数字对应 5^rem 个数
          int rem = len - pos - 1;
          ll block = pow5[rem];

          int idx = N / block;
          N %= block;

          int d = cand[idx];
          ans.push_back(char('0' + d));
          last = d;
      }

      cout << ans << '\n';

      return 0;
  }


// #include <bits/stdc++.h>

// using namespace std;

// typedef long long ll;


//  bool ok(long long x) {
//       string s = to_string(x);

//       if (s.size() < 2) return false;

//       for (int i = 1; i < s.size(); i++) {
//           int a = s[i - 1] - '0';
//           int b = s[i] - '0';

//           if (a % 2 == b % 2) {
//               return false;
//           }
//       }

//       return true;
//   }

// int main(){
//     ll n;
//     cin >> n;
//     ll count=0;
//     for(int i=10;i<=1e10;i++){
//         if(ok(i)){
//             count++;
//             if(count==n){
//                 cout<< i;
//                 return 0;
//             }
//         }
//     }
// }