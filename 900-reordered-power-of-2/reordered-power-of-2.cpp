// Starting with a positive integer N, we reorder the digits in any order (including the original order) such that the leading digit is not zero.
//
// Return true if and only if we can do this in a way such that the resulting number is a power of 2.
//
//  
//
//
//
//
//
// Example 1:
//
//
// Input: 1
// Output: true
//
//
//
// Example 2:
//
//
// Input: 10
// Output: false
//
//
//
// Example 3:
//
//
// Input: 16
// Output: true
//
//
//
// Example 4:
//
//
// Input: 24
// Output: false
//
//
//
// Example 5:
//
//
// Input: 46
// Output: true
//
//
//  
//
// Note:
//
//
// 	1 <= N <= 10^9
//
//
//
//
//
//
//


class Solution {
public:
    bool reorderedPowerOf2(int N) {
        string s = to_string(N);
        sort(s.begin(), s.end());
        for(int i = 1; i > 0; i = i << 1){
            string t = to_string(i);
            if(s.size() == t.size()){
                sort(t.begin(), t.end());
                if(s == t)
                    return true;
            }
            if(s.size() < t.size())
                return false;
        }
        return false;
    }
};
