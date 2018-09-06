class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> dead(deadends.begin(), deadends.end());
        if (dead.count(target) || dead.count("0000"))
            return -1;
        if (target == "0000")
            return 0;
        set<string> s;
        queue<string> q;
        q.push("0000");
        for (int d = 1; !q.empty(); d++)
            for (int n = q.size(); n > 0; n--) {
                string cur = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    for (int j = -1; j <= 1; j += 2) {
                        string tmp = cur;
                        tmp[i] = (tmp[i] - '0' + j + 10) % 10 + '0';
                        if (tmp == target)
                            return d;
                        if (!dead.count(tmp) && !s.count(tmp))
                            q.push(tmp);
                        s.insert(tmp);
                    }
                }
            }
        return -1;
    }
};
