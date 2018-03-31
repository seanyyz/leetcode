struct ListNode
{
    ListNode *next = nullptr;
    int val;

    ListNode(int v)
    {
        val = v;
    }
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode res(0);
        ListNode *lres = &res;
        int left = 0;
        for (; l1 || l2 || left;)
        {
            if (l1)
            {
                left += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                left += l2->val;
                l2 = l2->next;
            }
            lres->next = new ListNode(left % 10);
            lres = lres->next;
            left /= 10;
        }
        return res.next;
    }
};
