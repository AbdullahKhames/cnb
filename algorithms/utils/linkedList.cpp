#include "../main.h"


StringNode* createStringLinkedList(string data) {
    StringNode *stringNode = new StringNode();
    stringNode->data = data;
    stringNode->next = nullptr; 
    return stringNode;
}

StringNode* addToStringLinkedList(StringNode* head, string data) {
    if (!head)
    {
        return NULL;
    }
    
    StringNode *stringNode = createStringLinkedList(data);
    StringNode *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    
    temp->next = stringNode;
    return stringNode;
}
StringNode* getFromStringLinkedList(StringNode* head, int index) {
    if (!head)
    {
        return NULL;
    }
    
    int count = 0;
    StringNode *temp = head;
    while (temp)
    {
        if (index == count)
        {
            return temp;
        }
        temp = temp->next;
        count++;
    }
    return NULL;
}
StringNode* deleteFromStringLinkedList(StringNode* head, int index) {
    if (!head || index < 0)
    {
        return NULL;
    }
    StringNode *temp = head;
    if (index == 0)
    {
        head = head->next;
        free(temp);
        return head;
    }
    int count = 0;
    StringNode *prev = temp;
    temp = temp->next;
    while (prev && temp)
    {
        if (index - 1 == count )
        {
            prev->next = temp->next;
            free(temp);
            return head;
        }
        temp = temp->next;
        prev = prev->next;
        count++;
    }
    cout << "index is higher than count "  << index << " " << count << endl;
    return head;

}

void printStringLinkedList(StringNode* head) {
    if (!head)
    {
        return;
    }
    cout<<"in print" << endl;
    StringNode *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
