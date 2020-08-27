#include <bits/stdc++.h>
using namespace std;


void insert(stack<int> &s, int ele){
    if(s.size()==0){
        s.push(ele);
        return;
    }
    int top = s.top();
    s.pop();
    insert(s,ele);
    s.push(top);

}
void rev_stack(stack<int> & s){
    if(s.empty() || s.size()==1){
        return ;
    }
    int top = s.top();
    s.pop();
    rev_stack(s);
    insert(s,top);
}
int main() {
    //code

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    stack<int> before = s;
    while(!before.empty()){
        cout<<before.top()<<" ";
        before.pop();
    }
    cout<<endl;
    
    rev_stack(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}