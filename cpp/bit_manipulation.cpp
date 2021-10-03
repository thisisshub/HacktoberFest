/// some simple bit manipulation program example
#include<bits/stdc++.h>
using namespace std;


/** BIT SHIFT **/
int LeftShift(int n,int val)
{
    return n = n << val; /// n = n*(2^val)
}

int RightShift(int n,int val)
{
    return n = n >> val; /// n = n/(2^val)
}

/** AND OPERATION **/

void isOdd(int n) ///property of & (AND)
{
    ((n&1)==1) ? cout << n <<" is Odd" << endl : cout << n <<" is NOT Odd"<< endl;
}

void isEven(int n) ///property of & (AND)
{
    ((n&1)==0) ? cout << n <<" is Even" << endl : cout << n <<" is NOT Even" << endl;
}

void toggle_i_th_bit(int n, int i) ///property of & (AND)
{
    int mask = 1 << i;
    cout << "After toggle " << i << " th bit " << n << " is " << (n^mask) << endl;
}

void if_i_th_bit_set_or_not(int n, int i) /// here i-th bit is zero based index ///property of & (AND)
{
    int mask = 1 << i;
    if((n&mask) == 0)
        cout << i << " th bit is NOT set (0) in number " << n << endl;
    else
        cout << i << " th bit is set (1) in number " << n << endl;
}

  /// if n = odd so last bit: 1, n-1 = even so last bit:0
 ///  else if n = even last set bit 1 and top of it is 0 of n-1

void turn_off_last_rightmost_set_bit(int n) ///property of & (AND)
{
   cout <<"After turning off last set bit " << n <<" is - " << (n&(n-1)) << endl;
}

void if_LSB_set_or_not(int num)
{
    /* If (num & 1) evaluates to 1 */
    if(num & 1)
        printf("LSB of %d is set (1).\n", num);
    else
        printf("LSB of %d is unset (0).\n", num);
}

void isPowerOfTwo(int n) /// we can also use builtinpopcount ; if only 1 set bit = true;
{

     if (((n&(n-1))==0) && (n!=0))
            cout << n << " is a power of TWO" << endl;
    else
            cout << n << " is NOT a power of TWO" << endl;
}

/** OR OPERATION **/

void turn_on_i_th_bit(int n, int i) ///property of | (OR)
{
    int mask = 1 << i;
    cout <<"After turning on "<< i <<" th bit " << n <<" is - " << (n|mask) << endl;
}

/** NOT OPERATION **/

void toggle_all_bit(int n) ///property of ~(NOT)
{
    cout << "After toggle all bit " << n << " is " << ~n << endl;
}

/** XOR OPERATION **/

void swap(int a,int b) ///property of ^ (XOR)
{
    cout << "Before swapping: " << a << " " << b << endl;
    a = a^b;
    b = a^b;
    a = a^b;

    cout << "After swapping: " << a << " " << b << endl;
}

///total number of bit need to change to form b from a /// property of ^ (XOR)
void total_bit_change_for_a_to_b(int a, int b)
{
    int res = a^b;
    cout << "Total number of bit change to become " << a << " to "<< b <<"  is - "<< __builtin_popcount(res) << endl;

}

///take all the pair sum in array and perform XOR a=[1,2] , pair sum XOR = (1+1)^(1+2)^(2+1)^(2+2)
/// an array A of N elements has N^2 pair,ordered pairs of numbers so (13, 16) != (16, 13)


void All_pair_sum()
{
    int arr[4] = {4,3,9,1};
    int result = 0;
    for(int i = 0; i<4; i++)
        result = result^(2*arr[i]);

    cout << result << endl;

}


int main()
{


    int a = 16, b = 2;

    cout << LeftShift(a,b) << endl;
    cout << RightShift(a,b) << endl;

    isEven(a);
    isOdd(a);

    swap(a,b);

    total_bit_change_for_a_to_b(a,b);

    if_i_th_bit_set_or_not(a,4);

    turn_off_last_rightmost_set_bit(a);

    if_LSB_set_or_not(15);

    isPowerOfTwo(0);

    turn_on_i_th_bit(a,0);

    toggle_all_bit(a);

    toggle_i_th_bit(b,2);

    cout<< "All Pair Sum of array: {4,3,9,1} is - ";
    All_pair_sum();




    return 0;
}
