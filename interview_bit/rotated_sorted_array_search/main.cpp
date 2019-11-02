int Solution::search(const vector<int> &A, int B) {
    int start = 0; int end = A.size() - 1; int mid;
    while(end > start)
    {
        mid = start + (end - start) / 2;
        if(A[mid] > A[0]) start = mid + 1;
        if(A[mid] < A[0]) end = mid - 1;
    }
    int res;
    if(A[start] < A[0]) res = start;
    else res = end + 1;
    if(B < A[0])
    {
        start = res; end = A.size() - 1;
        while(end > start)
        {
            mid = start + (end - start) / 2;
            if(A[mid] == B) return mid;
            if(A[mid] > B) end = mid - 1;
            if(A[mid] < B) start = mid + 1;
        }
        if(A[start] == B) return start;
        return -1;
    }
    start = 0; end = res - 1;
    while(end > start)
    {
        mid = start + (end - start) / 2;
        if(A[mid] == B) return mid;
        if(A[mid] > B) end = mid - 1;
        if(A[mid] < B) start = mid + 1;
    }
    if(A[start] == B) return start;
    return -1;
}