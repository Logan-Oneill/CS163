#include "text_messenger.h"

//*******************Stack ADT functions************************
Stack::Stack()
{
    head = NULL;
    top_index = 0;
}

Stack::~Stack()
{

}

//Pushes a text message onto the stack TODO
int Stack::push(text &textMessage)
{
    //If the stack is empty, make a new node, add the text to the array, shift
    //and  then index
    if(!head)
    {
        head = new s_node;
        head->textMessages = new text[5];
        head->next = NULL;
        head->textMessages[top_index] = textMessage;
        ++top_index;
        return 1;
    }
    
    //If the stack has nodes, but the head's array is full, create a new node
    //append data to that node, connect the new node to the list, make the new
    //node head.
    if(top_index >= 4)
    {
        top_index = 0;
        s_node * temp = new s_node;
        temp->textMessages = new text[5];
        temp->next = head;
        temp->textMessages[top_index] = textMessage;
        head = temp;
        ++top_index;
        return 1;
    }

    //If there is data and the current array is not full append a text message
    //to the array and increment top_index
    if(top_index < 4)
    {
        head->textMessages[top_index] = textMessage;
        ++top_index;
        return 1;
    }

    //failure case, somehow no cases were met and the data is not pushed onto
    //the stack
    return 0;
}

//pops a data item off of the stack. TODO
int Stack::pop()
{
    //if head is empy nothing is there
    if(!head) return 0;

    //Check if the array only has 1 item
    if(top_index == 0)
    {
        delete head->textMessages[top_index].sender;
        delete head->textMessages[top_index].message;
        delete [] head->textMessages;
        
        //If that was the last item in the stack, the stack is now empty
        if(!head->next)
        {
            delete head;
            return 1;
        }

        //If there are more nodes in the stack, shift to that node and the 
        //last element in that node's array
        if(head->next)
        {
            s_node * temp = head;
            head = head->next;
            delete temp;
            top_index = 4;
            return 1;
        }
        return 0;
    }
    
    //The case where we are not at the 0th item in the node's array
    //TODO possible memory problem. The text is not deleted from the array
    //If we popped once, and then pushed onto the stack I'm not sure if the
    //pushed text message would overwrite the previous popped text message
    if(top_index <= 4)
    {
        delete head->textMessages[top_index].sender;
        delete head->textMessages[top_index].message;
        --top_index;
        return 1;
    }

    //If no cases were met, base case will return 0 for failure
    return 0;
}

//*******************Queue ADT Functions************************
Queue::Queue()
{
    rear = NULL;
}

Queue::~Queue()
{

}

//Adds a data item to the queue. TODO
int Queue::enqueue(text &textMessage)
{

}

//removes a data item from the queue. TODO
int Queue::dequeue()
{

}

//*******************Text Messenger ADT Functions***************

