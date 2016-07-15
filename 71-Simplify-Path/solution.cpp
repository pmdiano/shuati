class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        const char delimiters[] = "/";
        char* pch = strtok(const_cast<char*>(path.c_str()), delimiters);
        while (pch) {
            string token(pch);
            if (token == "..") {
                if (!stk.empty()) {
                    stk.pop();
                }
            } else if (token != ".") {
                stk.push(string(pch));
            }
            pch = strtok(NULL, delimiters);
        }

        string result;
        while (!stk.empty()) {
            result += "/" + stk.top();
            stk.pop();
        }
        return result.empty() ? "/" : result;
    }
};