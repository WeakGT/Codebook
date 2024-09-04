auto cmp = [](int a, int b) {
        return a > b;
};
set<int, decltype(cmp)> s = {1, 2, 3, 4, 5};
cout << *s.begin() << '\n';