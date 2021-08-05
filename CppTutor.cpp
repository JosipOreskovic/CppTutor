/*
 * CppTutor
 * v. 0.1.3
 * © Josip Oreskovic
*/


#include <iostream> // std::cout, std::cin, std::endl
#include <limits> // std::numeric_limits<T>
#include <iomanip> // std::setw(), std::left, std::right
#define NOMINMAX
#include <windows.h> // HWND, MoveWindow

// global variable declaration

int gl;

// Function declarations

void NewTopic();
int FuncVal(int f_i);
int FuncRef(int &f_i);
int FuncPtr(int *f_i);
int FuncArr(int arr[]);
int FuncArrPtr(int *arr);
int FuncArrRef(int (&arr)[3]);
int Func2DArr(int arr[][3]);

// Overloaded function declaration

void FuncOL();
int FuncOL(int, int);
double FuncOL(double, double);

// Return type pointer to function definition and function declaration 
typedef int (*PF) (int, int);
PF f1(int);
int f2(int, int);

int main()
{
	// New console window 1200x700

	HWND console = GetConsoleWindow();
	MoveWindow(console, 0, 0, 1200, 700, true);

	// Hello world
	// This is a comment
	/* This is
	a comment
	too */

	std::cout << "Hello world, of course! ";
	std::cout <<
		"I am C++ tutor."
		;

	NewTopic();

	// Basic data types variables decalaration and initalization
	std::cout << "VARIABLES" << std::endl;
	std::cout << std::endl;

	std::cout << "Local and global variables" << std::endl;
	std::cout << std::endl;
	// block
	{
		// local variable declaration
		using std::cout; // now we can use only cout instead of std::cout
		using std::endl; // now we can use only endl instead of std::endl

		int lo = 3;
		gl = 10;
		cout << "Local lo variable value (inside block): " << lo << endl;
		cout << "Global gl variable value (inside block): " << gl << endl;
	}

	int lo = 10; // new lo variable
	gl = 15; // the same global gl vlariable as in the block

	std::cout << "Local lo variable value (outside block): " << lo << std::endl;
	std::cout << "Global gl variable value (outside block): " << gl << std::endl;

	NewTopic();

	int i;
	int x, y = 12, z{ 20 };
	bool b;
	char c('a');
	float f{ 1.2 };
	double d = 232.312;
	short s = 23;
	long l (4000000);
	long long ll{ 5000000000 };
	unsigned int ui = 500000000;
	unsigned char uc = 65;
	wchar_t wc = 2323;
	i = 213123;
	b = true;

	// Console output of variables values, data type size, data dype minimum and maximum values
	// Special characters formating

	std::cout << "BASIC TYPES" << std::endl;
	std::cout << std::endl;
	std::cout << "int" << "\t\t" << "i=" << i << "\t" << "Size: " << sizeof i << " bytes" << "\t" << "Min: " << std::numeric_limits<int>::min() << "\t\t" << "Max: " << std::numeric_limits<int>::max() << "\n";
	std::cout << "bool" << "\t\t" << "b=" << b << " (" << std::boolalpha << b << ")" << "\t" << "Size: " << sizeof b << " bytes" << "\t" << "Min: " << std::numeric_limits<bool>::min() << "\t\t\t" << "Max: " << std::numeric_limits<bool>::max() << "\n";
	std::cout << "char" << "\t\t" << "c=" << c << "\t\t" << "Size: " << sizeof c << " bytes" << "\t" << "Min: " << static_cast<int>(std::numeric_limits<char>::min()) << "\t\t\t" << "Max: " << static_cast<int>(std::numeric_limits<char>::max()) << "\n";
	std::cout << "float" << "\t\t" << "f=" << f << "\t\t" << "Size: " << sizeof f << " bytes" << "\t" << "Min: " << std::numeric_limits<float>::min() << "\t\t" << "Max: " << std::numeric_limits<float>::max() << "\n";
	std::cout << "double" << "\t\t" << "d=" << d << "\t" << "Size: " << sizeof d << " bytes" << "\t" << "Min: " << std::numeric_limits<double>::min() << "\t\t" << "Max: " << std::numeric_limits<double>::max() << "\n";
	std::cout << "short" << "\t\t" << "s=" << s << "\t\t" << "Size: " << sizeof s << " bytes" << "\t" << "Min: " << std::numeric_limits<short>::min() << "\t\t\t" << "Max: " << std::numeric_limits<short>::max() << "\n";
	std::cout << "long" << "\t\t" << "l=" << l << "\t" << "Size: " << sizeof l << " bytes" << "\t" << "Min: " << std::numeric_limits<long>::min() << "\t\t" << "Max: " << std::numeric_limits<long>::max() << "\n";
	std::cout << "long long" << "\t" << "ll=" << ll << "\t" << "Size: " << sizeof ll << " bytes" << "\t" << "Min: " << std::numeric_limits<long long>::min() << "\t" << "Max: " << std::numeric_limits<long long>::max() << "\n";
	std::cout << "unsigned int" << "\t" << "ui=" << ui << "\t" << "Size: " << sizeof ui << " bytes" << "\t" << "Min: " << std::numeric_limits<unsigned int>::min() << "\t\t\t\t" << "Max: " << std::numeric_limits<unsigned int>::max() << "\n";
	std::cout << "unsigned char" << "\t" << "uc=" << uc << "\t\t" << "Size: " << sizeof uc << " bytes" << "\t" << "Min: " << std::numeric_limits<unsigned char>::min() << "\t\t\t\t" << "Max: " << std::numeric_limits<unsigned char>::max() << "\n";
	std::cout << "wchar_t" << "\t\t" << "d=" << wc << "\t\t" << "Size: " << sizeof wc << " bytes" << "\t" << "Min: " << std::numeric_limits<wchar_t>::min() << "\t\t\t\t" << "Max: " << std::numeric_limits<wchar_t>::max() << "\n";
	
	NewTopic();
	
	std::cout << "TYPE CONVERSIONS AND NUMBER OVERFLOW" << std::endl;
	std::cout << std::endl;

	i = f; // float to int
	i = b; // bool to int
	b = f; // float to bool
	uc = -1;

	// std::cout formating 

	std::cout << std::setw(65) << std::left << "Float to int (truncate decimal places): " << std::setw(15) << std::right << i << std::endl;
	std::cout << std::setw(65) << std::left << "Bool to int (1 if true, 0 if false): " << std::setw(15) << std::right << i << std::endl;
	std::cout << std::setw(65) << std::left << "Any number type to bool (false if 0, true in any other number): " << std::setw(15) << std::right << b << std::endl;
	std::cout << std::setw(65) << std::left << "Unsigned char of value -1 (value will be 255): " << std::setw(15) << std::right << (int)uc << std::endl;
	std::cout << std::setw(65) << std::left << "Maximum int + 1 (value will be minimum int): " << std::setw(15) << std::right << std::numeric_limits<int>::max() + 1 << std::endl;
	std::cout << std::setw(65) << std::left << "Minimum int - 1 (value will be maximum int): " << std::setw(15) << std::right << std::numeric_limits<int>::min() - 1 << std::endl;
	

	NewTopic();

	// Expressions, Operators

	std::cout << "EXPRESIONS AND OPERATORS" << std::endl;
	std::cout << std::endl;

	i = 1;
	std::cout << "i = " << i << std::endl;
	int j = 2;
	i = i + 1;
	std::cout << "i + 1 = " << i << std::endl;
	i = i * j;
	std::cout << "i * j = " << i << std::endl;
	i = i / 2 * j;
	std::cout << "i / 2 * j = " << i << std::endl;
	
	std::cout << std::endl;

	std::cout << "i = " << i << std::endl;
	std::cout << "i = " << ++i << " , ++i, first i incremented and then printed on console. After i = " << i << std::endl;
	std::cout << "i = " << i++ << " , i++, first i is printed on console and after is incremented. After i = " << i << std::endl;

	std::cout << std::endl;
	std::cout << "i= " << i << std::endl;
	i += 2;
	std::cout << "i += 2 adds 2 to i, i = " << i << std::endl;

	std::cout << std::endl;
	std::cout << "i = " << i << std::endl;
	i *= 2;
	std::cout << "i *= 2 multiply i by 2, i = " << i << std::endl;
	std::cout << std::endl;

	bool b1 = true;
	bool b2 = false;
	
	std::cout << "b1 = " << std::boolalpha << b1 << std::endl;
	std::cout << "b2 = " << std::boolalpha << b2 << std::endl;
	std::cout << "b1 and b2 = " << std::boolalpha << (b1 && b2) << std::endl;
	std::cout << "b1 or b2 = " << std::boolalpha << (b1 || b2) << std::endl;
	std::cout << "not b1 = " << std::boolalpha << !b1 << std::endl;

	NewTopic();

	// References & Pointers

	std::cout << "REFERENCES AND POINTERS" << std::endl;
	std::cout << std::endl;

	int *p_i{ &i }; // Pointer to int variable
	int &r_i = i; // Reference of int variable
	int *&r_pi = p_i; // Reference of pointer to int variable
	int** p_p_i = &p_i; // Pointer to a pointer

	std::cout << std::setw(65) << std::left << "Variable value:" << std::setw(15) << std::right << i << std::endl;
	std::cout << std::setw(65) << std::left << "Reference value:" << std::setw(15) << std::right << r_i << std::endl;
	std::cout << std::setw(65) << std::left << "Variable address:" << std::setw(15) << std::right << &i << std::endl;
	std::cout << std::setw(65) << std::left << "Reference address:" << std::setw(15) << std::right << &r_i << std::endl;
	std::cout << std::setw(65) << std::left << "Pointer value:" << std::setw(15) << std::right << p_i << std::endl;
	std::cout << std::setw(65) << std::left << "Indirect (*pointer) value:" << std::setw(15) << std::right << *p_i << std::endl;
	std::cout << std::setw(65) << std::left << "Reference to pointer value:" << std::setw(15) << std::right << r_pi << std::endl;
	std::cout << std::setw(65) << std::left << "Pointer to pointer value:" << std::setw(15) << std::right << p_p_i << std::endl;
	std::cout << std::setw(65) << std::left << "Indirect (*pointer to pointer) value:" << std::setw(15) << std::right << *p_p_i << std::endl;
	std::cout << std::setw(65) << std::left << "Doubly indirect (**pointer) indirect value:" << std::setw(15) << std::right << **p_p_i << std::endl;
	std::cout << std::endl;
	std::cout << "(Remark: We used reference and pointer to int i variable)";
	std::cout << std::endl;

	NewTopic();

	// typedef, using, auto, decltype

	
	typedef double DB; // db is other name for double
	using DB1 = DB; // db1 is other name for db and double
	using P_DB = DB1*; // p_db is pointer to double
	typedef DB* P_DB1; // p_db1 is pointer to double

	DB d1 = 2.3; // same as double d1 = 2.3;
	DB1 d2 = d1; // same as double d1 = d1;
	P_DB p_db1 = &d1; // same as double *pdb1 = &d1;
	P_DB1 p_db2; // same as double *pdb2
	p_db2 = &d2; 

	std::cout << "d1 = " << d1 << std::endl;
	std::cout << "d2 = " << d2 << std::endl;
	std::cout << "p_db1 = " << p_db1 << std::endl;
	std::cout << "*p_db1 = " << *p_db1 << std::endl;
	std::cout << "p_db2 = " << p_db2 << std::endl;
	std::cout << "*p_db2 = " << *p_db1 << std::endl;

	NewTopic();

	// Statements

	; // null statement

	i = i + 1; // simple expression statement 

	// if - else statement

	std::cout << "IF STATEMENT" << std::endl;
	std::cout << std::endl;

	std::cout << "Please input a number: ";    
	std::cin >> i;                       
	std::cin.ignore();                    
	if (i < 100) {                
		std::cout << "Your number is less then 100"; 
	}
	else if (i == 100) {            
		std::cout << "Your number is 100";        
	}
	else {
		std::cout << "You number is greather then 100";     
	}

	NewTopic();
	
	// switch statement
	
	std::cout << "SWITCH STATEMENT" << std::endl;
	std::cout << std::endl;
	

	std::cout << "1. option" << std::endl;
	std::cout << "2. option" << std::endl;
	std::cout << "3. option" << std::endl;
	std::cout << "4. option" << std::endl;
	std::cout << "Selection: ";
	
	std::cin >> i;
	std::cin.ignore();

	switch (i) {
	case 1:            // Note the colon, not a semicolon
		std::cout << "You selected first option." << std::endl;
		break;
	case 2:            // Note the colon, not a semicolon
		std::cout << "You selected second option." << std::endl;
		break;
	case 3:            // Note the colon, not a semicolon
		std::cout << "You selected third option." << std::endl;
		break;
	case 4:            // Note the colon, not a semicolon
		std::cout << "You selected fourth option." << std::endl;
		break;
	default:            // Note the colon, not a semicolon
		std::cout << "Bed input." << std::endl;
		break;
	}

	NewTopic();

	// for statement

	std::cout << "FOR STATEMENT" << std::endl;
	std::cout << std::endl;

	int sum{ 0 };
	std::cout << "Sum of 5 integral numbers using for loop" << std::endl;
	std::cout << "Enter 5 integral numbers (numbers are separated by space od Enter): " << std::endl;
	for (int i = 0; i < 5; i++)
	{
		int j;
		std::cin >> j;
		sum += j;
	}

	std::cin.ignore();
	std::cout << "Sum is: " << sum << std::endl;

	NewTopic();

	// while statement

	std::cout << "WHILE STATEMENT" << std::endl;
	std::cout << std::endl;

	sum = 0;
	std::cout << "Sum of arbitrary number of integral numbers using while loop" << std::endl;
	std::cout << "Enter integral numbers. Enter 0 at the end (numbers are separated by space od Enter): " << std::endl;
	while (std::cin >> i && i != 0)
		sum += i;
	std::cout << "Sum is: " << sum << std::endl;

	std::cin.ignore();
	NewTopic();

	// Strings, Vectors, Arrays
	
	std::cout << "STRINGS" << std::endl;
	std::cout << std::endl;

	std::string str;
	std::string str1 = "C++ rules!";
	std::cout << std::setw(65) << std::left << "This is the first string str1:" << std::setw(15) << std::left << str1 << std::endl;
	std::string str2 = "I love C++.";
	std::cout << std::setw(65) << std::left << "This is the second string str2:" << std::setw(15) << std::left << str2 << std::endl;
	str = str1 + str2;
	std::cout << std::setw(65) << std::left << "This is new string str = str1 + str2: " << std::setw(15) << std::left << str << std::endl;
	std::cout << std::setw(65) << std::left << "First character in string str1: " << std::setw(15) << std::left << str1[0] << std::endl;
	std::cout << std::setw(65) << std::left << "Last character in string str1: " << std::setw(15) << std::left << str1[str1.size()-1] << std::endl;
	std::cout << std::setw(65) << std::left << "These are all characters in string str1 in uppercase" << std::endl;
	std:: cout << std::setw(65) << std::left << "(iterate through string using range): ";

	for (char c : str1)
	{
		c = static_cast<char>(toupper(c));
		std::cout << c << " ";
	}
	std::cout << std::endl;
	std::cout << std::setw(65) << std::left << "String str1 IS NOT changed: ";
	std::cout << str1 << std::endl;
	std::cout << std::endl;

	std::cout << "These are all characters in string str1 in uppercase" << std::endl;
	std::cout << std::setw(65) <<  std::left << "(iterate through string using range): ";

	for (char &c : str1)
	{
		c = static_cast<char>(toupper(c));
		std::cout << c << " ";
	}

	std::cout << std::endl;

	std::cout << std::setw(65) << std::left << "String str1 IS CHANGED, new string str1: ";
	std::cout << str1 << std::endl;
	std::cout << std::endl;

	std::cout << "This is every other character in str1" << std::endl;
	std::cout << std::setw(65) << std::left << "(iterate through string using iterator) : ";
	for (auto it = str1.begin(); it < str1.end()-2; it +=2)
		std::cout << *it << " ";


	NewTopic();

	std::cout << "ARRAYS" << std::endl;
	std::cout << std::endl;

	int arr1[3];
	int arr2[]{ 6, 7, 8, 9};
	int arr3[3]{ 0 };

	for (int i = 0; i < 3; ++i)
	{
		arr1[i] = i + 1;
	}

	std::cout << std::endl;

	for (int i = 0; i < 3; ++i)
	{
		std::cout << i + 1 << ". element of arr1[" << i <<"]:" << "\t" << arr1[i] << std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < (sizeof(arr2) / sizeof(arr2[0])); ++i)
	{
		std::cout << i + 1 << ". element of arr2[" << i << "]:" << "\t" << arr2[i] << std::endl;
	}

	std::cout << std::endl;

	for (auto i : arr3)
	{
		std::cout << i + 1 << ". element of arr3[" << i << "]:" << "\t" << arr3[i] << std::endl;
	}

	NewTopic();

	std::cout << "MULTIDIMENSIONAL ARRAYS" << std::endl;
	std::cout << std::endl;

	int arr4[2][3];

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 3; ++j)
			arr4[i][j] = i + j;

	for (auto &i : arr4)
		for (auto &j : i)
			std::cout << "arr4[" << *i << "][" << j << "]= " << j << std::endl;


	NewTopic();

	std::cout << "ARRAYS AND POINTERS" << std::endl;
	std::cout << std::endl;

	std::cout << std::setw(70) << std::left << "Name of an array arr1 is a pointer to a first element of the array: ";
	std::cout << std::setw(15) << std::right << arr1 << std::endl;
	std::cout << std::setw(70) << std::left << "First element of the array: " << std::setw(15) << std::right << *arr1 << std::endl;
	std::cout << std::setw(70) << std::left << "Second element of the array: " << std::setw(15) << std::right << *(arr1 + 1) << std::endl;
	std::cout << std::setw(70) << std::left << "Last element of the array: " << std::setw(15) << std::right << *(arr1 + (sizeof(arr1) / sizeof(*arr1)) - 1) << std::endl;

	NewTopic();

	// C-style string

	std::cout << "C-STYLE STRING" << std::endl;
	std::cout << std::endl;

	const char* cs = "Original C-style string"; // Declaration and initialization
	std::cout << std::setw(70) << std::left << "Initialized string: " << std::setw(25) << std::right << cs << std::endl;
	cs = "New C-style string"; // Assignment
	std::cout << std::setw(70) << std::left << "New string assignment: " << std::setw(25) << std::right << cs << std::endl;
	std::cout << std::setw(70) << std::left << "String from second character to end: " << std::setw(25) << std::right << cs + 1 << std::endl;
	std::cout << std::setw(70) << std::left << "First character in string: " << std::setw(25) << std::right << *cs << std::endl;
	std::cout << std::setw(70) << std::left << "First character in string: " << std::setw(25) << std::right << cs[1] << std::endl;
	std::cout << std::setw(70) << std::left << "Second character in string: " << std::setw(25) << std::right << *(cs + 1) << std::endl;
	std::cout << std::setw(70) << std::left << "Second character in string: " << std::setw(25) << std::right << cs[1] << std::endl;

	NewTopic();

	// Structures

	std::cout << "STRUCTURES" << std::endl;
	std::cout << std::endl;
	
	struct MyStruct
	{
		int i;
		std::string str;
	};

	MyStruct S;
	S.i = 5;
	S.str = "This is the string in structure";

	std::cout << "Value of S.i = " << S.i << std::endl;
	std::cout << "Value of S.str = " << S.str << std::endl;

	NewTopic();
	
	// Functions

	std::cout << "FUNCTIONS" << std::endl;
	std::cout << std::endl;

	std::cout << std::setw(75) << std::left << "Value of i before function FuncVal(i) call (pass by value):" << std::setw(25) << std::right << i << std::endl;
	std::cout << std::setw(75) << std::left << "Value of FuncVal(i) call:" << std::setw(25) << std::right << FuncVal(i) << std::endl;
	std::cout << std::setw(75) << std::left << "Value of i after function FuncVal(i) call (pass by value):" << std::setw(25) << std::right << i << std::endl;

	std::cout << std::endl;

	std::cout << std::setw(75) << std::left << "Value of i before function FuncRef(i) call (pass by reference):" << std::setw(25) << std::right << i << std::endl;
	std::cout << std::setw(75) << std::left << "Value of FuncRef(i) call:" << std::setw(25) << std::right << FuncRef(i) << std::endl;
	std::cout << std::setw(75) << std::left << "Value of i after function FuncRef(i) call (pass by reference):" << std::setw(25) << std::right << i << std::endl;

	std::cout << std::endl;

	std::cout << std::setw(75) << std::left << "Value of i before function FuncPtr(&i) call (pass by reference/pointer):" << std::setw(25) << std::right << i << std::endl;
	std::cout << std::setw(75) << std::left << "Value of FuncPtr(&i) call:" << std::setw(25) << std::right << FuncPtr(&i) << std::endl;
	std::cout << std::setw(75) << std::left << "Value of i after function FuncPtr(&i) call (pass by reference):" << std::setw(25) << std::right << i << std::endl;

	NewTopic();

	std::cout << "FUNCTIONS AND ARRAYS" << std::endl;
	std::cout << std::endl;
	std::cout << std::setw(25) << std::right << FuncArr(arr1) << std::endl;
	std::cout << std::setw(25) << std::right << FuncArrPtr(arr1) << std::endl;
	std::cout << std::setw(25) << std::right << FuncArrRef(arr1) << std::endl;
	std::cout << std::setw(25) << std::right << Func2DArr(arr4) << std::endl;

	NewTopic();

	std::cout << "OVERLOADING FUNCTIONS" << std::endl;
	std::cout << std::endl;
	// Overloaded functions

	FuncOL();
	std::cout << FuncOL(2, 3) << std::endl;
	std::cout << FuncOL(2.1, 3.) << std::endl;

	NewTopic();

	// Function pointer

	std::cout << "FUNCTION POINTER" << std::endl;
	std::cout << std::endl;

	int (*Func)(int); // Points to a function which returns int and take int as argument
	Func = FuncVal; // Function name is pointer 
	std::cout << "Func(1) = " << Func(1) << std::endl;
	std::cout << "Same as FuncVal(1) = " << FuncVal(1) << std::endl;
	std::cout << std::endl;

	// Pointer to function as return type

	std::cout << "Pointer to function as return type." << std::endl;
	std::cout << std::endl;

	using PF1 = int (*) (int, int);
	PF1 pf2 = f2;
	std::cout << "Function f1 returns pointer to function f2: " << f1(3) << std::endl;
	std::cout << "Function name f2 is pointer to function f2: " << f2 << std::endl;
	std::cout << "Pointer to function f2 value: " << pf2 << std::endl;
	std::cout << std::endl;

	NewTopic();
	std::cout << std::endl;
	std::cout << "The end." << std::endl;
}


