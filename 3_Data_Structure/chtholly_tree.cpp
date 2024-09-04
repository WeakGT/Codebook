// 存 {x, v} ，從 x 開始到下一個位置前都是v
map<int, int> s;
// [l, r)
void ins(int l, int r, int i) {
    auto it1 = s.find(l);
    auto it2 = s.find(r);
    for (auto it = it1; it != it2; it++) {
        
    }
    s.erase(it1, it2); // [it`, it2)
    s[l] = ;
}
void split(int pos) {
    auto it = s.lower_bound(pos);
    if (it == s.end() or it->F != pos) {
        s[pos] = prev(it)->S;
    }
}