#include <vector>
#include <unordered_set>

class Solution {
public:
    ListNode* modifiedList(std::vector<int>& nums, ListNode* head) {

        std::unordered_set<int> toDelete(nums.begin(), nums.end());


        ListNode* dummy = new ListNode(0); // Dummy node before head
        dummy->next = head;
        ListNode* current = dummy;

        while (current->next != nullptr) {
            if (toDelete.count(current->next->val)) {
                // Remove the node by skipping over it
                current->next = current->next->next;
            } else {
                // Move to the next node
                current = current->next;
            }
        }

        return dummy->next;
    }
};
