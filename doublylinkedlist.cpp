#include<iostream>
using namespace std;

class node
{
    public:
            int data ;
            node *next,*prev;
};

class dll
{
        node *head,*tail;
    public:
            dll()       //constructor called
            {
                head=NULL;
                tail=NULL;
            }
            void create_list();
            void displaylist();
            void reverse_list();
            void insert_at_begining();
            void insert_at_end();
            void insert_in_between();
            void insert_by_position();
            void delete_first();
            void delete_last();
            void delete_by_postion();

};

void dll :: create_list()
{
    node *temp;
    int n;
    cout<<"\n enter the elements ";
    cin>>n;
    for( int i=0;i<n;i++)
    {
        temp=new node ;
        cout<<"\n enter the data ";
        cin>>temp->data ;
        temp->next=NULL;
        temp->prev=NULL;
        if( i==0)
        {
            head=temp;
            tail=temp;
        }
        else
        {
            tail->next=temp;
            temp->prev=tail;
        }
        tail=temp;
    }
}

void dll :: displaylist()
{
    node *temp=new node ;
    temp=head;
    cout<<"\n data to be displayed ";
    if(temp==NULL)
    {
        cout<<"\n list is empty";
    }
    else
    {
        while( temp!=NULL)
        {
            cout<<"\n"<<temp->data;
            temp=temp->next;
        };
    }
}

void dll :: reverse_list()
{
    node *temp=head;
    while( temp->next!=NULL)
    {
        temp=temp->next;
    };
    cout<<"\n reverse list is ";
    while(temp!=NULL)
    {
        cout<<"\n"<<temp->data;
        temp=temp->prev;
    };
}

void dll ::insert_at_begining()
{
   node *temp=new node ;
   cout<<"\n enter the data ";
   cin>>temp->data ;
   temp->prev=NULL;
   temp->next=head;
   head->prev=temp;
   head=temp;
}

void dll :: insert_at_end()
{
    node *temp=new node ;
    cout<<"\n enter the data ";
    cin>>temp->data ;
    temp->next=NULL;
    temp->prev=NULL;
    node *temp1=head;   //temp1 is used to keep track of head node
    if( head ==NULL )
    {
        cout<<"\n list is empty ";
    }
    while( temp1->next!=NULL )
    {
        temp1=temp1->next;
    };
    temp->prev=temp1;
    temp1->next=temp;
}

void dll :: insert_in_between()
{
    node *temp = new node ;
    cout<<"\n enter the data ";
    cin>>temp->data ;
    node *temp1=head->next;;
    temp->next=temp1->next;
    temp->prev=temp1;
    temp1->next=temp;
    if( temp->next!=NULL)
    {
        temp->next->prev=temp;
    }
}

void dll :: insert_by_position()
{
    node *temp1=head;
    node *temp;
    if( head==NULL)
    {
        cout<<"\n list is empty";
    }
    else
    {
        int position ;
        cout<<"\n enter the position ";
        cin>>position;
        if( position==1 )
        {
            cout<<"\n invalid as function for it (insert_at_beginning";
        }
        else
        {
            int i=2 ;
            while(i<=position-1 && temp1!=NULL)
            {
                temp1=temp1->next;
                i++;
            };
            if( temp1!=NULL)    //checking if head is not empty
            {
                temp=new node ;
                cout<<"\n enter the data ";
                cin>>temp->data ;
                temp->next=temp1->next;
                temp->prev=temp1;
                if( temp1->next!=NULL)
                {
                    temp1->next->prev=temp;
                }
                temp1->next=temp;
            }
            else
            {
                cout<<"\n invalid position ";

            }
        }
    }
}

void dll :: delete_first()
{
    node *temp=head;
    temp->next->prev=NULL;
    head=temp->next;delete(temp);
}

void dll::delete_last()
{

    if( head->next==NULL)
    {
        delete(head);
        head=NULL;
    }
    node *temp=head;
    node *temp1;
    while( temp->next!=NULL)
    {
        temp1=temp;
        temp=temp->next;
    };
    delete(temp);
    temp1->next=NULL;
}

void dll::delete_by_postion()
{
    node *temp=head;
    if( head==NULL)
    {
        cout<<"\n list is empty";
    }
    else
    {
        int position ;
        cout<<"\n enter the position ";
        cin>>position ;
        if( position==1)
        {
            cout<<"\n invalid as function exists for it ";

        }
        else
        {
            int i=1;
            while( i<=position-1 && temp!=NULL )
            {
                temp=temp->next;
                i++;
            };
            if( temp->next!=NULL)
            {
               temp->next->prev=temp->prev;
               temp->prev->next=temp->next;
               delete(temp);
            }

        }
    }

}

int main()
{
    dll a;
    //*****************
    a.create_list();
    a.displaylist();
    a.reverse_list();
    a.displaylist();
    //******************
    a.insert_at_begining();
    a.displaylist();
    a.insert_at_end();
    a.displaylist();
    a.insert_in_between();
    a.displaylist();
    a.insert_by_position();
    a.displaylist();
    //********************
    a.delete_first();
    a.displaylist();
    a.delete_last();
    a.displaylist();
    a.delete_by_postion();
    a.displaylist();



    return 0;

}

