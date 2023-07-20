#include <iostream>
#include <conio.h>
#include <iomanip>
#include <stdlib.h>
using namespace std;

class Node {
    int value;   Node* nxt;
    public:
    Node() { value=0;  nxt = NULL; }
    ~Node() { delete nxt; }
		void setvalue(int value) { this->value = value; }
		int getvalue()  { return value; }
		void setnxtNode(Node* nxt) {  this->nxt=nxt; }
		Node* getnxtNode() { return nxt; }
};

class SLL {
    int size;   
    Node* head;
    Node* current;   
    public:
    SLL() { size=0;  head = NULL;  current= NULL;  }
    ~SLL() { delete head;  delete current; }
        void Error();
        void NoRecord();
        void Complete();
        bool Nolist();
        void Exit();
        void RepeatitionMenu(int&);
        void IDMenu(int&);
        void USCMenu(int&);
        int findsize(int);
        int* find(int);

        void Create(int val) {
                Node* newnode = new Node;
                newnode->setvalue(val);
            if(head == NULL) {
                newnode->setnxtNode(NULL);
                head = newnode;
            }
            else {
                current = head;
                while(current->getnxtNode() != NULL) {
                    current = current->getnxtNode();
                }
                current->setnxtNode(newnode);
                newnode->setnxtNode(NULL);
            }
            size++;
        }

        void InsertionMenu() {
            int check = Nolist();
            if(check!=0) {
			int choice;
			do{
				IDMenu(choice);
				
					  switch(choice) {
					  	
					  	case 1:   int val;
						  		  cout<<"\nEnter the Value: ";  cin>>val;
						  		  InsertStart(val);     Display();  
				                  system("cls");   break;
						
					  		case 2:    InsertEnd();   Display();  
							           system("cls");    break;
						  
					  			case 3:  Display();  
								int location;
    	                        cout<<"\nIndex for Insertion: ";  cin>>location; 
								InsertAfterSpecific(location,0);   Display();  
								system("cls");   break;

                                    case 4:  Display();  
								    int data;
    	                            cout<<"\nData for Insertion: ";  cin>>data; 
								    InsertAfterValue(data);   Display();  
								    system("cls");   break;
								
					  				    case 6: Exit();  exit(0) ; 
					  				
					default:  if(choice != 5) { Error(); } 
					  } 
			    }while(choice != 5);
		    }
        }

        void InsertStart(int val) {
            Node* newnode = new Node;   
            newnode->setvalue(val);
            if(head == NULL) {
                head = newnode;
                newnode->setnxtNode(NULL);
            }
            else {
                newnode->setnxtNode(head);
                head = newnode;
            }
            size++;   Complete();
        }

        void InsertEnd() {
            Node* newnode = new Node;   int val;
            cout<<"\nEnter the Value: ";  cin>>val;
            newnode->setvalue(val);
            if(head == NULL) {
                head = newnode;
                newnode->setnxtNode(NULL);
            }
            else {
                current = head;
                while(current->getnxtNode() != NULL) {
                    current = current->getnxtNode();
                }
                current->setnxtNode(newnode);
                newnode->setnxtNode(NULL);
            }
            size++;   Complete();
        }

        void InsertAfterSpecific(int index, int val) {
            if(index>size || index<0) {  Error();  }
            else if(index==0) {
			    int val;  cout<<"\nEnter the Value: ";  cin>>val; 
				InsertStart(val); 
			}
            else {
                Node* newnode = new Node;   int val;
                cout<<"\nEnter the Value: ";  cin>>val; 
                newnode->setvalue(val);
                current = head;
                int i = 0;  // i=1
                while(i != index-1) {  //i!=index
                    current = current->getnxtNode();
                    i++;
                }
                newnode->setnxtNode(current->getnxtNode());
                current->setnxtNode(newnode);
                size++;   Complete();
            }
        }

