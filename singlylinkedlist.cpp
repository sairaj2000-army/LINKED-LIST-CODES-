#include<iostream>
using namespace std;

class node
{
        public:
                int data ;
                node* next;
};

class sll
{
        node *head ,*tail;
    public:
            sll()   //default cnstructor called
            {
                head=NULL ;
                tail=NULL;
            }
            void create_list();
            void insert_at_position();
            void displaylist();
            void delete_node();
            void reverse_list();
            void concate_list(sll a );
            void length();
            void merge_list(node *temp1,node *temp2);
            void sort_list();
};

void sll :: create_list()
{

        node *temp;
        temp = head;

        temp = new node;
        cout<<"\n enter the data";
        cin>>temp->data;
        temp->next =NULL;

        if( head == NULL)
        {
                head = temp;
                tail = temp;

        }
        else
        {

                tail->next = temp;
                tail =temp;

        }

}

void sll :: insert_at_position()
{
    int position ;
    cout<<"\n enter the position ";
    cin>>position;
    node *temp =head;
    node *NEW=new node ;
    cout<<"\n enter the data ";
    cin>>NEW->data;
    NEW->next=NULL;

    if(position==1 )
    {
        NEW->next=temp;
        head=NEW;
    }
    else
    {
        for(int i=1;i<position-1 ;i++)
        {
            temp=temp->next;

        };
        NEW->next=temp->next;
        temp->next=NEW;
    }


}

void sll :: displaylist()
{
    node *temp=new node ;
    temp=head;
    cout<<"\n data to be displayed is ";
    if( temp==NULL )
    {
        cout<<"\n list is empty ";
    }
    else
    {
            while(temp!=NULL)
            {
                cout<<"\n"<<temp->data;
                temp=temp->next;
            };
    }
}

void sll :: delete_node()
{
    node *temp=head , *NEWTEMP ;
        if( head==NULL)
    {
        cout<<"\n list is empty";
    }

    int position ;
    cout<<"\n enter the position";
    cin>>position ;

    if(position ==1 )
    {
        head=temp->next;
        delete(temp);
    }
    else
    {
        //NEWTEMP=temp->next;
        for(int i=1;i<position-1;i++)
        {
            temp=temp->next;
        }


        NEWTEMP = temp->next->next;
        delete(temp->next);
        temp->next=NEWTEMP;

    }

}

void sll :: reverse_list()
{
    node *temp=head;
    node *NEWTEMP=NULL;
    node *auxillary=NULL;
    while( temp != NULL )
    {
        NEWTEMP = temp->next;
        temp->next=auxillary;
        auxillary=temp;
        temp=NEWTEMP;
    };
    head=auxillary;
}

void sll:: concate_list(sll a)
{
    node *temp =head;   //original list
    node *temp1=a.head; //new list
    while( temp->next!=NULL )
    {
        temp=temp->next;
    };
    temp->next=temp1;
}

void sll :: length()
{
    node *temp=head;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    };
    cout<<"\n length of list is "<<count;

}

void sll :: merge_list(node *temp1, node *temp2)
{
    node *t1,*t2,*t3,*t4;
    //node *temp1=NULL,*temp2=NULL;
    t1=temp1;
    t2=temp2;
    t3=t1->next;
    t4=t2->next;
    while(t1!=NULL && t2!=NULL )
    {
        t1->next=t2;
        t2->next=t3;
        t2=t4;
        t3=t3->next;
        t4=t4->next;
    };
    if(t1==NULL )
    {
        t1=temp1;
        while(t1->next!=NULL)
        {
            t1=t1->next;
            t1->next=t2;
        };
    }

}

void sll :: sort_list()
{
   node *temp=head;
   node *temp1=NULL;
   int a;   //temporary variable
   if( head==NULL )
   {
       cout<<"\n list is empty";
   }
   else
   {
       while( temp!=NULL)
       {
            temp1=temp->next;
            while( temp1!=NULL)
            {
                    if( temp->data>temp1->data)
                    {
                        int a=temp->data;
                        temp->data=temp1->data;
                        temp1->data=a;
                    }
                    temp1=temp1->next;
            };
            temp=temp->next;

       };
   }



}


int main()
{
    sll a;


    a.create_list();
    a.displaylist();

    a.insert_at_position();
    a.insert_at_position();
    a.insert_at_position();
    a.insert_at_position();
    a.insert_at_position();
    a.displaylist();
    a.delete_node();
    a.displaylist();
    a.reverse_list();
    a.displaylist();
    a.length();
    sll b;
    b.insert_at_position();
    b.insert_at_position();
    a.concate_list(b);
    a.displaylist();
    /*node *temp1=new node ;
    node *temp2=new node;
    a.merge_list(temp1,temp2);
    cout<<"\n merged list is ";
    a.displaylist();*/

    a.sort_list();
    a.displaylist();
    return 0;


}

/*void sll :: insert_node()
{
    int position;
    cout<<"\n enter the position ";
    cin>>position;

    node *temp , *current ;
    temp=head;
    current =new node  ;
    cout<<"\n enter the data ";
    cin>>current->data;
    current->next=NULL;
    if(position==1)
    {
        current->next=temp;
        head=current;
    }
    else if(position>0 && position<5)
    {
            current =head;
            for(int i=1;i<position-1;i++)
            {
                current=current->next;

            }
            temp->next=current->next;
            current->next=temp;
    }
    else
    {
        cout<<"\n position out of range ";
    }

}*/




