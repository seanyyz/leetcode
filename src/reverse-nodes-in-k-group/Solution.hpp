#include <stddef.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// k = 3
// (last group) -> 1 -> 2 -> 3 -> (next group)
// (last group) -> 1 -> 2 -> 3 -> (left list)
//
// group_remaining:
//      1 -> 2 -> 3
// * store group head as next group-process's last-group
//
// * store pointer of group head->next as group_remaining (Node 2)
// * group head point to left list :
//      1 -> (left list)
// group_remaining:
//      2 -> 3
// left list is now:
//      1 -> (left list)
//
// * store pointer of group head->next as group_remaining (Node 3)
// * group head point to left list :
//      2 -> (left list)
// group_remaining:
//      3
// left list is now:
//      2 -> (left list)
//
// * store pointer of group head->next as group_remaining (NULL)
// * group head point to left list :
//      3 -> (left list)
// group_remaining:
//      (empty)
// left list is now:
//      3 -> (left list)
//

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k < 2)
        {
            return head;
        }
        ListNode *group_remaining = head;
        ListNode *p = head;
        ListNode *lastgroup = head;
        ListNode *ret = head;
        int kcount = 0;
        for (; p != NULL;)
        {
            kcount++;
            if (kcount == k)
            {
                ret = p;
                ListNode *nextgroup = p->next;
                ListNode *leftlist = p->next;
                for (; kcount > 0; kcount--)
                {
                    ListNode *hn = group_remaining->next;
                    group_remaining->next = leftlist;
                    leftlist = group_remaining;
                    group_remaining = hn;
                }
                p = nextgroup;
                break;
            }
            else
            {
                p = p->next;
            }
        }

        for (; p != NULL;)
        {
            kcount++;
            if (kcount == k)
            {
                ListNode *nextgroup = p->next;
                ListNode *leftlist = p->next;
                ListNode *templastgroupnext = lastgroup->next;
                ListNode *hn;
                for (; kcount > 0; kcount--)
                {
                    hn = group_remaining->next;
                    group_remaining->next = leftlist;
                    leftlist = group_remaining;
                    group_remaining = hn;
                }
                p = nextgroup;
                lastgroup->next = leftlist;
                lastgroup = templastgroupnext;
            }
            else
            {
                p = p->next;
            }
        }

        return ret;
    }
};
