
Position Find( BinTree BST, ElementType X )
{
    while (BST && BST->Data != X)
    {
        if(X < BST->Data)
            BST = BST->Left;
        else
            BST = BST->Right;
    }
    return BST;
}

Position FindMin( BinTree BST )
{
    if(BST)
        while (BST->Left)
            BST = BST->Left;
    return BST;
}

Position FindMax( BinTree BST )
{
    if(BST)
        while (BST->Right)
            BST = BST->Right;
    return BST;
}

BinTree Insert( BinTree BST, ElementType X )
{
    if(!BST){
        BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    }else{
        if(X < BST->Data)
            BST->Left = Insert(BST->Left, X);
        else if(X > BST->Data)
            BST->Right = Insert(BST->Right, X);
    }

    return BST;
}

BinTree Delete( BinTree BST, ElementType X )
{
    Position temp;
    if(!BST)
        printf("Not Found\n");
    else{
        if(X < BST->Data)
            BST->Left = Delete(BST->Left, X);
        else if(X > BST->Data)
            BST->Right = Delete(BST->Right, X);
        else
        {
            /*双子节点*/
            if(BST->Left && BST->Right){
                temp = FindMin(BST->Right);
                BST->Data = temp->Data;
                BST->Right = Delete(BST->Right, BST->Data);
            }else{
                temp = BST;
                if(!BST->Left)
                    BST = BST->Right;
                else if(!BST->Right)
                    BST = BST->Left;
                free(temp);
            }
        }
    }

    return BST;
}
