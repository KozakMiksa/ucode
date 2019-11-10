#include "libmx.h"
void mx_pop_back(t_list **head)
{
    t_list *s = *head;
    while(s->next->next != NULL)
    {
        s = s->next;
    }
    t_list *ss = s;
    s = s->next;
    free(s);
    ss->next = NULL;
}
