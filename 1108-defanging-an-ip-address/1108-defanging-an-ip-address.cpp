class Solution {
public:
    string defangIPaddr(string address) {

        // ye final defanged IP address store karega
        string result;

        // ye given address ki length store karega
        int size = address.size();

        // ye address string ko traverse karega
        for (int i = 0; i < size; i++)
        {
            // agar current character dot hai
            if(address[i] == '.')
            {
                // toh dot ki jagah [.] add kar denge
                result += ("[.]");
            }
            else
            {
                // otherwise same character result mein add kar denge
                result.push_back(address[i]);
            }
        }

        // final defanged IP address return kar denge
        return result;

// Time Complexity: O(n)
// - We traverse the entire input string once.
// - Each character is processed once.
// - Adding [.] takes constant time because its length is fixed.
// Therefore, TC = O(n).

// Space Complexity: O(n)
// - We create a new string result.
// - In the worst case, every character could be replaced by [.].
// - The resulting string can have a length up to approximately 3n.
// Therefore, SC = O(n).
    }
};