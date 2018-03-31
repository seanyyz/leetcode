#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <string>

#include <add-two-numbers/Solution.hpp>

class AddTwoNumbersTest : public ::testing::Test
{
protected:
    AddTwoNumbersTest() {}
    virtual ~AddTwoNumbersTest() {}
    virtual void SetUp() override
    {
        list1a = CreateList(342);
        list1b = CreateList(465);
        list1c = CreateList(342 + 465);

        list2a = CreateList(341);
        list2b = CreateList(1663);
        list2c = CreateList(341 + 1663);

        list3a = CreateList(58426);
        list3b = CreateList(1001);
        list3c = CreateList(58426 + 1001);

        listVal0 = CreateList(0);
    }
    virtual void TearDown() override
    {
        DeleteList(list1a);
        DeleteList(list1b);
        DeleteList(list1c);

        DeleteList(list2a);
        DeleteList(list2b);
        DeleteList(list2c);

        DeleteList(list3a);
        DeleteList(list3b);
        DeleteList(list3c);

        DeleteList(listVal0);
    }

    Solution solution;

    ListNode *list1a;
    ListNode *list1b;
    ListNode *list1c;

    ListNode *list2a;
    ListNode *list2b;
    ListNode *list2c;

    ListNode *list3a;
    ListNode *list3b;
    ListNode *list3c;

    ListNode *listVal0;

    ListNode *CreateList(uint32_t val)
    {
        ListNode head(0);
        ListNode *n = &head;
        for (; val > 0; val /= 10)
        {
            n->next = new ListNode(val % 10);
            n = n->next;
        }
        return head.next;
    }

    void DeleteList(ListNode *l)
    {
        ListNode *n = l;
        for (; n != nullptr;)
        {
            ListNode *next = n->next;
            delete n;
            n = next;
        }
    }

    std::string ListToString(ListNode *l)
    {
        std::string str = "";
        for (ListNode *n = l; n != nullptr; n = n->next)
        {
            str += std::to_string(n->val);
            if (n->next)
            {
                str += " -> ";
            }
        }
        return str;
    }
};

TEST_F(AddTwoNumbersTest, Normal)
{
    EXPECT_STREQ(ListToString(solution.addTwoNumbers(list1a, list1b)).c_str(), ListToString(list1c).c_str());
    EXPECT_STREQ(ListToString(solution.addTwoNumbers(list1a, listVal0)).c_str(), ListToString(list1a).c_str());
    EXPECT_STREQ(ListToString(solution.addTwoNumbers(list2a, list2b)).c_str(), ListToString(list2c).c_str());
    EXPECT_STREQ(ListToString(solution.addTwoNumbers(listVal0, list2b)).c_str(), ListToString(list2b).c_str());
    EXPECT_STREQ(ListToString(solution.addTwoNumbers(list3a, list3b)).c_str(), ListToString(list3c).c_str());
    EXPECT_STREQ(ListToString(solution.addTwoNumbers(listVal0, listVal0)).c_str(), ListToString(listVal0).c_str());
}

TEST_F(AddTwoNumbersTest, EmptyList)
{
    EXPECT_STREQ(ListToString(solution.addTwoNumbers(list1a, nullptr)).c_str(), ListToString(list1a).c_str());
    EXPECT_STREQ(ListToString(solution.addTwoNumbers(nullptr, list1b)).c_str(), ListToString(list1b).c_str());
    EXPECT_STREQ(ListToString(solution.addTwoNumbers(list2a, nullptr)).c_str(), ListToString(list2a).c_str());
    EXPECT_STREQ(ListToString(solution.addTwoNumbers(nullptr, list2b)).c_str(), ListToString(list2b).c_str());
}