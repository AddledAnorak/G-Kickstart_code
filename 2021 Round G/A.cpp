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
string ANS_DATA = "";



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


template<class T> void write(T data) {
    ANS_DATA += to_string(data);
}



void solve() {
    int n, d, c, m;
    cin >> n >> d >> c >> m;
    
    string line;
    cin >> line;
    
    int numdogs = 0, numcats = 0;
    EACH(animal, line) {
        if(animal == 'D') numdogs++;
        else numcats++;
    }
    
    if(d < numdogs) {
        write("NO");
        return;
    }
    
    int currDogs = 0;
    
    EACH(animal, line) {
        if(animal == 'D') {
            currDogs++;
            d--; 
            c += m;
            
            if(d == 0 && currDogs != numdogs) {
                write("NO");
                return;
            }
        }
        
        if(currDogs == numdogs) {
            write("YES");
            return;
        }
        
        if(animal == 'C') {
            if(c == 0) {
                write("NO");
                return;
            }
            c--;
        }
    }
}


int main()
{
    int testCases;
    cin >> testCases;
    
    FORVAR(testCases, testIndex) {
        ANS_DATA = "";
        solve();
        cout << "Case #" << testIndex+1 << ": " << ANS_DATA << endl;
    }
}