#include <algorithm>
#include <cstdio>
#include<math.h>
using namespace std;

typedef long long ll;
#define REP(i, n) for (int i = 0; i < (n); i++)

int ri()
{
  int x;
  scanf("%d", &x);
  return x;
}

const int N = 100000, Q = 100000;
int nn, block, a[N], l[N], r[N], h[N], c[N], fenwick[N];
ll cnt = 0, ans[Q];
struct B
{
  int l, r, id;
  bool operator<(const B &o) const {
    int i = l/block, j = o.l/block;
    return i < j || i == j && r < o.r;
  }
} b[Q];

int getSum(int x)
{
  int s = 0;
  for (; x; x &= x-1)
    s += fenwick[x-1];
  return s;
}

void add(int x, int v)
{
  for (; x < nn; x |= x+1)
    fenwick[x] += v;
}

void remove(int i)
{
  add(h[i], -1);
  cnt -= getSum(r[i]) - getSum(l[i]);
}

void add(int i)
{
  cnt += getSum(r[i]) - getSum(l[i]);
  add(h[i], 1);
}

int main()
{
  int n = ri(), k = ri();
  REP(i, n)
    a[i] = ri();
  copy_n(a, n, c);
  sort(c, c+n);
  nn = unique(c, c+n) - c;
  REP(i, n) {
    l[i] = lower_bound(c, c+nn, a[i]-k) - c;
    r[i] = upper_bound(c, c+nn, a[i]+k) - c;
    h[i] = lower_bound(c, c+nn, a[i]) - c;
  }
  
  int q = ri();
  block = max(1.0, sqrt(double(n)*n/max(1, q)));
  REP(i, q) {
    b[i].id = i;
    b[i].l = ri();
    b[i].r = ri()+1;
  }
  sort(b, b+q);
  int l = 0, r = 0;
  REP(i, q) {
    while (l < b[i].l) remove(l++);
    while (b[i].l < l) add(--l);
    while (b[i].r < r) remove(--r);
    while (r < b[i].r) add(r++);
    ans[b[i].id] = cnt;
  }
  REP(i, q)
    printf("%lld\n", ans[i]);
}
