class Solution {
public:
    string defangIPaddr(string address) {
        string result;
        int size = address.size();
        for (int i = 0; i < size; i++)
        {
            if(address[i] == '.')
            {
                result += ("[.]");
            }
            else
            {
                result.push_back(address[i]);
            }
        }
        return result;
    }
};