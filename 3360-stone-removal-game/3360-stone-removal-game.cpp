class Solution {
public:
    bool canAliceWin(int n) {

        // Intuition:

        // We simulate the game turn by turn because the number of stones
        // removed decreases by 1 after every turn.

        // - Alice starts by removing 10 stones.
        // - Bob removes 9 stones.
        // - Alice removes 8 stones.
        // - Bob removes 7 stones, and so on.

        // We maintain a boolean variable alice to keep track of whose turn it
        // is.

        // As long as the current number of stones is greater than or equal to
        // the number of stones that need to be removed, the player makes their
        // move.

        // After every move:
        // 1. Subtract the required stones from n.
        // 2. Decrease the required stones by 1.
        // 3. Switch the player's turn.

        // When a player cannot make a move, that player loses. Therefore, if it
        // is Alice's turn when the loop ends, Bob wins. Otherwise, Alice wins.

        int stones = 10;
        bool alice = true; // Alice plays first

        while (n >= stones) {
            n = n - stones; // removing the required stones

            stones--; // next player removes 1 less stone

            alice = !alice; // switching the player's turn
        }

        // If it is Alice's turn, she cannot make a move, so she loses
        // Otherwise, Bob cannot make a move, so Alice wins
        return !alice;

        // Complexity Analysis:

        // - Time Complexity: O(1)
        //   At most 10 iterations are possible because the number of stones to
        //   be removed starts at 10 and decreases by 1 until it reaches 1.

        // - Space Complexity: O(1)
        //   We are using only two extra variables, stones and alice,
        //   irrespective of the input size.
    }
};