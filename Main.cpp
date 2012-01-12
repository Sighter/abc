
/* Main.cpp<++>
 * @Author:      The Sighter (sighter@resource-dnb.de)
 * @License:     GPL
 * @Created:     2012-01-12.
 * @Editor:      Vim
 */


#include "GenProperty.h"

using namespace std;


int main()
{

   GenProperty<int> prop; 
   prop.SetValue(42);
   prop.Print();
   cout << endl << "Typeid: " << prop.GetTypeID() << endl;

   GenProperty<string> str_prop;
   str_prop.SetValue("Hallo");
   str_prop.Print();
   cout << endl << "Typeid: " << str_prop.GetTypeID() << endl;

}
