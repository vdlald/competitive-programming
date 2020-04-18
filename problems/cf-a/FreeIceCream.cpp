#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define FOR(i, size) for (int i = 0; i < size; ++i)
#define FORI(size) for (int i = 0; i < size; ++i)

int comp_double(double a, double b);

vector<string> string_split(char *str, char *delimiter);

ll x;
int n;

void read() {
    cin >> n >> x;
}

void solve() {
    unsigned ll g = 0;
    char c;
    ll d;
    FORI(n) {
        cin >> c >> d;
        if (c == '+') {
            x += d;
        } else if (d <= x){
            x -= d;
        } else {
            g++;
        }
    }
    cout << x << ' ' << g << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    read();
    solve();
    return 0;
}

int comp_double(double a, double b) {
    if (fabs(a - b) <= 1e-10)
        return 0;
    return a < b ? -1 : 1;
}

vector<string> string_split(char *str, char *delimiter) {
    vector<string> tokens;
    char *token = strtok(str, delimiter);

    while (token != nullptr) {
        tokens.emplace_back(token);
        token = strtok(nullptr, delimiter);
    }
    return tokens;
}
