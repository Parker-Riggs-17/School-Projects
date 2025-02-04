CS 2401 Spring 2024  
# Lab 12: Recursion  
Due: Friday 4/19 at 11:59 PM   
***  
This assignment is to be completed on your own. Refer to the plagiarism policy in the syllabus.
***  

For this lab you are to write two recursive functions. The two problems have nothing to do with each other, so you should do the easy one first and test it, and then tackle the second one. The functions are to be recursive, meaning that there will be no “while” or “for” anywhere in the program except where I have shown it in the main below. No credit will be given for a non-recursive solution.  

***  

## Problem One  
Write a recursive function, called counting, that receives a single parameter which should always be a positive number and then prints all the even numbers from 0 up to, and including the number that was passed in, if that number is even, or one less than the number passed in if it is odd. (“Up to” means that you start with the smallest number and end with the largest number.)  

Run with the program with the values 23, 18, and -2. (No output should be generated by the last.) 

The main for this program will look like this: 
```
int main(){  
    int x;  
    for(int j = 0; j < 3; ++j){              
        cout << ”Enter a number: “;  
        cin >> x;  
        cout << ”The even numbers counting up to there:\n”;  
        counting(x);  
    }  

    // main for Part Two will go here  

 

    return 0;  
} 
```
The function that you are to implement is:  
```
int counting(int n);  
```
***  

## Problem Two  
In this one, the recursive function takes a string and two arguments that are array indexes. The program then reverses all the characters within the array indexes, so given s= “abcdef” and the numbers 2 and 5 the printed string should be “abfedc”. Remember to pass the string by reference and that the base case needs to consider the possibility of the two indexes crossing each other.  

**Add this function prototype:**  
```
reversing(string s, int start, int end);  
```
**And this code to the main:**  
```
    string s;  
    int start, end;

    cout << "Enter a string: ";  
    getline(cin,s);

    cout << "Enter two numbers that are within the bounds of the string.\n";  
    cin >> start >> end;

    cout << "This is how your string looks now:\n";  
    reversing(s, start, end);  
    cout << s << endl;  
```
A sample output for this section is: 

Enter a string: go bobcats  
Enter two numbers that are within the bounds of the string.  
3 7  
This is how your string looks now:  
go acbobts  

***  

**Your final GitHub repository should include** your main program and both recursive functions.
