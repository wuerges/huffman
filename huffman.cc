#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <map>
#include <memory>
#include <optional>
#include <set>

using namespace std;

struct Tree {
    int freq;
    optional<char> c;
    unique_ptr<Tree> left, right;

    bool operator<(const Tree& o) {
        return freq>o.freq;
    }

    Tree(char cp, int f): freq(f), c(cp) {}
    Tree(Tree * l, Tree * r): freq(l->freq+r->freq), left(l), right(r) {}
};

map<char,int> count;
set<Tree> q;

void getFreqs(char t[]) { 
    for (int i=0; i<strlen(t); ++i) {
        count[t[i]]++;
    }
    for (auto& x : count) {
        q.insert(Tree(x.first, x.second));
        //cout << x.first << " " << x.second << endl;
    }
}

int main() {
    char text[500];
    fgets(text, sizeof text, stdin);
    text[strlen(text)-1]=0;
    getFreqs(text);
    //vector<int> frequency=getFreqs(text);
    /*for (int i=0; i<frequency.size(); ++i) {
        cout << frequency[i] << " ";
    }*/
    for (auto e : q) {
        cout << e->freq << " " << *(e->c) << endl;
    }
    return 0;
}
