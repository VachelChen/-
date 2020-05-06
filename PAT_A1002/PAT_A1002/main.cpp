//
//  main.cpp
//  PAT_A1002
//
//  Created by VachelChen on 2020/5/6.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

struct Polynomial{
    int n;
    double exp[1010];
    Polynomial(){
        fill(exp,exp+1010,0);
        n = 0;
    }
};

int main(int argc, const char * argv[]) {
    Polynomial a,b;
    
    cin >> a.n;
    for (int i=0; i<a.n; i++) {
        int x;
        cin >> x;
        cin >> a.exp[x];
    }
    
    cin >> b.n;
    for (int i=0; i<b.n; i++) {
        int y;
        cin >> y;
        cin >> b.exp[y];
    }
    
    for (int i=0; i<1001; i++) {
        if(b.exp[i] == 0)  continue;
        
        if(a.exp[i] == 0){
            a.exp[i] = b.exp[i];
            a.n++;
        }
        else{
            a.exp[i] += b.exp[i];
            if(a.exp[i] == 0)   a.n--;
        }
    }
    
    cout<<a.n;
    for (int i=1001; i>=0; i--) {
        if(a.exp[i] != 0){
            cout<<" "<<i<<" ";
            printf("%.1f",a.exp[i]);
        }
    }
    cout<<endl;
    return 0;
}
