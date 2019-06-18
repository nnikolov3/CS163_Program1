//Nikolay Nikolov
// CS163 Program 1
// Instructor : Karla Fant 
#include"program1.h" 
using namespace std ;
// assistance_node--------everything related to that node starts here ---------------------------------------------------------------------
assistance_node :: assistance_node() // constructor for the assistance node 
{
	// setting all the variables to NULL or 0 in order to alocate the proper amount of memory 
	hours =NULL ;
	location = NULL;
	rating = 0 ;
	ref =0;
	price = 0 ;
	descrpt = NULL;
	comment = NULL ;
	next = NULL  ;
}

assistance_node ::~ assistance_node()// destructor for the assistance node
{
	// after we have used the variable we delete and set to NULL in order to avoid memory leaks
	if (hours)
		delete [] hours ;
	hours = NULL ;

	if (location )
		delete [] location ;
	location = NULL  ; 

	if ( descrpt )
		delete [] descrpt ; 
	descrpt = NULL  ;

	if (comment) 
		delete [] comment ;
	comment = NULL ; 	
}
int assistance_node :: data ( ) // the display function that will diplay the information stored within 
	// a node
{
	cout <<"\nThe hours are :\n " << hours << "\nThe location is\n " << location << "\nThe description of the help is\n  " << descrpt <<"\nThe comment is\n " << comment <<"\nThe price is\n " << price << "\nThe rating is\n " <<  rating << "\n The reference # is \n "<<ref << " \n End\n"<< endl ;

	return 0 ;
}

//----------everything related with the assistance_node--- ends here ---------------------------------------------------------


//subject_node - nodes for the subjects -----everything related with that node starts here----------------------------------------------

subject_node :: subject_node()// constructor for the subject node 
{ 	name = NULL ; 
	head = NULL ;
	next = NULL ;
}
subject_node :: ~ subject_node () // destructor for the subject node 
{
	remove_all (head) ; // the function remove_all is called 
	if(name)  
		delete [] name ; // delete and set name to NULL to avoid memory leaks
	name = NULL;
}
int subject_node :: remove_all ( assistance_node *& head ) // the function to delete all the nodes 
{ 								// the function is implemented recursively 
	if(!head)
		return 0; 

	remove_all (head -> next); // the function calls itself
	delete head;
	head = NULL; 
	return 0;
}

int subject_node :: create_entry(char * hours ,  char *  location , char *  descrpt ,char *  comment ,int price, int rating ,int ref)
// the function that create a new node for the help entry
{
	assistance_node * temp = head ;
	head = NULL ;
	head = new assistance_node;
	// alocating dynamically space and performing a deep copy 	
	head ->hours = new char [strlen (hours)+1] ;
	strcpy (head -> hours, hours ) ;

	head ->location = new char [strlen(location)+1] ;
	strcpy (head -> location, location) ; 

	head -> descrpt =new char [strlen (descrpt) +1 ] ;
	strcpy (head -> descrpt, descrpt) ;

	head -> comment = new char [strlen (comment) +1 ] ;
	strcpy (head -> comment, comment ) ;

	head ->price = price;
	head ->rating = rating;
	head ->ref =ref ;

	head -> next = temp ;
	return 0 ;		
}
int subject_node :: display_all ()
{
// the function that will implement and traverse through the nodes with help 
	assistance_node  * current = head ; // current is set to head 

	while (current) {
		current ->  data () ;// display the data in the node
		current = current -> next ; 
		return 1 ;
	}
	return 0 ;
}

int subject_node :: display_by_rating()
{
	// the function that will traverse through the assistance nodes and see if there is a rating 3> 
	assistance_node * current = head ; // current
	assistance_node * temp = current ; // temp 

	while  (current ){
		// we will traverse until  we go to the end 
		if (current ->rating > 3)
		{
			temp = current ;
			temp -> data () ;
			return 1; 
		}
		current =current -> next ;
	}
	return 0 ;
}
int subject_node :: edit(char * hours ,  char *  location , char *  descrpt ,char *  comment ,int price, int rating ,int ref)
{
// the function that will impliment the edit after we have located the right node through the reference number we have created 
	assistance_node * current= head ;
	while (current)
	{
		if (current -> ref == ref) // if the reference number matches the input from the user
		{

			// delete whatever is inside the node , get data from the user and the allocate memory and copy everything from the user back
			if(current -> hours)
				delete [] current -> hours;

			if (current -> location)
				delete [] current -> location;

			if (current -> descrpt)
				delete [] current ->descrpt ;

			if (current -> comment )
				delete[] current -> comment ;



			current ->hours = new char [strlen (hours)+1] ;
			strcpy (current -> hours, hours ) ;

			current ->location = new char [strlen(location)+1] ;
			strcpy (current -> location, location) ; 

			current -> descrpt =new char [strlen (descrpt) +1 ] ;
			strcpy (current -> descrpt, descrpt) ;

			current -> comment = new char [strlen (comment) +1 ] ;
			strcpy (current -> comment, comment ) ;

			current ->price = price;
			current ->rating = rating;
			current ->ref =ref ;
		}

		current = current -> next ;
	}
	return 0 ;
}



//---------------everything related related with the nodes that contain the subject ENDS HERE----------------------------------


//---------------everything related with the subject_list class ,which is the ADT for the program--starts here 

subject_list :: subject_list () // constructor for the ADT class 
{
	head = NULL ; // set head to null to avoid memory leaks

}

