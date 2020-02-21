//
//  main.cpp
//  2016_寒假作业
//
//  Created by VachelChen on 2020/2/21.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int a[13];
    int ans=0;
    for(int i=0;i<13;i++)
        a[i]=i+1;
    do{
        if(a[0]+a[1] == a[2] &&
           a[3]-a[4] == a[5] &&
           a[6]*a[7] == a[8] &&
           a[9]/a[10] == a[11] && a[9]%a[10] == 0){
            ans++;
        }
    }while(next_permutation(a,a+13));
    cout<<ans<<endl;
    return 0;
}