        void InsertAfterValue(int data) {
            int found = Search(data);  
            if(found==1) {
                Node* newnode = new Node;   int val;
                cout<<"\nEnter the Value: ";  cin>>val;
                newnode->setvalue(val);
                current = head;
                while(current->getvalue() != data) {
                    current = current->getnxtNode();
                }
                newnode->setnxtNode(current->getnxtNode());
                current->setnxtNode(newnode);
                size++;  Complete();
            }
            else if(found>1) {
                    int newindex, flag=0; 
                    cout<<"\nEnter the Desired Index: ";  cin>>newindex;
                    int* temp = find(data);
                    int temp_size = findsize(data);
                    for(int i=0;i<temp_size;i++) {
                        if(newindex==temp[i]) {   flag++; }
                    }
                    if(flag == 0) { Error(); }
                    if(flag > 0) {  InsertAfterSpecific(newindex, 0); }
                }  
        }

        void DeletionMenu() {
            int check = Nolist();
            if(check!=0) {
			int choice;
			do{
				IDMenu(choice);
				
					  switch(choice) {
					  	
					  	case 1: Display();  DeleteStart();   Display();  
				                system("cls");   break;
						
					  		case 2: Display();   DeleteEnd();   Display();  
							           system("cls");    break;
						  
					  			case 3:  Display();  
								int location;
    	                        cout<<"\nIndex To Delete: ";  cin>>location; 
								DeleteSpecific(location);   Display();  
								system("cls");   break;

                                    case 4:  Display();  
								    int data;
    	                            cout<<"\nData Of That Node: ";  cin>>data; 
								    DeleteByValue(data);   Display();  
								    system("cls");   break;
								
					  				    case 6: Exit();  exit(0) ; 
					  				
					default:  if(choice != 5) { Error(); } 
					  } 
			    }while(choice != 5);
            }
		}

        void DeleteStart() {
            current = head;
            head = head->getnxtNode();
            free(current);  size--;
            Complete();
        }

        void DeleteEnd() {  
            if(head->getnxtNode() == NULL) { DeleteStart(); }  
            else {
                Node* prev = head;
                current = head->getnxtNode();
                while(current->getnxtNode() != NULL) {
                    current = current->getnxtNode();
                    prev = prev->getnxtNode();
                }
                prev->setnxtNode(NULL);   //current->getnxtNode()
                free(current);  size--;
                Complete();
            }
        }

        void DeleteSpecific(int index) {
            if(index>size || index<=0) {  Error();  }
            else if(index==1) { DeleteStart(); }
            else {
                Node* prev = head;
                current = head->getnxtNode();
                int i=1;
                while(i != index-1) {
                    current = current->getnxtNode();
                    prev = prev->getnxtNode();
                    i++;
                }
                prev->setnxtNode(current->getnxtNode());
                free(current);  size--;
                Complete();
            }
        }

        void DeleteByValue(int val) {
            int found = Search(val);
            if(found==1) {
            if(head->getvalue() == val) { DeleteStart(); }
            else {
                Node* prev = head;
                current = head->getnxtNode();
                while(current->getvalue() != val && current->getnxtNode() != NULL) {
                    current = current->getnxtNode();
                    prev = prev->getnxtNode();
                }
                if(current->getvalue() == val) {
                    prev->setnxtNode(current->getnxtNode());
                    free(current);  size--;  
                    Complete();
                } 
            }
            }
            else if(found>1) {
                    int newindex, flag=0; 
                    cout<<"\nEnter the Desired Index: ";  cin>>newindex;
                    int* temp = find(val);
                    int temp_size = findsize(val);
                    for(int i=0;i<temp_size;i++) {
                        if(newindex==temp[i]) {   flag++; }
                    }
                    if(flag == 0) { Error(); }
                    if(flag > 0) {  DeleteSpecific(newindex); }
                } 
        }

        void UpdateMenu() {
            int check = Nolist();
            if(check!=0) {
			int choice;
			do{
				USCMenu(choice);
				
					  switch(choice) {
					  			case 1:  Display();   
								    int location;
    	                            cout<<"\nIndex for Updation: ";  cin>>location; 
								    UpdateIndex(location);    Display();  
									system("cls");   break;
								    
								    case 2: Display();    UpdateValue();    Display();  
									        system("cls");  break;
					  				
									    case 4: Exit();  exit(0) ;  break;
									    
					default:  if(choice != 3) { Error();  } 
					} 
			}while(choice != 3);
        }
    }

