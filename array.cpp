// Project 4
// Array Functions

#include <iostream>
#include <cassert>
#include <string>
#include <cmath>
#include <cctype>
#include <cstdlib>

using namespace std;

// Declaration of Functions

int locateMinimum( const string array[ ], int n );
int countPunctuation( const string array[ ], int  n );
bool hasReverse( const string array[ ], int n );
char highestOccurredCharacter( const string array[ ], int n, int index );
bool isInIncreasingOrder( const string array[ ], int  n );
char firstNonRepeatedCharacter( const string array[ ], int n, int index );
bool isOnlyDigits( const string array[ ], int n );

// main function

int main ()
{
    string people[5] = { "jon", "mamabbcc!", "samwell,", "daenerys.", "tyrion" };
    string test[5] = { "20", "2!", "3:", "4,", "35"};
    string folks[8] = {
    "samwell", "jon", "margaery", "daenerys",
    "tyrion", "sansa", "llewmad", "noj"
    };
    string TestRepeatChar[3] = {"aabbbdddd", "hello", "thankyou"};
    string Test[6] = {"A", "AB", "B", "65", "456", "6?"};
    string empty[3] = {"","",""};
    
    cout.setf(ios::boolalpha);
    
    cout << highestOccurredCharacter(TestRepeatChar, 3, 2) << endl;
    string a[6] = { "123", "456", "789", "gamma", "beta", "delta" };

    //locate minimum test
    assert(locateMinimum( people, 5 ) == 3);
    assert(locateMinimum(people, 0) == -1);
  
    
    //count punctionation tests
    assert(countPunctuation( people, 5 ) ==3);
    assert(countPunctuation( people, 1 ) == 0);
    assert(countPunctuation(people, -1)== -1);
    
    // hasreverse tests
    assert(hasReverse( people, 5 ) == false);
    assert(hasReverse( folks, 8 ) == true);
    assert(hasReverse(people, 0)== false);
    
    // highests occured characters tests
    assert(highestOccurredCharacter( people, 5, 0 ) == 'j');
    assert(highestOccurredCharacter( people, 5, 2 ) == 'l');
    assert(highestOccurredCharacter(folks, 0, 0) == '\0');
    assert(highestOccurredCharacter(folks, 3, 5) == '\0');
    assert(highestOccurredCharacter(folks, 3, -1)== '\0');
    
    // is inceasing order tests
    assert(isInIncreasingOrder( people, 5 ) == false);
    assert(isInIncreasingOrder( people, 3 ) == true);
    assert(isInIncreasingOrder(people, -1)== false);
    
    // first nonrepeated char tests
    assert(firstNonRepeatedCharacter( people, 5, 1 ) == '!');
    assert(firstNonRepeatedCharacter( people, 5, 0 ) == 'j');
    assert(firstNonRepeatedCharacter(people, -1, -1) == '\0');
    assert(firstNonRepeatedCharacter(people, 2, 3)== '\0');
    assert(firstNonRepeatedCharacter(people, 4, -1)== '\0');
    assert(firstNonRepeatedCharacter(TestRepeatChar, 3, 0) == '\0');
    
    // is only digits test
    assert(isOnlyDigits(a, 6 ) == false);
    assert(isOnlyDigits(a, 3 ) == true);
    assert(isOnlyDigits(a, -1)== false);

    cout << "All tests succeeded" << endl;
  
    return( 0 );
}


// Definition of Functions

// Location minimum function

int locateMinimum( const string array[ ], int n )
{
    //  initialize variables
    string Min = array[0];
    int index = 0;
    
    // n cant be less 0 or less
    if (n <= 0)
    {
        return (-1);
    }
    
    //loop to find min
    for (int i = 0; i < n; i++)
    {
         if (Min > array[i])
         {
             Min = array[i];
             index = i;
         }
        
    }
    
    return (index);
}

