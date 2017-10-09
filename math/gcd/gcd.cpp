//algorithm to compute the gcd of two integer

int gcd(int a, int b) {
    if (b < a) swap(a,b);
    if (a == 0) return b;
    int c = b%a;
    while (c) {
        b = a;
        a = c;
        c = b%a;
    }
    return a;
}
 
 int main (void) {
   gcd(2336,1314);
 }
