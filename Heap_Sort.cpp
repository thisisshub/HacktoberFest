
void heap(int arr[], int n, int i)
{
    int large = i; // Initialize large as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2

    // If left child larger than root
    if (l < n && arr[l] > arr[large])
        large = l;

    // If right child larger than large so far
    if (r < n && arr[r] > arr[large])
        large = r;

    // If largest is not root
    if (large != i)
    {
        swap(arr[i], arr[large]);
        heap(arr, n, large);
    }
}

// to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heap(arr, n, i);

    // One by one extract an element
    for (int i=n-1; i>0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heap on the reduced heap
        heap(arr, i, 0);
    }
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
