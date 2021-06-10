// { Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}
// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/
Node * merge (Node * a,Node * b){
    Node * t=new Node(0);
    Node * t2=t;
    while(a&&b){
        if(a->data<b->data){
            t->bottom=a;
            a=a->bottom;
            t=t->bottom;
        }
        else {
            t->bottom=b;
            b=b->bottom;
             t=t->bottom;
        }
    }
    while(a){
       t->bottom=a;
            a=a->bottom;
             t=t->bottom;
    }
    while(b){
          t->bottom=b;
            b=b->bottom;
             t=t->bottom;
    }
    
    return t2->bottom;
}
/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
    if(root==NULL)
    return NULL;
    Node *temp=root->next;
     Node *m=root;
    while(temp!=NULL){
        
     m= merge(m,temp);
        temp=temp->next;
    }
    
    return m;
   // Your code here
}
