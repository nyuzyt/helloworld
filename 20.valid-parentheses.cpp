class Solution {
public:
    bool isValid(string s) {
        stack<char> mystack;
        for (char c : s) {
            if (mystack.empty())
                mystack.push(c);
            else if (c == ')' && mystack.top() == '(' ||
                     c == '}' && mystack.top() == '{' || c == ']' && mystack.top() == '[')
                mystack.pop();
            else
                mystack.push(c);
        }
        if (!mystack.empty())
            return false;
        return true;
    }
};
