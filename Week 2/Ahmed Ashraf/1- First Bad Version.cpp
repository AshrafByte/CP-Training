// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) 
    {
        int st = 1;
        int en = n;
        while (st <= en)
        {
            int mid = st + (en-st)/2 ;
            if (isBadVersion(mid))
                en = mid - 1;
            else
                st = mid + 1 ;
        }
        return st ; 
    }
};