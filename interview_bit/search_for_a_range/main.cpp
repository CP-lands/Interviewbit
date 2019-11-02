vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int start = 0; 
    int end = A.size() - 1; 
    int temp = -1; 
    int mid; 
    vector<int> res(2);
    while(end > start)
    {
        mid = start + (end - start) / 2;
        if(A[mid] == B)
        {
            temp = 0;
            break;
        }
        if(A[mid] > B)
            end = mid - 1;
        if(A[mid] < B) 
            start = mid + 1;
    }
    if(A[mid] == B || A[end] == B) temp = 0;
    if(temp == -1)
    {
        res[0] = -1; res[1] = -1;
        return res;
    }
    res[1] = upper_bound(A.begin(), A.end(), B) - A.begin() - 1;
    res[0] = lower_bound(A.begin(), A.end(), B) - A.begin();
    return res;
}