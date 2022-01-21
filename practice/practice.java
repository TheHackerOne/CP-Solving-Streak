#include<bits/stdc++.h>
using namespace std;
int x, y, n, i,k;
bool flag;
long int e, d, j,temp[50],totient;
string encrypted, m;
string msg;
bool prime(long int);
void encryption_key();
void encrypt();
void decrypt();
int main()
{
cout << "\nENTER FIRST PRIME NUMBER: ";
cin >> x;
//checking whether input is prime or not
flag = prime(x);
if(flag == false)
{
cout << "\nINVALID INPUT\n";
exit(0);
}
cout << "\nENTER SECOND PRIME NUMBER: ";
cin >> y;
flag = prime(y);
if(flag == false || x == y)
{
cout << "\nINVALID INPUT\n";
exit(0);
}
cout << "\nENTER MESSAGE OR STRING TO ENCRYPT: ";
fflush(stdin);
getline(cin,msg);
for(i = 0; msg[i] != '\0'; i++)
m[i] = msg[i];
n = x * y;
totient = (x - 1) * (y - 1);
cout<<"\nTotient Function, phi(N)= "<<totient<<"\n\n";
encryption_key();
encrypt();
decrypt();
return 0;
} //end of the main program
bool prime(long int number) //function to check for prime number
{
if(number<2) return false;
if(number==2 || number==3)
{
return true;
}
for(int i = 2; i *i <= number;i++)
{
if(number % i == 0)
return false;
}
return true;
}
//function to generate encryption key
void encryption_key()
{
e = 2;
// Chose e {1<e<phi(N), e is coprime with phi(N)}
while(e < totient) {
if(__gcd(e, totient) == 1)
break;
++e;
}
// Public Key = (e, N)
// Finding the Private Key (d, N)
// d is the multiplicative inverse of e mod phi(N)
int k = 1; // a constant value
while((1+(k*totient)) % e != 0)
++k;
d = (1+(k*totient))/e;
cout<<"Public key, e="<<e<<"\nPrivate Key d="<<d<<"\n\n";
}
//function to encrypt the message
void encrypt()
{
long int plainText, cipherText,k, len;
i = 0;
len = msg.length();
// Given a plaintext P, represented as a number,
// the cipher text C is calculated as:
// C = P^e mod n
while(i != len)
{
plainText = m[i];
plainText = plainText - 96;
k = 1;
for(j = 0; j < e; j++)
{
k = k * plainText;
k = k % n;
}
temp[i] = k;
cipherText= k + 96;
encrypted[i] = cipherText;
i++;
}
encrypted[i] = -1;
cout << "THE ENCRYPTED MESSAGE IS: ";
for(i=0; encrypted[i] != -1; i++)
cout << encrypted[i];
}
//function to decrypt the message
void decrypt()
{
long int plainText, cipherText, k;
i = 0;
// Using the private key (n,d), the plaintext can be found using:
// P=Cd mod n

while(encrypted[i] != -1)
{
cipherText = temp[i];
k = 1;
for(j = 0; j < d; j++)
{
k = k * cipherText;
k = k % n;
}
plainText = k + 96;
m[i] = plainText;
i++;
}
m[i] = -1;
cout << "\n\nTHE DECRYPTED MESSAGE IS: ";
for(i = 0; m[i] != -1; i++)
cout << m[i];
cout << endl;
}
