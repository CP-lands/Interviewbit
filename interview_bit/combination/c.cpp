void backtrack(vector<int> &a, int x, vector<vector<int>> &v, vector<int> &v1, int size)
{
    if(v1.size() == size)
        v.push_back(v1);
    for(auto i = x; i < a.size(); i++)
    {
        v1.push_back(a[i]);
        backtrack(a, i + 1, v, v1, size);
        v1.pop_back();
    }
}
vector<vector<int> > Solution::combine(int A, int B) {
    vector<int> a;
    int size = B;
    for(int i = 1; i <= A; i++)
        a.push_back(i);
    vector<vector<int>> v;
    vector<int> v1;
    backtrack(a, 0, v, v1, size);
    return v;
}