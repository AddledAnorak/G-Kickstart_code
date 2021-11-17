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
    return min(first, MAX(rest...));
}



void solve() {
    int n;
    read(n);
    
    string p;
    read(p);
    
    vi r(n);
    vi y(n);
    vi b(n);
    
    unordered_map<char, vi> mp;
    mp['U'] = vi{0,0,0};
    mp['R'] = vi{1,0,0};
    mp['Y'] = vi{0,1,0};
    mp['B'] = vi{0,0,1};
    mp['O'] = vi{1,1,0};
    mp['P'] = vi{1,0,1};
    mp['G'] = vi{0,1,1};
    mp['A'] = vi{1,1,1};
    
    int i = 0;
    for(char sq : p) {
        vi seq = mp[sq];
        
        r[i] = seq[0];
        y[i] = seq[1];
        b[i] = seq[2];
        
        i++;
    }
    
    int ans = 0;
    int prev = 0;
    
    for(int x : r) {
        if(x == 0) prev = 0;
        else {
            if(prev == 0){
                ans++;
                prev = 1;
            }
        }
    }
    
    prev = 0;
    for(int x : y) {
        if(x == 0) prev = 0;
        else {
            if(prev == 0){
                ans++;
                prev = 1;
            }
        }
    }
    
    prev = 0;
    for(int x : b) {
        if(x == 0) prev = 0;
        else {
            if(prev == 0){
                ans++;
                prev = 1;
            }
        }
    }
    
    write(ans);
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
