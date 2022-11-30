class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int vl1[100],
            vl2[100],
            res_digits[101],
            res_size = 0,
            sz1 = 0,
            sz2 = 0,
            sum;
        bool over = 0;

        while(l1 != 0)
        {
            vl1[sz1++] = l1->val;
            l1 = l1->next;
        }
        while(l2 != 0)
        {
            vl2[sz2++] = l2->val;
            l2 = l2->next;
        }
        int i1 = 0, i2 = 0;
        while((i1 != sz1) || (i2 != sz2))
        {
            sum = 0;
            if(i1 < sz1)
                sum += vl1[i1++];
            if(i2 < sz2)
                sum += vl2[i2++];
            sum += over;
            over = sum >= 10;
            res_digits[res_size++] = (sum >= 10 ? sum % 10 : sum);
        }
        if(over)
            res_digits[res_size++] = 1;
        ListNode* res = 0;
        while(res_size)
            res = new ListNode(res_digits[--res_size], res);
        return res;
    }
};