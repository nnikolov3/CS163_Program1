//Nikolay Nikolov
// CS163 Program 1
// Instructor : Karla Fant 
#include"program1.h"
#include <iostream>
using namespace std ;


const int SIZE = 100;
int main() {// Here starts main 

	//The main has been created primerily with the notion that it will be easy to test the ADT , rather 
	//providing an awesome user experience. Practiality came first .  


	subject_list subjects; // Calling the ADT
	char name [SIZE] ;
	char hours[SIZE];
	char descrpt[500];
	char comment[500];
	char location[SIZE];
	int price;
	int rating ;
	int ref ;
	int var ;
	int var1 ;
	char response [SIZE] ;
	char ans;	
	bool done = false;

	while(!done) // while to bring the user to the main menu 
	{

		menu (var1); // main menu 
		switch (var1){
			case 1:	// add subject -- initially the list is empty
				if (subjects.display_subjects () == 0)
					cout<< " The list is empty " << endl;
				cout<<"Let's add a class ! " << endl;

				do{	cout << "Please enter the name of the class you want to add ." << endl ;
					cin.get( name ,SIZE , '\n'); cin.ignore(SIZE,'\n') ;
					subjects.add_subject(name);
				}while (again1());

				cout <<"Your classes  are : " << endl ;
				subjects.display_subjects() ;


				break ;
			case 2: // add information for a particular class, after the information is gathered is assigned to a class
				do{
					cout << "For which class do you want to save the help information? " << endl ;
					cin.get( name , SIZE,'\n') ;cin.ignore(SIZE, '\n') ;
					char * search_name = new char[strlen(name) + 1];
					strcpy(search_name, name);

					cout << "Let's add some information about the class you want to add the help " << endl ;

					cout << "Please enter the hours of availability for the help in chars , ex. two to five . " << endl;
					cin.get( hours, 500, '\n') ; cin.ignore(500,'\n') ;

					cout << "Please enter the location  in 500 chars ,ex. FAB 88. " << endl;
					cin.get( location, 500, '\n') ; cin.ignore(500,'\n') ;

					cout << "Please enter the description for the type of assistance in 500 chars . " << endl;
					cin.get( descrpt, 500, '\n') ; cin.ignore(500,'\n') ;

					cout << "Please enter a comment  of help  you want to add  , ex. too crowded, easy access ect. . " << endl ;
					cin.get (comment , 501, '\n') ; cin.ignore(501, '\n') ;

					cout << "Please enter AN INTEGER for the  price of the service , ex.25." << endl ;
					cin >> price ;
					cin.ignore() ;

					cout << "Please rate the assistance from 0-10 , with zero not helpful ." << endl; 
					cin >> rating;
					cin.ignore();

					cout << "Please create a reference number for the assistance, ex. 1 ." << endl;
					cout << "Providing the reference number and the name of the class you can edit particular help later " << endl ; 
					cin >> ref;
					cin.ignore();

					cout<< "Now lets save everything" << endl;
					subjects.add_assistance (name , hours, location ,descrpt , comment ,price, rating,ref );

					if(search_name){
						delete [] search_name;
						search_name = NULL;
					}
				}while (again()) ;
				break ;
			case 3: // display ALL information for a particular class that you have to provide the name for
				cout <<"For which class do you want to display ALL help information ? " << endl ;
				do{
					do{
						cout<< "Please enter the name " << endl ;
						cin.get( name , SIZE,'\n') ;cin.ignore(SIZE, '\n') ;
						char * search_name = new char[strlen(name) + 1];
						strcpy(search_name, name);
						//	var = subjects.display(name, hours , location, descrpt,comment, price, rating,ref);
						subjects.display(name, hours , location, descrpt,comment, price, rating,ref);
						if (search_name){
							delete [] search_name ;
							search_name = NULL ;
						}
					}while (again2());
				}while (var = 0) ;
				break ;
			case 4:// diplay the help that is rated with 3+

				cout << "For which class would you like to search for help rated  3+ ? ."  <<endl;
				do{
					do{
						cout << "Please enter the name: " << endl ;
						cin.get( name , SIZE,'\n') ;cin.ignore(SIZE, '\n') ;
						char * search_name = new char[strlen(name) + 1];
						strcpy(search_name, name);
						//	var = subjects.display_by_rating (name) ;
						subjects.display_by_rating (name) ;
						if(search_name){
							delete [] search_name;	
							search_name = NULL;
						}
					}while (again2());
				}while (var = 0) ;
				break;
			case 5:// delete everything 

				cout << "Would you like to delete everything in your list ?" << endl;
				cin >> ans ; cin.ignore(100,'\n');
				ans = tolower(ans);
				if (ans == 'y')
					subjects.delete_all_wrapper();

			case 6: // edit assistance , the user has provide reference number and name 
		 // the drawback of the program is that it does not look for duplicate ref # 
		// theoretically the user can add multiple identicall ref # and edit each other
				{
					cout <<"For which class you would like to edit the information?"<< endl ;

					cout<< "Please enter the name " << endl ;
					cin.get( name , SIZE,'\n') ;cin.ignore(SIZE, '\n') ;
					char * search_name = new char[strlen(name) + 1];
					cout <<"Please provide a reference # " << endl; 
					cout <<" If you don't remeber it , press 0, that will take you to the main menu " << endl ;
					cout <<" There you can look up the information for the class and see the reference you entered " << endl ;
					cin >> ref ;cin.ignore (100, '\n') ;
					//var = subjects.edit(name, hours , location, descrpt,comment, price, rating,ref);
					cout << "Please enter the hours of availability for the help in chars , ex. two to five . " << endl;
					cin.get( hours, 500, '\n') ; cin.ignore(500,'\n') ;

					cout << "Please enter the location  in 500 chars ,ex. FAB 88. " << endl;
					cin.get( location, 500, '\n') ; cin.ignore(500,'\n') ;

					cout << "Please enter the description for the type of assistance in 500 chars . " << endl;
					cin.get( descrpt, 500, '\n') ; cin.ignore(500,'\n') ;

					cout << "Please enter a comment  of help  you want to add  , ex. too crowded, easy access ect. . " << endl ;
					cin.get (comment , 501, '\n') ; cin.ignore(501, '\n') ;

					cout << "Please enter AN INTEGER for the  price of the service , ex.25." << endl ;
					cin >> price ;
					cin.ignore() ;

					cout << "Please rate the assistance from 0-10 , with zero not helpful ." << endl; 
					cin >> rating;
					cin.ignore();

					cout << "Please create a reference number for the assistance, ex. 1 ." << endl;
					cout << "Providing the reference number and the name of the class you can edit particular help later " << endl ; 
					cin >> ref;
					cin.ignore();

					subjects.edit(name, hours , location, descrpt,comment, price, rating,ref) ;
					//here goes the function
					if (search_name){
						delete [] search_name ;
						search_name = NULL ;
					}
					break;
				}
			case 7:// exit the program
				{
					cout<< "Have a wonderful day !" << endl ;
					done = true;
					break;
				}
			default:
				break;
		}
	}
	return 0 ;
}
