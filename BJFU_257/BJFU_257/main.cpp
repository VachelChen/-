//
//  main.cpp
//  BJFU_257
//
//  Created by VachelChen on 2020/8/22.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <string.h>
#define maxn 100
using namespace std;

int main(int argc, const char * argv[]) {
    char c[maxn];
    int s[40];
    while (cin>>c) {
        memset(s, 0, sizeof(s));
        if (c[0] == '0' && c[1]=='\0') {
            break;
        }
        for (int i=0; i<strlen(c); i++) {
            if (c[i]<='9' && c[i]>='0') {
                s[(int)c[i]-48]++;
            }
            else if (c[i]<='Z' && c[i]>='A') {
                s[(int)c[i]-55]++;
            }
        }
        for (int j=0; j<40; j++) {
            if (s[j] != 0 && j<10) {
                cout<<(char)(j+48)<<":"<<s[j]<<endl;
            }
            else if(s[j] != 0 && j>=10){
                cout<<(char)(j+55)<<":"<<s[j]<<endl;
            }
        }
    }
    return 0;
}
