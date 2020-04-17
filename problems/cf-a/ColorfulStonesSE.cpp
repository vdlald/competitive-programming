#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, size) for (int i = 0; i < size; ++i)
#define fs(x) fast_scan(x)
#define fsa(a, size) fast_scan(a, size)
#define fsw(x, size) fast_scan_word(x, size)
#define fsl(x, size) fast_scan_line(x, size)
#define fw(x) fast_write(x)
#define nca(size) new char[size]
#define nia(size) new int[size]

template<typename T> void fast_scan(T &number);
inline void fast_scan(int *nums, size_t size);
size_t fast_scan_line(char *chars, size_t size);
size_t fast_scan_word(char *chars, size_t size);
inline void fast_write(int num);
inline void fast_write(char *str);
int comp_double(double a, double b);

char s[51];
char t[51];

void read() {
    fsw(s, 51);
    fsw(t, 51);
}

void solve() {
    int p = 1;
    REP(i, 51) {
        if (s[p-1] == t[i]) {
            p++;
        }
    }
    fw(p);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read();
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

template<typename T>
void fast_scan(T &number) {
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

inline void fast_scan(int *nums, size_t size) {
    for (size_t i = 0; i < size; ++i)
        fs(nums[i]);
}

inline void fast_write(int num) {
    int N = num, rev, count = 0;
    rev = N;
    if (N == 0) {
        putchar('0');
        putchar('\n');
        return;
    }
    if (N < 0) {
        putchar('-');
        N *= -1;
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

int comp_double(double a, double b) {
    if (fabs(a - b) <= 1e-10)
        return 0;
    return a < b ? -1 : 1;
}