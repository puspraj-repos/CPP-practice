#include <bits/stdc++.h>
using namespace std;

void print_arr( vector<long long> arr);
long long calc_power( long long msb );
void processing(long long c);


using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long c;
        cin >> c;
        processing(c);
    }
}

void processing(long long c)
{
    vector<long long> arr;

    // if c is zero
    if( c == 0 )
    {
        arr.push_back(1);
        arr.push_back(1);
        print_arr(arr);
        return;
    }
    int flag = 1;
    bitset<63> bit_conversion = c;

    // Calculating max index

    long long msb = 62;
    while (bit_conversion[msb] == 0)
    {
        msb--;
    }
    
    //arr.push_back(calc_power(msb+1));

    while( msb >= 0 )
    {
            arr.push_back( calc_power( msb+1 ) );

            while ( msb >= 0 && ( ! ( bit_conversion[msb] ^ flag ) ) )
            {
                msb--;
            }
            flag = !flag;

    }
    print_arr( arr );

}

void print_arr( vector<long long> arr)
{
    int len= arr.size();
    cout << len << endl;
    for(int i = 0; i < len; i++ )
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

long long calc_power(long long msb)
{
    long long ans,index=1;
    
    ans = ( index << msb ) - 1;
    return ans;
}





// 85


// 1010101
// 1111111 1111111
//  111111 1000000
//   11111 1011111
//    1111 1010000
//     111 1010111
//      11 1010100
//       1 1010101

// 1000000

// 10011

