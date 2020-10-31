/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean help(TreeNode root1, TreeNode root2)
    {
        if(root1 == null && root2==null)
            return true;
          if(root1!=null && root2==null)
            return false;
         if(root1==null && root2!=null)
            return false;
        
        int l= root1.val;
        int r=root2.val;
        
        if(l!=r)
    return false;
        
        if(!help(root1.left,root2.right))
         return false;
         if(!help(root1.right,root2.left))
         return false;
      return true;
    }
    public boolean isSymmetric(TreeNode root) {
     if(root==null)
         return true;
       if(root.left ==null && root.right==null)
       {
           return true;
       }
        if(root.left!=null && root.right==null)
            return false;
         if(root.left==null && root.right!=null)
            return false;
       return help(root,root);
    }
}
