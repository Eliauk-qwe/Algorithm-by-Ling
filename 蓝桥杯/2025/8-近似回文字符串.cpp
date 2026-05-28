  #include <bits/stdc++.h>
  using namespace std;

  const int INF = 1e9;

  int main() {
      ios::sync_with_stdio(false);
      cin.tie(nullptr);

      string s;
      cin >> s;

      int n = s.size();

      // 改成 1 下标，方便处理题目中的区间
      s = " " + s;

      /*
          nxt[i][c] 表示：
          从位置 i 开始往右，第一个字符 c 出现的位置。

          c = 0 表示 'a'
          c = 1 表示 'b'
          ...
          c = 25 表示 'z'
      */
      vector<array<int, 26>> nxt(n + 2);

      for (int c = 0; c < 26; c++) {
          nxt[n + 1][c] = INF;
      }

      for (int i = n; i >= 1; i--) {
          nxt[i] = nxt[i + 1];
          nxt[i][s[i] - 'a'] = i;
      }

      auto get = [&](int L, int R) {
          vector<char> res;
          vector<pair<int, char>> tmp;

          /*
              枚举 26 种字符，找它在 [L, R] 中第一次出现的位置。
              如果出现过，就加入 tmp。
          */
          for (int c = 0; c < 26; c++) {
              int pos = nxt[L][c];

              if (pos <= R) {
                  tmp.push_back({pos, char('a' + c)});
              }
          }

          // 按第一次出现的位置排序，得到去重后的顺序
          sort(tmp.begin(), tmp.end());

          for (auto [pos, ch] : tmp) {
              res.push_back(ch);
          }

          return res;
      };

      int m;
      cin >> m;

      while (m--) {
          int La, Ra, Lb, Rb;
          cin >> La >> Ra >> Lb >> Rb;

          vector<char> A = get(La, Ra);
          vector<char> B = get(Lb, Rb);

          int lenA = A.size();
          int lenB = B.size();
          int len = min(lenA, lenB);

          int ans = 0;

          // 相同位置字符不同，就计入答案
          for (int i = 0; i < len; i++) {
              if (A[i] != B[i]) {
                  ans++;
              }
          }

          // 较长串多出来的部分，每个位置都算不同
          ans += abs(lenA - lenB);

          cout << ans << '\n';
      }

      return 0;
  }