template <typename T>
int freq(vector<T> a, T b)
{
    map<T,int> m;
    for(T x:a) m[x]++;
    return m[x];
}
int freq(string a, char b)
{
    map<char,int> m;
    for(char x:a) m[x]++;
    return m[x];
}
// overloaded

