/*
1.首先判断p和q是否同时为空，同时为空的话，返回true,不同时为不空的话，返回false,然后判断p和q的值是否相等，
	然后继续 递归返回左子树和右子树返回值的与 
*/
bool isSameTree(TreeNode*p,TreeNode*q)
{
	 if(p==null && q==null)
            return true;
        if(p==null || q==null)
            return false;
        if(p->val !=  q->val)
            return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
	
	
 } 
 
