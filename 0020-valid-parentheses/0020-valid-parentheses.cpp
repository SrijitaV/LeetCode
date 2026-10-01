class Solution {
public:
    bool isValid(string s) {

        // The bracket that opened last must always close first — and that is
        // exactly what a stack does.

        // Think of it like a pile of plates: you can only touch the top one.
        // See ( { [ → put a plate on the pile
        // See ) } ] → take the top plate off and check it's the matching type

        // Only three things can go wrong:
        // Problem	-- Example -- What happened
        //     Wrong type on top      --    "(]"   -- 	took off ( but needed [
        //     Nothing to take off	   --    ")("	--  pile was already empty
        //     Plates left over	   --    "({["	--  opened but never closed

        // If none of those happen and the pile ends empty → ✅ valid

        // Create an empty stack
        stack<char> st;

        // Walk through every character
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            // If it's (, [ or { → push it
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            }
            // Otherwise it's a closing bracket
            else {

                // Stack empty? → return false (nothing to match)
                if (st.empty()) {
                    return false;
                }

                // Pop the top and check it's the right partner
                char top = st.top();
                st.pop();

                // Wrong type? → return false
                if (ch == ')' && top != '(') {
                    return false;
                }
                if (ch == ']' && top != '[') {
                    return false;
                }
                if (ch == '}' && top != '{') {
                    return false;
                }
            }
        }

        // At the end, return stack.isEmpty()
        return st.empty();

        // Time O(n), Space	O(n)
    }
};