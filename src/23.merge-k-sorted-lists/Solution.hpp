#include <stddef.h>
#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *mergeKLists(std::vector<ListNode *> &lists)
    {
        const size_t size = lists.size();
        if (size == 0)
        {
            return nullptr;
        }

        int interval = 1;
        for (; interval < size;)
        {
            for (size_t i = 0; i < size - interval; i += interval * 2)
            {
                lists[i] = mergeList(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }
        return lists[0];
    }

private:
    ListNode *mergeList(ListNode *l1, ListNode *l2)
    {
        ListNode head(0);
        ListNode *tail = &head;

        for (;;)
        {
            if (l1 == nullptr)
            {
                if (l2 != nullptr)
                {
                    tail->next = l2;
                }
                return head.next;
            }
            if (l2 == nullptr)
            {
                if (l1 != nullptr)
                {
                    tail->next = l1;
                }
                return head.next;
            }
            if (l1->val > l2->val)
            {
                tail->next = l2;
                tail = tail->next;
                l2 = l2->next;
            }
            else
            {
                tail->next = l1;
                tail = tail->next;
                l1 = l1->next;
            }
        }

        return head.next;
    }
};
