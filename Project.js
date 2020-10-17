//Linked List Cycle Algorithm

//Given a linked list, return the node where the cycle begins. If there is no cycle, return null, using the tortoise and hare alg.

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
const detectCycle = function(head) {
    let tortoise = head, hare = head, intersec;
    while (tortoise && hare) {
        tortoise = tortoise.next;
        hare = hare.next ? hare.next.next : null;
        if (tortoise == hare) {
            intersec = tortoise;
            break;
        }
    }
    while (head && intersec) {
        if (head === intersec) {
            return head;
        }
        head = head.next;
        intersec = intersec.next;
    }
    return null;
};