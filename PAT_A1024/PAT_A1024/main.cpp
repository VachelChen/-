//
//  main.cpp
//  PAT_A1024
//
//  Created by VachelChen on 2020/6/15.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

string n;
int k;

bool judge(string s){
    for (int i=0; i<s.size(); i++) {
        if (s[i] != s[s.size()-1-i]) {
            return false;
        }
    }
    return true;
}

string i2s(int x){
    stringstream ss;
    string s;
    ss << x;
    ss >> s;
    return s;
}

int temp[100];
void add(string &a,string b){
    int jinwei = 0;
    int index = 0;
    for (int i=(int)a.size()-1; i>=0; i--) {
        temp[index++] = ((a[i]-'0') + jinwei + (b[i]-'0'))%10;
        if ((a[i]-'0') + jinwei + (b[i]-'0') >= 10) {
            jinwei =  ((a[i]-'0') + jinwei + (b[i]-'0'))/10;
        }
        else{
            jinwei = 0;
        }
    }
    if(jinwei) temp[index++] = jinwei;
    string newa;
    for (int i=index-1; i>=0; i--) {
        newa.append(i2s(temp[i]));
    }
    a = newa;
}

int main(int argc, const char * argv[]) {
    cin >> n >> k;
    int x=0;
    while (!judge(n) && k!=x) {
        string m = n;
        reverse(n.begin(), n.end());
        add(n,m);
        x++;
    }
    while (n[0] == '0') {
        n.erase(0,1);
    }
    cout<<n<<endl<<x<<endl;
    return 0;
}
