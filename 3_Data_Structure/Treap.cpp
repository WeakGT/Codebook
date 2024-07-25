#include <bits/stdc++.h>
using namespace std;
mt19937 rng;
struct node {
  node *l, *r;
  int v, p, s; bool t; // val, pri, size, tag
  void pull() {
    s = 1;
    for (auto x : {l, r})
      if (x) s += x->s;
  }
  void push() {
    if (t) {
      swap(l, r), t = 0;
      for (auto& x : {l, r})
        if (x) x->t ^= 1;
    }
  }
  node(int _v = 0): v(_v), p(rng()), s(1), t(0), l(0), r(0) {}
};
int sz(node* o) {return o ? o->s : 0;}
node* merge(node* a, node* b) {
  if (!a || !b) return a ? : b;
  if (a->p < b->p) return a->push(), a->r = merge(a->r, b), a->pull(), a;
  else return b->push(), b->l = merge(a, b->l), b->pull(), b;
}
void split(node* o, node*& a, node*& b, int k) { // a < k, b >= k
  if (!o) return a = b = nullptr, void();
  o->push();
  if (o->v < k) a = o, split(o->r, a->r, b, k);
  else b = o, split(o->l, a, b->l, k);
  o->pull();
}
void insert(node*& o, int k) {
  node *a, *b;
  split(o, a, b, k), o = merge(a, merge(new node(k), b));
}
void ssplit(node* o, node*& a, node*& b, int k) { // split first k things
  if (!o) return a = b = nullptr, void();
  o->push();
  if (sz(o->l) + 1 <= k) a = o, ssplit(o->r, a->r, b, k - sz(o->l) - 1);
  else b = o, ssplit(o->l, a, b->l, k);
  o->pull();
}
void reverse(node* o, int l, int r) { // [l, r]
  node *a, *b, *c;
  ssplit(o, a, b, l - 1), ssplit(b, b, c, r - l + 1);
  b->t ^= 1, o = merge(a, merge(b, c));
}
/*
node* root = nullptr;
for (int i = 0; i < n; i++)
  root = merge(root, new node(x));
*/