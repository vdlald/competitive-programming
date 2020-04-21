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

int n, m;
pair<int,int> e[101]{};

void read() {
    cin >> n >> m;
    int t1, t2;
    REP(i, m) {
        cin >> t1 >> t2;
        auto *p1 = &e[t1];
        auto *p2 = &e[t2];
        if (p1->first == 0) {
            p1->first = t2;
        } else {
            p1->second = t2;
        }
        if (p2->first == 0) {
            p2->first = t1;
        } else {
            p2->second = t1;
        }
    }
}

void solve() {
    int r = 0;
    vector<int> t1, t2;
    t1.push_back(1);
//    t2.push_back(e[1].first);
    int m1, m2, m3;
    for (int i = 2; i <= n; ++i) {
        m1 = i;
        m2 = e[i].first;
        m3 = e[i].second;
        if (m2 == 0 && m3 == 0) {
            if (t1.size() > t2.size()) {
                t2.push_back(m1);
            } else {
                t1.push_back(m1);
            }
        }
        bool m1inT1 = find(t1.begin(), t1.end(), m1) != t1.end();
        bool m1inT2 = find(t2.begin(), t2.end(), m1) != t2.end();
        if (m1inT1 || m1inT2) {
            continue;
        }
        bool m2inT1 = find(t1.begin(), t1.end(), m2) != t1.end();
        bool m2inT2 = find(t2.begin(), t2.end(), m2) != t2.end();
        bool m3inT1 = find(t1.begin(), t1.end(), m3) != t1.end();
        bool m3inT2 = find(t2.begin(), t2.end(), m3) != t2.end();
        if (m2inT1 && m3inT2 || m2inT2 && m3inT1) {
            r++;
            continue;
        }
        if (m2inT1 || m3inT1) {
            t2.push_back(m1);
        } else if (m2inT2 || m3inT2) {
            t1.push_back(m1);
        } else {
            if (t1.size() > t2.size()) {
                t2.push_back(m1);
            } else {
                t1.push_back(m1);
            }
        }
    }
    cout << (r + fabs(t1.size() - t2.size()));
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
