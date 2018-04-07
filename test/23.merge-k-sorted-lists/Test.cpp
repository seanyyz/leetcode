#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <string>
#include <set>

#include <23.merge-k-sorted-lists/Solution.hpp>

class MergeKSortedListsTest : public ::testing::Test
{
protected:
    MergeKSortedListsTest() {}
    virtual ~MergeKSortedListsTest() {}
    virtual void SetUp() override
    {
        input1.resize(3);
        input1[0] = CreateList({1, 4, 5});
        input1[1] = CreateList({1, 3, 4});
        input1[2] = CreateList({2, 6});
        expect1 = CreateList({1, 1, 2, 3, 4, 4, 5, 6});

        input2.resize(4);
        input2[0] = CreateList({1, 4, 5});
        input2[1] = CreateList({1, 3, 4, 8, 10});
        input2[2] = CreateList({2, 7});
        input2[3] = CreateList({0, 3, 6, 9});
        expect2 = CreateList({0, 1, 1, 2, 3, 3, 4, 4, 5, 6, 7, 8, 9, 10});

        input3.resize(4);
        input3[0] = CreateList({1, 4, 5});
        input3[1] = CreateList({1, 3, 4, 8, 10});
        input3[2] = nullptr;
        input3[3] = CreateList({0, 3, 6, 9});
        expect3 = CreateList({0, 1, 1, 3, 3, 4, 4, 5, 6, 8, 9, 10});

        input4.clear();
        expect4 = nullptr;
    }

    virtual void TearDown() override
    {
        DeleteLists(input1);
        DeleteList(expect1);
        DeleteLists(input2);
        DeleteList(expect2);
        DeleteLists(input3);
        DeleteList(expect3);
        DeleteLists(input4);
        DeleteList(expect4);
        DeleteLists(outputs);
    }

    Solution solution;

    std::vector<ListNode *> input1;
    std::vector<ListNode *> input2;
    std::vector<ListNode *> input3;
    std::vector<ListNode *> input4;

    ListNode *expect1;
    ListNode *expect2;
    ListNode *expect3;
    ListNode *expect4;

    std::vector<ListNode *> outputs;
    std::set<ListNode *> deletedNode;

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
        for (; l != nullptr;)
        {
            ListNode *next = l->next;
            if(deletedNode.find(l) != deletedNode.end()){
                deletedNode.insert(l);
                delete l;
            }
            l = next;
        }
    }

    void DeleteLists(std::vector<ListNode *> &lists)
    {
        for (auto i : lists)
        {
            DeleteList(i);
        }
        lists.clear();
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

    std::string ListsToString(std::vector<ListNode *> &lists)
    {
        std::string str = "";
        const size_t size = lists.size();
        str += "[";
        for (size_t i = 0; i < size; i++)
        {
            if (i != 0)
            {
                str += ", ";
            }
            str += "\n";
            str += ListToString(lists[i]);
        }
        str += "\n]\n";
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

TEST_F(MergeKSortedListsTest, Example)
{
    std::string input = ListsToString(input1);
    std::string expect = ListToString(expect1);
    ListNode *output = solution.mergeKLists(input1);
    outputs.push_back(output);
    std::string actual = ListToString(output);
    MY_EXPECT_EQ(actual, expect, input);
}

TEST_F(MergeKSortedListsTest, EvenNumbersOfLists)
{
    std::string input = ListsToString(input2);
    std::string expect = ListToString(expect2);
    ListNode *output = solution.mergeKLists(input2);
    outputs.push_back(output);
    std::string actual = ListToString(output);
    MY_EXPECT_EQ(actual, expect, input);
}

TEST_F(MergeKSortedListsTest, NullptrLists)
{
    std::string input = ListsToString(input3);
    std::string expect = ListToString(expect3);
    ListNode *output = solution.mergeKLists(input3);
    outputs.push_back(output);
    std::string actual = ListToString(output);
    MY_EXPECT_EQ(actual, expect, input);
}

TEST_F(MergeKSortedListsTest, ZeroLists)
{
    std::string input = ListsToString(input4);
    std::string expect = ListToString(expect4);
    ListNode *output = solution.mergeKLists(input4);
    outputs.push_back(output);
    std::string actual = ListToString(output);
    MY_EXPECT_EQ(actual, expect, input);
}

#undef MY_EXPECT_EQ
