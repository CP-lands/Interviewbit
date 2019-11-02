void Solution::merge(vector<int> &A, vector<int> &B) {
    int a = A.size(); int b = B.size(); int j = 0;
    vector<int> res; int k = 0;
    for(int i = 0; i < a; i++)
    {
        while(A[i] >= B[j] && j < b)
        {
            res.push_back(B[j]);
            j++;
        }
        res.push_back(A[i]);
        if(i == a - 1 && j <= b - 1)
            for(; j < b; j++)
                res.push_back(B[j]);
    }
    A = res;
}