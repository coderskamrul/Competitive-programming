//Tempalte
#include<bits/stdc++.h>
using namespace std;


const int N = 1e5 + 9;
int a[N];
long long t[4 * N], lazy[4 * N];

void push(int n, int b, int e) {
  if (lazy[n] == 0) {
    return;
  }

  // if we add lazy[n] to the elements in this segment, what will happen to our t[n]?
  // remember that t[n] = the sum of elements in this segment
  t[n] = t[n] + 1LL * (e - b + 1) * lazy[n];

  // push to the childs
  if (b != e) {
    int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
    lazy[l] += lazy[n];
    lazy[r] += lazy[n];
  }

  lazy[n] = 0;
}


void build(int n, int b, int e) {
  if (b == e) {
    t[n] = a[b];
    return;
  }
  int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
  build(l, b, mid);
  build(r, mid + 1, e);
  t[n] = t[l] + t[r];
}

void upd(int n, int b, int e, int i, int j, int v) {
  push(n, b, e);
  if (e < i or j < b) return;
  if (b >= i and e <= j) {
    // add v to every element in this segment
    lazy[n] = v;
    push(n, b, e);
    return;
  }
  int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
  upd(l, b, mid, i, j, v);
  upd(r, mid + 1, e, i, j, v);
  t[n] = t[l] + t[r];
}

long long query(int n, int b, int e, int i, int j) {
  push(n, b, e);
  if (e < i or j < b) return 0;
  if (b >= i and e <= j) {
    return t[n];
  }
  int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
  return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q; cin >> n >> q;

  build(1, 1, n);
  while (q--) {
    int ty; cin >> ty;
    if (ty == 1) {
      int l, r, v; cin >> l >> r >> v;
      --r;

      ++l; ++r;
      // for (int i = l; i <= r; i++) {
      //   a[i] += v;
      // }
      upd(1, 1, n, l, r, v);
    }
    else {
      int i; cin >> i;
      ++i;

      // cout << a[i] << '\n';
      cout << query(1, 1, n, i, i) << '\n';
    }
  }
  return 0;
}
