//
//  main.cpp
//  PAT_A1017
//
//  Created by VachelChen on 2020/6/11.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;

const int starttime = 8*3600;
const int endtime = 17*3600;

int s2i(string str){
    stringstream ss;
    int x;
    ss << str;
    ss >> x;
    return x;
}

struct timer{
    int arrive,p;
}person[10010];

int window[110];

bool cmp(timer a, timer b){
    return a.arrive < b.arrive;
}

int main(int argc, const char * argv[]) {
    int n,k;
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        string t;
        int p;
        cin >> t >> p;
        person[i].arrive = (s2i(t.substr(0,1))*10 + s2i(t.substr(1,1)))*3600+
        (s2i(t.substr(3,1))*10 + s2i(t.substr(4,1)))*60+
        s2i(t.substr(6,1))*10 + s2i(t.substr(7,1));
        person[i].p = p*60;
    }
    sort(person,person+n,cmp);
    
    for (int i=0; i<k; i++) {
        window[i] = starttime;
    }
    double total=0;
    int c = 0;
    for (int i=0; i<n; i++) {
        if (person[i].arrive > endtime) break;
        else{
            c++;
            int minserver = INT_MAX;
            int winnumber = 0;
            for (int j=0; j<k; j++) {
                if (window[j] < minserver) {
                    minserver = window[j];
                    winnumber = j;
                }
            }
            int servertime = max(person[i].arrive,minserver);
            total += (servertime - person[i].arrive);
            window[winnumber] = servertime + person[i].p;
        }
    }
    printf("%.1f\n",total/60/c);
    return 0;
}
