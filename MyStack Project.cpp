#include <iostream>
using namespace std;

template <class T>

class clsDblLinkedList
{
protected:
    int _Size = 0;

public:
    class Node
    {
    public:
        T Value;
        Node* Next;
        Node* Prev;
    };

    Node* Head = NULL;

    void PrintList()
    {
        Node* Current = Head;

        while (Current != NULL)
        {
            cout << Current->Value << " ";
            Current = Current->Next;
        }
        cout << "\n";
    }

    Node* Find(T Value)
    {
        Node* Current = Head;

        while (Current != NULL)
        {
            if (Current->Value == Value)
                return Current;
            Current = Current->Next;
        }
        return NULL;
    }

    void InsertAtBeginning(T Value)
    {
        Node* NewNode = new Node;
        NewNode->Value = Value;
        NewNode->Next = Head;
        NewNode->Prev = NULL;

        if (Head != NULL)
            Head->Prev = NewNode;

        Head = NewNode;
        _Size++;
    }

    void InsertAfter(Node* Current, T Value)
    {
        if (Current == NULL)
            return;

        Node* NewNode = new Node;
        NewNode->Value = Value;
        NewNode->Next = Current->Next;
        NewNode->Prev = Current;

        if (Current->Next != NULL)
            Current->Next->Prev = NewNode;

        Current->Next = NewNode;
        _Size++;
    }

    void InsertAtEnd(T Value)
    {
        Node* NewNode = new Node;
        NewNode->Value = Value;
        NewNode->Next = NULL;

        if (Head == NULL)
        {
            NewNode->Prev = NULL;
            Head = NewNode;
        }
        else
        {
            Node* LastNode = Head;
            while (LastNode->Next != NULL)
                LastNode = LastNode->Next;

            NewNode->Prev = LastNode;
            LastNode->Next = NewNode;
        }
        _Size++;
    }

    void DeleteNode(Node*& NodeToDelete)
    {
        if (Head == NULL || NodeToDelete == NULL)
            return;

        if (Head == NodeToDelete)
            Head = NodeToDelete->Next;

        if (NodeToDelete->Next != NULL)
            NodeToDelete->Next->Prev = NodeToDelete->Prev;

        if (NodeToDelete->Prev != NULL)
            NodeToDelete->Prev->Next = NodeToDelete->Next;

        delete NodeToDelete;
        _Size--;
    }

    void DeleteFirstNode()
    {
        if (Head == NULL)
            return;

        Node* Temp = Head;
        Head = Head->Next;

        if (Head != NULL)
            Head->Prev = NULL;

        delete Temp;
        _Size--;
    }

    void DeleteLastNode()
    {
        if (Head == NULL)
            return;

        if (Head->Next == NULL)
        {
            delete Head;
            Head = NULL;
            _Size--;
            return;
        }

        Node* Current = Head;
        while (Current->Next->Next != NULL)
            Current = Current->Next;

        Node* Temp = Current->Next;
        Current->Next = NULL;
        delete Temp;
        _Size--;
    }

    int Size()
    {
        return _Size;
    }

    bool IsEmpty()
    {
        return (_Size == 0);
    }

    void Clear()
    {
        while (!IsEmpty())
            DeleteFirstNode();
    }

    void Reverse()
    {
        Node* Current = Head;
        Node* Temp = nullptr;

        while (Current != nullptr)
        {
            Temp = Current->Prev;
            Current->Prev = Current->Next;
            Current->Next = Temp;
            Current = Current->Prev;
        }

        if (Temp != nullptr)
            Head = Temp->Prev;
    }

    Node* GetNode(int Index)
    {
        if (Index > (_Size - 1) || Index < 0)
            return NULL;

        Node* Current = Head;
        int Counter = 0;

        while (Counter != Index)
        {
            Current = Current->Next;
            Counter++;
        }
        return Current;
    }

    T GetItem(int Index)
    {
        Node* ItemNode = GetNode(Index);
        if (ItemNode == NULL)
            return NULL;
        else
            return ItemNode->Value;
    }

    bool UpdateItem(int Index, T NewValue)
    {
        Node* ItemNode = GetNode(Index);
        if (ItemNode != NULL)
        {
            ItemNode->Value = NewValue;
            return true;
        }
        return false;
    }

