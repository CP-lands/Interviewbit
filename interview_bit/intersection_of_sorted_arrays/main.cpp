vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    int j = 0;
    vector<int> res;
    for(int i = 0; i < A.size(); i++)
    {
        while(j < B.size() && A[i] >= B[j])
        {
            if(A[i] == B[j])
            {
                res.push_back(A[i]);
                j++;
                break;
            }
            j++;
        }
    }
    return res;
}