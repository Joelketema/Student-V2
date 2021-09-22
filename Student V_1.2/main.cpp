#include <iostream>
#include <string.h>
#include<windows.h>   //using STL's and other header files
#include<iomanip>
#include<fstream>
#include<stdio.h>
#include<cstdio>


using namespace std;

/*declaring structures here*/

//course structure

struct course
{
    int c_id;
	string course_name;
    string instructor_name;
    int credit_hour ;
    float assesment , finalResult;
    char grade;
    string passorfail;
}c;

//student structure

struct student
{
	string studentname;
	int id_no;
    int rankk;
	char sex ;
	string gpa;
	int course_number;
	course c[100];
	char section;
	int student_amount;

}s; // struct variable

struct admin{
	string username;
	string password;
}a;
/*Functions declaration*/

/******MENU FUNCTIONS******/
char masterMenu();
void userchoice();
char adminLogin();
char functionMenu();
char studentMenu(int*);

/******OPERATION FUNCTIONS******/
void getinfo();
int display();
int changeAdminInfo();

/*****STUDENT result functions*****/
string passorfail(char*);
string gpa(char*);
char calcgrade(float*, float*);
void welcomeScreen();
template <class T>
T rankk(T*);


/*****OPERATION STUDENT FUNCTIONS*****/
int currentSemester(int*);
int status(int*);
int nextSem(int*);
int contact(int*);
void choice();
/***Extra screen functions***/
void exiting();
void aboutUs();
void validate(int);

/*file functions*/
int createStudent();
int searchStudent(int*);
int displayAll();
int Delete(int*);
int Modify(int*);
int deleteall();

/***gloabl variable used for controlling  welcome screen***/
int countt = 1;

/*main function*/

int main()
{
    system("COLOR 3F");
    if(countt == 1)
    {
        welcomeScreen();
    }
	userchoice();
	return 0;
}

/******DEFINING THE FUNCTIONS******/

/**master Menu and Other Menu Functions**/

