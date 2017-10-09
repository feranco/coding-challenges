//algorithm to find the number of different corresponding bits in binary representation
// for all pairs in a vector of integers. Return the answer modulo 109+7.
//O(n) time, O(1) space

int cntBits(vector<int> &a) {
    int n_bits = sizeof(int)*8;
    long int result = 0;//important set to long
    const int mod = (1e9)+7;

    //cycle on all bits
    for (int i = 0; i < n_bits; ++i) {
        long int n_zero = 0, n_one = 0;
	//count number of zeros and unos in the i bit for each int
        for (int x : a) {
            if (x & (1 << i)) n_one++;
            else n_zero++;
        }
	//update result
        result += (2 * n_one * n_zero);
    }
    
    return (int)(result%mod);
}

int main (void) {
    vector<int> a{2,4,6};
    cntBits(a);
}
