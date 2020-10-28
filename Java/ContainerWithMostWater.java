public class ContainerWithMostWater{
    public int maxArea(int[] height) {
        int left = 0;
        int right = height.length -1;
        int max = Integer.MIN_VALUE;
     
        while(left < right){
            int min = Math.min(height[left], height[right]);//contraint
            max = Math.max(max, min *(right-left));
            if(height[left] > height[right])
                right--;
            else
                left++;

           
        }
        return max;
    }

    public static void main(String[] args) {
        ContainerWithMostWater maxDimensions = new ContainerWithMostWater();
        int[] height = {1,8,6,2,5,4,8,3,7};
        System.out.println("Container that can hold the most water's size is " + maxDimensions.maxArea(height));
        
    }


}