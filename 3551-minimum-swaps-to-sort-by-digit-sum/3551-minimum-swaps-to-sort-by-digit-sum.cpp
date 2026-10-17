class Solution {
public:
    int minSwaps(vector<int>& nums) {

        // Step 1: Digit sum nikalna ~ Har number ka digit sum calculate karte
        // hain.
        vector<tuple<int, int, int>> arr; // {digit_sum, number, original_index}

        for (int i = 0; i < nums.size(); i++) {
            string num = to_string(nums[i]);
            int add = 0;

            for (int j = 0; j < num.size(); j++) {
                add = add + num[j] -
                      '0'; // -'0' kyun kiya? Kyunki num[j] character hai, aur
                           // -'0' karne se uska actual numeric digit milta hai.
            }

            arr.push_back(
                {add, nums[i], i}); // Digit sum, number aur original index ko
                                    // ek saath store kar dete hain.
        }

        // Step 2: Sort karna ~ Har number ke saath uska original index bhi
        // store karte hain, taaki pata rahe number pehle kahan tha.
        sort(arr.begin(), arr.end());
        // C++ tuple ko pehle first value, phir second aur phir third value ke
        // according sort karta hai. Isliye sorting ka order automatically ye
        // ban jaata hai: 1. Digit sum ascending, 2. Number ascending, agar
        // digit sum equal ho, 3. Original index ascending, agar pehli dono
        // values equal hon Yahi question ke sorting rules hain.

        vector<bool> visited(nums.size(), false);
        int swaps = 0; // swaps minimum swaps count karega.

        // Step 3: Minimum swaps count karna ~ visited array aur cycles ki help
        // se calculate karte hain ki kitne swaps lagenge.
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] || get<2>(arr[i]) == i) {
                // Ismein 2 checks hain.
                // Check 1: visited[i] ~ Agar index pehle process ho chuka hai,
                // toh usko dobara process nahi karna. Check 2: get<2>(arr[i])
                // == i ~ get<2>(arr[i]) tuple ki third value, yaani original
                // index, nikalta hai. Agar original index aur current sorted
                // position same hain, toh element already apni correct position
                // par hai. Uske liye swap nahi chahiye. continue ka matlab
                // current iteration chhodkar next i par jaana.
                continue;
            }

            int j = i; // j current index ko track karta hai aur cycle batata
                       // hai ki cycle mein kitne elements hain.
            int cycle = 0;

            while (!visited[j]) {  // Jab hum kisi already visited index par
                                   // wapas aa jaate hain, cycle complete ho
                                   // jaati hai aur while ruk jaata hai.
                visited[j] = true; // current index ko processed mark karta hai
                j = get<2>(
                    arr[j]); // humein us element ka original index deta hai
                cycle++;     // cycle mein ek element count karta hai.
            }

            swaps = swaps + cycle - 1; // Minimum swaps = cycle size - 1
        }

        return swaps;

        // Time: O(n log n), sorting ki wajah se.
        // Space: O(n), arr aur visited ki wajah se.
    }
};