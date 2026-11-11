class Solution {
public:
    // har jagah long long se deal karna padega
    // toh long long ko ham ll define kar le rahe hai
    typedef long long ll;

    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {

        // case 1 - cost1 + cost2 ~ sasta
        // costboth jisse ek type1 and ek type2 mil jata hai
        // is costlier or equal to cost1 + cost2
        if (cost1 + cost2 <= costBoth) {
            return (1LL * need1 * cost1) + (1LL * need2 * cost2);
            // 1LL taaki overflow na ho qki constraints mein cost aur need
            // ki 10 k powers mein value di hui hai
        }

        // case 2 - costboth ~ sasta

        // isse cost1 aue cost2 both times mil jaega
        int both = min(need1, need2);
        ll total = 1LL * both * costBoth;

        // itne baar type1 aur type2 dono mil gaya tha
        need1 = need1 - both;
        need2 = need2 - both;

        // ab jo bach gaya usk scene bhi set kar dete hai
        if (need1 > 0) {
            total = total + (1LL * need1 * min(cost1, costBoth));
        } else if (need2 > 0) {
            total = total + (1LL * need2 * min(cost2, costBoth));
        }

        return total;
    }
};