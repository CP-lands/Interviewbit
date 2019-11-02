string temp = "";
void backtrack(vector<int> &v, int st, vector<string> &res, vector<string> &label)
{
    if(v[st] >= 0 && v[st] < 10)
    {
        for(auto i = 0; i < label[v[st]].size(); i++)
        {
            temp += label[v[st]][i];
            if(st == v.size() - 1)
                res.push_back(temp);
            else
                backtrack(v, st + 1, res, label);
            temp.pop_back();
        }
    }
}
vector<string> Solution::letterCombinations(string A) {
    vector<int> v;
    for(auto x : A)
        v.push_back(x - '0');
    vector<string> res;
    vector<string> label;
    
    label.push_back("0");
    label.push_back("1");
    label.push_back("abc");
    label.push_back("def");
    label.push_back("ghi");
    label.push_back("jkl");
    label.push_back("mno");
    label.push_back("pqrs");
    label.push_back("tuv");
    label.push_back("wxyz");
    
    backtrack(v, 0, res, label);
    return res;
}