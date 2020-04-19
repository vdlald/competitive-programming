#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, size) for (int i = 0; i < size; ++i)
#define fs(x) fast_scan(x)
#define fsa(a, size) fast_scan(a, size)
#define fsw(x, size) fast_scan_word(x, size)
#define fsl(x, size) fast_scan_line(x, size)
#define fw(x) fast_write(x)

size_t fast_scan_num_to_array(short *buf, size_t sizeBuf);

template<typename T>
void fast_scan(T &number);

template<typename T>
inline void fast_scan(T *nums, size_t size);

size_t fast_scan_line(char *chars, size_t size);

size_t fast_scan_word(char *chars, size_t size);

inline void fast_write(int num);

inline void fast_write(char *str);

int comp_double(double a, double b);

vector<string> string_split(char *str, char *delimiter);

template <size_t size>
class BigInt {
private:
    size_t busy;
    bool negative;
public:
    array<short, size> digits;
    BigInt() {
        busy = 0;
        negative = false;
        for (int j = 0; j < size; ++j) {
            digits[j] = 0;
        }
    }

    friend istream& operator>>(istream& input, BigInt &o) {
        string number;
        int i = 0;
        input >> number;
        if (number.at(0) == '-') {
            o.negative = true;
            i = 1;
        }
        for (; i < number.size(); ++i) {
            o.digits[i] = number.at(i) - 48;
            o.busy++;
        }
        return input;
    }

    void fast_scan_from_std_in() {
        int c;
        size_t i;

        c = getchar();
        if (c == '-') {
            negative = true;
            c = getchar();
        }

        for (i = 0; (c > 47 && c < 58 && i < size); c = getchar(), i++) {
            digits[i] = c - 48;
            busy++;
        }
    }

    string to_string() {
        stringstream ss;
        for (int i = 0; i < busy; ++i) {
            ss << digits[i];
        }
        return ss.str();
    }

//    friend BigInt operator+(const BigInt& left, const BigInt& right) {
//        BigInt<max(left.busy, right.busy)+1> res;
//        for (int i = 0; i < left.busy && i < right.busy; ++i) {
//            res.digits
//        }
//    }
};

BigInt<251> x;
BigInt<251> y;

void read() {
//    x.fast_scan_from_std_in();
    cin >> x;
//    y.fast_scan_from_std_in();
}

void solve() {
    cout << x.to_string();
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

vector<string> split(const string &s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

size_t fast_scan_num_to_array(short *buf, size_t sizeBuf) {
    int c;
    size_t i;

    c = getchar();
    if (c == '-') {
        buf[0] = 1;
        c = getchar();
    } else {
        buf[0] = 0;
    }

    for (i = sizeBuf - 1; (c > 47 && c < 58); c = getchar(), i--)
        buf[i] = c - 48;

    return sizeBuf - i - 1;
}
