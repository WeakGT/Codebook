int mu[MAXN], lp[MAXN];
void build() {
  mu[1] = 1;
  FOR (i, 2, MAXN - 1) {
    if (!lp[i]) {
      for (int j = i; j < MAXN; j += i) {
        lp[j] = i;
      }
    }
    if (i / lp[i] % lp[i])
      mu[i] = -mu[i / lp[i]];
  }
}