    bool InsertAfter(int Index, T Value)
    {
        Node* ItemNode = GetNode(Index);
        if (ItemNode != NULL)
        {
            InsertAfter(ItemNode, Value);
            return true;
        }
        return false;
    }
};

template <class T>

class clsMyQueue
{
protected:
    clsDblLinkedList<T> _MyList;

public:
    void Push(T Item)
    {
        _MyList.InsertAtEnd(Item);
    }

    void Pop()
    {
        _MyList.DeleteFirstNode();
    }

    void Print()
    {
        _MyList.PrintList();
    }

    int Size()
    {
        return _MyList.Size();
    }

    bool IsEmpty()
    {
        return _MyList.IsEmpty();
    }

    T Front()
    {
        return _MyList.GetItem(0);
    }

    T Back()
    {
        return _MyList.GetItem(Size() - 1);
    }

    T GetItem(int Index)
    {
        return _MyList.GetItem(Index);
    }

    void Reverse()
    {
        _MyList.Reverse();
    }

    void UpdateItem(int Index, T NewValue)
    {
        _MyList.UpdateItem(Index, NewValue);
    }

    void InsertAfter(int Index, T NewValue)
    {
        _MyList.InsertAfter(Index, NewValue);
    }

    void InsertAtFront(T Value)
    {
        _MyList.InsertAtBeginning(Value);
    }

    void InsertAtBack(T Value)
    {
        _MyList.InsertAtEnd(Value);
    }

    void Clear()
    {
        _MyList.Clear();
    }
};

template <class T>

class clsMyStack : public clsMyQueue<T>
{
public:
    void Push(T Item)
    {
        clsMyQueue<T>::_MyList.InsertAtBeginning(Item);
    }

    T Top()
    {
        return clsMyQueue<T>::Front();
    }

    T Bottom()
    {
        return clsMyQueue<T>::Back();
    }

    void Pop()
    {
        clsMyQueue<T>::Pop();
    }

    T GetItem(int Index)
    {
        return clsMyQueue<T>::GetItem(Index);
    }

    void Reverse()
    {
        clsMyQueue<T>::Reverse();
    }

    void UpdateItem(int Index, T value)
    {
        clsMyQueue<T>::UpdateItem(Index, value);
    }

    void InsertAfter(int Index, T value)
    {
        clsMyQueue<T>::InsertAfter(Index, value);
    }

    void InsertAtFront(T value)
    {
        clsMyQueue<T>::InsertAtFront(value);
    }

    void InsertAtBack(T value)
    {
        clsMyQueue<T>::InsertAtBack(value);
    }

    void Clear()
    {
        clsMyQueue<T>::Clear();
    }
};

int main()
{
    clsMyStack<int> MyStack;

    MyStack.Push(10);
    MyStack.Push(20);
    MyStack.Push(30);
    MyStack.Push(40);
    MyStack.Push(50);

    cout << "\nStack:\n";
    MyStack.Print();

    cout << "\nStack Size  : " << MyStack.Size();
    cout << "\nStack Top   : " << MyStack.Top();
    cout << "\nStack Bottom: " << MyStack.Bottom();

    MyStack.Pop();

    cout << "\n\nStack after Pop(): \n";
    MyStack.Print();

    cout << "\n\nItem(2): " << MyStack.GetItem(2);

    MyStack.Reverse();

    cout << "\n\nStack after Reverse(): \n";
    MyStack.Print();

    MyStack.UpdateItem(2, 600);

    cout << "\n\nStack after Updating Item(2) to 600: \n";
    MyStack.Print();

    MyStack.InsertAfter(2, 800);

    cout << "\n\nStack after Inserting 800 after Item(2): \n";
    MyStack.Print();

    MyStack.InsertAtFront(1000);

    cout << "\n\nStack after Inserting 1000 at front: \n";
    MyStack.Print();

    MyStack.InsertAtBack(2000);

    cout << "\n\nStack after Inserting 2000 at back: \n";
    MyStack.Print();

    MyStack.Clear();

    cout << "\n\nStack after Clear(): \n";
    MyStack.Print();

    return 0;
}