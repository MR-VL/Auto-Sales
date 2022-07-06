#include "bubbasales.h"

int main()
{
   //cals the welcome module 
    welcome();
    
    //used to run the program as many times as user wishes
    int keepgoing = 5;
    while (keepgoing == 5)
    {
		//declares the vector to store all the information 2-d
		vector<vector<string>> content;
		//calls the load data to get info from file while referencing content vector for everything to be stored
        loadData(content);

		//calls reportInfo module to display the menu to the user
		reportInfo();

		//the option choice for what the report the user wants to generate
		int option = 0;
		//gets the user report option
		cout << "Which report would you like to create?\nEnter '1' for Report One, '2' for Report Two, or '3' to exit the program. :";
		cin >>  option;
		
		//validation
		while (option < 1 && option > 3)
		{
			cout << "ERROR! Invalid option choice\n";
			cout << "Which report would you like to create?\nEnter '1' for Report One, '2' for Report Two, or '3' to exit the program. :";
			cin >> option;
		}

		//Selects which option the user chose and performs the required action
		if (option == 1)
		{
			reportOne(content);
		}

		else if (option == 2)
		{
			reportTwo(content);
		}

		//Ends the program
		else {
			keepgoing = 0;
		}

    }//END OF KEEPGOING LOOP

    //Displayed after the program ends
    cout << "\n\nThe program has successfully ended";
}//END OF MAIN



/****************************************************************
    Welcome
Displays welcome message to user and other basic program info.
***************************************************************/
void welcome() {
    cout << "\nWelcome to Bubba J's Auto Sales. \nThis is a program that will generate two different monthly sales reports\nfor the 12 salespeople employed at Bubba J's dealership.\n\n"<<endl;
}//END OF WELCOME



