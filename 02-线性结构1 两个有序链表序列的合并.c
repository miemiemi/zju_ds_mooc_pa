/* 你的代码将被嵌在这里 */
List Merge( List L1, List L2 )
{
    List head = (PtrToNode)malloc(sizeof(struct Node));
    List tail = head;
    // 都非空
    while (L1->Next != NULL && L2->Next != NULL)
    {
        if(L1->Next->Data <= L2->Next->Data){
            tail->Next = L1->Next;
            tail = tail->Next;
            L1->Next = L1->Next->Next;
        }else
        {
            tail->Next = L2->Next;
            tail = tail->Next;
            L2->Next = L2->Next->Next;
        }
    }
    if(L1->Next != NULL){
        tail->Next = L1->Next;
        L1->Next = NULL;
    }
    if(L2->Next != NULL){
        tail->Next = L2->Next;
        L2->Next = NULL;
    }

    return head;
}