// Function definitions

void NewTopic()
{
	std::cout << std::endl;
	std::cin.clear();
	fflush(stdin);
	std::cout << std::endl << "Press any key to continue...";
	std::cin.ignore();
	system("CLS");
}

int FuncVal(int f_i)
{
	++f_i;
	return f_i;
}

int FuncRef(int& f_i)
{
	++f_i;
	return f_i;
}

int FuncPtr(int *f_i)
{
	++(*f_i);
	return *f_i;
}

int FuncArr(int arr[])
{
	std::cout << std::setw(80) << std::left << "Function returns first element of array (pass by array name (pointer)):  ";
	return arr[0];
}

int FuncArrPtr(int *arr)
{
	std::cout << std::setw(80) << std::left << "Function returns first element of array (pass by pointer):  ";
	return *arr;
}

int FuncArrRef(int(&arr)[3])
{
	std::cout << std::setw(80) << std::left << "Function returns second element of array (pass by reference): ";
	return arr[1];
}

int Func2DArr(int arr[][3])
{
	std::cout << std::setw(80) << std::left << "Function returns second element of first row of 2D array (pass by reference): ";
	return arr[0][1];
}


// Overloaded functions definition

void FuncOL()
{
	std::cout << "Calls function without arguments without return value." << std::endl;
}

int FuncOL(int i, int j)
{
	std::cout << "Calls function with int arguments and return value is ";
	return i * j;
}

double FuncOL(double i, double j)
{
	std::cout << "Calls function with double arguments and return value is ";
	return i * j;
}

// Pointer to function return value - function definition

PF f1(int x)
{
	return f2;
}

int f2(int i, int j)
{
	return (i + j);
}
