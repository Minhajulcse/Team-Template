#include <bits/stdc++.h>
using namespace std;

template<typename T, typename Comp = std::less<T>>
struct OST {
    struct Node {
      T key;
      int prior, cnt, sz;
      Node *l, *r;
      Node(const T &v){
            key = v;
            prior = rand();
            cnt = 1;
            sz = 1;
            l = r = NULL;
      }
    } *root = NULL;

    Comp cmp;

    int getsz(Node* t){ return t ? t->sz : 0; }

    void upd(Node* t){
      if(t) t->sz = getsz(t->l) + getsz(t->r) + t->cnt;
    }

    void rotate_left(Node* &t){
      Node* r = t->r;
      t->r = r->l;
      r->l = t;
      upd(t);
      upd(r);
      t = r;
    }

    void rotate_right(Node* &t){
      Node* l = t->l;
      t->l = l->r;
      l->r = t;
      upd(t);
      upd(l);
      t = l;
    }

    void insert(Node* &t, const T &x){
      if(!t){ t = new Node(x); return; }

      if(!cmp(x, t->key) && !cmp(t->key, x)) t->cnt++;
      else if(cmp(x, t->key)){
            insert(t->l, x);
            if(t->l->prior > t->prior) rotate_right(t);
      } 
      else {
            insert(t->r, x);
            if(t->r->prior > t->prior) rotate_left(t);
      }
      upd(t);
    }

    void erase(Node* &t, const T &x){
      if(!t) return;

      if(cmp(x, t->key)) erase(t->l, x);
      else if(cmp(t->key, x)) erase(t->r, x);
      else {
            if(t->cnt > 1) t->cnt--;
            else {
                if(!t->l) t = t->r;
                else if(!t->r) t = t->l;
                else {
                    if(t->l->prior > t->r->prior){
                        rotate_right(t);
                        erase(t->r, x);
                    } 
                    else {
                        rotate_left(t);
                        erase(t->l, x);
                    }
                }
            }
      }
      if(t) upd(t);
    }

    // ---------- PUBLIC API ----------

    void insert(const T &x){ insert(root, x); }
    void erase(const T &x){ erase(root, x); }

    int size(){ return getsz(root); }
    bool empty(){ return size() == 0; }

    // order_of_key(x): count of elements < x
    int order_of_key(const T &x){
      Node* t = root;
      int ans = 0;
      while(t){
            if(!cmp(t->key, x) && !cmp(x, t->key)) {
                ans += getsz(t->l);
                break;
            }
            if(cmp(t->key, x)){
                ans += getsz(t->l) + t->cnt;
                t = t->r;
            } 
            else t = t->l;
      }
      return ans;
    }
    // find_by_order(k): k-th smallest (0-indexed)
    T find_by_order(int k){
      Node* t = root;
      if(k < 0 || k >= size()) throw out_of_range("index out of range");
      while(t){
            int left = getsz(t->l);
            if(k < left) t = t->l;
            else if(k < left + t->cnt) return t->key;
            else {
                k -= left + t->cnt;
                t = t->r;
            }
      }
      throw out_of_range("index not found");
    }
    // lower_bound(x): first value >= x
    T lower_bound(const T &x){
      Node* t = root;
      bool ok = false;
      T ans{};
      while(t){
            if(!cmp(t->key, x)){ // t->key >= x
                ans = t->key;
                ok = true;
                t = t->l;
            } 
            else t = t->r;
      }
      if(!ok) throw out_of_range("no lower bound");
      return ans;
    }
    // upper_bound(x): first value > x
    T upper_bound(const T &x){
      Node* t = root;
      bool ok = false;
      T ans{};
      while(t){
            if(cmp(x, t->key)){ // t->key > x
                ans = t->key;
                ok = true;
                t = t->l;
            } 
            else t = t->r;
      }
      if(!ok) throw out_of_range("no upper bound");
      return ans;
    }
};
/*
<--------Using int------->
OST<int> st;
st.insert(5);
st.insert(2);
st.insert(10);
st.insert(5);

cout << st.find_by_order(1) << endl; // 5
cout << st.order_of_key(6) << endl;  // 3
cout << st.lower_bound(6) << endl;   // 10
cout << st.upper_bound(5) << endl;   // 10
*/
/*
<------Using string------->
OST<string> st;
st.insert("apple");
st.insert("banana");
st.insert("banana");
st.insert("orange");

cout << st.find_by_order(1) << endl;     // banana
cout << st.order_of_key("banana") << endl; // 1
cout << st.lower_bound("ball") << endl;  // banana
*/
/*
<----Using pair<int,int> (lexicographic)--->
OST<pair<int,int>> st;

st.insert({2,3});
st.insert({1,5});
st.insert({2,1});

cout << st.find_by_order(0).first << endl; // 1
cout << st.order_of_key({2,0}) << endl;    // 1

*/