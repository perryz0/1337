# Apr. 3rd, 2025 (daily)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        # single pass only
        def dfs(node, curDepth):
            if node is None:
                return (curDepth, None)
            
            ld, ln = dfs(node.left, curDepth + 1)
            rd, rn = dfs(node.right, curDepth + 1)

            if ld == rd:
                return (ld, node)
            elif ld > rd:
                return (ld, ln)
            else:
                return (rd, rn)

        return dfs(root, 0)[1]









        # two pass, decoupled processing
        # # lcaNode = root
        # def dfs(node, curDepth):
        #     # nonlocal maxDepth, lcaNode
        #     if node is None:
        #         return curDepth
        #     ld = dfs(node.left, curDepth+1)
        #     rd = dfs(node.right, curDepth+1)

        #     # postorder
        #     return max(ld,rd)

        # maxDepth = dfs(root, 0)
        # # print(maxDepth)

        # # lcaNode = root
        # def findlca(n, curDepth):
        #     nonlocal maxDepth
        #     if curDepth == maxDepth-1:
        #         # print(f"Node {n} with depth {curDepth}")
        #         return n
        #     if n is None:
        #         return None
        #     ln = findlca(n.left, curDepth+1)
        #     rn = findlca(n.right, curDepth+1)
        #     if ln and rn:   # found the lca since leftd == rightd
        #         return n
            
        #     return ln if ln else rn

        # return findlca(root, 0)