public class SumOfNodes {  
  
      //Represent the node of binary tree  
        public static class Node{  
        int data;  
        Node left;  
        Node right;  
  
        public Node(int data){  
            //Assign data to the new node, set left and right children to null  
            this.data = data;  
            this.left = null;  
            this.right = null;  
        }  
      }  
  
      //Represent the root of binary tree  
      public Node root;  
  
      public SumOfNodes(){  
        root = null;  
      }  
  
      //calculateSum() will calculate the sum of all the nodes present in the binary tree  
      public int calculateSum(Node temp){  
        int sum, sumLeft, sumRight;  
        sum = sumRight = sumLeft = 0;  
  
        //Check whether tree is empty  
        if(root == null) {  
            System.out.println("Tree is empty");  
            return 0;  
        }  
        else {  
            //Calculate the sum of nodes present in left subtree  
            if(temp.left != null)  
                sumLeft = calculateSum(temp.left);  
  
            //Calculate the sum of nodes present in right subtree  
            if(temp.right != null)  
                sumRight = calculateSum(temp.right);  
  
            //Calculate the sum of all nodes by adding sumLeft, sumRight and root node's data  
            sum = temp.data + sumLeft + sumRight;  
            return sum;  
        }  
      }  
  
      public static void main(String[] args) {  
  
        SumOfNodes bt = new SumOfNodes();  
        //Add nodes to the binary tree  
        bt.root = new Node(5);  
        bt.root.left = new Node(2);  
        bt.root.right = new Node(9);  
        bt.root.left.left = new Node(1);  
        bt.root.right.left = new Node(8);  
        bt.root.right.right = new Node(6);  
  
        //Display the sum of all the nodes in the given binary tree  
        System.out.println("Sum of all nodes of binary tree: " + bt.calculateSum(bt.root));  
      }  
    }  
