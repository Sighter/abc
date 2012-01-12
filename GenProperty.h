
/* GenProperty.h
 * @Author:      The Sighter (sighter@resource-dnb.de)
 * @License:     GPL
 * @Created:     2012-01-12.
 * @Editor:      Vim
 */

#ifndef GENPROPERTY_H
#define GENPROPERTY_H

#include <iostream>
#include <typeinfo>

#include "GenPropertyBase.h"


/* define a template for basic types
 */
template <typename typ>
class GenProperty : GenPropertyBase
{
    public:

        ~GenProperty()
        {
            if (this->mpData)
                delete (typ*) this->mpData;
        };
        
        void SetValue(typ value)
        {
            this->mpData = (void*) new typ(value); 
        };
    
        typ GetValue()
        {
            return *this->mpData;
        };

        std::string GetTypeID()
        {
            return typeid(*((typ*)this->mpData)).name();
        };

        void Print()
        {
            std::cout << *((typ*) this->mpData);
        }
};



#endif
