#include <iostream>
#include <vector>
using namespace std;

class FindMisNum {
public:
    int findMissing(vector<int>& nums) {
        int n = nums.size();
        int total = n * (n + 1) / 2; 
        int sum = 0;
        for (int num : nums)
            sum += num;
        return total - sum;
    }
};

int main() {
    vector<int> nums = {3,0, 2};
    FindMisNum obj;
    cout << "Missing number is: " << obj.findMissing(nums) << endl;
    return 0;
}
