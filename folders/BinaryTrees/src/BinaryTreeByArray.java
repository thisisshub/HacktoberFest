import java.sql.Array;

public class BinaryTreeByArray {
    public int[] array;
    public int lastUpdatedindex;

    public BinaryTreeByArray(int size) {
        this.array = new int[size + 1];
        this.lastUpdatedindex = lastUpdatedindex;
        System.out.println("Blank binary tree is created with size = " + size);
    }

    public boolean isTreeFull() {
        if (array.length - 1 == lastUpdatedindex) {
            return true;
        } else {
            return false;
        }
    }

    public void insertA(int value) {
        if (!isTreeFull()) {
            array[lastUpdatedindex+1] = value;
            System.out.println("Node is inserted successfully");
        } else {
            System.out.println("Tree is full");
        }
    }


}
