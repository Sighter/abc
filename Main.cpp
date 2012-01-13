
/* Main.cpp<++>
 * @Author:      The Sighter (sighter@resource-dnb.de)
 * @License:     GPL
 * @Created:     2012-01-12.
 * @Editor:      Vim
 */

#include <iostream>
#include <list>


#include "GenProperty.h"

using namespace std;


int main()
{

   GenProperty<int> prop; 
   prop.SetValue(42);
   prop.Print();
   cout << endl << "Typeid: " << prop.GetTypeN() << endl;

   GenProperty<string> str_prop;
   str_prop.SetValue("Hallo");
   str_prop.Print();
   cout << endl << "Typeid: " << str_prop.GetTypeN() << endl;


   list<GenPropertyBase*> prop_list;

   GenPropertyBase* p1 = &prop;
   GenPropertyBase* p2 = &str_prop;

   prop_list.push_back(p1);
   prop_list.push_back(p2);


   list<GenPropertyBase*>::const_iterator it;
   for (it = prop_list.begin(); it != prop_list.end(); it++)
   {
       cout << *(*it);
       cout << endl;
   }


   cout << "types:\n";
   cout << "Int --> " << GetTypeName<int>() << endl;
   cout << "Float --> " << GetTypeName<float>() << endl;
   cout << "double* --> " << GetTypeName<double*>() << endl;

}