void userchoice()
{
	system("CLS");

    again: // for goto

    int Choice2 =  masterMenu();
    system("CLS");
    switch(Choice2)
    {
    case 1:
        {
            system("CLS");
            int success = adminLogin();
            if(success == 1)
            {
                system("CLS");
                system("COLOR 3F");
                //getting instructor name

                cout << "\t\t\t" <<char(218);      for(int i=0; i<30; i++){cout << char(196);}      cout << char(191) << endl;
                cout << "\t\t\t"<< "   Admin Name: "; cin.ignore();getline(cin,c.instructor_name);
                system("CLS");
                cout<<"\n\t\t\t WELCOME " << c.instructor_name <<endl;
                cout<<endl;
                cout<<"\n\t\t->"; system("PAUSE");
                system("CLS");

                redo: // for the lable of goto

                int done = functionMenu();

                //getting information//
                if(done == 1)
                {
                    //local vairables
                    system("CLS");
                    int hold = createStudent();

                    if(hold == 1)
                    {
                        goto redo;
                    }

                }
                 //display students
                else if(done == 2)
                {
                    system("CLS");
					int hold = display();
					if(hold== 1)
                   	{
						 goto redo;
					 }
                }
                //search student
                else if(done == 3)
                {
                    system("CLS");
                    int id;
                    cout<<"\t->Enter Student ID: ";
                    cin>>id;

                    int hold = searchStudent(&id);

                    if(hold == 1)
                    {
                        goto redo;
                    }
                }
                //Delete student
                else if(done == 4)
                {
                    system("CLS");
                    int id;
                    cout<<"\t->Enter Student ID: ";
                    cin>>id;

                    int hold = Delete(&id);
                    cout<<"\n\n\t\t-> ";system("PAUSE");
                    if(hold == 1)
                    {
                        system("CLS");
                        goto redo;
                    }
                }
                //Delete ALL students
                else if(done == 5)
                {
                    system("CLS");
                    int hold = deleteall();
                    cout<<"\n\n\t\t-> ";system("PAUSE");
                    if(hold == 1)
                    {
                        system("CLS");
                        goto redo;
                    }
                }
                //modify student
                else if(done == 6)
                {
                   system("CLS");
                   int id;
                   cout<<"\t->Enter Student ID: ";
                   cin>>id;

                   int hold = Modify(&id);
                   cout<<"\n\n\t\t-> ";system("PAUSE");
                   if(hold == 1)
                   {
                     system("CLS");
                     goto redo;}
                }

                //main menu
                else if(done == 7)
                {
                    system("CLS");
                    goto again;

                }
				//changing info

				else if(done == 9)
                {
                    int hold = changeAdminInfo();
                    if(hold == 1)
                   {
                     system("CLS");
                     goto redo;}

                }
                //neither
                else
                {
                    exiting();
                }



    //end of main if statement
        }
    }
    //end of case 1

            break;
    case 2:
        {
        system("CLS");
        int idNew;
        cout << "\t\t\t" <<char(218);      for(int i=0; i<30; i++){cout << char(196);}      cout << char(191) << endl;

        cout << "\t\t\t"<< "   Enter your ID: "; cin>>idNew;

        redo2:

        int done2 = studentMenu(&idNew);

        //student conditions from the menu

        //display his/her information
        if(done2 == 1)
        {
            system("CLS");
            int hold = status(&idNew);

            if(hold == 1)
            {
              goto redo2;
            }
        }
        //display current semester grade
        else if(done2 == 2)
        {
            system("CLS");
            int hold = currentSemester(&idNew);

            if(hold == 1)
            {
               goto redo2;
            }
        }

       else if(done2 == 3)
        {
            system("CLS");
            int hold = nextSem(&idNew);

            if(hold == 1)
            {
              goto redo2;
            }
        }

        //Contact teacher
        else if(done2 == 4)
        {
            system("CLS");
            int hold = contact(&idNew);

            if(hold == 1)
            {
              goto redo2;
            }
    	}
    	//neither
        else if(done2 == 5)
            {
                system("CLS");
                countt+=1;
                main();
            }

            else if(done2 == 6)
            {
                exiting();
            }

            else if(done2 == 0)
            {
                cout<<"\t\t\n\n -> NO SUCH STUDENT EXISTS IN DATABASE....\n\n";
                cout<<"\n\t\t->";system("pause");
                system("CLS");
                countt+=1;//counting so it doesn't load the welcome animation everytime we go to menu
                main();
            }
}
	break;

    case 3:
        {
           aboutUs();
           cout<<"\t\t\t->";system("pause");
           system("CLS");
           countt+=1;
           main();
        }
        break;
    case 4:
        {
            exiting();// calling the exiting function when logging out

        }
//end of switch

}

}
char masterMenu()
{
    int choice;//variable to store the choice
    system("COLOR 3F");
    //welcome sign
    cout<<endl;

    cout <<"\t\t\t\t       MAIN MENU \n\n";
    //one box
    cout << "\t\t\t\t\t" <<char(218);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(191) << endl;
    cout << "\t\t\t\t\t" <<char(179) << " 1.Login as Admin    " << char(179) << endl;
    cout << "\t\t\t\t\t" <<char(192);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(217) << endl;
    cout<<endl;
    cout<<endl;
    //one box
    cout << "\t\t\t\t" << char(218);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(191) << endl;
    cout << "\t\t\t\t" << char(179) << " 2.Login as Student  " << char(179) << endl;
    cout << "\t\t\t\t" << char(192);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(217) << endl;


    //one box
    cout<<endl;
    cout<<endl;
    cout << "\t\t\t\t\t" << char(218);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(191) << endl;
    cout << "\t\t\t\t\t" << char(179) << "      3.About US     " << char(179) << endl;
    cout << "\t\t\t\t\t" << char(192);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(217) << endl;
    cout<<endl;
    cout<<endl;
    cout << "\t\t\t\t\t\t" << char(218);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(191) << endl;
    cout << "\t\t\t\t\t\t" << char(179) << "      4.To Exit      " << char(179) << endl;
    cout << "\t\t\t\t\t\t" << char(192);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(217) << endl;
    cout<<endl;
    cout<<endl;
    cout<<"\n\t\t\t\t->Input Here: " ;cin>>choice;

    countt+=1; //counting so it doesn't load the welcome animation everytime we go to menu
    return choice;

}
char adminLogin()
{
    ifstream iafile("adminInfo.txt");
	bool success = false;
    system("color 9F");

    string User;
    string Pass;

    cout<<endl;
	cout << "\t\t" << char(218);      for(int i=0; i<39; i++){cout << char(196);}      cout << char(191) << endl;
    cout << "\t\t" << char(179) << " \t        ADMIN LOGIN PAGE        " << char(179) << endl;
    cout << "\t\t" << char(179) << "                     \t\t\t" << char(179) << endl;
    cout << "\t\t" << char(179) << "  Enter UserName:  "; cin>> User; cout<<"\t\t"<< char(179);
    cout<<"\t\t\t\t\t"<< char(179) << endl;
    cout << "\t\t" << char(179) << "  PASSWORD: "; cin>>Pass; cout << "\t\t" << char(179);
    cout<<"\t\t\t\t\t"<< char(179) << endl;
    cout << "\t\t" << char(179) << "                 \t\t\t" << char(179) << endl;
    cout << "\t\t" << char(192);      for(int i=0; i<39; i++){cout << char(196);}      cout << char(217) << endl;

    //if statement to check
	while(getline(iafile,a.username) && getline(iafile, a.password))
	{
		if(a.username == User && a.password == Pass)
   		 {
   		 	 success = true;
      		 return 1;// for sucess
   		 }
	}

    if(success == false)
    {

        cout <<"\t\t->LOGIN FAILED\n\n";
        cout<<"\t\t";system("pause");
        system("CLS");
        countt+=1; //counting so it doesn't load the welcome animation everytime we go to menu
        main(); // calling back to the main function
    }
	iafile.close();
}

