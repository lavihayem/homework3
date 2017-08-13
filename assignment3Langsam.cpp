#include <iostream>
#include <cstdlib>
#include <fstream>
/*Hw#3
Name:
  Copyright:
  Author: Shafieollah Lavihayem
  Date: 7/19/2017 18:51
  Description: Calculates net and gross pay and over time for ten people

*/
using namespace std;
float computeAverage(float test1,float test2,float finalTest),average;
char letterGrade(float semesterAverage, char);
void printRecord(string,float,float,float,float,char,float,float,float);

int main()
{
    float test1,test2,finalTest,semesterAverage,sum=0,totalAverage=0;
    int counterSum=0;
    float finalAverage;
    string name;
    char letter,finalGrade,grade,maxLetter;
    ifstream infile;                      //create the file infile for input
    infile.open("StudentGrades.txt");  //open the file

    if ( !infile.is_open() )              //checks to see if file was opened
    {
        // The file could not be opened
        cout << endl << "ERROR: Unable to open file" << endl;
        system ("PAUSE");
        exit(1);
    }
    //*********************************************************************************8
    ofstream outfile;
    outfile.open("Roster.txt");

    outfile.setf(ios::fixed,ios::floatfield);          // setup output format for
    outfile.precision(2);
    // ******************************************************************************
    infile>>name>>test1>>test2>>finalTest;
    semesterAverage=computeAverage(test1,test2,finalTest);
    finalGrade=letterGrade(semesterAverage, grade);


    float maxGrade=0.0,minGrade=120;


    while(!infile.eof())
    {

        semesterAverage=computeAverage(test1,test2,finalTest);
        if(semesterAverage>maxGrade)
            maxGrade=semesterAverage;//name
        // cout<<"\n\nTHe1  maximum Grade is    "<<maxGrade<<"\nThe minimum  Grade is    "<<minGrade<<endl;
        else if
        ( semesterAverage<minGrade)
            minGrade=semesterAverage;//lowest grade
            else;

        counterSum++;
        totalAverage=totalAverage + semesterAverage;
        //  cout<<"\n\nTHe2  maximum Grade is    "<<maxGrade<<"\nThe minimum  Grade is    "<<minGrade<<endl;

        infile>>name>>test1>>test2>>finalTest;
        // cout<<"\n\nTHe 3 maximum Grade is    "<<maxGrade<<"\nThe minimum  Grade is    "<<minGrade<<endl;
    }
     finalAverage=totalAverage/counterSum;
    cout<<"\n\n The Average of class is    "<<finalAverage;

    cout<<"\n\nTHe  maximum Grade is    "<<maxGrade
        <<"\nThe minimum  Grade is    "<<minGrade<<endl;
    printRecord( name, test1,test2, finalTest,semesterAverage,
                finalGrade,finalAverage,minGrade,maxGrade);

    return 0;
}
//**************************************THE END OF MAIN*******************************
float computeAverage(float test1,float test2,float finalTest)
{
    float semesterAverage=.2*test1+.3*test2+.5*finalTest;
    return semesterAverage;
}
//**********************************************************************************************
char letterGrade(float semesterAverage,char grade)
{

    char finalGrade;//countera
    if(semesterAverage>=90)
        return'A';
    else    if (semesterAverage < 90 && semesterAverage >= 80 )
        return 'B';
    else if( semesterAverage < 80 && semesterAverage  >=70 )
        finalGrade='C';

    else if(semesterAverage < 70 && semesterAverage >= 60)
        return 'D';
    else if(semesterAverage < 60 )
        return 'F';
    else
        ;
    return finalGrade;
}
//**********************************************************************************************************8
void printRecord(string name,float test1,float test2, float finalTest,float semesterAverage,char finalGrade,float finalAverage,float minGrade,float maxGrade)
{

    ofstream outfile;
    outfile.open("Roster.txt");

    outfile.setf(ios::fixed,ios::floatfield);          // setup output format for
    outfile.precision(2);
    // outfile<<"\n\t\t\t          Student Grades and Average  "<<endl<<endl;
    cout<<"\t\t\t             Student Grades and Average            "<<endl<<endl<<endl;

    char letter,grade;

    cout<<"   "<<"name    "<< "    "<<"   "<<"test1"<<"      "<<"test2"<<"       "<<"finalTest"<<"    ";
    cout<<   "Semester average";
    cout<<"   "<<"Final Grade";
    ifstream infile;                      //create the file infile for input
    infile.open("StudentGrades.txt");  //open the file

    if ( !infile.is_open() )              //checks to see if file was opened
    {
        // The file could not be opened
        cout << endl << "ERROR: Unable to open file" << endl;
        system ("PAUSE");
        exit(1);
    }
    outfile<<"\n\t\t\t          Student Grades and Average  "<<endl<<endl;

    outfile<<"\n   "<<"name    "<< "    "<<"   "<<"test1"<<"      "<<"test2"<<"     "<<"finalTest"<<"    ";
    outfile<<"Semester average"<<"     FinalGrade"<<endl;


    infile>>name>>test1>>test2>>finalTest;
    while(!infile.eof())
    {
        semesterAverage=computeAverage(test1,test2,finalTest);
        finalGrade=letterGrade(semesterAverage, grade);

        //  outfile<<endl;
        cout<<endl<<endl;


        cout<<"   "<< name      << "   "<<"  " <<test1<<"        "<<test2<<"         "<<finalTest<<"       ";
        cout<<semesterAverage;
        cout<<"             "<<finalGrade;
        outfile<<"\n\nn    "<< name      << "          " <<test1<<"        "<<test2<<"         "<<finalTest<<"       ";
        outfile<<semesterAverage<<"              "<<finalGrade<<endl<<endl;


        infile>>name>>test1>>test2>>finalTest;
    }//end of while loop

    outfile<<"\n\nThe Average of class is :   "<<finalAverage<<endl;
    outfile<<"THe  maximum Grade is   :     "<<maxGrade<<endl;
    outfile<<"The  minimum  Grade is  :     "<<minGrade<<endl<<endl;


}
