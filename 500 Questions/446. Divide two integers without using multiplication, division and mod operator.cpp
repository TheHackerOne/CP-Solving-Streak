#include <bits/stdc++.h>
using namespace std;
 
// Function to divide a by b and
// return floor value it
int divide(int dividend, int divisor) {
 
  // Calculate sign of divisor i.e.,
  // sign will be negative only iff
  // either one of them is negative
  // otherwise it will be positive
  int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
 
  // Update both divisor and
  // dividend positive
  dividend = abs(dividend);
  divisor = abs(divisor);
 
  // Initialize the quotient
  int quotient = 0;
  while (dividend >= divisor) {
    dividend -= divisor;
    ++quotient;
  }
  
  // Return the value of quotient with the appropriate sign.
  return quotient * sign;
}
 
// Driver code
int main() {
  int a = 10, b = 3;
  cout << divide(a, b) << "\n";
 
  a = 43, b = -8;
  cout << divide(a, b);
 
  return 0;
}