/**Admin Function Menu**/

char functionMenu()
{
    int choice;
    system("COLOR 3F");
    cout << "\t"<< char(201);      for(int i=0; i<60; i++){cout << char(205);}      cout << char(187) << endl;
	cout << "\t"<< char(186) << "                       \t\t\t\t     " << char(186) << endl;
	cout << "\t"<< char(186) << " \t\t Functions menu                     \t     " << char(186) << endl;
	cout << "\t"<< char(186) << " \t\t\t\t\t\t\t     " << char(186) << endl;
	cout << "\t"<< char(186) << "   \t\t 1.To Insert  Record              \t     " << char(186) << endl;
	cout << "\t"<< char(186) << "   \t\t 2.To Display Record               \t     " << char(186) << endl;
	cout << "\t"<< char(186) << "   \t\t 3.To Search  Record           \t             " << char(186) << endl;
	cout << "\t"<< char(186) << "   \t\t 4.To Delete  Record            \t     " << char(186) << endl;
	cout << "\t"<< char(186) << "   \t\t 5.To Delete ALL Records        \t     " << char(186) << endl;
	cout << "\t"<< char(186) << "   \t\t 6.To Modify  Record            \t     " << char(186) << endl;
	cout << "\t"<< char(186) << "   \t\t 7.MAIN MENU            \t\t     " << char(186) << endl;
	cout << "\t"<< char(186) << "   \t\t 8.To EXIT            \t\t\t     " << char(186) << endl;
	cout << "\t"<< char(186) << "   \t\t 9.To Change login information \t             " << char(186) << endl;
	cout << "\t"<< char(186) << "                    \t\t\t\t\t     " << char(186)<<endl;
	cout << "\t"<< "   \t\t\t ->Input Here: ";cin>>choice;
    //validate(choice);

	return choice;

}

/**student menu**/

char studentMenu(int* idnumber)
{
    ifstream ifile("student.txt");
    system("CLS");

    bool success = false;
    while( ifile >> s.id_no && getline(ifile, s.studentname) && ifile >> s.section && ifile >> s.sex && ifile >> s.course_number && ifile >> s.gpa && ifile >> s.rankk)
    {
        if(s.id_no == *idnumber)
    {
        int choice;
        cout << "\t" << char(201);      for(int i=0; i<60; i++){cout << char(205);}      cout << char(187) << endl;
        cout << "\t"<< char(186) << "                       \t\t\t\t     " << char(186) << endl;
        cout << "\t"<< char(186) << " \t\t FUNCTION MENU                    \t     " << char(186) << endl;
        cout << "\t"<< char(186) << " \t\t\t\t\t\t\t     " << char(186) << endl;
        cout << "\t"<< char(186) << "   \t\t 1.To Display your status                    " << char(186) << endl;
        cout << "\t"<< char(186) << "   \t\t 2.Current Semester Grade                    " << char(186) << endl;
        cout << "\t"<< char(186) << "   \t\t 3.Next Semester Courses                     " << char(186) << endl;
        cout << "\t"<< char(186) << "   \t\t 4.Contact your teacher                      " << char(186) << endl;
        cout << "\t"<< char(186) << "   \t\t 5.MAIN MENU            \t\t     " << char(186) << endl;
        cout << "\t"<< char(186) << "   \t\t 6.TO EXIT           \t\t\t     " << char(186) << endl;
        cout << "\t"<< char(186) << "                    \t\t\t\t\t     " << char(186) << endl;
        cout << "\t"<< char(186) << "   \t\t\t ->Input Here: ";cin>>choice;


        success = true;
        return choice;
    }

    }
    if (success == false)  // to know if the login was successfull or not
    {
        cout<< "  \n\n\t\t\t ->NO SUCH STUDENT EXISTS IN DATABASE\n";
        cout<<"\n\t\t";system("Pause");
        system("CLS");
        countt++;
        main();
        return 0;

    }
    ifile.close();

}

/******Get info function******/

