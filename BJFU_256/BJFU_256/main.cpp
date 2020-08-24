//
//  main.cpp
//  BJFU_256
//
//  Created by VachelChen on 2020/8/15.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

bool judge(string a,string b){
    int i=0,j=0;
    while (i<a.size() && j<b.size()) {
        if (a[i] == b[j]) {
            i++;j++;
        }
        else{
            j = j-i+1;
            i = 0;
        }
    }
    if(i==a.size()) return true;
    else return false;
}

int main(int argc, const char * argv[]) {
    string a,b;
    bool flag;
    while(cin >> a >> b){
        if (a == "0" && b=="0") break;
        flag = false;
        string da = a+a;
        for (int i=0; i<a.size(); i++) {
            string ca = da.substr(i,a.size());
            if (judge(ca,b)) {
                flag = true;
                break;
            }
        }
        if (flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
