bool isPossible(long long A, long long B, vector<int> &C, long long min_time)
{
    int count = 1; long long sum = 0;
    for(int i = 0; i < C.size(); i++)
    {
        if(C[i] > min_time) return false;
        sum += C[i];
        if(sum > min_time) 
        {
            count++;
            sum = C[i];
        }
        if(count > A) return false;
    }
    return true;
}
int Solution::paint(int A, int B, vector<int> &C) {
    long long start = 0;
    long long end = 0;
    long long mid;
    for(int i = 0; i < C.size(); i++)
        end += C[i];
    while(end > start)
    {
        mid = start + (end - start) / 2;
        if(isPossible(A, B, C, mid))
            end = mid;
        else
            start = mid;
        if(end - start <= 1)
        {
            if(isPossible(A, B, C, start)) return (start * B) % 10000003;
            return (end * B) % 10000003;
        }
    }
}