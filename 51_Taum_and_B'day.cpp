#include <bits/stdc++.h>
using namespace std;

long long taumBday(long long b, long long w, long long bc, long long wc, long long z) {
    long long black_cost = min(bc, wc + z);
    long long white_cost = min(wc, bc + z);
    return b * black_cost + w * white_cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long b, w;
        cin >> b >> w;
        long long bc, wc, z;
        cin >> bc >> wc >> z;

        cout << taumBday(b, w, bc, wc, z) << "\n";
    }

    return 0;
}
