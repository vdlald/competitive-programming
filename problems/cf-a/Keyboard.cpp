/*
 * int: -2^31...2^31-1 (-2*10^9...2*10^9)
 * long long: -2^63...2^63-1 (-9*10^18...9*10^18)
 * __int128_t: -2^127...2^127-1 (-10^38...10^38)
 */
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, size) for (int i = 0; i < size; ++i)
#define fs(x) fast_scan(x)
#define fsa(a, size) fast_scan(a, size)
#define fsw(x, size) fast_scan_word(x, size)
#define fsl(x, size) fast_scan_line(x, size)
#define fw(x) fast_write(x)

template<typename T> void fast_scan(T &number);
template<typename T> inline void fast_scan(T *nums, size_t size);
size_t fast_scan_line(char *chars, size_t size);
size_t fast_scan_word(char *chars, size_t size);
inline void fast_write(int num);
inline void fast_write(char *str);
int comp_double(double a, double b);
vector<string> string_split(char *str, char *delimiter);

char m;
char str[101];
std::size_t size;

void read() {
    m = (char) getchar();
    getchar();
    size = fsw(str, 101);
}

void solve() {
    char N1[] = "qwertyuiop";
    char N2[] = "asdfghjkl;";
    char N3[] = "zxcvbnm,./";
    char R1[] = "qqwertyuio";
    char R2[] = "aasdfghjkl";
    char R3[] = "zzxcvbnm,.";
    char L1[] = "wertyuiopp";
    char L2[] = "sdfghjkl;;";
    char L3[] = "xcvbnm,.//";
    map<char, char> L;
    map<char, char> R;
    for (int i = 0; i < 10; ++i) {
        L.insert(make_pair(N1[i], L1[i]));
        L.insert(make_pair(N2[i], L2[i]));
        L.insert(make_pair(N3[i], L3[i]));
        R.insert(make_pair(N1[i], R1[i]));
        R.insert(make_pair(N2[i], R2[i]));
        R.insert(make_pair(N3[i], R3[i]));
    }
    if (m == 'R') {
        for (int i = 0; i < size; ++i) {
            cout << R[str[i]];
        }
    } else {
        for (int i = 0; i < size; ++i) {
            cout << L[str[i]];
        }
    }
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

template<typename T>
inline void fast_scan(T *nums, size_t size) {
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
    if (abs(a - b) <= 1e-9)
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

vector<string> split(const string& s, char delimiter)
{
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}
