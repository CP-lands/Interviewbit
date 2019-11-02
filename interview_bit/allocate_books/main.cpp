bool Possible(vector<int> &A, int B, int pages)
{
    long long sum = 0; long long count = 1;
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] > pages) return false;
        sum += A[i];
        if(sum > pages)
        {
            count++;
            sum = A[i];
        }
        if(count > B) return false;
    }
    return true;
}
int Solution::books(vector<int> &A, int B) {
    if(B > A.size()) return -1;
    long long start = 0; long long end = 0;
    for(int i = 0; i < A.size(); i++)
        end += A[i];
    while(end > start)
    {
        int mid = start + (end - start) / 2;
        if(Possible(A, B, mid))
            end = mid;
        else
            start = mid;
        if(end - start <= 1)
        {
            if(Possible(A, B, start)) return start;
            else return end;
        }
    }
    return start;
}