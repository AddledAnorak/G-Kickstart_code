#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <limits.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define FOR(n) for(int i = 0; i < n; i++)
#define FORVAR(n, var) for(int var = 0; var < n; var++)
#define EACH(var, list_) for (auto& var: list_)
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
string ANS_DATA = "";


// to_string
string to_string(char c) {
    return string(1, c);
}

string to_string(bool b) {
	return b ? "true":"false";
}

string to_string(const char* s) {
	return string(s);
}

string to_string(string s) {
	return s;
}


// write
template<class T> void write(T data) {
    ANS_DATA += to_string(data);
}

template<class T> void write(vt<T> vec) {
    EACH(data, vec) {
        write(data);
        write(' ');
    }
}

template<class A, class B> void write(map<A, B> mp) {
    EACH(data, mp) {
        write("<" + to_string(data.first) + "," + to_string(data.second) + ">");
    }
}

template<class T, class... Rest>
void write(T first, Rest... rest) {
    write(first);
    write(' ');
    write(rest...);
}



// read
template<class T> void read(T& var) {
    cin >> var;
}

template<class T> void read(vt<T>& vec) {
    EACH(item, vec) {
        read(item);
    }
}

template<class T, class... Rest>
void read(T& first, Rest&... rest) {
    read(first);
    read(rest...);
}


// MAX
template<class T> T MAX(T first) {
    return first;
}

template<class T> T MAX(vt<T> nums) {
    return *max_element(all(nums));
}

template<class T, class... Rest>
T MAX(T first, Rest... rest) {
    return max(first, MAX(rest...));
}


// MIN
template<class T> T MIN(T first) {
    return first;
}

template<class T> T MIN(vt<T> nums) {
    return *min_element(all(nums));
}

template<class T, class... Rest>
T MIN(T first, Rest... rest) {
    return min(first, MIN(rest...));
}


void solve() {
    int n, x, y;
    read(n, x, y);

    long long nr = x*n*(n+1);
    long long dr = 2*x + 2*y;

    if(nr % dr != 0) {
        write("IMPOSSIBLE");
        return;
    }

    vi nums;
    long long s = nr/dr;

    for(int i = n; i >= 1; i--) {
        if(i <= s) {
            s -= i;
            nums.pb(i);
        }

        if(s == 0) 
            break;
    }

    write("POSSIBLE\n");
    write(nums.size(), '\n');
    EACH(num, nums) {
        write(num, ' ');
    }
}

int main() {
    int testCases;
    cin >> testCases;
    
    FORVAR(testCases, testIndex) {
        ANS_DATA = "";
        solve();
        cout << "Case #" << testIndex+1 << ": " << ANS_DATA << endl;
    }
}
