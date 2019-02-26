class Solution {
public:
    int getSum(int a, int b) {
        // if (b > 0) {
        //     while (b--) {
        //         a++;
        //     }
        // }
        // else {
            
        //     while (b<0) {
        //         b++;
        //         a--;
        //     }
        // }
        // return a;
        int carry = 0;
        while (true) {
            carry = a & b;
            a = a ^ b;
            if (carry == 0)
                break;
            b = (carry & 0xffffffff) << 1;
        }
        
        return a;
    }
};