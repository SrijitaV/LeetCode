class Solution {
public:
    bool isPowerOfFour(int n) {

        // n > 0
        // ye check karta hai ki number positive hai ya ni ? 
        // Power of Four ke liye - n positive hona chahiye.

        // (n & (n-1)) == 0
        // ye Power of Two check karne ki trick hai.
        // powers of two ke binary representation mein exactly one bit set hoti hai, yani ek hi 1.
        // & means bitwise AND. Result mein bit 1 tabhi aata hai jab dono bits 1 hon.
        // isliye: (n & (n-1)) == 0
        // powers of two ke liye true return karta hai.
        // Lekin problem kya hai?
        // 8 = 2³ bhi power of two hai, aur 16 = 4² bhi. Humein sirf powers of four chahiye!
        // Ab aati hai third condition, jo actual trick hai.
        
        // n & 0x55555555
        // 0x55555555 hexadecimal number hai.
        // Iski 32-bit binary representation hai: 01010101 01010101 01010101 01010101
        // Isme har alternate position par 1 hai.
        // Powers of four mein 1 even-numbered bit position par hota hai, counting position 0 se shuru karte hain.
        // 0x55555555 exactly in even positions par 1 rakhta hai.
        // Result zero nahi hai, so condition true hai.
        // Result zero hai, so condition false hai.
        // yahi third condition Power of Two aur Power of Four mein difference karti hai!

        return n > 0 && (n & (n-1)) == 0 && (n & 0x55555555);

        // n > 0 ~ Number positive hona chahiye
        // (n & (n-1)) == 0 ~ Number power of two hona chahiye
        // (n & 0x55555555) ~ Set bit correct position par honi chahiye, so power of four
        // && ka matlab hai saari conditions true honi chahiye.
    
    }
};