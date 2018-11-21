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

string sVToS(vector<string> s) {
    string repr = "{";

    for (int i = 0; i < s.size(); i++) {
        repr += s[i];

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
