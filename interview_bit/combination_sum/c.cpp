void backtrack(vector<int> &a, int st, vector<vector<int>> &v, vector<int> &v1, int B)
{
    int sum = 0;
    for(auto x : v1) sum += x;
    if(sum >= B)
    {
        if(sum == B) v.push_back(v1);
        return;
    }
    if(st == a.size()) return;
    
    v1.push_back(a[st]);
    backtrack(a, st, v, v1, B);
    v1.pop_back();
    backtrack(a, st + 1, v, v1, B);
    
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    set<int> s;
    vector<int> a, v1;
    vector<vector<int>> v;
    
    for(int i = 0; i < A.size(); i++)
        s.insert(A[i]);
        
    while(!s.empty())
    {
        a.push_back(*s.begin());
        s.erase(s.begin());
    }
    
    backtrack(a, 0, v, v1, B);
    return v;
}