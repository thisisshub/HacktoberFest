/*

Serialization is converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You need to ensure that a binary search tree can be serialized to a string, and this string can be deserialized to the original tree structure.
*/


public class Codec {
    StringBuilder s=new StringBuilder();
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        
        if(root==null){
            return s.toString();
        }
        else{
            s.append(";");
            s.append(root.val);
            
            serialize(root.left);
            serialize(root.right);
        }
            
        return s.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
     //   System.out.println(data);
        String[] str=data.split(";"); 
      //  System.out.println(str[1]);
        if(data.length()==0){
            return null;
        }
        else{
            int n=Integer.parseInt(str[1]);
            TreeNode a=new TreeNode(n); //constructor call to add element in tree
             
             for(int i=2;i<str.length;i++){ 
                 int v=Integer.parseInt(str[i]);
                 a=functionn(a,v);  //fn call for further elements to enter in a tree
             }
                 return a;
        }
       
    }
    
   public TreeNode functionn(TreeNode root,int val){
                if(val<root.val){
                    if(root.left==null){
                        root.left=new TreeNode(val);
                    }
                    else{
                        root.left=functionn(root.left,val);
                    }
                }
                else{
                    if(root.right==null){
                        root.right=new TreeNode(val);
                    }
                    else{
                        root.right=functionn(root.right,val);
                    }
                }
                return root;
            }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// String tree = ser.serialize(root);
// TreeNode ans = deser.deserialize(tree);
// return ans;
