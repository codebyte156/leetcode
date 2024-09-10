#include <numeric>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next) return head;  
        
        ListNode* current = head;
        
        while (current && current->next) {
            int gcdValue = std::gcd(current->val, current->next->val);
            ListNode* gcdNode = new ListNode(gcdValue);
    
            gcdNode->next = current->next;
            current->next = gcdNode;
            
            // Move to the next pair
            current = gcdNode->next;
        }
        
        return head;
    }
};
