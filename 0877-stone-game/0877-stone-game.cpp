class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};

// true → Alice wins
// false → Alice loses / Bob wins

// Why can you always return true?
// The key conditions are:
// 1. There are an even number of piles.
// 2. Alice goes first.
// 3. On every turn, a player can take from either end.
// 4. The total number of stones is odd, so there can't be a tie.
// 5. Both players play optimally.
//  The crucial property is the even number of piles.

// Alice can respond by taking the corresponding opposite end, maintaining control over one parity group.

// Alice always wins under the given constraints, so return true for every valid input.