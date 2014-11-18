class  Solution {
 public:
  bool isMatch(const char* s, const char* p) {
    if (!s || !p) return false;
    int n = strlen(s);
    bool *pre = new bool[n + 1];
    bool *now = new bool[n + 1];
    pre[0] = true;
    for (; *p; p++) {
      if (*p == '*') {
        bool flag = false;
        for (int i = 0; i <= n; i++) 
          now[i] = flag |= pre[i];
      } else {
        now[0] = false;
        for (int i = 1; i <= n; i++) 
          now[i] = pre[i - 1] && (*p == '?' || *p == s[i - 1]);
      }
      swap(pre, now);
    }
    return pre[n];
  }
};
