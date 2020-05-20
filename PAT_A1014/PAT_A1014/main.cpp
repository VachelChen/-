//
//  main.cpp
//  PAT_A1014
//
//  Created by VachelChen on 2020/5/19.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1024;
int n,m,k,q;
int firstWindows[21];

struct downTime{
    int h;
    int m;
};

struct person{
    int id;
    int process;
    downTime dt;
    person(){
        dt.h = -1;
    }
}p[maxn];

queue<person> windows[21];

void coming(int init){
    int x=1;
    int queueNumber = 1;
    int outLine = 0;
    while (x<=init && x!= k+1) {
        windows[queueNumber].push(p[x]);
        queueNumber = (queueNumber+1) % (n+1);
        if(queueNumber == 0) queueNumber++;
        x++;
    }
    
    for (int i=1; i<=540; i++) {
        for (int j=1; j<=n; j++) {
            if (!windows[j].empty()) {
                if (firstWindows[j]>0) {
                    firstWindows[j] --;
                }
                else{
                    firstWindows[j] = windows[j].front().process;
                    firstWindows[j] --;
                }
            }
        }
        for (int j=1; j<=n; j++) {
            if (firstWindows[j] == 0) {
                int number = windows[j].front().id;
                p[number].dt.h = i / 60 + 8;
                p[number].dt.m = i % 60;
                windows[j].pop();
                outLine++;
                firstWindows[j] = -1;
            }
        }
        while (x <= k && outLine>0) {
            int minLine = m;
            int minWindow = 0;
            for (int j=1; j<=n; j++) {
                if (windows[j].size() < minLine) {
                    minWindow = j;
                    minLine = (int)windows[j].size();
                }
            }
            windows[minWindow].push(p[x]);
            x++;
            outLine--;
        }
    }
    
    int maxtime = -1;
    for (int i=1; i<=n; i++) {
        if (firstWindows[i] > 0) {
            maxtime = max(maxtime,firstWindows[i]);
        }
    }
    for (int i=541; i<=maxtime+540; i++) {
        for (int j=1; j<=n; j++) {
            if (firstWindows[j]>0) {
                firstWindows[j] --;
            }
        }
        for (int j=1; j<=n; j++) {
            if (firstWindows[j] == 0) {
                int number = windows[j].front().id;
                p[number].dt.h = i / 60 + 8;
                p[number].dt.m = i % 60;
                windows[j].pop();
                firstWindows[j] = -1;
            }
        }
    }
    
    
    
    
}

int main(int argc, const char * argv[]) {
    memset(firstWindows, -1, sizeof(firstWindows));
    
    scanf("%d %d %d %d",&n,&m,&k,&q);
    for (int i=1; i<=k; i++) {
        p[i].id = i;
        scanf("%d",&p[i].process);
    }
    coming(n*m);
    for (int i=1; i<=q; i++) {
        int y;
        scanf("%d",&y);
        if(p[y].dt.h == -1){
            cout<<"Sorry"<<endl;
        }
        else{
            printf("%02d:%02d\n",p[y].dt.h,p[y].dt.m);
        }
        //cout<<"ok"<<endl;
    }
    return 0;
}
