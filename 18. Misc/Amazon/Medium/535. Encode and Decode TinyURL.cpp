class Solution {
public:
    map<string, string> mp;
    int num = 0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string n = to_string(num);
        string addOn = "http://tinyurl.com/";
        addOn += n;
        mp[addOn] = longUrl;
        num++;
        return addOn;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));