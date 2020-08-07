#include <bits/stdc++.h>
using namespace std;
    bool solve(){
        string str;
        cin>>str;
        int n=str.length();
        if(n&1)                 // string length is odd
            return false;
        else{
            stack<char>s;       // string length is even
            for(int i=0;i<n;i++){
                char ch = str[i];
                if(ch=='(' || ch=='{' || ch=='[')      // if any kind of opening bracket is there we will push it in the stack
                    s.push(ch);
                else{                                   
                    if(s.empty())                   
                        return false;                   // if any kind of closing bracket is there and stack is empty i.e not balanced
                    if(ch==')' && s.top()=='(')
                        s.pop();                        // if closing bracket matches with top element of stack that means sequence is balanced till this point so we pop
                    else if(ch=='}' && s.top()=='{')
                        s.pop();                        // if closing bracket matches with top element of stack that means sequence is balanced till this point so we pop
                    else if(ch==']' && s.top()=='[')
                        s.pop();                        // if closing bracket matches with top element of stack that means sequence is balanced till this point so we pop
                    else 
                        return false;                   // if s.top() has any other thing or has closing bracket return false
                    
                }
            }
            return s.empty();       // if stack is empty, bracket sequence was balanced, else it was not balanced
        }
    }
int main() {
    int t;
    cin>>t;
    while(t--){
        if(solve()) cout<<"YES\n";
        else cout<<"NO\n";        
    }
}