        void UpdateIndex(int index)  {
            if(index>size || index<=0) {  Error();  }
            else {
                current = head;
                int i=1;
                while(i != index) {
                    current = current->getnxtNode();
                    i++;
                }
                int val;
                cout<<"\nEnter the Value: ";  cin>>val;
                current->setvalue(val);
                Complete();
            }
        }

        void UpdateValue()  {
            int data, newdata, index=1;
            cout<<"\nEnter Node Data: ";  cin>>data;
            int found = Search(data);
            if(found==1) {
                current = head;
                while(current->getvalue() != data) {
                current = current->getnxtNode();
                }
                cout<<"\nEnter the Value: ";  cin>>newdata;
                current->setvalue(newdata);
                Complete();
            }
            else if(found>1) {
                int choice;
        	    do{
        		    RepeatitionMenu(choice);
        		    
        		    switch(choice) {
        		      	    case 1:    
							    cout<<"Enter the Value: ";   cin>>newdata;
        		      	        	current = head;
                                    while(current != NULL) {
                                        if(current->getvalue() == data) {
                                            current->setvalue(newdata);
                                            cout<<"\t\t\t\t\t________________________________"<<endl;
		            					    cout<<"\t\t\t\t\t|                              |"<<endl;
										    cout<<"\t\t\t\t\t|   UPDATED VALUE AT NODE# "<<setw(2)<<index<<"  |"<<endl;
										    cout<<"\t\t\t\t\t|______________________________|"<<endl;
                                        }
                                    current = current->getnxtNode();    index++;
                                    }
                                break;
        		      	    
        		      	        case 2: {  
        		      	        	int newindex, flag=0; 
                                    cout<<"\nEnter the Desired Index: ";  cin>>newindex;
                                    int* temp = find(data);
                                    int temp_size = findsize(data);
                                    for(int i=0;i<temp_size;i++) {
                                        if(newindex==temp[i]) {  flag++; }
                                    }
                                    if(flag == 0) { Error(); }
                                    if(flag > 0) {  UpdateIndex(newindex); } 
                                }
                                break; 

                                default:   Error(); 
					}
			    }while(choice > 2);
            }
        }

        void SwapMenu() {
            int check = Nolist();
            if(check!=0) {
			int choice;
			do{
				USCMenu(choice);
				
					  switch(choice) {
					  			case 1:   Display();  	
								    int location1, location2;
    	                            cout<<"\nEnter First Index for Swapping: ";   cin>>location1;
                                    if(location1>size || location1<=0) { Error(); }
                                    else {
								        cout<<"\nEnter Second Index for Swapping: ";  cin>>location2;  
								        SwapIndex(location1, location2);  Display();  
									    system("cls");  
                                        }  break;
								    
								    case 2: Display();   SwapByValue();   Display();  
									        system("cls");   break;
					  				
									    case 4: Exit();  exit(0) ;  break;
									    
					default:  if(choice != 3) { Error();  } 
					} 
			}while(choice != 3);
        }
    }

        void SwapIndex(int i1,int i2) {
            if(i1>size || i1<=0 || i2>size || i2<=0) {  Error();  }   
            else {
                int index1=1, index2=1;
                Node* swap = head;   current = head;
                while(index1 != i1 ) {
                    swap = swap->getnxtNode();
                    index1++;
                }
                while(index2 != i2 ) {
                    current = current->getnxtNode();
                    index2++;
                }
                int temp;
                temp = swap->getvalue();
                swap->setvalue(current->getvalue());
                current->setvalue(temp);
                Complete();
            }
        }

