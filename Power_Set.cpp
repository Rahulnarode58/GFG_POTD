// <<<<<<<<<<<<<<<<<< Power Set <<<<<<<<<<<<<<<<<<
// POTD Date 26-02-2024
// Coding_with_rahul
// Level : Medium
// Company : Snapdeal
// Topic : Mathematical , Bit Magic , Data Structures , Algorithms

/*Given a string s of length n, find all the possible subsequences of the string s in lexicographically-sorted order.

Example 1:

Input :
s = "abc"
Output:
a ab abc ac b bc c
Explanation :
There are a total 7 number of subsequences possible
for the given string, and they are mentioned above
in lexicgraphically sorted order.*/

/*Your Task:
You don't need to read input or print anything. Your task is to complete the function AllPossibleStrings() which takes a string s as the input parameter and returns a list of all possible subsequences (non-empty) that can be formed from s in lexicographically-sorted order.

Expected Time Complexity: O( n*2n  )
Expected Space Complexity: O( n * 2n )

Constraints:
1 <= n <= 16
s will constitute of lower case english alphabets*/

class Solution
{
public:
    int subs(string input, vector<string> &output)
    {
        if (input.empty())
        {
            output.push_back("");
            return 1;
        }

        string smallString = input.substr(1);
        int smallOutputSize = subs(smallString, output);

        for (int i = 0; i < smallOutputSize; i++)
        {
            output.push_back(input[0] + output[i]);
        }

        return 2 * smallOutputSize;
    }

    vector<string> AllPossibleStrings(string s)
    {
        vector<string> result;
        subs(s, result);
        result.erase(remove_if(result.begin(), result.end(), [](const string &str)
                               { return str.empty(); }),
                     result.end());
        sort(result.begin(), result.end());
        return result;
    }
};
