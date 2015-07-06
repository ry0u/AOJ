#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

struct Tree {
    string s;
    int index;
    vector<Tree*> v;

    Tree(string _s) {
        s = _s;
        index = 0;
        v.clear();
    }

    Tree(string _s,int id) {
        s = _s;
        index = id;
        v.clear();
    }

    void add(int id,int i,string s) {
        find(i)->v.push_back(new Tree(s,id));
    }

    Tree* find(int id) {
        if(this->index == id) return this;
        
         rep(i,v.size()) {
             Tree *tree = this->v[i]->find(id);
             if(tree != NULL) {
                 return tree;
             }
         }

         return NULL;
    }

    void print(int dep) {
        
        rep(i,dep) {
            cout << ".";
        }
        cout << this->s << endl;
        
        rep(i,this->v.size()) {
            this->v[i]->print(dep+1);
        }

        return;
    }

};

int main() {
    int n;
    cin >> n;
    
    int dist;
    string s;

    cin >> dist >> s;

    Tree *tree = new Tree(s,dist);

    REP(i,1,n) {
        cin >> dist >> s;
        tree->add(i,dist-1,s);

    }

    tree->print(0);

    return 0;
}
