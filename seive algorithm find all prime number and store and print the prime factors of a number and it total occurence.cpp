#include<bits/stdc++.h>
using namespace std;
const int mx = 1e3;
vector<int>prime(mx,1);///initital all number is marked as true;
map<int,int>store_prime; ///store prime factors with occur.first one is prime factors second is total occur;
void sp(int a)
{
    for(int i = 2;i<=a;i++)
    {
        while(a%i == 0)
        {
            store_prime[i]++; ///make primes increment total occur
            a/=i;
        }
    }
}
void sie()  //store all prime numbers using sieve algo at prime vectrs;  
{
    prime[0] = prime[1] = 0;
    for(int i = 2;i<mx;i++)
    {
        if(prime[i]) ///if prime then take all of its multiplier.(because they are not prime as well)
        {
            for(int j = 2*i;j<mx;j+=i)
            {
                prime[j] = 0;///mark all multiplier to 0(nt prime)
            }
        }
    }
}
int main()
{
    sie();
    for(int i = 2;i<=20;i++)
    {
        printf("number : %d %s\n",i,(prime[i]==1)?"yes":"no"); ///print the number is prime or not
        sp(i); ///call store prime_factors function for all the value of i
        printf("prime factors are: \n");
        for(auto it : store_prime)
        {
            cout<<it.first<<" "<<it.second<<endl; ///first one is prime factor and second is total occurence;
        }
        store_prime.clear(); ///clear after each itter otherwise all the factors will store we need only specefic factors for the specefic number;
    }

    return 0;
}
