#include<bits/stdc++.h>
#define REP(i, n) for (int i = (0); (i) < (n); (i)++)
using namespace std;

typedef long long Long;

const Long MAXN = (int)1e6 + 6;


// const Long MODA = 2;
// const Long MODB = 3;
const Long MODA = 2;
const Long MODB = 500000003;

const Long MOD = MODA * MODB;

Long fab[MAXN]; // fab[i] will store i! without any MODA or MODB factor
Long fa[MAXN];
Long fb[MAXN];

Long nfa[MAXN];
Long nfb[MAXN];

Long getNumberOfFactors(Long n, Long f) { // n <= 10^6
    if (f == MODA) return nfa[n];
    return nfb[n];

    // old (not memo) implementation
    Long ans = 0;
    Long b = f;
    while (b <= n) {
        ans += n / b;
        b = b * f;
    }
    return ans;
}

void init() {
    // cout << getNumberOfFactors((int)1e6, 2); // this results in 999993, so next operation will take that time
    fab[0] = 1;
    fa[0] = 1;
    fb[0] = 1;
    nfa[0] = 0;
    nfb[0] = 0;
    for (int i = 1; i < MAXN; i++) {
        int jab = i;
        int ja = i;
        int jb = i;
        int na = 0;
        while (jab % MODA == 0) {
            jab /= MODA;
            ja /= MODA;
            na++;
        }
        int nb = 0;
        while (jab % MODB == 0) {
            jab /= MODB;
            jb /= MODB;
            nb++;
        }
        nfa[i] = nfa[i - 1] + na;
        nfb[i] = nfb[i - 1] + nb;

        fab[i] = (fab[i - 1] * jab) % (MODA * MODB);
        fa[i] = (fa[i - 1] * ja) % (MODA);
        fb[i] = (fb[i - 1] * jb) % (MODB);
    }
}

pair<pair<Long, Long>, Long> ee(Long x, Long y) {
    Long a = 0, b = 1, r = y;
    Long A = 1, B = 0, R = x;
    Long q;
    while (r != 0) {
        q = R/r;
        R = R - q * r; swap(r, R);
        A = A - q * a; swap(a, A);
        B = B - q * b; swap(b, B);
    }
    return make_pair(make_pair(A, B), R);
}

Long getInv(Long a, Long mod) { // coprimes guaranteed
    auto r = ee(a, mod);
    Long ans = r.first.first;
    while (ans < 0) ans += mod;
    return ans;
}

int main() {
    // auto r = ee(2, 3);
    // cout << r.first.first << r.first.second << r.second << endl; // -1 1 1

    int tc;
    scanf("%d", &tc);

    init();

    REP (itc, tc) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);

        Long na = getNumberOfFactors(b, MODA) - getNumberOfFactors(b - c, MODA) - getNumberOfFactors(c, MODA);
        Long nb = getNumberOfFactors(b, MODB) - getNumberOfFactors(b - c, MODB) - getNumberOfFactors(c, MODB);

        Long ex = 0;
        if (na < 1 || nb < 1) {
            if (na > 0) {
                Long mod = MODB;
                ex = (fb[b] * getInv(fb[b - c], mod))%mod;
                ex = (ex * getInv(fb[c], mod))%mod;
                ex = (ex * getInv(MODA, mod))%mod;
                ex = ex * MODA;
            } else if (nb > 0) {
                Long mod = MODA;
                ex = (fa[b] * getInv(fa[b - c], mod))%mod;
                ex = (ex * getInv(fa[c], mod))%mod;
                ex = (ex * getInv(MODB, mod))%mod;
                ex = ex * MODB;
            } else {
                Long mod = MODA * MODB;
                ex = (fab[b] * getInv(fab[b - c], mod))%mod;
                ex = (ex * getInv(fab[c], mod))%mod;
            }
        }

/**
 * So, we need C(b, c) % (MODA * MODB)
 * 
 * Let D = C(b, c), d = (MODA * MODB), r < d
 * D = d * q + r
 * 
 * consider MODA divides D but MODB doesnt, then r must be a multiple of MODA:
 * D/MODA = d/MODA * q + r/MODA
 * 
 * In this case we just solve for r/MODA  and then multiply by MODA
 * 
 * 
 * **/

        // now we just need a ^ ex , we know ex < 1e9 + 7
        Long ans = 1;
        Long mod = (int)(1e9) + 7;

        while (ex) {
            if (ex&1) ans = (ans * a) % mod;
            a = (a * a) % mod;
            ex >>= 1;
        }
        cout << ans << endl;
    }
}
