class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded_string;
        encoded_string += to_string(strs.size()) + "_";
        for (string& s : strs) {
            encoded_string += to_string(s.length()) + "_";
            encoded_string += s;
        }
        return encoded_string;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        const char* p = s.c_str();
        vector<string> strs(atoi(p));
        while (*p != '_') p++; p++;

        for (int i = 0; i < strs.size(); i++) {
            int len = atoi(p);
            while (*p != '_') p++; p++;
            strs[i] = string(p, len);
            p += len;
        }

        return strs;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));