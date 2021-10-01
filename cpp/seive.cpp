const int max_N = 100000;
bitset<max_N+10> prime;
prime = ~prime;

void seive()
{
    for (int p=2; p*p<=max_N; p++)
    {
        if (prime[p] == 1)
        {
            for (int i=p*2; i<=max_N; i += p) prime[i] = 0;
        }
    }
}

