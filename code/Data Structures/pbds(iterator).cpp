#include <bits/stdc++.h>
using namespace std;

template<typename T, typename Comp = std::less<T>>
struct OST {
    struct Node {
        T key;
        int prior, cnt, sz;
        Node *l, *r, *p;
        Node(const T &v){
            key = v;
            prior = rand();
            cnt = 1;
            sz = 1;
            l = r = p = NULL;
        }
    } *root = NULL;

    Comp cmp;

    int getsz(Node* t){ return t ? t->sz : 0; }

    void upd(Node* t){
        if(t){
            t->sz = getsz(t->l) + getsz(t->r) + t->cnt;
            if(t->l) t->l->p = t;
            if(t->r) t->r->p = t;
        }
    }

    void rotate_left(Node* &t){
        Node* r = t->r;
        t->r = r->l;
        if(r->l) r->l->p = t;
        r->l = t;
        r->p = t->p;
        t->p = r;
        upd(t);
        upd(r);
        t = r;
    }

    void rotate_right(Node* &t){
        Node* l = t->l;
        t->l = l->r;
        if(l->r) l->r->p = t;
        l->r = t;
        l->p = t->p;
        t->p = l;
        upd(t);
        upd(l);
        t = l;
    }

    void insert(Node* &t, const T &x, Node* parent = NULL){
        if(!t){
            t = new Node(x);
            t->p = parent;
            return;
        }

        if(!cmp(x,t->key) && !cmp(t->key,x)) t->cnt++;
        else if(cmp(x,t->key)){
            insert(t->l, x, t);
            if(t->l->prior > t->prior) rotate_right(t);
        }
        else{
            insert(t->r, x, t);
            if(t->r->prior > t->prior) rotate_left(t);
        }
        upd(t);
    }

    void erase(Node* &t, const T &x){
        if(!t) return;

        if(cmp(x,t->key)) erase(t->l,x);
        else if(cmp(t->key,x)) erase(t->r,x);
        else {
            if(t->cnt > 1){
                t->cnt--;
            }
            else{
                if(!t->l) t = t->r;
                else if(!t->r) t = t->l;
                else{
                    if(t->l->prior > t->r->prior){
                        rotate_right(t);
                        erase(t->r,x);
                    } else{
                        rotate_left(t);
                        erase(t->l,x);
                    }
                }
                if(t) t->p = NULL;
            }
        }
        if(t) upd(t);
    }

    void insert(const T &x){ insert(root,x); }
    void erase(const T &x){ erase(root,x); }
    int size(){ return getsz(root); }
    bool empty(){ return size()==0; }

    // ------- order + k-th -------
    int order_of_key(const T &x){
        Node* t = root;
        int ans = 0;
        while(t){
            if(cmp(t->key,x)){
                ans += getsz(t->l) + t->cnt;
                t = t->r;
            } else t = t->l;
        }
        return ans;
    }

    T find_by_order(int k){
        Node* t = root;
        if(k < 0 || k >= size()) throw out_of_range("index");

        while(t){
            int left = getsz(t->l);
            if(k < left) t = t->l;
            else if(k < left + t->cnt) return t->key;
            else{
                k -= left + t->cnt;
                t = t->r;
            }
        }
        throw out_of_range("index");
    }

    // ------ iterator ------
    struct iterator {
        Node* cur;

        iterator(Node* n = NULL): cur(n) {}

        T& operator*(){ return cur->key; }
        T* operator->(){ return &cur->key; }

        bool operator==(const iterator &o) const { return cur == o.cur; }
        bool operator!=(const iterator &o) const { return cur != o.cur; }

        // next inorder
        iterator& operator++(){
            if(!cur) return *this;
            if(cur->r){
                cur = cur->r;
                while(cur->l) cur = cur->l;
            }
            else{
                Node* p = cur->p;
                while(p && cur == p->r){
                    cur = p;
                    p = p->p;
                }
                cur = p;
            }
            return *this;
        }

        // prev inorder
        iterator& operator--(){
            if(!cur) return *this;
            if(cur->l){
                cur = cur->l;
                while(cur->r) cur = cur->r;
            }
            else{
                Node* p = cur->p;
                while(p && cur == p->l){
                    cur = p;
                    p = p->p;
                }
                cur = p;
            }
            return *this;
        }
    };

    iterator begin(){
        Node* t = root;
        if(!t) return iterator(NULL);
        while(t->l) t = t->l;
        return iterator(t);
    }

    iterator end(){
        return iterator(NULL);
    }

    iterator lower_bound(const T &x){
        Node* t = root;
        Node* ans = NULL;
        while(t){
            if(!cmp(t->key,x)){
                ans = t;
                t = t->l;
            } else t = t->r;
        }
        return iterator(ans);
    }

    iterator upper_bound(const T &x){
        Node* t = root;
        Node* ans = NULL;
        while(t){
            if(cmp(x,t->key)){
                ans = t;
                t = t->l;
            } else t = t->r;
        }
        return iterator(ans);
    }
};
/*
OST<int> st;

st.insert(5);
st.insert(2);
st.insert(10);
st.insert(5);

for(auto x : st)
    cout << x << " ";
cout << "\n";

auto it = st.lower_bound(5);
cout << *it << "\n";

auto it2 = st.upper_bound(5);
cout << *it2 << "\n";

it = st.begin();
++it;
cout << *it << "\n";
*/