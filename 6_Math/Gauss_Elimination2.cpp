#include<bits/stdc++.h>
using namespace std;
const int maxn = 20 + 5;
struct mat {
    double a[maxn][maxn];
    int n, m;
};

void gauss_elim(mat &A) {
    for (int i = 0; i < A.n; i++) {
        int id = i ;
        for (int j = i + 1; j < A.n; j++)
            if (fabs(A.a[j][i]) > fabs(A.a[id][i])) id = j ;
        if (id != i)
            for (int j = 0; j < A.m; j++) swap(A.a[i][j], A.a[id][j]) ;

        for (int j = i + 1; j < A.n; j++)
        {
            double f = A.a[j][i] / A.a[i][i] ;
            for (int k = i; k < A.m; k++)
                A.a[j][k] -= A.a[i][k] * f ;
        }
    }

    for (int i = A.n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < A.n; j++)
            A.a[i][A.m - 1] -= A.a[j][A.m - 1] * A.a[i][j] ;
        A.a[i][A.m - 1] /= A.a[i][i] ;
    }
}

mat A ;
main()
{
    int T ; scanf("%d", &T) ;
    while (T--)
    {
        int n ; scanf("%d", &n) ;
        A.n = n ; A.m = n + 1 ;
        for (int i = 0; i < n; i++) for (int j = 0; j < n + 1; j++)
                A.a[i][j] = 0.0 ;
        for (int i = 0; i < n; i++)
        {
            int k ; scanf("%d", &k) ;
            while (k--)
            {
                int x ; scanf("%d", &x) ;
                A.a[i][x] = 1.0 ;
            }
            scanf("%lf", &A.a[i][n]) ;
        }
        gauss_elim(A) ;
        for (int i = 0; i < n; i++) printf("%d\n", int(A.a[i][n] + 0.5)) ;
    }
}