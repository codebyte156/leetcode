class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // Initialize the matrix with -1
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        
        int top = 0, bottom = m - 1, left = 0, right = n - 1;

        ListNode* current = head;

        while (top <= bottom && left <= right && current) {
           
            for (int i = left; i <= right && current; ++i) {
                matrix[top][i] = current->val;
                current = current->next;
            }
            ++top;  
            
            for (int i = top; i <= bottom && current; ++i) {
                matrix[i][right] = current->val;
                current = current->next;
            }
            --right; 
            
           
            for (int i = right; i >= left && current; --i) {
                matrix[bottom][i] = current->val;
                current = current->next;
            }
            --bottom;
            // Traverse from bottom to top on the left column
            for (int i = bottom; i >= top && current; --i) {
                matrix[i][left] = current->val;
                current = current->next;
            }
            ++left; 
        }
        
        return matrix;
    }
};
