/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    List<Node> ls = new ArrayList<>();
    
    private void traversal(Node node, int level) {
        if(node == null) {
            return;
        }
        
        int nextLevel = level + 1;
        
        if(ls.size() < nextLevel) {
            ls.add(node);
        } else {
            Node current = ls.get(level);
            current.next = node;
            ls.set(level, current.next);
        }
        
        traversal(node.left, nextLevel);
        traversal(node.right, nextLevel);
    }
    
    public Node connect(Node root) {
        traversal(root, 0);
        return root;
    }
}