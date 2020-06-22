#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
using namespace std;

map<string, set<int>>title, author, keywords, publicer, year;

void query(map<string, set<int>>&m, string &s) {
    if (m.find(s) != m.end()) {
        for (auto val : m[s])
            printf("%07d\n", val);
    }
    else cout << "Not Found" << endl;
}

int main() {
    int n, id, m, t;
    string ttitle, tauthor, tkeyword, tpublicer, tyear, s;
    
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        scanf("%d\n", &id);
        getline(cin, ttitle);   title[ttitle].insert(id);
        getline(cin, tauthor);  author[tauthor].insert(id);
        while (cin>>tkeyword){
            keywords[tkeyword].insert(id);
            char ch = getchar();
            if (ch == '\n')break;
        }
        getline(cin, tpublicer); publicer[tpublicer].insert(id);
        cin >> tyear; year[tyear].insert(id);
    }
    
    cin >> m;
    
    for (int i = 1; i <= m; i++) {
        scanf("%d: ", &t);
        getline(cin, s);
        cout << t << ": " << s << endl;
        switch (t){
        case 1:query(title, s); break;
        case 2:query(author, s); break;
        case 3:query(keywords, s); break;
        case 4:query(publicer, s); break;
        case 5:query(year, s); break;
        default:break;
        }
    }

    return 0;
}

