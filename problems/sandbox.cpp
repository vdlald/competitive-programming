#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fs(x) fast_scan(x)
#define fw(x) fast_write(x)

inline void fast_scan(int &number);
inline void fast_write(int num);



void solve() {

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
    c = getchar_unlocked();
    if (c == '-') {
        // number is negative
        negative = true;

        // extract the next character from the buffer
        c = getchar_unlocked();
    }

    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c > 47 && c < 58); c = getchar_unlocked())
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
        putchar_unlocked('0');
        putchar_unlocked('\n');
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
        putchar_unlocked(rev % 10 + '0');
        rev /= 10;
    }
    while (count--) putchar_unlocked('0');
}
