class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int length = tokens.size();
        int tmp1, tmp2;
        stack<int> nums;
        for (int i = 0; i < length; i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" ||
                tokens[i] == "/") {
                tmp1 = nums.top();
                nums.pop();
                tmp2 = nums.top();
                nums.pop();
                if (tokens[i] == "+") {
                    nums.push(tmp1 + tmp2);
                } else if (tokens[i] == "-") {
                    nums.push(tmp2 - tmp1);
                } else if (tokens[i] == "*") {
                    nums.push(tmp1 * tmp2);
                } else if (tokens[i] == "/") {
                    nums.push(tmp2 / tmp1);
                }
            } else
                nums.push(stoi(tokens[i]));
        }
        return nums.top();
    }
};
