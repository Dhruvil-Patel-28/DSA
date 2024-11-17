
#include <iostream>
using namespace std;  
void show (char c);	
void show (double d); 
void show (char c) { 
cout << "Character is shown here" << c;
}
void show (double d)  {       
cout << "Double is shown here" << d;  
}	     
int main() 
      {     show('A'); // (i) 
            show(12);  // (ii)
            show(20.5); // (iii) 
      } 	