void getinfo()
{
    system("CLS");
    system("COLOR 3E");
	int a =0;
    cout << "\t\t" << char(218);      for(int i=0; i<39; i++){cout << char(196);}      cout << char(191) << endl;
    cout << "\t\t" << char(179) << " \t        WELCOME                 " << char(179) << endl;
    cout << "\t\t" << char(179) << "                      \t\t\t" << char(179) << endl;
    cout << "\t\t" << char(218);      for(int x=0; x<39; x++){cout << char(196);}      cout << char(191) << endl;
    cout << "\t\t" << char(179) << " \tSTUDENT: " << a+1 << "\t\t        "<< char(179) ; cout<<endl;
    cout << "\t\t" << char(192);      for(int i=0; i<39; i++){cout << char(196);}      cout << char(217) << endl;
    cout<<endl;
    cout << "\t\t"<< "  Enter Student ID:  ";cin>>s.id_no;
    cout<<endl;
    cout << "\t\t"  << "  Enter the student name: ";cin.ignore(); getline(cin,s.studentname);
    cout<<"\t\t\t" << endl;
    cout << "\t\t" << "  Enter Gender of student (M/F): ";cin>>s.sex;
    cout<<"\t\t\t" << endl;
    cout << "\t\t" << "  Enter SECTION: ";cin>>s.section;
    cout<<"\t\t\t" << endl;
    cout << "\t\t" << "  Enter Number of Courses: ";cin>>s.course_number;
    cout<<"\t\t\t" << endl;

        for(int j=0;j<s.course_number; j++ )
        {
            system("CLS");
            cout << "\t\t" << char(218);      for(int x=0; x<39; x++){cout << char(196);}      cout << char(191) << endl;
            cout << "\t\t" << " \tCOURSE: " << j+1 << "\t\t        ";cout<<endl;
            cout << "\t\t" << char(192);      for(int x=0; x<39; x++){cout << char(196);}      cout << char(217) << endl;
            cout << "\t\t" <<"  Enter Course Name:  ";cin.ignore(); getline(cin,s.c[j].course_name);
            cout<<"\t\t\t"<< endl;
            cout << "\t\t" << "  Enter credit Hour: ";cin>>s.c[j].credit_hour;
            cout<<"\t\t\t" << endl;
            cout << "\t\t" <<"  Enter the assessment result: ";cin>> s.c[j].assesment; cout<<endl;
            cout << "\t\t" << "  Enter the Final Result: ";cin>>s.c[j].finalResult;
            cout<<"\t\t\t" << endl;
            system("CLS");
            s.c[j].grade = calcgrade(&s.c[j].assesment, &s.c[j].finalResult); //Grade
            s.c[j].passorfail = passorfail(&s.c[j].grade); //passorfail
            s.rankk = rankk(&s.c[j].grade); //rank of student
            s.gpa = gpa(&s.c[j].grade); //actual gpa

        }
        a++;

}

/****calculate grade*****/

char calcgrade(float* first, float* second)
{
    int total = *first  + *second;



    if( total>=85 && total <=100)
    {
        return 'A';
    }
    else if( total<70 && total >60)
    {
        return 'B';
    }

    else if( total <=50 && total >=40)
    {
        return 'C';
    }

    else{

        return 'F';
    }
}
/**Calculate rank based on a grade****/
template<class T>
T rankk(T *grade)
{
    if(*grade == 'A')
        return 1;
    else if(*grade == 'B')
        return 2;
    else if(*grade == 'C')
        return 3;
    else if(*grade =='D')
        return 4;
    else
    {
        return 5;
    }

}
/**pass or fail**/

string passorfail(char *a)
{

    if(*a == 'B' || *a =='A')
    {
        return "PASS";
    }

    else if( *a=='C' || *a=='D')
    {
        return "WARN";
    }

        else if( *a=='F')
    {
        return "DISMISS";
    }
}


string gpa(char *grade)
{
    if(*grade == 'A')
        return "4";
    else if(*grade =='B')
        return "3";
    else if(*grade == 'C')
        return "2";
    else if (*grade == 'D')
        return "1";
    else if(*grade == 'F')
        return "NULL";

}
/***create the file***/

int createStudent()
{
    int pick;
    do{
	ofstream ofile("student.txt", ios::app);
	ofstream cfile("courses.txt", ios::app);
	getinfo();
	ofile << s.id_no;
	ofile << s.studentname <<endl;
	ofile << s.section << " "<< s.sex << " " << s.course_number << endl;
	ofile << s.gpa <<" "<< s.rankk << endl;

	for(int i = 0; i < s.course_number ;i++)
    {
        cfile << s.id_no;
        cfile << s.c[i].course_name << endl;
        cfile << s.c[i].credit_hour << endl;
        cfile << s.c[i].grade << " " << s.c[i].passorfail << endl;
    }


    cout << "\n\t\t->Add more students? (1-for yes / 0- for No) : ";
    cin>>pick;
    system("CLS");
    ofile.close();
    }
    while(pick == 1);

    return 1;
}

/*** display students***/

