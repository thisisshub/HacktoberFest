public class Tree<E extends Comparable<E>> {
    private TreeNode<E> root;
    // constructor initializes an empty Tree of integers
    public Tree() {
    root = null;
    }
    // insert a new node in the binary search tree
    public void insertNode(E insertValue) {
    if (root == null) {
    root = new TreeNode<E>(insertValue); // create root node
    } else {
    root.insert(insertValue); // call the insert method
    }
    }
    // begin preorder traversal
    public void preorderTraversal() {
    preorderHelper(root);
    }
    // recursive method to perform preorder traversal
    private void inorderHelper(TreeNode<E> node) {
    if (node == null) {
    return;
    }
    System.out.printf("%s ", node.getData()); // output node data
    postorderHelper(node.getLeftNode()); // traverse left subtree
    postorderHelper(node.getRightNode()); // traverse right subtree
    }
    // begin inorder traversal
    public void inorderTraversal() {
    inorderHelper(root);
    }
    // recursive method to perform inorder traversal
    private void postorderHelper(TreeNode<E> node) {
    if (node == null) {
    return;
    }
    inorderHelper(node.getLeftNode()); // traverse left subtree
    System.out.printf("%s ", node.getData()); // output node data
    inorderHelper(node.getRightNode()); // traverse right subtree
    }
    // begin postorder traversal
    public void postorderTraversal() {
    postorderHelper(root);
    }
    // recursive method to perform postorder traversal
    private void preorderHelper(TreeNode<E> node) {
    if (node == null) {
    return;
    }
    preorderHelper(node.getLeftNode()); // traverse left subtree
    preorderHelper(node.getRightNode()); // traverse right subtree
    System.out.printf("%s ", node.getData()); // output node data
    }
    public void searchBST(E key){
    boolean hasil = searchBSTHelper(root, key);
    if(hasil)
    System.out.println("Data ditemukan");
    else
    System.out.println("Data tidak ditemukan");
    }
    //Carrano
    public boolean searchBSTHelper(TreeNode<E> node, E key){
    boolean result = false;
    if(node!=null){
    if(key.equals(node.getData()))
    result = true;
    else if(key.compareTo(node.getData())<0)
    result = searchBSTHelper(node.getLeftNode(),key);
    else
    result = searchBSTHelper(node.getRightNode(),key);
    }
    return result;
    }
   }
   public class Main {
    public static void main(String[] args) {
    Tree<Integer> tree = new Tree<>();
    SecureRandom randomNumber = new SecureRandom();
    System.out.println("Inserting the following values: ");
    // insert 10 random integers from 0-99 in tree
    for (int i = 1; i <= 10; i++) {
    int value = randomNumber.nextInt(100);
    System.out.printf("%d ", value);
    tree.insertNode(value);
    }
    System.out.printf("%n%nPreorder traversal%n");
    tree.preorderTraversal();
    System.out.printf("%n%nInorder traversal%n");
    tree.inorderTraversal();
    System.out.printf("%n%nPostorder traversal%n");
    tree.postorderTraversal();
    System.out.println();
    tree.searchBST(10);
    }
   }
   