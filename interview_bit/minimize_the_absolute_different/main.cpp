int min_abs(int a, int b, int c)
{
    int maxx = max(a, b);
    maxx = max(maxx, c);
    int minn = min(a, b);
    minn = min(minn, c);
    return maxx - minn;
}
int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int a = 0, b = 0, c = 0, temp;
    int min_sum = min_abs(A[0], B[0], C[0]);
    while(a < A.size() && b < B.size() && c < C.size())
    {
        temp = min(min(A[a], B[b]), C[c]);
        if(temp == A[a])
            min_sum = min(min_sum, min_abs(A[++a], B[b], C[c]));
        if(temp == B[b])
            min_sum = min(min_sum, min_abs(A[a], B[++b], C[c]));
        if(temp == C[c])
            min_sum = min(min_sum, min_abs(A[a], B[b], C[++c]));
    }
    return min_sum;
}