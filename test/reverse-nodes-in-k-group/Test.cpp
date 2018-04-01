#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <string>

#include <reverse-nodes-in-k-group/Solution.hpp>

class ReverseNodesInKGroupTest : public ::testing::Test
{
protected:
    ReverseNodesInKGroupTest() {}
    virtual ~ReverseNodesInKGroupTest() {}
    virtual void SetUp() override
    {
        list1 = CreateList({1, 2, 3, 4, 5});
        list1k2 = CreateList({2, 1, 4, 3, 5});
        list2 = CreateList({1, 2, 3, 4, 5});
        list2k3 = CreateList({3, 2, 1, 4, 5});
        list3 = CreateList({1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                            11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                            21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
                            31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
                            41, 42, 43, 44});
        list3k5 = CreateList({5, 4, 3, 2, 1, 10, 9, 8, 7, 6,
                              15, 14, 13, 12, 11, 20, 19, 18, 17, 16,
                              25, 24, 23, 22, 21, 30, 29, 28, 27, 26,
                              35, 34, 33, 32, 31, 40, 39, 38, 37, 36,
                              41, 42, 43, 44});
    }
    virtual void TearDown() override
    {
        DeleteList(list1);
        DeleteList(list1k2);
        DeleteList(list2);
        DeleteList(list2k3);
        DeleteList(list3);
        DeleteList(list3k5);
    }

    Solution solution;

    ListNode *list1;
    ListNode *list1k2;
    ListNode *list2;
    ListNode *list2k3;

    ListNode *list3;
    ListNode *list3k5;

    ListNode *CreateList(std::vector<int> list)
    {
        ListNode head(0);
        ListNode *n = &head;
        for (auto &&i : list)
        {
            n->next = new ListNode(i);
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

#define MY_EXPECT_EQ(expect, actual, input)                            \
    if (expect != actual)                                              \
    {                                                                  \
        GTEST_NONFATAL_FAILURE_("Expected equality of these values:"); \
        std::cout << "  Input:" << std::endl;                          \
        std::cout << input << std::endl;                               \
        std::cout << "  Expected:" << std::endl;                       \
        std::cout << expect << std::endl;                              \
        std::cout << "  Actual: " << std::endl;                        \
        std::cout << actual << std::endl;                              \
    }

TEST_F(ReverseNodesInKGroupTest, Example)
{
    std::string input = ListToString(list1) + ", k=" + std::to_string(2);
    std::string expect = ListToString(list1k2);
    std::string actual = ListToString(solution.reverseKGroup(list1, 2));
    MY_EXPECT_EQ(actual, expect, input);

    input = ListToString(list2) + ", k=" + std::to_string(3);
    expect = ListToString(list2k3);
    actual = ListToString(solution.reverseKGroup(list2, 3));
    MY_EXPECT_EQ(actual, expect, input);
}

TEST_F(ReverseNodesInKGroupTest, LongListWithK5)
{
    std::string input = ListToString(list3) + ", k=" + std::to_string(5);
    std::string expect = ListToString(list3k5);
    std::string actual = ListToString(solution.reverseKGroup(list3, 5));
    MY_EXPECT_EQ(actual, expect, input);
}

TEST_F(ReverseNodesInKGroupTest, KBiggerThanListSizeIsNotMatchDescriptionButStillAppearedInLeetCodeTestCases)
{
    auto l = ListNode(1);
    std::string input = ListToString(&l) + ", k=" + std::to_string(2);
    std::string expect = ListToString(&l);
    std::string actual = ListToString(solution.reverseKGroup(&l, 2));
    MY_EXPECT_EQ(actual, expect, input);
}

#undef MY_EXPECT_EQ