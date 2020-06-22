//
//  main.cpp
//  PAT_A1038
//
//  Created by VachelChen on 2020/6/19.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

string s[10100];

bool cmp(string a,string b){
    return a+b < b+a;
}

int main(int argc, const char * argv[]) {
    string str="";
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> s[i];
    }
    sort(s, s+n, cmp);
    for (int i=0; i<n; i++) {
        str += s[i];
    }
    while (str[0] == '0' && str.size()>1) {
        str.erase(str.begin());
    }
    cout<<str<<endl;
    return 0;
}
