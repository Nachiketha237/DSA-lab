//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     struct ListNode *next;
//  * };
//  */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){





   
  struct ListNode *p = list1;
  if (list1 == NULL && list2 != NULL)
    return list2;
  else if (list2 == NULL && list1 != NULL)
    return list1;
  else if (list1 == NULL && list2 == NULL)
    {
      return NULL;
    }
  else
    {

      while (p->next != NULL)
    {
      p = p->next;
    }
           p->next = list2;

    }

  int temp;
  struct ListNode *z = list1;

  while (z->next != NULL)
    {
      struct ListNode *b = z->next;
      while (b != NULL)
    {
      if ((z->val) > (b->val))
        {
          temp = z->val;
          z->val = b->val;
          b->val = temp;
        }
      b = b->next;

    }
      z = z->next;
    }
  return list1;

}
