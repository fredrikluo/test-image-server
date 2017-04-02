#include "util.h"
#include <iostream>

using namespace std;

void LOG(const char * prefix, const vector<char>&  payload) {
    cout << prefix;
    for (auto itr = payload.begin(); itr != payload.end(); ++ itr) {
        cout << *itr;
    }

    cout << endl;
}

void LOG(const char * str) {
    cout << str << endl;
}

void LOG(const char * str, int extra) {
    cout << str << ":" << extra << endl;
}

