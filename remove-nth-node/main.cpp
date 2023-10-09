#include <iostream>
#include <memory>

struct ListNode {
    int val;
    ListNode* next;

    ListNode() {
        this->val = 0;
        this->next = nullptr;
    }

    ListNode(int x) {
        this->val = x;
        this->next = nullptr;
    }

    ListNode(int x, ListNode* next) {
        this->val = x;
        this->next = next;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // get size
        int size = 0;
        ListNode* tmp = head;
        while (tmp) {
            size++;
            tmp = tmp->next;
        }
        int nth = size - (n - 1);

        // edge cases
        if (n == size) {
            return head->next;
        }

        // traverse
        tmp = head;
        int i = 1;
        ListNode* p;
        while (tmp) {
            if (i == nth - 1) {
                p = tmp;
                tmp = tmp->next;
                break;
            }
            i++;
            tmp = tmp->next;
        }

        // map ptr
        p->next = tmp->next;

        return head;
    }
};

int main() {
    ListNode head = ListNode(1);
    ListNode n = ListNode(2);
    head.next = &n;
    
    /* ListNode m = ListNode(3); */
    /* n.next = &m; */
    /*  */
    /* ListNode i = ListNode(4); */
    /* m.next = &i; */
    /*  */
    /* auto a = ListNode(5); */
    /* m.next->next = &a; */
    /*  */

    auto b = Solution().removeNthFromEnd(&head, 1);
    while (b) {
        std::cout << " " << b->val;
        b = b->next;
    }
    std::cout << std::endl;

    return 0;
}
