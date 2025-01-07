#include "LinkedList.h"
#include "Node.h"

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

LinkedList::LinkedList()
{
}

LinkedList::~LinkedList()
{
    if (head != nullptr)
    {
        Node* current = head;
        Node* deleteNode = nullptr;

        while (current != nullptr)
        {
            deleteNode = current;
            current = current->next;

            delete deleteNode;
        }
    }
}

void LinkedList::AddToHead(int data)
{
    // �� ��� ����.
    Node* newNode = new Node(data);

    // 1. ��尡 ���� ���.
    if (head == nullptr)
    {
        head = newNode;
    } 
    // 2. ��尡 �ִ� ���.
    else
    {
        // �� ����� ���� ��带 ������ ��� ���� ����.
        newNode->next = head;
        // ��� ��带 �� ���� ��ü.
        head = newNode;
    }

    // ����� ��� �� ���� ó��.
    ++count;
}

void LinkedList::Insert(int data)
{
    // �� ��� ����.'
    Node* newNode = new Node(data);

    // ������ ��ġ ã��.
    // 1. ��尡 ��� �ִ� ���.
    if (head == nullptr)
    {
        head = newNode;
    }
    else  // ������ ��ġ �˻�
    {
        Node* current = head;
        Node* trail = nullptr;

        // ��ġ �˻�
        while (current != nullptr)
        {

            // �� ��
            if (current->data >= data)
            {
                break;
            }
            // ���� ���� �̵�.
            trail = current;
            current = current->next;
        }

        // �˻��� ����� Ȯ���ؼ� ó��.
        if (current == head)
        {
            newNode->next = head;
            head = newNode;
        }
        else  // �˻��� ��尡 �߰� ��ġ�� ���.
        {
            newNode->next = current;
            trail->next = newNode;

        }
    }
    // ��� �� ���� ó��.
    ++count;
}

void LinkedList::Delete(int data)
{
    // ������ ��� ã��.
    // ���� ó��.
    if (head == nullptr)
    {
        std::cout << "����Ʈ�� ����־� ������ �Ұ��� �մϴ�.\n";
        return;
    }

    // �˻� ����.
    Node* current = head;
    Node* trail = nullptr;

    while (current != nullptr)
    {
        if (current->data == data)
        {
            break;
        }

        trail = current;
        current = current->next;
    }

    // �˻��� ��� 2����.
    // 1. ��ã�� ���.
    if (current == nullptr)
    {
        std::cout << "�� " << data << "�� ã�� ���߽��ϴ�.\n";
        return;
    }

    // 2. ã�� ���.
    if (head == current)
    {
        // ��� ��� ��ü.
        head = head->next;
    }
    else
    {
        trail->next = current->next;
    }

    // ��� ����.
    delete current;

    // ��� �� ����.
    --count;
}

void LinkedList::Print()
{
    Node* current = head;
    while (current != nullptr)
    {
        std::cout << *current << "\n";
        current = current->next;
    }
}

int LinkedList::Count() const
{
    return count;
}