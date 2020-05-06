//
//  main.cpp
//  PAT_A1001
//
//  Created by VachelChen on 2020/5/6.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <sstream>
using namespace std;

string i2s(int x){
    string s;
    stringstream ss;
    ss << x;
    ss >> s;
    return s;
}

int main(int argc, const char * argv[]) {
    int a,b,ans;
    cin >> a >>b;
    ans = a+b;
    bool flag = false;
    if(ans < 0){
        flag = true;
        ans = ans*(-1);
    }
    string str = i2s(ans);
    for (int i=str.size()-3; i>0; i=i-2) {
        str.insert(i,",");
        i--;
    }
    if (flag) {
        str.insert(0,"-");
    }
    cout<< str <<endl;
    return 0;
}
