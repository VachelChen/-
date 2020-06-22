//
//  main.cpp
//  PAT_A1042
//
//  Created by VachelChen on 2020/6/22.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <sstream>
using namespace std;

string p[55];
int a[55];
string temp[55];

string i2s(int x){
    stringstream ss;
    string str;
    ss << x;
    ss >> str;
    return str;
}

int n;
int main(int argc, const char * argv[]) {
    int index = 1;
    for (int i=0; i<4; i++) {
        for (int j=0; j<13; j++) {
            string x="";
            switch (i) {
                case 0:x += "S";break;
                case 1:x += "H";break;
                case 2:x += "C";break;
                case 3:x += "D";break;
                default:break;
            }
            x += i2s(j+1);
            p[index++] = x;
        }
    }
    p[53] = "J1";
    p[54] = "J2";
    
    cin >> n;
    for (int i=1; i<=54; i++) {
        cin >> a[i];
    }
    while (n--) {
        for (int i=1; i<=54; i++) {
            temp[a[i]] = p[i];
        }
        for (int i=1; i<=54; i++) {
            p[i] = temp[i];
        }
    }
    cout<<p[1];
    for (int i=2; i<=54; i++) {
        cout<<" "<<p[i];
    }
    cout<<endl;
    return 0;
}
