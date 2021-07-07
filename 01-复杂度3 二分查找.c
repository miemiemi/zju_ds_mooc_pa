Position BinarySearch( List L, ElementType X )
{
    Position i;
    for(i = 0; i <= L->Last; i++){
        if(L->Data[i] == X)
            return i;
    }
    return NotFound;
}