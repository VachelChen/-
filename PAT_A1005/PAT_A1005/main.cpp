//
//  main.cpp
//  PAT_A1005
//
//  Created by VachelChen on 2020/5/7.
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

int change(string s){
    int sum=0;
    for (int i=0; i<s.size(); i++) {
        sum += s[i] - '0';
    }
    return sum;
}

string ans(char c){
    if (c == '1') {
        return "one";
    }
    else if(c == '2'){
        return "two";
    }
    else if(c == '3'){
        return "three";
    }
    else if(c == '4'){
        return "four";
    }
    else if(c == '5'){
        return "five";
    }
    else if(c == '6'){
        return "six";
    }
    else if(c == '7'){
        return "seven";
    }
    else if(c == '8'){
        return "eight";
    }else if(c == '9'){
        return "nine";
    }
    else{
        return "zero";
    }
}

void spell(int x){
    string s = i2s(x);
    
    cout<<ans(s[0]);
    for (int i=1; i<s.size(); i++) {
        cout<<" "<<ans(s[i]);
    }
}

int main(int argc, const char * argv[]) {
    string s;
    cin >> s;
    int x = change(s);
    spell(x);
    cout<<endl;
    return 0;
}
