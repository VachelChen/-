//
//  main.cpp
//  PAT_B1040
//
//  Created by VachelChen on 2020/3/6.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

//暴力
//int main(int argc, const char * argv[]) {
//    string str;
//    cin >> str;
//    int length = int(str.size());
//    int ans = 0;
//    for (int i=0; i<length; i++) {
//        if(str[i] == 'P'){
//            for(int j=i;j<length; j++)
//                if(str[j] == 'A')
//                    for (int k=j; k<length; k++) {
//                        if(str[k] == 'T')
//                        ans++;
//                    }
//        }
//    }
//    cout<<ans<<endl;
//    return 0;
//}


//使用动态规划的方法取巧求解

const int MOD = 1000000007;

int main(int argc, const char * argv[]) {
    string str;
    cin >> str;
    int ans = 0;
    int leftNumP[100000];
    leftNumP[0] = (str[0] == 'P'?1:0);
    for(int i=1;i<str.size();i++){
        if(str[i] == 'P')
            leftNumP[i] = leftNumP[i-1]+1;
        else
            leftNumP[i] = leftNumP[i-1];
    }
    
    int rightNumT = 0;
    for(int i=(int)str.size()-1;i>0;i--){
        if(str[i] == 'T'){
            rightNumT++;
        }
        if(str[i] == 'A'){
             ans = (ans + rightNumT*leftNumP[i])%MOD;
        }
    }
    cout<<ans<<endl;
    return 0;
}