int display()
{
	ifstream ifile("student.txt");
	bool counter = false;
 	system("CLS");

	cout<<"\t" << char(201);      for(int x=0; x<70; x++){cout << char(205);}      cout << char(187) << endl;
    cout<<"\t" << "  ID "<< "\t" <<" Student Name" <<"\t   "<< "   Cumulative Grade" <<"\t "  << " RANK "<<"     " <<" SECTION " << endl;
    cout << "\n\t" << char(200);      for(int x=0; x<70; x++){cout << char(205);}      cout << char(188) << endl;

	while( ifile >> s.id_no && getline(ifile, s.studentname) && ifile >> s.section && ifile >> s.sex && ifile >> s.course_number && ifile >> s.gpa && ifile >> s.rankk)
	{
		 cout <<"\t" << setw(5)<<s.id_no<<"\t " << setw(15)<<s.studentname <<"             "<< setw(3)<<s.gpa <<"       " << setw(5)<<" " <<s.rankk <<setw(2)<<"          " << s.section<<"   " << endl;
		 counter = true;
	}

    if(counter == false)
    {
        cout<<"\n\t\t-> NO STUDENTS IN DATABASE ";
    }
    ifile.close();
    cout<<endl;
    cout<<"\n\t\t->";system("PAUSE");
	system("CLS");
	return 1;

}
/**Search student that takes id number as a parameter and returns after completion**/

int searchStudent(int *idNew)
{
    ifstream ifile("student.txt");
    system("CLS");
    bool success = false;

    while( ifile >> s.id_no && getline(ifile, s.studentname) && ifile >> s.section && ifile >> s.sex && ifile >> s.course_number && ifile >> s.gpa && ifile >> s.rankk)
    {
    if(s.id_no == *idNew)
     {

    int choice;
    cout << "\t" << char(201);      for(int x=0; x<60; x++){cout << char(205);}      cout << char(187) << endl;
	cout << "\t"<< char(186) << "                       \t\t\t\t     " << char(186) << endl;
	cout << "\t"<< char(186) << " \t\t FUNCTION MENU                    \t     " << char(186) << endl;
	cout << "\t"<< char(186) << " \t\t\t\t\t\t\t     " << char(186) << endl;
	cout << "\t"<< char(186) << "   \t\t 1.To Display Current Status                 " << char(186) << endl;
	cout << "\t"<< char(186) << "   \t\t 2.Overall Information                       " << char(186) << endl;
    cout<<endl;
	cout << "\t" << "   \t\t\t ->Input Here: ";cin>>choice;

	if(choice == 1)
    {
        currentSemester(idNew);
        return 1;
    }

    else if(choice == 2 )
    {
        status(idNew);
        return 1;
    }

    success = true;

    }

}

    if(success == false)
    {
        cout<<"\t\t\n\n -> NO SUCH STUDENT EXISTS IN DATABASE....\n\n";
        cout<<"\t\t->";system("pause");
        system("CLS");
        ifile.close();
        return 1;
    }
	ifile.close();
}
/***delete student from file**/

int Delete(int *idnumber)
{
	int counterr = 0;
    ofstream ofile("temp.txt", ios::app);
    ifstream ifile("student.txt");
    ifstream cfile("courses.txt");
    ofstream tcfile("tempc.txt", ios::app);

    while(ifile >> s.id_no && getline(ifile, s.studentname) && ifile >> s.section && ifile >> s.sex && ifile >> s.course_number && ifile >> s.gpa && ifile >> s.rankk)
    {

     if(s.id_no!=*idnumber)
     {
        ofile << s.id_no;
        ofile << s.studentname <<endl;
        ofile << s.section <<" " << s.sex <<" "<< s.course_number << endl;
        ofile << s.gpa <<" "<< s.rankk << endl;
     }
     counterr++;

    }

    while(cfile>>c.c_id && getline(cfile, c.course_name) && cfile >> c.credit_hour && cfile >> c.grade && cfile >> c.passorfail)
    {
        if(c.c_id!=*idnumber)
        {
         for(int i = 0; i < s.course_number ;i++)
        {
            tcfile << c.c_id;
            tcfile << c.course_name << endl;
            tcfile << c.credit_hour << endl;
            tcfile << c.grade <<c.passorfail << endl;
        }

     }
     counterr++;
    }

    cfile.close();
    tcfile.close();
    ifile.close();
    ofile.close();


    remove("student.txt");
    remove("courses.txt");

    rename("temp.txt", "student.txt");
    rename("tempc.txt", "courses.txt");

    if(counterr == 0)
    {
    	cout<<"\n\t->NO STUDENT EXISTS\n";
	}
	else
	{
		cout<<"\n\t->SUCCESSFULLY DELETED\n";
	}

    return 1;

}

/** modify student***/

