//
//  main.cpp
//  PAT_A1069
//
//  Created by VachelChen on 2020/3/7.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

int s2i(string s){
    int x;
    stringstream ss;
    ss << s;
    ss >> x;
    return x;
}

string i2s(int x){
    string s;
    stringstream ss;
    ss << x;
    ss >> s;
    return s;
}

int main(int argc, const char * argv[]) {
    string start;
    cin >> start;
    while (start.size() < 4) {
        start.insert(start.begin(), '0');
    }
    if(start[0] == start[1] && start[1] == start[2] && start[2] == start[3])
        cout<<start<<" - "<<start<<" = 0000"<<endl;
    else if(start == "6174")
        cout<<"7641 - 1467 = 6174"<<endl;
    else
        while(start != "6174"){
            string inc,dec;
            inc = start;
            sort(inc.begin(),inc.end());
            dec = inc;
            reverse(dec.begin(),dec.end());
            int ans;
            
            ans = s2i(dec) - s2i(inc);
            string strAns = i2s(ans);
            while (strAns.size() < 4) {
                strAns.insert(strAns.begin(), '0');
            }
            cout<<dec<<" - "<<inc<<" = "<<strAns<<endl;
            start = strAns;
        }
    return 0;
}