        void SwapByValue() {
            Node* swap = head;
            int value1, flag=0, index1=1, index2=1;
            cout<<"Enter First Value For Swapping: ";   cin>>value1;
            int found = Search(value1);
            if (found==1) {
                while(swap->getvalue() != value1 ) {
                    swap = swap->getnxtNode();
                    index1++;
                }
            }
            else if (found>1) {
                int newindex; 
                cout<<"\nEnter the Desired Index: ";  cin>>newindex;
                int* temp = find(value1);
                int temp_size = findsize(value1);
                for(int i=0;i<temp_size;i++) {
                    if(newindex==temp[i]) {  index1=newindex;  flag++; }
                }
                if(flag == 0) { Error(); } 
            }

            if(flag > 0 || found == 1){
                int value2, flag2=0;
                cout<<"Enter Second Value For Swapping: ";   cin>>value2;
                int found2 = Search(value2);
                if (found2==1) {
                    current = head;
                    while(current->getvalue() != value2 ) {
                        current = current->getnxtNode();
                        index2++;
                    }
                }
                else if (found2>1) {
                    int newindex2; 
                    cout<<"\nEnter the Desired Index: ";  cin>>newindex2;
                    int* temp2 = find(value2);
                    int temp_size2 = findsize(value2);
                    for(int i=0;i<temp_size2;i++) {
                        if(newindex2==temp2[i]) {  index2=newindex2;  flag2++; }
                    }
                    if(flag2 == 0) { Error();  found2=0; }
                }
                if(found>=1 && found2>=1) {
                    SwapIndex(index1,index2);
                }
            }
        }

        void CopyMenu() {
            int check = Nolist();
            if(check!=0) {
			int choice;
			do{
				USCMenu(choice);
				
					  switch(choice) {
					  			case 1:   Display();  	
								    int location, destination;
    	                            cout<<"\nEnter Index to Copy: ";   cin>>location;
                                    if(location>size || location<=0) { Error(); }
                                    else {
								        cout<<"\nEnter Index to Paste: ";  cin>>destination;  
								        CopyIndex(location, destination);  Display();  
									    system("cls");  
                                        }  break;
								    
								    case 2: Display();   CopyByValue();  Display();  
									        system("cls");  break;
					  				
									    case 4: Exit();  exit(0);  break;
									    
					default:  if(choice != 3) { Error();  } 
					} 
				}while(choice != 3);
        	}
    	}

        void CopyIndex(int location,int destination) {
            if(destination>size || destination<=0 || location>size || location<=0) {  Error();  }
            else {
                current = head;   Node* copy = head;
                int index1=1, index2=1; 
                while(index1 != location) {
                    copy = copy->getnxtNode();
                    index1++;
                }
                while(index2 != destination) {
                    current = current->getnxtNode();
                    index2++;
                }
                current->setvalue(copy->getvalue());    
                Complete();
            }
        }

        void CopyByValue() {
            Node* temp = head;
            int copy, index1=1, index2=1;  
    	    cout<<"\nValue to Copy: ";  cin>>copy;
            int found = Search(copy);
            if(found>=1) {
                //temp = head;  
                while(temp->getvalue() != copy) {
                    temp = temp->getnxtNode();
                    index1++;
                }
            int paste;
            cout<<"\nValue to Paste: ";  cin>>paste;
            int found2 = Search(paste);
            if(found2==1) {
                current = head;
                while(current->getvalue() != paste) {
                    current = current->getnxtNode();
                    index2++;
                }
                CopyIndex(index1,index2);
            }
            else if(found2>1) {
                int choice;
        	    do{    
					RepeatitionMenu(choice);
					
        		    switch(choice) {
        		      	    case 1: {
        		      	        	current = head;  int i=1;
                                    while(current != NULL) {
                                        if(current->getvalue() == paste) {
                                            current->setvalue(temp->getvalue());
                                            cout<<"\t\t\t\t\t________________________________"<<endl;
		            					    cout<<"\t\t\t\t\t|                              |"<<endl;
										    cout<<"\t\t\t\t\t|    COPIED VALUE AT NODE# "<<setw(2)<<i<<"  |"<<endl;
										    cout<<"\t\t\t\t\t|______________________________|"<<endl;
                                        }
                                    current = current->getnxtNode();    i++;
                                    }
                                }
                                break;
        		      	    
        		      	        case 2: {  
        		      	        	int newindex, flag=0; 
                                    cout<<"\nEnter the Desired Index: ";  cin>>newindex;
                                    int* temp = find(paste);
                                    int temp_size = findsize(paste);
                                    for(int i=0;i<temp_size;i++) {
                                        if(newindex==temp[i]) { index2=newindex;  flag++; }
                                    }
                                    if(flag == 0) { Error(); }
                                    if(flag > 0) {  CopyIndex(index1,newindex); } 
                                }
                                break; 

                                default:   Error(); 
					}
			    }while(choice > 2);
            }
            }
        }

