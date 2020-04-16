#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fs(x) fast_scan(x)
#define fw(x) fast_write(x)

inline void fast_scan(int &number);
inline void fast_write(int num);

int lowerCase(char c) {
    if (c >= 'A' && c <= 'Z')
        return (int) c + 32;
    return c;
}

void solve() {
    string string1;
    string string2;
    getline(cin, string1);
    getline(cin, string2);
    for (int i = 0; i < string1.size(); ++i) {
        int s1 = lowerCase(string1.at(i));
        int s2 = lowerCase(string2.at(i));
        if (s1 != s2) {
            if (s1 > s2) {
                cout << 1;
            } else {
                cout << -1;
            }
            return;
        }
    }
    cout << 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

inline void fast_scan(int &number) {
    //variable to indicate sign of input number
    bool negative = false;
    int c;

    number = 0;

    // extract current character from buffer
    c = getchar();
    if (c == '-') {
        // number is negative
        negative = true;

        // extract the next character from the buffer
        c = getchar();
    }

    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c > 47 && c < 58); c = getchar())
        number = number * 10 + c - 48;

    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}

inline void fast_write(int num) {
    int N = num, rev, count = 0;
    rev = N;
    if (N == 0) {
        putchar('0');
        putchar('\n');
        return;
    }
    while ((rev % 10) == 0) {
        count++;
        rev /= 10;
    } //obtain the count of the number of 0s
    rev = 0;
    while (N != 0) {
        rev = (rev << 3) + (rev << 1) + N % 10;
        N /= 10;
    }  //store reverse of N in rev
    while (rev != 0) {
        putchar(rev % 10 + '0');
        rev /= 10;
    }
    while (count--) putchar('0');
}
