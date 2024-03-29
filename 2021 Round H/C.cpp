// THIS CODE ONLY WORKS FOR TS1


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




// THIS CODE ONLY WORKS FOR TS2


class Node {
public:
    char val;
    Node* next;

    Node(char v = ' ', Node* nxt = NULL) {
        val = v;
        next = nxt;
    }

    bool isEq(Node* node) {
        if(node->val != val) return 0;
        if(next == NULL && node->next == NULL) return 1;
        if(next == NULL && node->next != NULL) return 0;

        return next->isEq(node->next);
    }
};

char findNextChar(char c) {
    if(c == '9') return '0';
    return ++c;
}

Node* replaceAll(Node* root, string rep) {
    Node* prev = root;
    Node* curr = root->next;

    while(curr != NULL) {
        if(curr->val == rep[1] && prev->val == rep[0]) {
            prev->val = findNextChar(rep[1]);
            prev->next = curr->next;
        }

        prev = curr;
        curr = curr->next;
    }

    return root;
}

string buildString(Node* node) {
    string s = "";
    while(node != NULL) {
        s += node->val;
        node = node->next;
    }

    return s;
}

void solve() {
    // THIS CODE ONLY WORKS FOR TS1

    int n;
    string s;

    read(n, s);

    Node* head = new Node;
    Node* curr = head;
    Node* prev = new Node;

    string prevString = "abc";
    string currString;

    FOR(n) {
        char c = s[i];
        curr->val = c;

        if(i == n-1) continue;
        curr->next = new Node;

        curr = curr->next;
    }
    

    while(1) {
        curr = replaceAll(
            replaceAll(
                replaceAll(
                    replaceAll(
                        replaceAll(
                            replaceAll(
                                replaceAll(
                                    replaceAll(
                                        replaceAll(
                                            replaceAll(
                                                head, "01"
                                            ), "12"
                                        ), "23"
                                    ), "34"
                                ), "45"
                            ), "56"
                        ), "67"
                    ), "78"
                ), "89"
            ), "90"
        );

        

        currString = buildString(curr);
        if(prevString == currString) break;

        prevString = currString;
    }

    write(prevString);
}






int main() {
    // THIS CODE ONLY WORKS FOR TS1
    int testCases;
    cin >> testCases;
    
    FORVAR(testCases, testIndex) {
        ANS_DATA = "";
        solve();
        cout << "Case #" << testIndex+1 << ": " << ANS_DATA << endl;
    }
}
