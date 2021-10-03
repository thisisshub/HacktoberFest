#include <bits/stdc++.h>
using namespace std;

struct Node
{
    long long int total_sum;
    long long int sqsum;
};

vector<Node> tree(100000 * 4);
vector<long long int> lazy(100000 * 4);

Node makenode(long long int val)
{
    Node temp;
    temp.sqsum = val * val;
    temp.total_sum = val;
    return temp;
}
void update(long long int idx, long long int segl, long long int segr, long long int ql, long long int qr, long long int delta)
{
    //segl,segr = segment length of node of ST
    //ql , qr = query range provided to us

    if (lazy[idx] != 0)
    {

        tree[idx].sqsum += 2 * (lazy[idx]) * tree[idx].total_sum + (segr - segl + 1) * lazy[idx] * lazy[idx];
        tree[idx].total_sum += (segr - segl + 1) * lazy[idx];

        if (segl != segr)
        {
            lazy[2 * idx + 1] += lazy[idx];
            lazy[2 * idx + 2] += lazy[idx];
        }
        lazy[idx] = 0;
    }

    if (segl > qr || segl > segr || segr < ql)
        return;

    if (ql <= segl && qr >= segr)
    {
        tree[idx].sqsum += 2 * (delta)*tree[idx].total_sum + (segr - segl + 1) * delta * delta;
        tree[idx].total_sum += (segr - segl + 1) * delta;

        if (segl != segr)
        {

            lazy[2 * idx + 1] += delta;
            lazy[2 * idx + 2] += delta;
        }

        return;
    }

    long long int mid = (segl + segr) / 2;
    update(2 * idx + 1, segl, mid, ql, qr, delta);
    update(2 * idx + 2, mid + 1, segr, ql, qr, delta);

    tree[idx].sqsum = tree[2 * idx + 1].sqsum + tree[2 * idx + 2].sqsum;
    tree[idx].total_sum = tree[2 * idx + 1].total_sum + tree[2 * idx + 2].total_sum;
}
void construct(vector<long long int> &arr, long long int l, long long int r, long long int idx)
{
    if (l > r)
        return;

    if (l == r)
    {
        tree[idx] = makenode(arr[l]);
        return;
    }

    long long int mid = (l + r) / 2;
    construct(arr, l, mid, 2 * idx + 1);
    construct(arr, mid + 1, r, 2 * idx + 2);
    tree[idx].sqsum = tree[2 * idx + 1].sqsum + tree[2 * idx + 2].sqsum;
    tree[idx].total_sum = tree[2 * idx + 1].total_sum + tree[2 * idx + 2].total_sum;
}
long long int getSum(long long int l, long long int r, long long int ql, long long int qr, long long int idx)
{

    if (lazy[idx] != 0)
    {

        tree[idx].sqsum += 2 * (lazy[idx]) * tree[idx].total_sum + (r - l + 1) * lazy[idx] * lazy[idx]; //This is how the square sum varies 
        tree[idx].total_sum += (r - l + 1) * lazy[idx];

        if (l != r)
        {
            lazy[2 * idx + 1] += lazy[idx];
            lazy[2 * idx + 2] += lazy[idx];
        }
        lazy[idx] = 0;
    }

    if (l > r || l > qr || r < ql)
        return 0;

    if (l >= ql && r <= qr)
        return tree[idx].sqsum;

    long long int mid = (l + r) / 2;

    return getSum(l, mid, ql, qr, 2 * idx + 1) + getSum(mid + 1, r, ql, qr, 2 * idx + 2);
}

int main()
{
    long long int n, q;
    cin >> n >> q;

    vector<long long int> arr(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    construct(arr, 0, n - 1, 0);
    long long int a, l, r, v;
    vector<long long int> answer;
    while (q--)
    {
        cin >> a;

        if (a == 1)
        {
            cin >> l >> r >> v;
            update(0, 0, n - 1, l - 1, r - 1, v);
        }
        if (a == 2)
        {
            cin >> l >> r;
            answer.push_back(getSum(0, n - 1, l - 1, r - 1, 0));
        }
    }
    for (long long int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }
}
