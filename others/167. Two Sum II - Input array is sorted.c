class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo = 0, high = numbers.size() - 1;
        while ((numbers[lo] + numbers[high]) != target) {
            if ((numbers[lo] + numbers[high]) < target)
                lo++;
            if ((numbers[lo] + numbers[high]) > target)
                high--;
        }
        return vector<int>({lo+1,high+1});
    }
};