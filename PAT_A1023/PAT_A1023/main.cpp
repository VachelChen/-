//
//  main.cpp
//  PAT_A1023
//
//  Created by VachelChen on 2020/6/15.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <map>
#include <sstream>
using namespace std;
const int maxn = 30;

string i2s(int x){
    stringstream ss;
    string s;
    ss << x;
    ss >>s;
    return s;
}

map<char, int> m1,m2;
string k,k2;
int a[maxn];

int main(int argc, const char * argv[]) {
    cin >> k;
    int index = 0;
    int jinwei = 0;
    for (int i=(int)k.length()-1; i>=0; i--) {
        m1[k[i]]++;
        a[index++] = ((k[i]-'0')*2 + jinwei)%10;
        jinwei = 0;
        if ((k[i]-'0')*2 + jinwei >= 10) {
            jinwei = ((k[i]-'0')*2+jinwei)/10;
        }
    }
    if (jinwei) {
        a[index++] = jinwei;
    }
    for (int i=index-1; i>=0; i--) {
        k2.append(i2s(a[i]));
    }
    for (int i=0; i<k2.length(); i++) {
        m2[k2[i]]++;
    }
    bool flag = true;
    if(m1.size() == m2.size()){
        for (map<char,int> ::iterator it = m1.begin(); it!=m1.end(); it++) {
            if (m1[it->first] != m2[it->first]) {
                cout<<"No"<<endl;
                flag = false;
                break;
            }
        }
        if(flag)
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    cout<<k2<<endl;
    return 0;
}
