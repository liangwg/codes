/*
1.�����ж�p��q�Ƿ�ͬʱΪ�գ�ͬʱΪ�յĻ�������true,��ͬʱΪ���յĻ�������false,Ȼ���ж�p��q��ֵ�Ƿ���ȣ�
	Ȼ����� �ݹ鷵��������������������ֵ���� 
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
 
