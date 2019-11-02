void backtrack(vector<int> &A, int st, vector<vector<int>> &v, vector<int> v1, int B, int sum)
{
    if(sum >= B)
    {
        if(sum == B) v.push_back(v1);
        return;
    }
    if(st == A.size()) return;
    v1.push_back(A[st]);
    sum += A[st];
    backtrack(A, st + 1, v, v1, B, sum);
    sum -= v1[v1.size() - 1];
    v1.pop_back();
    if(st < A.size() - 1 && A[st] != A[st + 1])
        backtrack(A, st + 1, v, v1, B, sum);
    else
    {
        while(st < A.size() - 1 && A[st] == A[st + 1])
        {
            st++;
        }
        backtrack(A, st + 1, v, v1, B, sum);
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    vector<vector<int>> v;
    vector<int> v1;
    vector<vector<int>> res;
    
    backtrack(A, 0, v, v1, B, 0);
    return v;
} 