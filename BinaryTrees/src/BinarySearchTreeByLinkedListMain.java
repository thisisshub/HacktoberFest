public class BinarySearchTreeByLinkedListMain {

    public static void main(String[] args) {
        BinarySearchTreeByLinkedList tree = new BinarySearchTreeByLinkedList();
        System.out.println("Inserting 10 nodes in Tree");
        tree.insert(100);
        tree.insert(80);
        tree.insert(70);
        tree.insert(90);
        tree.insert(50);
        tree.TreeTraversal(tree.root);
    }
}
