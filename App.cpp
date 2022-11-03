#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) 
    {
        // used to store numbers we have seen
        unordered_set<int> seen;

        // loop
        while (n != 1)
        {
            int current = n;
            int sum = 0;

            // iterating through all of the numbers within a number
            // ex: 19 
            // first iteration = 9
            // second iteration = 1
            while (current != 0)
            {

                // mod 10 will always give us the last digit of number
                // multiply by itself to get the square value
                sum += (current % 10) * (current % 10);

                // get the next number by moving left
                current /= 10;
            }

            // we have already seen this number
            // we are in endless loop, return false
            // if find returns and iterator pointing to the end of the set, the number was not found
            if (seen.find(sum) != seen.end())
            {
                return false;
            }

            // add number to set
            seen.insert(sum);

            // update n for next iteration
            n = sum;
        }

        return true;
    }
};

int main()
{
    Solution solution;
    int example_one = 19;
    int example_two = 2;

    cout << "Example One : " << solution.isHappy(example_one) << endl;
    cout << "Example Two : " << solution.isHappy(example_two) << endl;
	return 0;
}
