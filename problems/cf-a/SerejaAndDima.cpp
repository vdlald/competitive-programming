#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, size) for (int i = 0; i < size; ++i)
#define fs(x) fast_scan(x)
#define fsw(x, s) fast_scan_word(x, s)
#define fsl(x, s) fast_scan_line(x, s)
#define fw(x) fast_write(x)

inline void fast_scan(int &number);

size_t fast_scan_line(char *chars, size_t size);

size_t fast_scan_word(char *chars, size_t size);

inline void fast_write(int num);

inline void fast_write(char *str);

inline void fast_write(char c);

int n;
int s = 0, d = 0;
int arr[1001];

void solve() {
    fs(n);
    REP(i, n) {
        fs(arr[i]);
    }
    bool turn = true; // if true - s
    int r = n - 1;
    int l = 0;
    while (l != r) {
        if (turn) {
            if (arr[l] > arr[r]) {
                s += arr[l];
                l++;
            } else {
                s += arr[r];
                r--;
            }
            turn = false;
        } else {
            if (arr[l] > arr[r]) {
                d += arr[l];
                l++;
            } else {
                d += arr[r];
                r--;
            }
            turn = true;
        }
    }
    if (n & 1) {
        s += arr[l];
    } else {
        d += arr[l];
    }
    fw(s);
    fw(' ');
    fw(d);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

size_t fast_scan_word(char *chars, size_t size) {
    char temp;
    for (int i = 0; i < size; ++i) {
        temp = (char) getchar();
        if (temp == '\n' || temp == ' ' || temp == '\0')
            return i;
        chars[i] = temp;
    }
}

size_t fast_scan_line(char *chars, size_t size) {
    char temp;
    for (int i = 0; i < size; ++i) {
        temp = (char) getchar();
        if (temp == '\n' || temp == '\0')
            return i;
        chars[i] = temp;
    }
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

inline void fast_write(char *str) {
    for (int i = 0; str[i]; i++)
        putchar(str[i]);
}

inline void fast_write(char c) {
    putchar(c);
}