subject_list :: ~ subject_list () // destructor for the ADT class
{

	delete_all(head);// the delete_ all function is called 
	head = NULL; // set head to NULL to prevent memory leaks and point to garbage
}
int subject_list ::  delete_all (subject_node * & head)// delete all recursive  function 
{
	if (!head) // taking the first case if there is nothing 
		return 0 ; 

	delete_all (head -> next ); // the function calls itself

	delete head ;			// delete 
	head = NULL;			// set to NULL to avoid pointing to garbage
	return 1;
}
int subject_list :: add_assistance (char * name,char*hours, char * location , char * descrpt , char * comment , int price , int rating, int ref)
{
	subject_node * current = head ;// current points to head 
	if (!head)
		return 0;

	while (current){

		if( strcmp(current->name, name)==0){
			// we will traverse until  we go to the end of the entire list or we find a match
			head -> create_entry(hours ,location, descrpt, comment, price, rating,ref);
		}else 
			return 1;

		// if we have a match for the name we can add a node with the entry
		current = current -> next ; // traverse 
	}
	return 0;	
}
int subject_list :: add_subject(char *  name)
	// adding a node to the list with subjects 
{
	subject_node * temp = head; 
	head = NULL;
	head = new subject_node;
	head -> name = new char [strlen(name)+1]; // dynamically allocating memory for data that the node will store
	strcpy (head -> name , name );// hard copy the name of the subject to the node
	head ->next = temp;

	return 1 ;
}
int subject_list :: display_subjects()
{
	subject_node*current = head ;// set current to head
	if (!head) // if the list is empty
		return 0 ;
	while (current) // getting ready to traverse 
	{
		cout <<  current -> name << endl; // display the name of the subject
		current = current -> next; // traverse
	}
	return 1 ;
}
int subject_list :: display (char*name,char*hours,char*location,char*descrpt ,char*comment,int price,int rating, int ref) 
{
	subject_node * current = head ;// current points to head 
	if (! head)
		return 0;

	while (current ){

		if(strcmp(current->name, name)==0)// we will traverse until  we go to the end of the entire list or we find a match		
		{
			cout<< current -> display_all (); 
			return 1;
		}else 
		{

			cout <<"There is no match " << endl ; // if the return value is 0 the function displays that message	
			return 0;

		}
		current = current -> next ; // traverse 
	}
	return 1 ;
}

int subject_list ::display_by_rating(char*name) // the function that will identify the node with the right name 
{
	subject_node * current = head ;
	if (! head )
		return 0;

	while (current )
	{
		if (strcmp(current->name, name)==0){// we will traverse until  we go to the end of the entire list or we find a match
			cout << current -> display_by_rating () ;
			return 1 ;
		}else
		{	cout<<"There is no match . " <<endl ;
			return 0;
		}

		current = current -> next;
	}
	return 1;

}
// the function that will identify connect the ADT with the right node by looking into the names in the subject list
int subject_list :: edit(char* name,char * hours,char*location,char*descrpt, char *comment, int price ,int rate, int ref)
{
	subject_node * current = head ;
	if (!head)
		return 0;
	while (current){ 
		if (strcmp(current->name, name)==0){// we will traverse until  we go to the end of the entire list or we find a match
			current -> edit (hours, location, descrpt ,comment ,price,rate,ref) ;
			return 1 ;
		}else
		{	cout<<"There is no match . " <<endl ;
			return 0;
		}

		current = current -> next;

	}
	return 1;
}



int subject_list :: delete_all_wrapper () // wrapper function to call delete all , since delete all is in private and its recursive 
{
	delete_all (head) ;
}

bool again() // the function again iterates in case the user wants to add another node for the help
	// nothing really special about that function ,just a boolean function 
{
	char response ;	
	cout << "Would you like to add more help information ? For yes press 'y'.  " << endl ; 
	cin >> response ; cin.ignore (100, '\n') ;

	response = tolower(response); 

	if (response == 'y' )
		return true ; 
	else 
		cout << "Thank you! " << endl ;

	return false ;	
}
bool again1() // the function again iterates in case the user wants to add another node for the help
	// nothing really special about that function ,just a boolean function 
{
	char response ;	
	cout << "Would you like to add another class? For yes press 'y'.  " << endl ; 
	cin >> response ; cin.ignore (100, '\n') ;

	response = tolower(response); 

	if (response == 'y' ){
		cout<< "OK ! :)" << endl; 
		return true ; 
	}
	else 
		cout << "Thank you " << endl ;

	return false ;	

}
bool again2() // Asking the user to repeat an action
{
	char response ;	
	cout << "Would you like to do that again? For yes press 'y'.  " << endl ; 
	cin >> response ; cin.ignore (100, '\n') ;

	response = tolower(response); 

	if (response == 'y' ){
		cout<< "OK ! :)" << endl; 
		return true ; 
	}
	else 
		cout << "Thank you " << endl ;

	return false ;	
}
int menu(int & var1)// The menu function that will trigger the switch statement
{

	cout << "Hi ! Here is what you can do !" << endl ;
	cout << "For new entries please follow step 1 and 2. Thank you! " << endl;
	cout << "Press (1) to add a subject " << endl ;
	cout << "Press (2) to add a new way to get help for a subject " << endl ;
	cout << "Press (3) to display ALL" << endl;
	cout << "Press (4) to display all with rating > 3" << endl;
	cout << "Press (5) to remove everything " << endl ;
	cout << "Press (6) to edit a way to get help for a particular subject" << endl ;
	cout <<" Press (7) to go back, if you are in the main menu that will exit you from the program " << endl ;	
	cin >> var1 ; cin.ignore (100 ,'\n');

	return 0;
}