        int Search(int search) {
            int check = Nolist();
            if(check!=0) {
                current=head;
                int index=1, flag=0;
                while(current != NULL){  //curret->getvalue() == data
                    if(current->getvalue() == search) {
                        cout<<"\t\t\t\t\t________________________________"<<endl;
		       	        cout<<"\t\t\t\t\t|                              |"<<endl;
				        cout<<"\t\t\t\t\t|       FOUND VALUE At #  "<<setw(2)<<index<<"   |"<<endl;
				        cout<<"\t\t\t\t\t|______________________________|"<<endl;   getch();  system("cls"); 
                        flag++;
                    }
                    current = current->getnxtNode();
                    index++;
                }
                if(flag == 0) {  NoRecord();  }
                return flag;
            }
        }

        void Display() {
            current = head;  int index=1;
            cout<<"\t\t\t\t\t    ________________\n"
			      "\t\t\t\t\t    |     HEAD     |\n"
			      "\t\t\t\t\t    |______________|\n"
                  "\t\t\t\t\t            |       \n"
                  "\t\t\t\t\t            V       \n";
            while(current != NULL) {
                cout<<"\t\t\t\t\t__________________________\n";
				cout<<"\t\t\t\t\t|     NODE NO. "<<index<<"   | "<<setw(4)<<current->getvalue()<<"|"<<endl; 
		    	cout<<"\t\t\t\t\t|__________________|_____|\n"
                      "\t\t\t\t\t            |       \n"
                      "\t\t\t\t\t            V       \n";
                current = current->getnxtNode();
                index++;
            }
            cout<<"\t\t\t\t\t    ________________\n"
			      "\t\t\t\t\t    |     NULL     |\n"
			      "\t\t\t\t\t    |______________|\n\n";    getch();
        }

        void Length() {
            cout<<endl<<endl;
			cout<<"\t\t\t\t______________________________________________"<<endl;
			cout<<"\t\t\t\t|_____________________|______________________|"<<endl;
			cout<<"\t\t\t\t|     TOTAL SIZE      |"<<setw (20)<<size<<"  |"<<endl;       
			cout<<"\t\t\t\t|____________________________________________|"<<endl;    getch();   system("cls");
        }

        void ClearList() {
            int check = Nolist();
            if(check!=0) {
            current = head;   Node* next = head;
            while(current != NULL) {
                next = current->getnxtNode();   //next storing current next addrest to delete where current is
                free(current);
                current = next;
                size--;
                }
                head = NULL;    Complete();
            }
        }
};

int SLL::findsize(int data) {
                int temp_size=1;
                current=head;  
                while(current != NULL) {
                    if(current->getvalue() == data) { temp_size++; }
                    current = current->getnxtNode();
                }
                return temp_size;
}

int* SLL::find(int data) {
                int index=1, temp_index=0;
                int  temp_size = findsize(data);
                int* temp = new int[temp_size];
                current=head;
                while(current != NULL){ 
                    if(current->getvalue() == data) { temp[temp_index] = index;  temp_index++; }
                    current = current->getnxtNode();
                    index++;
                }
                return temp;
}

void SLL::RepeatitionMenu(int& choice) {
				cout<<"\n\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
                          "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"  
				    "\n\t\t\t\t\t      ______________________"
				    "\n\t\t\t\t\t     |                      |"
				    "\n\t\t\t\t\t     | 1->   ON ALL         |"
				    "\n\t\t\t\t\t     | 2->  SPECIFIC VALUES |"
				    "\n\t\t\t\t\t     |______________________|"
		            "\n\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
                       "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n"        
		            "\t\t\t\t\t      Choice =      ";    cin>>choice;     cin.clear();   fflush(stdin);
}

void SLL::USCMenu(int& choice) {
	cout<<"\n\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
                  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"  
		        "\n\t\t\t\t\t________________________________"
		        "\n\t\t\t\t\t|                              |"
				"\n\t\t\t\t\t|             Menu             |"
				"\n\t\t\t\t\t|______________________________|"
		        "\n\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
                "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
				"\n\t\t\t\t\t     ______________________"
				"\n\t\t\t\t\t    |                      |"
				"\n\t\t\t\t\t    | 1->  BY LOCATION     |"
				"\n\t\t\t\t\t    | 2->  BY VALUE        |"
				"\n\t\t\t\t\t    | 3->  MAIN MENU       |"
				"\n\t\t\t\t\t    | 4->  EXIT            |"
				"\n\t\t\t\t\t    |______________________|"
		        "\n\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
                "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n"       
		        "\t\t\t\t\t      Choice =      ";    cin>>choice;   cin.clear();   fflush(stdin);   system("cls");
}

