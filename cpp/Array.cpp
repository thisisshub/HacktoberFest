#include <iostream>
using namespace std;

class array {

    int a[100], length, size;

    public:

    array(int arr[100], int l, int s) {
        length = l;
        size = s;
        for(int i=0;i<length;i++) {
            a[i] = arr[i]; 
        }
    }

    void display() {
        cout<<"Elements are: ";
        for(int i=0;i<length;i++) {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }

    void append(int x) {
        a[length++] = x;
    }

    void insert(int index, int x) {
        if(index>=0 && index<length) {
        for(int i=length;i>index;i--) {
            a[i] = a[i-1];
        }
        a[index] = x;
        length++;
        }
        else {
            cout<<"Not possible.\n";
        }
    }

    int delete_element(int index) {
        if(index>=0 && index<length) {
            int x = a[index];
        for(int i=index;i<length-1;i++) {
            a[i] = a[i+1];
        }
        length--;
        return x;
        }
        else {
            cout<<"Not possible.\n";
            return -1;
        }
    }

    int linear_search(int x) {
        for(int i=0;i<length;i++) {
            if(a[i] == x) {
                return i;
            }
        }
        return -1;
    }

    int binary_search(int x) {
        int low = 0, high, mid;
        high = length -1;
        while(low<=high) {
            mid = (low+high)/2;
            if(a[mid] == x) {
                return mid;
            }
            else if(a[mid]>x) {
                high = mid - 1;
            }
            else if(a[mid]<x) {
                low = mid + 1;
            }
        }
        return -1;
    }
};

int main() {
    int arr[] = {2,4,6,8,10};
    array a(arr, 5, 20);
    cout<<a.linear_search(10)<<endl;
    cout<<a.binary_search(10)<<endl;
    return 0;
}
