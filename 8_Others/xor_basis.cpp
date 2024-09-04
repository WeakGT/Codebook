int basis[20]
bool add(int x) {
    for (int i = 19; i >= 0; i--) {
        if (!(x >> i & 1)) continue;
        if (!basis[i]) {
            basis[i] = x;
            return true;
        }
        else x ^= basis[i];
    }
    return false;
}
// 維持 basis[i] 的最高為是 i