void SLL::IDMenu(int& choice) {
	cout<<"\n\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
                "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"  
		        "\n\t\t\t\t\t________________________________"
		        "\n\t\t\t\t\t|                              |"
				"\n\t\t\t\t\t|             Menu             |"
				"\n\t\t\t\t\t|______________________________|"
		        "\n\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
                "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
				"\n\t\t\t\t\t      ______________________"
				"\n\t\t\t\t\t     |                      |"
				"\n\t\t\t\t\t     | 1->  START           |"
				"\n\t\t\t\t\t     | 2->  END             |"
				"\n\t\t\t\t\t     | 3->  BY SPECIFIC     |"
                "\n\t\t\t\t\t     | 4->  BY VALUE        |"
				"\n\t\t\t\t\t     | 5->  MAIN MENU       |"
				"\n\t\t\t\t\t     | 6->  EXIT            |"
				"\n\t\t\t\t\t     |______________________|"
		        "\n\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
                "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n"        
		        "\t\t\t\t\t      Choice =      ";    cin>>choice; cin.clear();   fflush(stdin);  system("cls");
}

void SLL::Error() {
    cout<<"\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
          "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"                             
		  "\n\t\t\t\t\t_____________________________________"
		  "\n\t\t\t\t\t| Error!                            |"
		  "\n\t\t\t\t\t|          INVALID INPUT!           |"
		  "\n\t\t\t\t\t|___________________________________|"
		  "\n\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
          "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";      
		getch();	system("cls");
}

bool SLL::Nolist() {
    if(head==NULL) {
        cout<<"\t\t\t\t\t________________________________"<<endl;
	    cout<<"\t\t\t\t\t|                              |"<<endl;
	    cout<<"\t\t\t\t\t|        LIST IS EMPTY !!!     |"<<endl;
	    cout<<"\t\t\t\t\t|______________________________|"<<endl;
        getch();	system("cls");  return 0;
    }
    else { return 1; }
    
}

void SLL::NoRecord() {
    cout<<"\t\t\t\t\t________________________________"<<endl;
	cout<<"\t\t\t\t\t|                              |"<<endl;
	cout<<"\t\t\t\t\t|      NO RECORD FOUND !!!     |"<<endl;
	cout<<"\t\t\t\t\t|______________________________|"<<endl;
    getch();	system("cls");
}

void SLL::Complete() {
    cout<<"\t\t\t\t\t________________________________"<<endl;
	cout<<"\t\t\t\t\t|                              |"<<endl;
    cout<<"\t\t\t\t\t|     Operation Completed!     |"<<endl;
	cout<<"\t\t\t\t\t|______________________________|"<<endl; 
    getch();
}

void SLL::Exit() {
	cout<<"\t\t\t\t\t________________________________"<<endl;
	cout<<"\t\t\t\t\t|                              |"<<endl;
	cout<<"\t\t\t\t\t|     T H A N K  Y O U !!!     |"<<endl;
	cout<<"\t\t\t\t\t|______________________________|"<<endl;
}

