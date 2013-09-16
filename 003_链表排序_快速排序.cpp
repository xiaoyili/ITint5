/*
 作者: Annie Kim, anniekim.pku[at]gmail.com
 时间: Sep 13, 2013
 题目: 链表排序
 难度: Medium
 链接: http://www.itint5.com/oj/#3
 问题: 对一个单链表原地（in-place）排序。即直接对链表节点排序。返回排序后链表的头节点。

 Solution: 快速排序。由于固定选择第一个节点为pivot，所以数据17会超时（遇到最坏情况）。
*/

/*
struct ListNode {
    int val;
    ListNode *next;
};
*/

void partition(ListNode *head, ListNode *&head1, ListNode *&pivot, ListNode *&head2) {
    pivot = head;
    head = head->next;
    ListNode dummy1, dummy2, *cur1 = &dummy1, *cur2 = &dummy2;
    while (head) {
        ListNode **target = head->val < pivot->val ? &cur1 : &cur2;
        (*target)->next = head;
        *target = (*target)->next;
        head = head->next;
    }
    pivot->next = NULL;
    cur1->next = NULL;
    cur2->next = NULL;
    head1 = dummy1.next;
    head2 = dummy2.next;
}

ListNode* quickSortLinkList(ListNode *&head, ListNode *&tail) {
    if (!head) return NULL;

    ListNode *head1 = NULL, *head2 = NULL, *pivot = NULL;
    partition(head, head1, pivot, head2);

    ListNode *tail1 = NULL, *tail2 = NULL;
    quickSortLinkList(head1, tail1);
    quickSortLinkList(head2, tail2);

    if (tail1) tail1->next = pivot;
    pivot->next = head2;
    head = head1 ? head1 : pivot;
    tail = tail2 ? tail2 : pivot;
    return head;
}

ListNode* sortLinkList(ListNode *head) {
    ListNode* tail = NULL;
    return quickSortLinkList(head, tail);
}