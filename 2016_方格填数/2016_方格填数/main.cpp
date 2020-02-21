//
//  main.cpp
//  2016_方格填数
//
//  Created by VachelChen on 2020/2/21.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int ans=0;

int main(int argc, const char * argv[]) {
    string s="0123456789";
    do{
        if(abs(s[0] - s[1]) == 1 ||
           abs(s[0] - s[3]) == 1 ||
           abs(s[0] - s[4]) == 1 ||
           abs(s[0] - s[5]) == 1){
            continue;
        }
        if(abs(s[1] - s[2]) == 1 ||
           abs(s[1] - s[4]) == 1 ||
           abs(s[1] - s[5]) == 1 ||
           abs(s[1] - s[6]) == 1){
            continue;
        }
        if(abs(s[2] - s[6]) == 1 ||
           abs(s[2] - s[5]) == 1 ){
            continue;
        }
        if(abs(s[3] - s[4]) == 1 ||
           abs(s[3] - s[7]) == 1 ||
           abs(s[3] - s[8]) == 1){
            continue;
        }
        if(abs(s[4] - s[5]) == 1 ||
           abs(s[4] - s[7]) == 1 ||
           abs(s[4] - s[8]) == 1 ||
           abs(s[4] - s[9]) == 1){
            continue;
        }
        if(abs(s[5] - s[6]) == 1 ||
           abs(s[5] - s[8]) == 1 ||
           abs(s[5] - s[9]) == 1){
            continue;
        }
        if(abs(s[6] - s[9]) == 1){
            continue;
        }
        if(abs(s[7] - s[8]) == 1){
            continue;
        }
        if(abs(s[8] - s[9]) == 1){
            continue;
        }
        ans++;
    }while(next_permutation(s.begin(),s.end()));
    cout<<ans<<endl;
    return 0;
}