int main() {
    SLL S;  int choice;
    system("COLOR 4E" );
    cout <<  "\n\t                               ||========================||" 
             "\n\t                               ||                        ||" 
             "\n\t                               ||      BSCS - III(C)     ||" 
             "\n\t                      ||------------------------------------------||" 
             "\n\t                      ||   ROLL No: 210920                        ||" 
             "\n\t                      ||  NAME: MUHAMMAD SALMAN SIDDIQUI          ||" 
             "\n\t             ||-------------------------------------------------------------||" 
             "\n\t             ||                                                             ||" 
             "\n\t             ||                  A S S I G N M E N T # 0 2                  ||" 
             "\n\t    ||------------------------------------------------------------------------------||" 
             "\n\t    ||                                                                              ||" 
             "\n\t    ||                                                                              ||" 
             "\n\t    ||                       S I N G L E  L I N K E D  L I S T                      ||" 
             "\n\t    ||                                                                              ||" 
             "\n\t    ||                             O P E R A T I O N S                              ||" 
             "\n\t    ||                                                                              ||" 
             "\n\t    ||                                 S Y S T E M                                  ||" 
             "\n\t    ||                                                                              ||" 
             "\n\t    ||------------------------------------------------------------------------------||" 
             "\n\t             ||                                                            ||" 
             "\n\t             ||   SUBMITTED TO:    Mr. Sagheer Ahmed                       ||" 
             "\n\t             ||------------------------------------------------------------||"
             "\n\t                      ||      C O M P U T E R  S C I E N C E      ||" 
             "\n\t                      ||            D E P A R T M E N T           ||" 
             "\n\t                      ||------------------------------------------||" 
             "\n\t                               ||                        ||" 
             "\n\t                               ||                        ||"
             "\n\t                               ||========================||" ;         getch();   system("cls");  system("COLOR 0F" );
    
    while(1) {
		cout <<"======================================================"              
           "==================================================================\n"
           "\n\n\t\t\t\t\t         M A I N   M E N U    \n\n\n"        
           "=============================================================="
           "==========================================================" 
           "\n     ________________________________  \t________________________________  \t________________________________"
           "\n     |                              |  \t|                              |  \t|                              |"
	       "\n     | 1 ->     CREATE LIST         |  \t| 5 ->     UPDATE MENU         |  \t| 9 ->     LIST LENGTH         |"
		   "\n     |______________________________|  \t|______________________________|  \t|______________________________|"
		   "\n     ________________________________  \t________________________________  \t________________________________"
           "\n     |                              |  \t|                              |  \t|                              |"
	       "\n     | 2 ->   TRAVERSAL MENU        |  \t| 6 ->      SWAP MENU          |  \t| 10 ->    DELETE LIST         |"
		   "\n     |______________________________|  \t|______________________________|  \t|______________________________|"
		   "\n     ________________________________  \t________________________________  \t________________________________"
           "\n     |                              |  \t|                              |  \t|                              |"
	       "\n     | 3 ->     INSERT MENU         |  \t| 7 ->      COPY MENU          |  \t| 11 ->       E X I T          |"
		   "\n     |______________________________|  \t|______________________________|  \t|______________________________|"
		   "\n     ________________________________  \t________________________________ "
           "\n     |                              |  \t|                              | "
	       "\n     | 4 ->    DELETION MENU        |  \t| 8 ->       SEARCH            | "
		   "\n     |______________________________|  \t|______________________________| "
		   "\n\n=============================================================="
           "==========================================================\n"
		      "\n\t\t\t\t\t\t ENTER YOU CHOICE =  ";     cin>>choice;   cin.clear();   fflush(stdin);    system("cls");
		switch(choice) {
			case 1:   int size, val;   
                    cout<<"\n\n       DATA ENTRY         \n";
			        cout<<"______________________________\n";
			        cout<<"\n ENTER NUMBER OF NODES =      ";     cin>>size;
                    cout<<"\n______________________________\n";
                    if(size>0) {
                        for(int i=1;i<=size;i++) {
                            cout<<"\nEnter Value of Node#"<<i<<" : ";  cin>>val;
                            S.Create(val);  }   system("cls"); 
                    }
                    else { S.Error(); }    break;
			 
			 	 case 2: S.Display();  system("cls");  break;
				
					case 3:  S.InsertionMenu();  break;
					
					    case 4:  S.DeletionMenu();    break;
						
						    case 5:  S.UpdateMenu();     break;
					    
					            case 6:  S.SwapMenu();       break;
					            
					                case 7:  S.CopyMenu();      break;
						   
                                        case 8: int search;
                                                cout<<"Searching Value: ";  cin>>search;  
                                                S.Search(search);     break;  
						    	
							                case 9:    S.Length();       break;
							                   
							                    case 10:  S.ClearList();    break;
							                    
							                        case 11:  S.Exit();  exit(0);
							                        
						default:   S.Error();
		}
	}
    return 0;
}