int Modify(int *idNew)
{
    ofstream Mfile("Memp.txt", ios::app);
	ifstream Sfile("student.txt");
	ifstream cfile("courses.txt");
    ofstream MCfile("Cemp.txt", ios::app);

   bool success= false;
   while(cfile>>c.c_id && getline(cfile, c.course_name) && cfile >> c.credit_hour && cfile >> c.grade && cfile >> c.passorfail)
   {
     while(Sfile >> s.id_no && getline(Sfile, s.studentname) && Sfile >> s.section && Sfile >> s.sex && Sfile >> s.course_number && Sfile >> s.gpa && Sfile >> s.rankk)
    {

        if(*idNew == s.id_no)
        {
        	cout<<"\n\t\t->Enter the new Data of the student\n";
			cout<<endl;
            getinfo();
            Mfile << s.id_no;
			Mfile << s.studentname <<endl;
			Mfile << s.section << s.sex << s.course_number << endl;
			Mfile << s.gpa <<" "<< s.rankk << endl;

			for(int i = 0; i < s.course_number ;i++)
   			 {
       			 MCfile << s.id_no;
       		   	 MCfile << s.c[i].course_name << endl;
  	 			 MCfile << s.c[i].credit_hour << endl;
        		 MCfile << s.c[i].grade << s.c[i].passorfail << endl;
  			}
            success = true;
        }

        else
        {
        	Mfile << s.id_no;
			Mfile << s.studentname <<endl;
			Mfile << s.section << s.sex << s.course_number << endl;
			Mfile << s.gpa <<" "<< s.rankk << endl;

			for(int i = 0; i < s.course_number ;i++)
   			 {
       			 MCfile << s.id_no;
       		   	 MCfile << c.course_name << endl;
  	 			 MCfile << c.credit_hour << endl;
        	   	 MCfile << c.grade << c.passorfail << endl;
  			}
            success = true;
		}
    }
}
        Mfile.close();
	    cfile.close();
		Sfile.close();
		MCfile.close();


		remove("student.txt");
	    remove("courses.txt");

		rename("Memp.txt", "student.txt");
		rename("Cemp.txt", "courses.txt");

    if(success == false)
    {
        cout <<"\n\t\t->" <<" NO STUDENT FOUND \n ";
        return 1;
    }

    else if(success == true)
    {
    	cout <<"\n\t\t->" <<" SUCCESSFULLY MODIFIED \n ";
        return 1;
	}
    return 1;

}

/**Delete all **/
int deleteall()
{
	char del;
	cout <<"\n\t--->ARE YOU SURE YOU WANT TO DELETE THE WHOLE DATABASE? (Y/N): ";
	cin>>del;
	if(del == 'Y' || del == 'y')
	{

		ofstream ofile("student.txt", ios::trunc);
		ofstream cfile("courses.txt", ios::trunc);
		cout<<"\n\t->TASK SUCCESSFULLY COMPLETED\n";

	}

	else
	{
		cout<<"\n\t->TASK SUCCESSFULLY CANCELLED\n";;
	}
	return 1;
}
/***change admin info***/
int changeAdminInfo()
{
	ofstream iafile("adminInfo.txt", ios::trunc);
	system("CLS");
	string User;
    string Pass;

    cout<<endl;
	cout << "\t\t" << char(218);      for(int i=0; i<39; i++){cout << char(196);}      cout << char(191) << endl;
    cout << "\t\t" << char(179) << " \t     ADMIN SETTING PAGE         " << char(179) << endl;
    cout << "\t\t" << char(179) << "                     \t\t\t" << char(179) << endl;
    cout << "\t\t" << char(179) << "  Enter New UserName:  "; cin>> User; cout<<"\t\t"<< char(179);
    cout<<"\t\t\t\t\t"<< char(179) << endl;
    cout << "\t\t" << char(179) << "  New PASSWORD: "; cin>>Pass; cout << "\t\t" << char(179);
    cout<<"\t\t\t\t\t"<< char(179) << endl;
    cout << "\t\t" << char(179) << "                 \t\t\t" << char(179) << endl;
    cout << "\t\t" << char(192);      for(int i=0; i<39; i++){cout << char(196);}      cout << char(217) << endl;
	cout <<"\t\t->SUCCESSFULLY CHANGED!\n\n";
	iafile << User <<endl;
	iafile << Pass << endl;

	iafile.close();
	return 1;
}

/***Over all status function takes idnumber as parameter***/

