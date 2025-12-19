#include <bits/stdc++.h>
using namespace std;

struct OST {
    struct Node {
      int key, prior, cnt, sz;
      Node *l, *r;
      Node(int v){
            key = v;
            prior = rand();
            cnt = 1;
            sz = 1;
            l = r = NULL;
      }
    } *root = NULL;

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

    void insert(Node* &t, int x){
      if(!t){ t = new Node(x); return; }
      if(x == t->key) t->cnt++;
      else if(x < t->key){
            insert(t->l, x);
            if(t->l->prior > t->prior) rotate_right(t);
      } else {
            insert(t->r, x);
            if(t->r->prior > t->prior) rotate_left(t);
      }
      upd(t);
    }

    void erase(Node* &t, int x){
      if(!t) return;
      if(x < t->key) erase(t->l, x);
      else if(x > t->key) erase(t->r, x);
      else {
            if(t->cnt > 1) t->cnt--;
            else {
                if(!t->l) t = t->r;
                else if(!t->r) t = t->l;
                else {
                  if(t->l->prior > t->r->prior){
                        rotate_right(t);
                        erase(t->r, x);
                  } else {
                        rotate_left(t);
                        erase(t->l, x);
                  }
                }
            }
      }
      if(t) upd(t);
    }

    // ---------- PUBLIC API ----------

    void insert(int x){ insert(root, x); }
    void erase(int x){ erase(root, x); }

    int size(){ return getsz(root); }
    bool empty(){ return size() == 0; }

    // order_of_key(x): count of elements < x
    int order_of_key(int x){
      Node* t = root;
      int ans = 0;
      while(t){
            if(x <= t->key) t = t->l;
            else {
                ans += getsz(t->l) + t->cnt;
                t = t->r;
            }
      }
      return ans;
    }

    // find_by_order(k): 0-indexed k-th smallest
    int find_by_order(int k){
      Node* t = root;
      if(k < 0 || k >= size()) return -1; 
      while(t){
            int left = getsz(t->l);
            if(k < left) t = t->l;
            else if(k < left + t->cnt) return t->key;
            else {
                k -= left + t->cnt;
                t = t->r;
            }
      }
      return -1;
    }
    // lower_bound(x): first value >= x, returns -1 if none
    int lower_bound(int x){
      Node* t = root;
      int ans = -1;
      while(t){
            if(t->key >= x){
                ans = t->key;
                t = t->l;
            } else t = t->r;
      }
      return ans;
    }
    // upper_bound(x): first value > x, returns -1 if none
    int upper_bound(int x){
      Node* t = root;
      int ans = -1;
      while(t){
            if(t->key > x){
                ans = t->key;
                t = t->l;
            } else t = t->r;
      }
      return ans;
    }
};
/*
<-----Example Usage (like PBDS)----->
int main(){
    OST st;

    st.insert(5);
    st.insert(2);
    st.insert(10);
    st.insert(5);   // duplicates allowed

    cout << "size = " << st.size() << "\n";   // 4
    cout << st.order_of_key(6) << "\n";       // 3  -> (2,5,5)
    cout << st.find_by_order(2) << "\n";      // 5

    cout << st.lower_bound(6) << "\n";        // 10
    cout << st.lower_bound(5) << "\n";        // 5
    cout << st.upper_bound(5) << "\n";        // 10

    st.erase(5);                              // removes 1 copy
    cout << st.find_by_order(2) << "\n";      // 10

    cout << (st.empty() ? "empty" : "not empty");
}
*/