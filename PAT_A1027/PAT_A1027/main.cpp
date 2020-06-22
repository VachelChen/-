//
//  main.cpp
//  PAT_A1027
//
//  Created by VachelChen on 2020/6/17.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

char v[14];

string change(int a,int b,int c){
    string x,y,z;
    while (a>13) {
        x += (v[a%13]);
        a /= 13;
    }
    x+=v[a];
    while (x.size()!=2) {
        x+='0';
    }
    reverse(x.begin(), x.end());
    while (b>13) {
        y += (v[b%13]);
        b /= 13;
    }
    y+=v[b];
    while (y.size()!=2) {
        y+='0';
    }
    reverse(y.begin(), y.end());
    while (c>13) {
        z += (v[c%13]);
        c /= 13;
    }
    z+=v[c];
    while (z.size()!=2) {
        z+='0';
    }
    reverse(z.begin(), z.end());
    return x+y+z;
}


int main(int argc, const char * argv[]) {
    v[0] = '0';v[1] = '1';v[2] = '2';v[3] = '3';v[4] = '4';v[5] = '5';
    v[6] = '6';v[7] = '7';v[8] = '8';v[9] = '9';v[10] = 'A';v[11] = 'B';v[12] = 'C';
    int r,g,b;
    cin >> r >> g >> b;
    cout<<"#"<<change(r,g,b)<<endl;
    return 0;
}