int  status(int *idnumber)
{
    ifstream ifile("student.txt");

    system("CLS");
    system("COLOR 4E");
    cout << "\t\t" << char(218);      for(int x=0; x<39; x++){cout << char(196);}      cout << char(191) << endl;
    cout << "\t\t" << char(179) << " \t        WELCOME                 " << char(179) << endl;
    cout << "\t\t" << char(179) << "                      \t\t\t" << char(179) << endl;

    while( ifile >> s.id_no && getline(ifile, s.studentname) && ifile >> s.section && ifile >> s.sex && ifile >> s.course_number && ifile >> s.gpa && ifile >> s.rankk)
    {
      if(s.id_no ==  *idnumber)
      {

        cout << "\t\t" << " \tSTUDENT: " <<s.studentname << "\t        "  << endl; cout<<endl;
        cout << "\t\t" << char(192);      for(int x=0; x<39; x++){cout << char(196);}      cout << char(217) << endl;
        cout<<endl;
        cout << "\t"<< char(201);      for(int i=0; i<70; i++){cout << char(205);}      cout << char(187) << endl;
        cout<<"\t"<<" Roll Number" <<"\t\t" <<" Current Grade" <<"\t   "<< "   Cumulative Grade" <<"\t" << " Rank " << endl;
        cout<<endl;
        cout << "\t"<< char(200);      for(int x=0; x<70; x++){cout << char(205);}      cout << char(188) << endl;
        cout << "\t" <<"   " << 1 <<"\t\t\t      " << setw(5)<< s.gpa << "\t\t" << setw(3)<<s.gpa << "\t\t" <<setw(3)<< s.rankk;
        cout<<"\n\t\t->";system("pause");
        system("CLS");
        return 1;
    }

    }
    ifile.close();
}

/****Operations for student page***/

int currentSemester(int *idnumber)
{
    ifstream ifile("student.txt");
    ifstream cfile("courses.txt");

    system("CLS");
    system("COLOR 4E");

    cout << "\t\t" << char(218);      for(int x=0; x<39; x++){cout << char(196);}      cout << char(191) << endl;
    cout << "\t\t" << char(179) << " \t        WELCOME                 " << char(179) << endl;
    cout << "\t\t" << char(179) << "                      \t\t\t" << char(179) << endl;
    while(cfile>>c.c_id && getline(cfile, c.course_name) && cfile >> c.credit_hour && cfile >> c.grade && cfile >> c.passorfail)
    {
     if(c.c_id == *idnumber)
    {
    while( ifile >> s.id_no && getline(ifile, s.studentname) && ifile >> s.section && ifile >> s.sex && ifile >> s.course_number && ifile >> s.gpa && ifile >> s.rankk)
    {
     if(s.id_no == *idnumber)
     {
        cout << "\t\t"  << " \tSTUDENT: "; cout <<s.studentname << "\t        " << endl; cout<<endl;
        cout << "\t\t" << char(192);      for(int x=0; x<39; x++){cout << char(196);}      cout << char(217) << endl;
        cout<<endl;
        cout << "    "<< char(201);      for(int i=0; i<63; i++){cout << char(205);}      cout << char(187) << endl;
        cout<<"\t"<<" Course Name" <<"\t\t" <<"Credit hours" <<"\t"<< " Grade " <<"\t" << "    STATUS" << endl;
        cout << "    "<< char(200);      for(int x=0; x<63; x++){cout << char(205);}      cout << char(188) << endl;
        for(int i=0;i<s.course_number;i++)
         {
            cout << "   "<< setw(13)<<c.course_name <<"\t"<< setw(15) << c.credit_hour << "\t" << setw(12) << c.grade << "\t" << setw(13) << c.passorfail<<endl;
         }
      }
    }
   }
}
ifile.close();
cfile.close();
cout<<"\n\t\t->";system("pause");
system("CLS");
return 1;
}

/**NEXT semester courses for a student feature**/

int nextSem(int *idnumber)
{
    ifstream ifile("student.txt");
    system("CLS");
    system("COLOR 4E");
    while( ifile >> s.id_no && getline(ifile, s.studentname) && ifile >> s.section && ifile >> s.sex && ifile >> s.course_number && ifile >> s.gpa && ifile >> s.rankk)
    {
        if(s.id_no == *idnumber)
        {
            cout << "\t\t" << char(218);      for(int x=0; x<39; x++){cout << char(196);}      cout << char(191) << endl;
            cout << "\t\t" << char(179) << " \t        WELCOME                 " << char(179) << endl;
            cout << "\t\t" << char(179) << "                      \t\t\t" << char(179) << endl;
            cout << "\t\t" << " \tSTUDENT: "  <<s.studentname << "\t        "  << endl; cout<<endl;
            cout << "\t\t" << char(192);      for(int x=0; x<39; x++){cout << char(196);}      cout << char(217) << endl;
            cout<<endl;

            cout << "\t\t"<< char(201);      for(int x=0; x<40; x++){cout << char(205);}      cout << char(187) << endl;
            cout<<"\t\t\t----NO INFORMATION-----\n";
            cout << "\t\t"<< char(200);      for(int x=0; x<40; x++){cout << char(205);}      cout << char(188) << endl;
        }
    }

    ifile.close();
	cout<<"\t\t\n->";system("pause");
	system("CLS");
	return 1;
}

