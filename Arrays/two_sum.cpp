//A program to find the two indices representing a provided sum.
//This method has O(n) time complexity with equivalent O(n) space complexity

//The space complexity is due to the use of the hash map (unordered map) 
//to keep track of the differences between the number in the array being investigated 
//and the target sum.

//A brute force O(n^2) solution would have a O(n) space complexity.

#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;

    unordered_map<int, int> prior;
    for (int i = 0; i < nums.size(); i++)
    {
        int difference = target - nums[i];
        if (prior.find(difference) == prior.end())
            prior[nums[i]] = i;
        else
        {
            result.push_back(i);
            result.push_back(prior[difference]);

            return result;
        }
    }

    return result;
}

int main()
{
    vector<int> array{ 2, 7, 5, 11 };

    twoSum(array, 9);

    if (!result.empty())
        cout << result[0] << "," << result[1] << endl;

    return 0;
}