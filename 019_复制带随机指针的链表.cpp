/*
 作者: Annie Kim, anniekim.pku[at]gmail.com
 时间: Sep 18, 2013
 题目: 复制带随机指针的链表
 难度: Hard
 链接: http://www.itint5.com/oj/#19
 问题: 
 给定一个单链表，链表除了包含next指针外，还包含一个random指针，该指针指向链表中某个结点。
 请复制链表到一个新的链表，random指针需要指向新链表中对应的结点。
 比如原链表某个结点random指针指向第2个结点，那么新结点的random指针也要指向到新链表的第2个结点。

 提示：此题存在空间复杂度O(1)的算法，不需要使用任何额外辅助空间。请不要改变原链表的结构。

 Solution: 不需要使用任何额外辅助空间。需要先打破原链表的结构，再重新复原。
           具体可以google “复制带随机指针的链表”，有很多人讲解。
*/

/**
链表结点的定义(请不要在代码中定义该类型)
struct ListNode {
    ListNode *next;
    ListNode *random;
};
*/

// 返回复制的新链表头结点
ListNode* copyListWithRandomPtr(ListNode *head) {
    for (ListNode *cur = head; cur; cur = cur->next->next) {
        ListNode *node = new ListNode;
        node->next = cur->next;
        cur->next = node;
    }

    for (ListNode *cur = head; cur; cur = cur->next->next)
        cur->next->random = cur->random->next;

    ListNode dummyHead; dummyHead.next = NULL;
    ListNode *newCur = &dummyHead;
    for (ListNode *cur = head; cur; cur = cur->next) {
        newCur->next = cur->next;
        newCur = newCur->next;
        cur->next = cur->next->next;
    }

    return dummyHead.next;
}