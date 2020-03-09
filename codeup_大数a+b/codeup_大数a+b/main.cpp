//
//  main.cpp
//  codeup_大数a+b
//
//  Created by VachelChen on 2020/3/9.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

string i2s(int x){
    string s;
    stringstream ss;
    ss << x;
    ss >> s;
    return s;
}

int s2i(char s){
    int x;
    stringstream ss;
    ss << s;
    ss >> x;
    return x;
}

int fushu(string a){
    if(a[0] == '-')
        return 1;
    else
        return 0;
}

bool bBigger(string a,string b){
    if(b.size()>a.size()) return true;
    if(b)
}

int main(int argc, const char * argv[]) {
    string a,b;
    string ans;
    while (cin >> a >> b) {
        if(fushu(a)+fushu(b)!=1){
            reverse(a.begin(),a.end());
            reverse(b.begin(),b.end());
            int carry=0;
            for(int i=0;i<max(a.size(),b.size());i++){
                int temp = s2i(a[i]) + s2i(b[i]) + carry;
                ans.append(i2s(temp % 10));
                carry = temp/10;
            }
            if (carry != 0) {
                ans.append(i2s(1));
            }
        }
        else{
            if(fushu(a)){
                string temp = a;
                a = b;
                b = temp;
            }
            b = b.substr(1,sizeof(b));
            reverse(a.begin(),a.end());
            reverse(b.begin(),b.end());
            bool ansSymbol = false;
            if(a.size()<b.size())
                ansSymbol = true;
            int borrow = 0;
            for (int i=0; i<a.size(); i++) {
                int temp = a[i] - b[i] - borrow;
                ans.append(temp>=0?i2s(temp):i2s(abs(temp)));
                if(temp<0)  borrow = 1;
                else    borrow = 0;
            }
            if(borrow == 1)
                
            
        }
        reverse(ans.begin(), ans.end());
        cout<<ans<<endl;
        a = b = ans = "";
    }
    return 0;
}
