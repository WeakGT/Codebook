int trie[MAXN * 31][2], node;
int tag[MAXN * 31];

void add(int x) {
    int now = 0;
    for (int i = 30; i >= 0; i--) {
        if (!trie[now][x >> i & 1]) trie[now][x >> i & 1] = ++node;
        now = trie[now][x >> i & 1];
        tag[now]++;
    }
}
void del(int x) {
    int now = 0;
    for (int i = 30; i >= 0; i--) {
        now = trie[now][x >> i & 1];
        tag[now]--;
    }
}
int qry(int x) {
    int now = 0, res = 0;
    for (int i = 30; i >= 0; i--) {
        int id = (x >> i & 1) ^ 1;
        if (!tag[trie[now][id]]) id ^= 1;
        now = trie[now][id];
        res = res * 2 + id;
    }
    return res;
}