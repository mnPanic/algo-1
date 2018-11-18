#include <iostream>
#include "vector"
#include <string>


using namespace std;

/******************************** UTILIDAD ********************************/

string vToS(vector<int> s) {
    string repr = "{";

    for (int i = 0; i < s.size(); i++) {
        repr += to_string(s[i]);

        if (i != s.size() - 1) {
            repr += ", ";
        }
    }

    repr += "}";

    return repr;
}

string mToS(vector<vector<int>> s) {
    string repr = "{";

    for (int i = 0; i < s.size(); i++) {
        if (i != 0) {
            repr += " ";
        }

        repr += vToS(s[i]);

        if (i != s.size() - 1) {
            repr += ",\n";
        }
    }

    repr += "}";

    return repr;
}


/******************************** EJ 5 ********************************/

void addLengthSeq(vector<vector<int>> &to, int e) {
    to.push_back({e, 1});
}

vector<vector<int>> comprimir(vector<int> s) {
    vector<vector<int>> res;
    addLengthSeq(res, s[0]);

    int actual = 0;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1] + 1) {
            res[actual][1]++;
        } else {
            addLengthSeq(res, s[i]);
            actual++;
        }
    }

    return res;
}

int main() {

    cout << "<1, 2, 3, 4, 5>"       << endl << mToS(comprimir({1,2,3,4,5}))     << endl;
    cout << "<1, 2, 3, 10, 11>"     << endl << mToS(comprimir({1,2,3,10,11}))   << endl;
    cout << "<1, 2, 3, 100, 102>"   << endl << mToS(comprimir({1,2,3,100,102})) << endl;
    cout << "<5, 4, 3, 2, 1>"       << endl << mToS(comprimir({5,4,3,2,1}))     << endl;


    return 0;
}


