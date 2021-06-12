/*
The Hamming distance hamming(a,b) between two strings a and b of equal
length is the number of positions where the strings differ. 
*/

// Naive Approach.
int hamming(string a, string b) {
    int d = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) d++;
    }
    return d;
}

// If length of strings is small, 
// we can optimize the code by storing the bit strings as integers and calculating the Hamming distances using bit operations.
int hamming_optimized(int a, int b) {

    // The xor operation constructs a bit string that has one bits in positions where a and b differ
    return __builtin_popcount(a^b);
}
