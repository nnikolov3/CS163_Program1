#include<iostream>
#include<cctype>
#include<cstring> 
#include<fstream> 

//Nikolay Nikolov , CS 163 , Program # 1 , October 8 , 2016
/* Purpose of the Program 1: 

   The purpose of the program is to provide help for a student to find  assstance with a subject in school. The user will be able to search for a subject that she is interested in ,and  the program will find that subject and display all the available sources for assistance. The program will have the option to add more subject(s) or sources for assistance, it will be able to display all, display only the top rated , and delete subjects and sources that are irrelevant.    The program uses ADT and Data Structures . 


 */

using namespace std ; 


struct  assistance_node // The node that will store the variables for the help 
{
	assistance_node () ; // constructor 
	~assistance_node () ; // destructor
	int data ( ) ; // The function to display the content inside the node
	// Setting up the veriables that will live within the  node  and using '*' to  connect the variables within the node 
	//with the node for the subject
	char * hours ; 
	char* location ;
	int rating ;
	int ref ;
	int  price ;
	char *descrpt;
	char * comment ;
	assistance_node * next ; // setting up the pointer to connect the assistance nodes

};

struct  subject_node // The node that will store the name of the subject and the pointer to the head for the assistance_node
{
	subject_node(); // constructor
	~subject_node();// destructor	
	int create_entry(char*hours , char * location , char * descrpt , char * comment , int price , int rating,int ref) ;
	//creates a single entry  for the assistance node 
	int display_all();
	int display_by_rating() ;
	int edit(char * hours ,  char *  location , char *  descrpt ,char *  comment ,int price, int rating ,int ref);
	int remove_all (assistance_node *& head ); 
	char * name ;
	subject_node * next ;	// The pointer to the next node
	assistance_node * head ; // The pointer to the head node for the assistance node
} ;	

class subject_list // ADT class , main has access only to this class 
{
	public:
		subject_list();
		~subject_list();
		int add_assistance (char * name,char*hours, char * location , char * descrpt , char * comment , int price , int rating,int ref);
		int display_by_rating(char*name);
		int display_subjects() ;
		int display   (char * name,char*hours, char * location , char * descrpt , char * comment , int price , int rating,int ref);
		int add_subject (char * name);
		int delete_all_wrapper ();
		int edit (char * name,char*hours, char * location , char * descrpt , char * comment , int price , int rating,int ref); ;
	private:

		int delete_all (subject_node *& head ); 
		subject_node * head ;
} ;
bool again1();
bool again2() ;
bool again() ; // function to iterate the entry of data within the menu
int menu(int & var1);
