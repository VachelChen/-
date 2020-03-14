//
//  main.cpp
//  PAT_A1060
//
//  Created by VachelChen on 2020/3/14.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

int n;

string deal(string s,int & e){
    int k = 0; //数组下标
    while(s[0] == '0' && s.length()>0){
        s.erase(s.begin());
    }
    if(s[0] == '.'){
        s.erase(s.begin()); //去除小数点
        while(s[0] == '0' && s.length()>0){
            s.erase(s.begin());
            e--;
        }
    }
    else{
        while (s[k] != '.' && k < s.length()) {
            k++;
            e++;
        }
        if (k < s.length()) {
            s.erase(s.begin()+k);
        }
    }
    if(s.length() == 0){
        e = 0;
    }
    while (s.length()<n) {
        s.append("0");
    }
    return s.substr(0,n);
}

int main(int argc, const char * argv[]) {
    string s1,s2,s3,s4;
    cin>> n >> s1 >> s2;
    int e1,e2;
    e1 = e2 = 0;
    s3 = deal(s1, e1);
    s4 = deal(s2, e2);
    if(s3 == s4 && e1 == e2){
        cout<<"YES 0."<<s3<<"*10^"<<e1<<endl;
    }
    else{
        cout<<"NO 0."<<s3<<"*10^"<<e1<<" 0."<<s4<<"*10^"<<e2<<endl;;
    }
    return 0;
}
