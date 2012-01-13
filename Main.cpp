
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
   
   int* p_int = new int(87);
   cout << "Pointer type:" << p_int << endl; 

   GenProperty<int*> pointer_prop(p_int, "pointer_prop");

   GenProperty<int> prop("IntegerProp"); 
   prop.SetValue(42);

   prop.SetValue(32);

   GenProperty<string> str_prop("str_prop");
   str_prop.SetValue("Hallo");
   
   GenProperty<double> double_prop(32.45, "double_prop");

   GenProperty<int> empty_prop("empty_prop");



   list<GenPropertyBase*> prop_list;

   GenPropertyBase* p1 = &prop;
   GenPropertyBase* p2 = &str_prop;
   GenPropertyBase* p3 = &double_prop;
   GenPropertyBase* p4 = &pointer_prop;
   GenPropertyBase* p5 = &empty_prop;

   prop_list.push_back(p1);
   prop_list.push_back(p2);
   prop_list.push_back(p3);
   prop_list.push_back(p4);
   prop_list.push_back(p5);


   list<GenPropertyBase*>::const_iterator it;
   for (it = prop_list.begin(); it != prop_list.end(); it++)
   {
       cout << *(*it) << "   Has Value: " << (*it)->HasValue();
       cout << endl;
   }


   cout << "types:\n";
   cout << "Int --> " << GetTypeName<int>() << endl;
   cout << "Float --> " << GetTypeName<float>() << endl;
   cout << "double* --> " << GetTypeName<double*>() << endl;

}