// CountPunctuation Function
int countPunctuation( const string array[ ], int  n )
{
    // initialize variables
    int PuntuationCount = 0;
    
    // n cant be 0 or less
    if (n <= 0)
    {
        return (-1);
    }
    
    // loop looking for punctuation in each string
    for (int i = 0; i < n; i++)
    {
        for (size_t k = 0; k < array[i].size(); k++)
        {
            if (array[i].at(k) == ',' || array[i].at(k) == '.' || array[i].at(k) == ';' || array[i].at(k) == '-' || array[i].at(k) == '?' || array[i].at(k) == '!' || array[i].at(k) == ':' || array[i].at(k) == '"' || array[i].at(k) == '(' || array[i].at(k) == ')')
            {
                PuntuationCount = PuntuationCount + 1;
            }
        }
    }
    
    
    
    return (PuntuationCount);
}


// definition of hasReverse function
bool hasReverse( const string array[ ], int n )
{
    
    // initialize variables
    bool result = false;
    size_t begin = 0;
    
    // n cant be 0 or less
    if (n <= 0)
    {
        return (false);
    }
    
    // loop checking first array input against the reverse of every other array input, then moving on to the next
    for (int k = 0; k < n; k++)
    {
        for (int FromEnd = n-1; FromEnd >= 0; FromEnd--)
        {
            if (array[k].size() == array[FromEnd].size())
            {
                for (size_t end = array[k].size()-1; end >= 0; end--)
                {
                    if (array[k].at(begin) == array[FromEnd].at(end))
                    {
                        result = true;
                        begin++;
                       
                        if (end == 0)
                        {
                            return (true);
                        }

                    }
                    else
                    {
                        result = false;
                        break;
                    }
        
            
                }
            }
            
            else
            {
                result = false;
            }
        }
    }
    
    return (result);
}

// definition of highestOccuredCharacter
char highestOccurredCharacter( const string array[ ], int n, int index )
{
    // count number of occurences of every char
    int count[256] = {0};
    int most = 0;
    
    // parameters of n and index
    if (n <= 0 || index >= n || index < 0)
    {
        return ('\0');
    }
    
    // adding counts in the array
    for (int i = 0; array[index][i]; i++)
    {
        count[array[index][i]]++;
    }
    
    // go thru count
    for (int k = 0; k < 256; k++)
    {
       if (count[k] > count[most])
       {
           most = k;
       }
    }
    
    
    return (most);
}

// isIncreasingOrder Function
bool isInIncreasingOrder( const string array[ ], int  n )
{
    //initialize variable
    bool result = false;
    
    // n cant be 0 or less
    if (n <= 0)
    {
        return (false);
    }
    
    // return true if n is 1
    if (n==1)
    {
        return (true);
    }
    
    // loop checking that each successive input is greater
    for (int i = 0; i < n-1; i++)
    {
        if (array[i] < array[i+1])
        {
            result = true;
        }
        
        else
        {
            result = false;
            break;
        }
    }
    
    return (result);
}

// definitiom of firstNonRepeatedCharacter function
char firstNonRepeatedCharacter( const string array[ ], int n, int index )
{
    // initialize variables
    int count[256] = {0};
    int NonRepeated = 0;
    
    // parameters of n and index
    if (n <= 0 || index >= n || index < 0)
    {
        return ('\0');
    }
    
    // counting amount of times each character appears
    for (int i = 0; array[index][i]; i++)
    {
        count[array[index][i]]++;
    }
    
    // go thru count, and stop once 1 is found
    for (int k = 0; k < 256; k++)
    {
       if (count[k] == 1)
       {
           NonRepeated = k;
           break;
       }
        
        // if none =1 then retunn NULL
        if (count[k] > 1)
        {
            NonRepeated = 0;
        }
    }
    
    return (NonRepeated);
}


// definition of isOnlyDigit function
bool isOnlyDigits( const string array[ ], int n )
{
    
    // initialize variables
    bool result = true;
    
    // n cant be 0 or less
    if (n <= 0)
    {
        return (false);
    }
    
    //loop searching fro digits
    for (int i = 0; i < n; i++)
    {
        for (size_t k = 0; k < array[i].size(); k++)
        {
            if (array[i].at(k) != '0' && array[i].at(k) != '1' && array[i].at(k) != '2' && array[i].at(k) != '3' && array[i].at(k) != '4' && array[i].at(k) != '5' && array[i].at(k) != '6' && array[i].at(k) != '7' && array[i].at(k) != '8' && array[i].at(k) != '9')
            {
                result = false;
                break;
            }
        }
        
    }
    
    return (result);
}
