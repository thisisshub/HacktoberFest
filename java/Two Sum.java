/*
Ques- Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= first < second <= numbers.length.

Return the indices of the two numbers, index1 and index2, as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

 */

class Solution {
    static int binarySearch(int arr[], int start, int end, int target){
        while(start<=end){
            int mid = start + (end - start)/ 2;
            
            if(arr[mid] == target){
                return mid+1;
            }
            else if(arr[mid]<target){
                start = mid + 1;
            }
            else{
                end = mid-1;
            }
        }
        return -1;
    }
    public int[] twoSum(int[] numbers, int target) {
        int len = numbers.length-1;
        
        for(int i=0; i<=len; i++){
            int temp = target - numbers[i];
            int res = binarySearch(numbers,i+1, len, temp);
            if(res != -1){
                System.out.print(i + " " +res);
                return new int[]{i+1,res}; 
            }
        }
        
        return new int[]{-1,-1};
    }
}
