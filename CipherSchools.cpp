#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

bool isBalanced(string str)
{
    stack<char> s;
    char t;


    for (int i = 0; i < str.length(); i++) {

        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            s.push(str[i]);
            continue;
        }

        if (s.empty())
            return false;

        if(str[i]==')') {
            t = s.top();
            s.pop();
            if (t == '{' || t == '[')
                return false;
        }

        else if(str[i]=='}') {
            t = s.top();
            s.pop();
            if (t == '(' || t == '[')
                return false;

        }

        else {


            t = s.top();
            s.pop();
            if (t == '(' || t == '{')
                return false;

        }
    }

    if(s.empty())
        return true;
    else
        return false;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
    string s;
    cin>>s;

    if (isBalanced(s))
        cout << "YES"<<endl;
    else
        cout << "NO"<<endl;
    }
    return 0;
}
