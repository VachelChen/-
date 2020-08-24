//
//  main.cpp
//  BJFU_259
//
//  Created by VachelChen on 2020/8/23.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#define maxn 100
using namespace std;

void insert(char*s,char*t,int pos){
    int length_t = 0,length_s = 0;
    while (s[length_s]!='\0') {
        length_s++;
    }
    while (t[length_t]!='\0') {
        length_t++;
    }
    for (int i=length_s-1; i>=pos-1; i--) {
        s[i+length_t] = s[i];
    }
    for (int j=pos-1;j<pos-1+length_t;j++) {
        s[j] = t[j-pos+1];
    }
    length_s+=length_t;
    s[length_s]='\0';
    cout<<s<<endl;
}


int main(int argc, const char * argv[]) {
    int pos;
    char s[maxn],t[maxn];
    while (cin>>pos && pos) {
        cin >> s;
        cin >> t;
        insert(s, t, pos);
    }
    return 0;
}
