
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

/** typename templates
 */
template <typename typ>
std::string GetTypeName() { return "undefined"; };


/** typename macro
 */
#define DEFINE_NEW_GETTYPENAME(type) \
template <> \
std::string GetTypeName<type>() {return "" #type ""; }; \


/** define important types
 */
DEFINE_NEW_GETTYPENAME(int)
DEFINE_NEW_GETTYPENAME(float)
DEFINE_NEW_GETTYPENAME(double)
DEFINE_NEW_GETTYPENAME(double&)
DEFINE_NEW_GETTYPENAME(double*)
DEFINE_NEW_GETTYPENAME(std::string)
DEFINE_NEW_GETTYPENAME(std::string&)
DEFINE_NEW_GETTYPENAME(std::string*)


/* define a template for basic types
 */
template <typename typ>
class GenProperty : public GenPropertyBase
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

        std::string GetTypeN()
        {
            return GetTypeName<typ>();
        };

        void Print()
        {
            std::cout << *((typ*) this->mpData);
        }

        void ToOutStream(std::ostream& rOut)
        {
            rOut << "[PROP<" << this->GetTypeN() << ">"
                 << this->mKey << ":" << *((typ*) this->mpData) << "]";
        }
};

std::ostream& operator<<(std::ostream& rOut, GenPropertyBase& rProp)
{
   rProp.ToOutStream(rOut);
   return rOut;
};



#endif