/***Contact the office for any complaints***/

int contact(int *idnumber)
{
    ifstream ifile("student.txt");
    system("COLOR 4E");
    while( ifile >> s.id_no && getline(ifile, s.studentname) && ifile >> s.section && ifile >> s.sex && ifile >> s.course_number && ifile >> s.gpa && ifile >> s.rankk)
    {
        if(s.id_no== *idnumber)
        {
            cout << "\t\t" << char(218);      for(int x=0; x<39; x++){cout << char(196);}      cout << char(191) << endl;
            cout << "\t\t" << char(179) << " \t        WELCOME                 " << char(179) << endl;
            cout << "\t\t" << char(179) << "                      \t\t\t" << char(179) << endl;
            cout << "\t\t" << " \tSTUDENT: " << s.studentname << "\t        " << endl; cout<<endl;
            cout << "\t\t" << char(192);      for(int x=0; x<39; x++){cout << char(196);}      cout << char(217) << endl;
            cout<<endl;

            cout << "\t\t"<< char(201);      for(int x=0; x<40; x++){cout << char(205);}      cout << char(187) << endl;
            cout<<"\t\t\t--Contact Information--\n\n";
            cout<<"\t\t"<< "\tInstructor Name: " << c.instructor_name <<"     "<<endl;
            cout<<endl;
            cout<<"\t\t"<< "\tPhone Number: " << " +(251)9-154-7845 " <<" "<<endl;
            cout << "\t\t"<< char(200);      for(int x=0; x<40; x++){cout << char(205);}      cout << char(188) << endl;

        }
    }

    ifile.close();
	cout<<"\n\t\t->";system("pause");
	system("CLS");
	return 1;

}



/**Welcome Screen Animation**/

void welcomeScreen()
{

    cout << "\n\n\n";
    Sleep(150);
    cout << "\t\t\t\t * * *  **** *      ****  ***   ***   ****   " << endl;
    Sleep(150);
    cout << "\t\t\t\t * * * *     *     *     *   * * * * *        "<< endl;
    Sleep(150);
    cout << "\t\t\t\t * * * ***** *     *     *   * * * * *****    " << endl;
    Sleep(150);
    cout << "\t\t\t\t * * * *     *     *     *   * * * * *         " << endl;
    Sleep(150);
    cout << "\t\t\t\t  ***   **** *****  ****  ***  * * *  ****     " << endl;
    Sleep(150);
    cout<<endl;
    cout<<"\t\t\t\t============================================="<<endl;
    Sleep(150);
    cout<<"\t\t\t\t\tSTUDENT MANEGEMENT SYSTEM  "<<endl;
    Sleep(150);
    cout<<"\t\t\t\t============================================="<<endl;
    Sleep(150);
    cout<<endl;
    cout<<"\a";
    cout<<"\t\t\t\t\t->";system("pause");
}

/**About Us**/

void aboutUs()
{

    cout << "\t" << char(201);      for(int i=0; i<60; i++){cout << char(205);}      cout << char(187) << endl;
	cout << "\t"<< char(186) << "                       \t\t\t\t     " << char(186) << endl;
	cout << "\t"<< char(186) << " \t\t GROUP MEMBERS                     ID        " << char(186) << endl;
	cout << "\t"<< char(186) << " \t\t\t\t\t\t\t     " << char(186) << endl;
	cout << "\t"<< char(186) << "   \t 1.EYUEL KETEMA                  \t0280/12      " << char(186) << endl;
	Sleep(200);
	cout << "\t"<< char(186) << "   \t 2.ERMIAS SIRAYE                  \t0253/12      " << char(186) << endl;
	Sleep(200);
	cout << "\t"<< char(186) << "   \t 3.ERMIAS TIRUNEH                 \t0251/12      " << char(186) << endl;
	Sleep(200);
	cout << "\t"<< char(186) << "   \t 4.MINTESNOT MARKOS               \t1025/12      " << char(186) << endl;
	Sleep(150);
	cout << "\t"<< char(186) << "   \t 5.ESTIFANOS GASHEWTENA           \t0260/12      " << char(186) << endl;
	Sleep(150);
	cout << "\t"<< char(186) << "                    \t\t\t\t\t     " << char(186) << endl;
	cout << "\t"<< char(200);      for(int x=0; x<60; x++){cout << char(205);}      cout << char(188) << endl;

}
/**EXITING Animation Function using built in function Sleep()**/
void exiting()
{
    cout<<"\n";
    cout<<"\t\t->EXITING";
    Sleep(200);cout<<".";Sleep(200);cout<<".";Sleep(200);cout<<".";Sleep(200);cout<<".";Sleep(200);cout<<".";cout<<"\a";
}


/**************************PHASE 2 COMPLETED***************************/
