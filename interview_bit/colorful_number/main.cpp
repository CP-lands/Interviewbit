string int_to_string(int n)
{
    string res = "";
    while(n / 10 > 0)
    {
        res += n % 10 + '0';
        n /= 10;
    }
    res += n % 10 + '0';
    string ans = "";
    for(int i = res.size() - 1; i >= 0; i--)
        ans += res[i];
    return ans;
}
int Solution::colorful(int A) {
    string s = int_to_string(A);
    map<int, int> mp;
    for(int i = 0; i < s.size(); i++)
    {
        int product = 1;
        for(int j = i; j < s.size(); j++)
        {
           product *= s[j] - '0';
           ++mp[product];
        }
    }
    for(auto x : mp)
        if(x.second > 1) return 0;
    return 1;
}