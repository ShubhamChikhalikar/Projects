// DataStructure Lib Project

#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////
//      Structure for Singly linear and Singly Circular
//      Description: 
//      Structure which contains the parameter to create the 
//      Singly LinkedList.
////////////////////////////////////////////////////////////////
template <typename T>
struct nodeS
{
    T data;
    struct nodeS* next;
};

///////////////////////////////////////////////////////////////
//      Structure for Doubly Linear and Doubly Circular
//      Description: 
//      Structure which contains the parameter to create the 
//      Doubly LinkedList.
///////////////////////////////////////////////////////////////
template<typename T>
struct nodeD
{
    T data;
    struct nodeD* next;
    struct nodeD* prev;
};
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//     Class Name: SinglyLL
//     Description: In this class we define the methods
//                  to do operations on the Singly Linear 
//                  LinkedList in Linear Nature.
///////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyLL
{
    public:
        struct nodeS<T>* first;
        SinglyLL();
        void insertFirst(T no);
        void insertLast(T no);
        void deleteFirst();
        void deleteLast();
        void insertAtPos(T no, int iPos);
        void deleteAtPos(int iPos);

        void display();
        int count();
};

///////////////////////////////////////////////////////////
//      Function Name: SinglyLL()
//      Description: It is an constructor of the class
//                   SinglyLL. It is used to intialise 
//                   the variables/characteristics.   
//////////////////////////////////////////////////////////
template <class T>
SinglyLL<T>:: SinglyLL()
{
    first= NULL;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////
//      Function Name: insertFirst()
//      Description: Function is used to create the linkedlist in linear format 
//                   and insert the node at First .
//////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::insertFirst(T no)
{
    struct nodeS<T>* newn= new struct nodeS<T>;
    newn->data= no;
    newn->next= NULL;

    if(first==NULL)
    {
        first= newn;
    }
    else
    {
        newn->next= first;
        first= newn;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//      Function Name: insertLast()
//      Description: Function is used to create the linkedlist in linear format 
//                   and insert the node at Last.
///////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::insertLast(T no)
{
    struct nodeS<T>* newn= new struct nodeS<T>;
    newn->data= no;
    newn->next= NULL;

    if(first==NULL)
    {
        first= newn;
    }
    else
    {
        struct nodeS<T>* temp= first;
        while(temp->next!=NULL)
        {
            temp= temp->next;
        }
        temp->next= newn;
    }
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
//      Function Name: insertAtPos()
//      Description: Function is used to create the node 
//                   and insert the node at given position.
////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::insertAtPos(T no, int iPos)
{
    struct nodeS<T>* newn= new struct nodeS<T>;
    newn->data= no;
    newn->next= NULL;
    int inodeSCount= count();

    if(iPos<1 || iPos >inodeSCount+1 )
    {
        cout<<"Invalid Input\n";
        return;
    }
    else if(iPos==1)
    {
        insertFirst(no);
    }
    else if(iPos==inodeSCount+1)
    {
        insertLast(no);
    }
    else
    {
        struct nodeS<T>* temp= first;

        for(int i=1; i<iPos-1; i++)
        {
            temp= temp->next;
        }
        newn->next= temp->next;
        temp->next= newn;
    }
}


/////////////////////////////////////////////////////////////////////////////
//      Function Name: deleteFirst()
//      Description: It is used to delete the first node of
//                   LinkedList.
////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::deleteFirst()
{
    struct nodeS<T>* temp= first;
    if(first==NULL)
    {
        cout<<"LinkedList is empty";
        return;
    }
    else if(first->next==NULL)
    {
        free(first);
        first= NULL;
    }
    else
    {
        first= first->next;
        free(temp);
        temp=NULL;
    }
}


///////////////////////////////////////////////////////////
//      Function Name: deleteLast()
//      Description: It is used to delete the last node of
//                   LinkedList. 
//////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::deleteLast()
{

    if(first==NULL)
    {
        cout<<"LinkedList is empty";
        return;
    }
    else if(first->next==NULL)
    {
        free(first);
        first= NULL;
    }
    else
    {
        struct nodeS<T>* temp= first;
        while(temp->next->next!=NULL)
        {
            temp= temp->next;
        }
        
        free(temp->next);
        temp->next= NULL;
    }
}


//////////////////////////////////////////////////////////////////////////////////////
//      Function Name: deleteAtPos()
//      Description:  Function is used to create the node 
//                   and delete the node at given position.
/////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::deleteAtPos(int iPos)
{
    
    int inodeSCount= count();

    if(iPos<1 || iPos >inodeSCount )
    {
        cout<<"Invalid Input\n";
        return;
    }
    else if(iPos==1)
    {
        deleteFirst();
    }
    else if(iPos==inodeSCount)
    {
        deleteLast();
    }
    else
    {
        struct nodeS<T>* temp= first;
        struct nodeS<T>* temp1= NULL;

        for(int i=1; i<iPos-1; i++)
        {
            temp= temp->next;
        }
        temp1= temp->next->next;
        free(temp->next);
        temp->next= temp1;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////
//      Function Name: display()
//      Description: It is used to display the nodes which are present.
///////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::display()
{
    struct nodeS<T>* temp = first;
    while (temp!=NULL)
    {
        cout<<temp->data<<"\t";
        temp= temp->next;
    } 
    cout<<"NULL\n";  
}


///////////////////////////////////////////////////////////////////////////////////////////////
//      Function Name: count()
//      Description: It is used to count the number of elements. 
//////////////////////////////////////////////////////////////////////////////////////////////
 
template <class T>
int SinglyLL<T>::count()
{
    struct nodeS<T>* temp = first;
    int iCnt=0;
    while (temp != NULL)
    {
        iCnt++;
        temp= temp->next;
    } 
    return iCnt;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//     Class Name: SinglyCL
//     Description: In this class we define the methods
//                  to do operations on the Singly Circular 
//                  LinkedList in Circular Nature.
///////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyCL
{
    public:
        struct nodeS<T>* first;
        struct nodeS<T>* last;
        SinglyCL();
        void insertFirst(T no);
        void insertLast(T no);
        void deleteFirst();
        void deleteLast();
        void insertAtPos(T no, int iPos);
        void deleteAtPos(int iPos);
        void display();
        int nodeCount();
};

///////////////////////////////////////////////////////////
//      Function Name: SinglyCL()
//      Description: It is an constructor of the class
//                   SinglyCL. It is used to intialise 
//                   the variables/characteristics.   
//////////////////////////////////////////////////////////

template<class T>
SinglyCL<T>::SinglyCL()
{
    first= NULL;
    last= NULL;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//      Function Name: insertFirst()
//      Description: Function is used to create the linkedlist in circular format 
//                   and insert the node at First .
//////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::insertFirst( T no)
{
    struct nodeS<T>* newn= new struct nodeS<T>;
    newn->data= no;
    newn->next= NULL;

    if(first==NULL && last==NULL)
    {
        first= newn;
        last= newn;
        last->next= first;
    }
    else
    {
        newn->next= first;
        first= newn;
        last->next= first;
    }

}

////////////////////////////////////////////////////////////////////////////////////////////////////
//      Function Name: insertLast()
//      Description: Function is used to create the linkedlist in circular format 
//                   and insert the node at Last.
///////////////////////////////////////////////////////////////////////////////////////////////////


template <class T>
void SinglyCL<T>::insertLast(T no)
{
    struct nodeS<T>* newn= new struct nodeS<T>;
    newn->data= no;
    newn->next= NULL;

    if(first==NULL && last==NULL)
    {
        first= newn;
        last= newn;
        last->next= first;
    }
    else
    {
        last->next= newn;
        last= newn;
        last->next= first;
    }

}

/////////////////////////////////////////////////////////////////////////////
//      Function Name: deleteFirst()
//      Description: It is used to delete the first node of
//                   LinkedList and also maintain the circular nature.
////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::deleteFirst()
{
    if(first==last)
    {
        free(first);
        first= NULL;
        last= NULL;
    }
    else
    {
        first= first->next;
        free(last->next);
        last->next= first;
    }
}

/////////////////////////////////////////////////////////////////////////////
//      Function Name: deleteLast()
//      Description: It is used to delete the Last node of
//                   LinkedList and also maintain the circular nature.
////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::deleteLast()
{
    if(first==last)
    {
        free(first);
        first= NULL;
        last= NULL;
    }
    else
    {
        struct nodeS<T>* temp= first;
        while(temp->next!=last)
        {
            temp= temp->next;
        }
        last= temp;
        free(last->next);
        last->next= first;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
//      Function Name: display()
//      Description: It is used to display the nodes which are present.
///////////////////////////////////////////////////////////////////////////////////////////////


template <class T>
void SinglyCL<T>::display()
{
    struct nodeS<T>* temp= first;    
    do
    {
        printf("|%d|->",temp->data);
        temp= temp->next;
    }while(temp!=last->next);
    printf("NULL\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////
//      Function Name: nodeCount()
//      Description: It is used to count the number of elements. 
//////////////////////////////////////////////////////////////////////////////////////////////
 
template <class T>
int SinglyCL<T>::nodeCount()
{
    int iCnt= 0;
    struct nodeS<T>* temp= first;
    do
    {
        iCnt++;
        temp= temp->next;
    }while(temp!=last->next);

    return iCnt;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//      Function Name: insertAtPos()
//      Description: Function is used to create the node 
//                   and insert the node at given position.
////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::insertAtPos(T no, int iPos)
{
    int count= nodeCount();

    if(iPos<1 || iPos>count+1)
    {
        printf("Invalid Input\n");
        return;
    }
    else if(iPos==1)
    {
        insertFirst( no);
    }
    else if(iPos==count+1)
    {
        insertLast(no);
    }
    else
    {
        struct nodeS<T>* newn= new struct nodeS<T>;
        newn->data= no;
        newn->next= NULL;
        struct nodeS<T>* temp= first;
        for(int i=1; i<iPos-1; i++)
        {
            temp= temp->next;
        }
        newn->next= temp->next;
        temp->next= newn;

    }

}

//////////////////////////////////////////////////////////////////////////////////////
//      Function Name: deleteAtPos()
//      Description:  Function is used to create the node 
//                   and delete the node at given position.
/////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::deleteAtPos(int iPos)
{
    int count= nodeCount();

    if(iPos<1 || iPos>count)
    {
        printf("Invalid Input\n");
        return;
    }
    else if(iPos==1)
    {
        deleteFirst();
    }
    else if(iPos==count)
    {
        deleteLast();
    }
    else
    {
        
        struct nodeS<T>* temp= first;
        struct nodeS<T>* temp1= NULL;
        for(int i=1; i<iPos-1; i++)
        {
            temp= temp->next;
        }
        temp1= temp->next->next;
        free(temp->next);
        temp->next= temp1;
    }

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//     Class Name: DoublyLL
//     Description: In this class we define the methods
//                  to do operations on the Doubly Linear 
//                  LinkedList in Linear Nature. In this,
//                  we can maintain the address of 2 consecutive nodes. 
///////////////////////////////////////////////////////////////////////////

template<class T>
class DoublyLL
{
    public:
        struct nodeD<T>* first;
        DoublyLL();

        void display();
        int nodeCount();
        void insertFirst(T no);
        void insertLast(T no);
        void deleteFirst();
        void deleteLast();
        void insertAtPos(T no, int iPos);
        void deleteAtPos(int iPos);
};

///////////////////////////////////////////////////////////
//      Function Name: DoublyLL()
//      Description: It is an constructor of the class
//                   DoublyLL. It is used to intialise 
//                   the variables/characteristics.   
//////////////////////////////////////////////////////////

template<class T>
DoublyLL<T>::DoublyLL()
{
    first= NULL;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//      Function Name: display()
//      Description: It is used to display the nodes which are present.
///////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLL<T>::display()
{
    struct nodeD<T>* temp= first;
    while(temp!=NULL)
    {
        printf("|%d|->", temp->data);
        temp= temp->next;
    }
    printf("NULL \n");
}

///////////////////////////////////////////////////////////////////////////////////////////////
//      Function Name: nodeCount()
//      Description: It is used to count the number of elements. 
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyLL<T>::nodeCount()
{
    int iCnt= 0;

    struct nodeD<T>* temp= first;
    while(temp!=NULL)
    {
        iCnt++;
        temp= temp->next;
    }
    return iCnt;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//      Function Name: insertFirst()
//      Description: Function is used to create the linkedlist in linear format 
//                   and insert the node at First , also maintain the doubly in nature 
//                   means maintain the address of 2 consecutive nodes.
//////////////////////////////////////////////////////////////////////////////////////////////////////////


template<class T>
void DoublyLL<T>::insertFirst(T no)
{
    struct nodeD<T>* newn= new struct nodeD<T>;
    newn->data= no;
    newn->next= NULL;
    newn->prev= NULL;

    if(first==NULL)
    {
        first= newn;
    }
    else
    {
        first->prev= newn;
        newn->next= first;
        first= newn;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//      Function Name: insertLast()
//      Description: Function is used to create the linkedlist in linear format 
//                   and insert the node at last , also maintain the doubly in nature 
//                   means maintain the address of 2 consecutive nodes.
//////////////////////////////////////////////////////////////////////////////////////////////////////////


template<class T>
void DoublyLL<T>::insertLast(T no)
{
    struct nodeD<T>* newn= new struct nodeD<T>;
    newn->data= no;
    newn->next= NULL;
    newn->prev= NULL;

    if(first==NULL)
    {
        first= newn;
    }
    else
    {
        struct nodeD<T>* temp= first;

        while(temp->next!=NULL)
        {
            temp= temp->next;
        }
        temp->next= newn;
        newn->prev= temp;
    }
}

/////////////////////////////////////////////////////////////////////////////
//      Function Name: deleteFirst()
//      Description: It is used to delete the first node of
//                   LinkedList also maintain the doubly in nature.
////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLL<T>::deleteFirst()
{
    if(first==NULL)
    {
        printf("LinkedList is empty\n");
        return;
    }
    else
    {
        first= first->next;
        delete(first->prev);
        first->prev= NULL;
    }
}

/////////////////////////////////////////////////////////////////////////////
//      Function Name: deleteLast()
//      Description: It is used to delete the last node of
//                   LinkedList also maintain the doubly in nature.
////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLL<T>::deleteLast()
{
    if(first==NULL)
    {
        printf("LinkedList is empty\n");
        return;
    }
    else
    {
        struct nodeD<T>* temp= first;

        while(temp->next->next!=NULL)
        {
            temp= temp->next;
        }
        delete (temp->next);
        temp->next= NULL;
    }
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////
//      Function Name: insertAtPos()
//      Description: Function is used to create the linkedlist in linear format 
//                   and insert the node at given position , also maintain the doubly in nature 
//                   means maintain the address of 2 consecutive nodes.
//////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLL<T>::insertAtPos( T no, int iPos)
{
    int count= nodeCount();

    if(iPos<1 || iPos>count+1)
    {
        printf("Invalid Input\n");
        return;
    }
    else if(iPos==1)
    {
        insertFirst( no);
    }
    else if(iPos==count+1)
    {
        insertLast(no);
    }
    else
    {
        struct nodeD<T>* temp= first;
        struct nodeD<T>* newn= new struct nodeD<T>;
        newn->data= no;
        newn->next= NULL;
        newn->prev= NULL;
        for(int i=1; i<iPos-1; i++)
        {
            temp= temp->next;
        }
        newn->next= temp->next;
        temp->next= newn;
        newn->prev= temp;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//      Function Name: deleteAtPos()
//      Description: Function is used to delete the linkedlist in linear format 
//                   and delete the node at given position , also maintain the doubly in nature 
//                   means maintain the address of 2 consecutive nodes.
//////////////////////////////////////////////////////////////////////////////////////////////////////////


template<class T>
void DoublyLL<T>::deleteAtPos( int iPos)
{
    struct nodeD<T>* temp= NULL;
    struct nodeD<T>* temp1= NULL;
    int count= nodeCount();

    if(iPos<1 || iPos>count)
    {
        printf("Invalid Input\n");
        return;
    }
    else if(iPos==1)
    {
        deleteFirst();
    }
    else if(iPos==count)
    {
        deleteLast();
    }
    else
    {
        temp= first;
        
        for(int i=1; i<iPos-1; i++)
        {
            temp= temp->next;
        }
        temp1= temp->next;
        temp->next = temp1->next;
        delete(temp1);
        temp->next->prev= temp;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//     Class Name: DoublyCLL
//     Description: In this class we define the methods
//                  to do operations on the Doubly Circular 
//                  LinkedList in Circular Nature. In this,
//                  we can maintain the address of 2 consecutive nodes and 
//                  also maintains the address of first and last node. 
//                  So this will create a circular nature.
///////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyCL
{
    public:
        struct nodeD<T>* first;
        struct nodeD<T>* last; 
        DoublyCL();

        void insertFirst(T no);
        void insertLast(T no);
        void deleteFirst();
        void deleteLast();
        void display();
        int nodeCount();
        void insertAtPos(T no, int iPos);
        void deleteAtPos(int iPos);
};

///////////////////////////////////////////////////////////
//      Function Name: DoublyCL()
//      Description: It is an constructor of the class
//                   DoublyCL. It is used to intialise 
//                   the variables/characteristics.   
//////////////////////////////////////////////////////////

template <class T>
DoublyCL<T>::DoublyCL()
{
    first= NULL;
    last= NULL;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//      Function Name: insertFirst()
//      Description: Function is used to create the linkedlist in Circular format 
//                   and insert the node at First , also maintain the doubly in nature 
//                   means maintain the address of 2 consecutive nodes.
//////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::insertFirst(T no)
{
    struct nodeD<T>* newn= new struct nodeD<T>;
    newn->data= no;
    newn->next= NULL;
    newn->prev= NULL;

    if(first==NULL && last==NULL)
    {
        first= newn;
        last= newn;
    }
    else
    {
        newn->next= first;
        first->prev= newn;
        first= newn;
    }
    first->prev= last;
    last->next= first;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//      Function Name: insertLast()
//      Description: Function is used to create the linkedlist in circular format 
//                   and insert the node at last , also maintain the doubly in nature 
//                   means maintain the address of 2 consecutive nodes.
//////////////////////////////////////////////////////////////////////////////////////////////////////////


template <class T>
void DoublyCL<T>::insertLast(T no)
{
    struct nodeD<T>* newn= new struct nodeD<T>;
    newn->data= no;
    newn->next= NULL;
    newn->prev= NULL;

    if(first==NULL && last==NULL)
    {
        first= newn;
        last= newn;
    }
    else
    {
        newn->prev= last;
        last->next= newn;
        last= newn;
    }
    first->prev= last;
    last->next= first;
}

/////////////////////////////////////////////////////////////////////////////
//      Function Name: deleteFirst()
//      Description: It is used to delete the first node of
//                   LinkedList also maintain the doubly in nature.
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::deleteFirst()
{
    if (first==NULL && last==NULL)
    {
        printf("LinkedList is Empty\n");
        return;
    }
    else
    {
        first= first->next;
        free(last->next);
        first->prev= last;
        last->next= first;
    }
}

/////////////////////////////////////////////////////////////////////////////
//      Function Name: deleteLast()
//      Description: It is used to delete the last node of
//                   LinkedList also maintain the doubly in nature.
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::deleteLast()
{
    if (first==NULL && last==NULL)
    {
        printf("LinkedList is Empty\n");
        return;
    }
    else
    {
        last= last->prev;
        free(first->prev);
        first->prev= last;
        last->next= first;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
//      Function Name: display()
//      Description: It is used to display the nodes which are present.
///////////////////////////////////////////////////////////////////////////////////////////////


template <class T>
void DoublyCL<T>::display()
{
    struct nodeD<T>* temp1= first;
    struct nodeD<T>* temp2= last;
    do
    {
        printf("|%d|<=>",temp1->data);
        temp1= temp1->next;
    }while(temp1!=temp2->next);
    printf("\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////
//      Function Name: nodeCount()
//      Description: It is used to count the number of elements. 
//////////////////////////////////////////////////////////////////////////////////////////////


template <class T>
int DoublyCL<T>::nodeCount()
{
    int iCnt= 0;
    struct nodeD<T>* temp1= first;
    struct nodeD<T>* temp2= last;

    do
    {
        iCnt++;
        temp1= temp1->next;
    }while(temp1!=temp2->next);

    return iCnt;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//      Function Name: insertAtPos()
//      Description: Function is used to create the linkedlist in Circular format 
//                   and insert the node at given position , also maintain the doubly in nature 
//                   means maintain the address of 2 consecutive nodes.
//////////////////////////////////////////////////////////////////////////////////////////////////////////


template <class T>
void DoublyCL<T>::insertAtPos(T no, int iPos)
{
    
    int count= nodeCount();

    if(iPos<1 && iPos>count+1)
    {
        printf("Invalid Input\n");
        return;
    }
    else if(iPos==1)
    {
        insertFirst(no);
    }
    else if(iPos==count+1)
    {
        insertLast(no);
    }
    else
    {
        struct nodeD<T>* newn= new struct nodeD<T>;
        newn->data= no;
        newn->next= NULL;
        newn->prev= NULL;

        struct nodeD<T>* temp= first;
        for(int i=1; i<iPos-1; i++)
        {
            temp= temp->next;
        }
        newn->next=temp->next;
        newn->prev= temp;
        temp->next= newn;
    }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//      Function Name: deleteAtPos()
//      Description: Function is used to delete the linkedlist in doubly format 
//                   and delete the node at given position, also maintain the doubly in nature 
//                   means maintain the address of 2 consecutive nodes.
//////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::deleteAtPos(int iPos)
{
    
    int count= nodeCount();

    if(iPos<1 && iPos>count+1)
    {
        printf("Invalid Input\n");
        return;
    }
    else if(iPos==1)
    {
        deleteFirst();
    }
    else if(iPos==count)
    {
        deleteLast();
    }
    else
    {
        struct nodeD<T>* temp= first;
        struct nodeD<T>* temp1= NULL;
        for(int i=1; i<iPos-1; i++)
        {
            temp= temp->next;
        }
        temp1= temp->next;
        temp->next= temp->next->next;
        free(temp1);
        temp->next->prev= temp;
    }

}




int main()
{


    return 0;
}