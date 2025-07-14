// July 13th, 2025

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* curr = head;
        string s;
        while (curr) {
            s.push_back(static_cast<char>(curr->val+'0'));
            curr = curr->next;
        }

        // cout << s << endl;

        int ans=0;
        int n=s.length();
        for (int i=n-1; i>=0; --i) {
            ans += (s[i]-'0')*pow(2,n-i-1);
        }

        return ans;
    }
};