/*******************************************
LoadData
Gets the information from the .csv file
And references the content array and changes
the values to the value stored in the .csv
********************************************/
void loadData(vector<vector<string>> &content) {
	//the name of the file
	string fname = "BubbaSales.csv";
	vector<string> row;
	string line, word;

	//reads the information from the file
	fstream file(fname, ios::in);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			row.clear();
			stringstream str(line);
			while (getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
	//IF FILE CANNOT OPEN
	else
		cout << "ERROR! Could not open Input file\n";
}//END LOAD DATA


/*************************************************************
reportInfo
Displays the different menu options and what each menu 
option does.
********************************************************/
void reportInfo() {
	//displays the menu
	cout << "\n'1'     Report ONE consist of an unsorted list of the salespeople names and sales.\n"
		<< "		Plus the salesperson with the highest and lowest sales\n\n\n";
	cout <<"'2'     Report TWO consists of a sorted list ascending order by name of salespeople and\n"
		<< "		monthly salesand the total combined sales for all the salespeople, \n" 
		<<"		and the average sales for the salespeople. \n\n\n";
	cout << "'3'     completely EXITS and ends the program\n"<<endl;
}//END reportInfo



/***************************************************
reportOne
prints an unsorted list of the employess
Also calls another module to save this report to a file
Also calls anotther module to find the lowest and 
highest sales and who had them
Additionally prints the report to a file 
**************************************************/
void reportOne(vector<vector<string>> content) {
	
	//Creates report heading
	cout << "\n\n\n";
	cout << "----------------------------------------------"<<endl;
	cout << "		Report One";
	cout << "\n\n----------------------------------------------" << endl;
	cout << "Name  | Sales"<<endl;
	cout << "--------------"<<endl;
	
	//displays the unsorted list of employees
	for (int i = 0; i < content.size(); i++)
	{
		for (int j = 0; j < content[i].size(); j++)
		{
			cout << content[i][j] << " ";
		}
		cout << "\n";
	}
	
	//declarations
	string leastSalesname, mostSalesname;
	int leastSales, mostSales;
	//default values
	leastSalesname = content[0][0];
	mostSalesname = content[0][0];
	

	//The two for loops below sort the vector and find the person with the least amount of sales
	//It converts a value from the string vector into an integer and then converts the next value
	//into a int value as well then compares them and stores the higher/lower one int the 
	//least/most sales value and stores the name of that person also
	//The stoi() converts string into integer format, to easily be compared.
/*********************************************************************************************/
	
	//Sorts the vector and finds the person that had the least amount of sales.
	for (int i=0; i <salespeople-1; i++)
	{
		//takes two values and converts them into integer format
		int num = stoi (content[i][1] );
		int num1 = stoi( content[i+1][1]);
		//compares if one is greater then next andd sotres that value and the loop repeats
		if (num < num1 )
		{
			//if one is greater it stores its value if not it just skips
			leastSalesname = content[i][0];
			leastSales = num;
		}
		//resets values for next time
		num = 0;
		num1=0;
	}


	//Sorts the vector and finds the person that had the most amount of sales.
	for (int i=0; i <salespeople-1; i++)
	{
		//takes two values and converts them into integer format
		int num = stoi (content[i][1] );
		int num1 = stoi( content[i+1][1]);
		//compares if one is greater then next andd sotres that value and the loop repeats
		if (num > num1 )
		{
			//if one is greater it stores its value if not it just skips
			mostSalesname = content[i][0];
			mostSales = num;
		}
		//resets values for next time
		num = 0;
		num1=0;
	}
	
/**********************************************************************************************/	
	//Displays the information to the console screen for the user to see
	cout << "\n\nThe salesperson with the lowest sales is: " << leastSalesname << " with $" << leastSales << endl;
	cout << "The salesperson with the highest sales is: " << mostSalesname << " with $" << mostSales << endl;
	cout << "\nFile named 'BubbaOne.txt' successfully created.";
	cout << "\n\n----------------------------------------------" << endl;

/*******************************************************************/
	//WRITE TO FILE
	ofstream raport1("BubbaOne.txt");
	raport1 << "----------------------------------------------"<<endl;
	raport1 << "		Report One";
	raport1 << "\n\n----------------------------------------------" << endl;
	raport1 << "Name  | Sales"<<endl;
	raport1<< "--------------"<<endl;
	
	//displays the unsorted list of employees to the file
	for (int i = 0; i < content.size(); i++)
	{
		for (int j = 0; j < content[i].size(); j++)
		{
			raport1 << content[i][j] << " ";
		}
		raport1 << "\n";
	}
	//displays the extra required information to the file
	raport1 << "\n\nThe salesperson with the lowest sales is: " << leastSalesname << " with $" << leastSales << endl;
	raport1 << "The salesperson with the highest sales is: " << mostSalesname << " with $" << mostSales << endl;
	raport1 << "\n\n----------------------------------------------" << endl;
  	// Close the file
  	raport1.close();
	
} //END REPORT ONE


/******************************************************************
reportTwo
Prints a ascending order by last name report for employees
Also displays the total sales
and the average sales.
Additionally prints the report to a file 
**************************************************************/
void reportTwo(vector<vector<string>> content) {
	//Creates a nice heading
	cout << "\n\n\n";
	cout << "----------------------------------------------" << endl;
	cout << "		Report Two";
	cout << "\n\n----------------------------------------------" << endl;
	cout << "Name  | Sales"<<endl;
	cout << "--------------"<<endl;
	
//Sorts the salespeople by last name and holds the required value position for each one
	string temp; //holds one record
	bool swap;
	do
	{
		swap = false;
		for (int count = 0; count < salespeople-1; count++)
		{
			//if the salesperson name is greater than the next
			//it swaps their values
			if (content[count][0] > content[count+1][0] )
			{
				//swaps name
				temp = content[count][0];
				content[count][0]= content[count+1][0];
				content[count + 1][0] = temp;
				//swaps sales amount
				temp = content[count][1];
				content[count][1]=content[count+1][1];
				content[count+1][1] = temp;
				swap = true;
				
			}
		}
	} while (swap);
		

	//displays the sorted array
	for (int i = 0; i < content.size(); i++)
	{
		for (int j = 0; j < content[i].size(); j++)
		{
			cout << content[i][j] << " ";
		}
		cout << "\n";
	}

	//variable declaration
	int finalTotal;
	
	/*This for loop takes the data stored in the 2d vector and converts the numbers part of it to actual integers
	It uses the stoi() to do the conversion along with temporary storage variables
	NOTE: The data in the vector is actually stored as strings and needs to be converted to integers for 
	the totalSales and average to work.
	*/
	for(int i=0; i<salespeople;i++)
	{
		//temporary storage location for a vector position
		string num; 
	    num=content[i][1];
	    //assigns x to the integer value of the vector data
		int x=  stoi(num);
		//adds the integer to the finalTotal
		finalTotal += x;
	
	}
	//Declares and finds teh average
	double average = finalTotal / salespeople;
	
	//Displays the total sales to console for user to see
	cout << "\n\nThe total sales is: $" << finalTotal << endl;
	
	//Displays the average to console screen
	cout << "The average sales is: $" << average<<endl;
	cout << "\nFile named 'BubbaTwo.txt' successfully created.";
	cout << "\n\n----------------------------------------------" << endl;
	
/*******************************************************************/
	//WRITE TO FILE
	ofstream raport2("BubbaTwo.txt");
	
	//creates the report headings
	raport2 << "----------------------------------------------"<<endl;
	raport2 << "		Report Two";
	raport2 << "\n\n----------------------------------------------" << endl;
	raport2 << "Name  | Sales"<<endl;
	raport2 << "--------------"<<endl;
	
	//prints out the sorted by last name salespeople and their sales amounts
	//NOTE this uses the verctor that was sorted earlier
	for (int i = 0; i < content.size(); i++)
	{
		for (int j = 0; j < content[i].size(); j++)
		{
			raport2 << content[i][j] << " ";
		}
		raport2 << "\n";
	}
	
	//Displays the total sales to filefor user to see
	raport2 << "\n\nThe total sales is: $" << finalTotal << endl;
	
	//Displays the average to file
	raport2 << "The average sales is: $" << average;
	raport2 << "\n\n----------------------------------------------" << endl;

  // Close the file
  	raport2.close();
}//End reportTwo