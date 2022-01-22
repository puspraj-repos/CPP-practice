#include <bits/stdc++.h>
using namespace std;

int divisible_by_two(long &n);

int prime_factor(long &n);

long process(long n, long a, long b);


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long n, a, b;
        cin >> n >> a >> b;
        long ans = process(n, a, b);
        cout << ans << endl;
    }
}

long process(long n, long a, long b)
{
    long count = 0;
    long initial = n;
    if (a > b)
    {
        if (a < 0)
        {
            if (n % 2 == 0)
            {
                count = a;
            }
            else
            {
                count = b;
            }
        }
        else if ( b < 0 )
        {
            // while (n % 2 == 0)
            // {
            //     n = n / 2;
            //     count += a;
            // }
            count = a * divisible_by_two( n );
            if (n == initial)
            {
                count = b;
            }
        }
        else
        {
            count = a * divisible_by_two( n );
            count = count + b * prime_factor( n );
        }
    }
    else 
    {
        if( b < 0 )
        {
            if( n % 2 != 0 )
            {
               count = b; 
            }
            else 
            {
                count = a;
            }
        }
        else if( a < 0 )
        {
            if( divisible_by_two( n ))
            {
                count = a + b * prime_factor( n );
            }
            else
            {
                count = b * prime_factor( n );
            }
        }
        else 
        {
            count = a * divisible_by_two( n );   
            count = count + b * prime_factor( n );
        }
    }
    return count;
}

int divisible_by_two(long &n)
{
    int count = 0;
    while ( n % 2 == 0 ) 
    {
        n = n / 2;
        count++;
    }
    return count;
}

int prime_factor(long &n)
{
    int count = 0;
    if (n < 3)
    {
        return count;
    }
    for (int i = 3; i <= sqrt(n); i++)
    {
        while (n % i == 0)
        {
            count++;
            n = n / i;
        }
    }
    if (n != 1)
    {
        return ++count;
    }
    else
    {
        return count;
    }
}
