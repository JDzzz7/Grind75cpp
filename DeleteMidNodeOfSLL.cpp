#include <iostream> 
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* counterHead = head;
        int count = 0;

        while (counterHead != NULL){
            counterHead = counterHead->next;
            count++;
        }
        int mid = count/2;

        if (head == NULL)
            return NULL;
        if (head->next == NULL){
            return NULL;
        }
        ListNode* originalHead = head;
        while (mid > 1){
            head = head->next;
            mid--;
        }
        head->next = head->next->next;
        return originalHead;
    }
};