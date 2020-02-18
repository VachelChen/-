//
//  main.cpp
//  2014_蚂蚁感冒
//
//  Created by VachelChen on 2020/2/18.
//  Copyright © 2020 VachelChen. All rights reserved.
//
//5
//20 4 -3 -10 -22
#include <iostream>
#include <cmath>
using namespace std;
int direction[50];
int virus;
int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>direction[i];
    }
    virus=direction[0];
    bool flag=false;
    int ans=1;
    if(virus>0){
        for(int i=1;i<n;i++){
            if(virus<abs(direction[i]) && direction[i]*virus<0){
                ans++;
                flag=true;
            }
        }
        if(flag){
            for(int i=1;i<n;i++){
                if(virus>direction[i] && direction[i]*virus>0){
                    ans++;
                }
            }
        }
    }
    else{
        for(int i=1;i<n;i++){
            if(abs(virus)>direction[i] && direction[i]*virus<0){
                ans++;
                flag=true;
            }
        }
        if(flag){
            for(int i=1;i<n;i++){
                if(abs(virus)<abs(direction[i]) && direction[i]*virus>0){
                    ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
