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
    public void flatten(TreeNode root) {
        List<TreeNode> res = new ArrayList<TreeNode>();
        Stack<TreeNode> stack = new Stack<TreeNode>();
		
        if (root != null) {
            stack.push(root);
            while (!stack.isEmpty()) {
                TreeNode curr = stack.pop();
                res.add(curr);
                if (curr.right != null) stack.push(curr.right);
                if (curr.left != null) stack.push(curr.left);
            }  
        }
        
        for (int i=1; i < res.size(); i++) {
            root.left = null;
            root.right = res.get(i);
            root = root.right;
        }
    }
}