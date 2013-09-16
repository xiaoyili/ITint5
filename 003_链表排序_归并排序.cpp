/*
 作者: Annie Kim, anniekim.pku[at]gmail.com
 时间: Sep 13, 2013
 题目: 链表排序
 难度: Medium
 链接: http://www.itint5.com/oj/#3
 问题: 对一个单链表原地（in-place）排序。即直接对链表节点排序。返回排序后链表的头节点。

 Solution: 归并排序。
*/

/*
struct ListNode {
    int val;
    ListNode *next;
};
*/

int getLength(ListNode *head) {
    int length = 0;
    while (head) {
        length++;
        head = head->next;
    }
    return length;
}

ListNode* mergeList(ListNode *head1, ListNode*head2) {
    ListNode dummy; dummy.next = NULL;
    ListNode *cur = &dummy;
    while (head1 && head2)
    {
        ListNode **min = head1->val < head2->val ? &head1 : &head2;
        cur->next = *min;
        cur = cur->next;
        *min = (*min)->next;
    }
    if (!head1) cur->next = head2;
    if (!head2) cur->next = head1;
    return dummy.next;
}

ListNode* sortLinkList(ListNode *&head, int N) {
    if (N == 0) return NULL;
    if (N == 1) {
        ListNode* cur = head;
        head = head->next;
        cur->next = NULL;
        return cur;
    }
    int half = N / 2;
    ListNode* head1 = sortLinkList(head, half);
    ListNode* head2 = sortLinkList(head, N - half);
    return mergeList(head1, head2);
}

ListNode* sortLinkList(ListNode *head) {
    return sortLinkList(head, getLength(head));
}