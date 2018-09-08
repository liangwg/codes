/*
1.将两个有序链表合并为一个新的有序链表并返回。
2.新链表是通过拼接给定的两个链表的所有节点组成的
3.输入：1->2->4,1->3->4
	输出：1->1->2->3->4->4 

*/

ListNode*mergeTwoLists(ListNode*l1,ListNode*l2)
{
	if(l1==NULL)return l2;
	if(l2==NULL)return l1; 
	ListNode*l3=NULL,p3=NULL;
	
	while(l1!=NULL&&l2!=NULL)
	{
		if(l1->val>l2->val)
		{
			if(l3==NULL)
				l3->next=l2;
			else
				p3->next=l2;
			p3=l2;
			l2=l2->next;
		 } 
		else
		{
			if(l3==NULL)
				l3->next=l1;
			else
				p3->next=l1;
			p3=l1;
			l1=l1->next;
		}
	}
	if(l1!=NULL)
		 p3->next=l1;
	else
		p3->next=l2;
	return l3;
 } 
