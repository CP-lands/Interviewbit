void backtrack(vector<int> &A, int st, vector<vector<int>> &v, vector<int> &v1)
{
    v.push_back(v1);
    
    for(auto i = st; i < A.size(); i++)
    {
        v1.push_back(A[i]);
        backtrack(A, i + 1, v, v1);
        v1.pop_back();
    }
}
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int>> v, res;
    vector<int> v1;
    
    backtrack(A, 0, v, v1);
    sort(v.begin(), v.end());
    int i = v.size() - 1;
    while(i > 0)
    {
        if(i >= 0 && v[i] == v[i - 1])
            v.erase(v.begin() + i);
        i--;
    }
    return v;
}