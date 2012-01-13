
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
#include "DefineException.h"

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
DEFINE_NEW_GETTYPENAME(int*)
DEFINE_NEW_GETTYPENAME(int&)
DEFINE_NEW_GETTYPENAME(float)
DEFINE_NEW_GETTYPENAME(double)
DEFINE_NEW_GETTYPENAME(double&)
DEFINE_NEW_GETTYPENAME(double*)
DEFINE_NEW_GETTYPENAME(std::string)
DEFINE_NEW_GETTYPENAME(std::string&)
DEFINE_NEW_GETTYPENAME(std::string*)


/** exceptions
 */
DEFINE_VAR_EXCEPTION(ErrorGenProperty)


/* define a template for basic types
 */
template <typename typ>
class GenProperty : public GenPropertyBase
{
    public:

        /////////////////////////////// PUBLIC ///////////////////////////////////////

        /*============================= LIFECYCLE ==================================*/
        
        /* default constructor
         */
        GenProperty()
        {
        }

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

        /* empty constructor with key
         */
        GenProperty(std::string const& rKey)
        {
            this->mKey = rKey;
        }

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

        /* constructor with value and key
         */
        GenProperty(typ value, std::string const& rKey)
        {
            this->mKey = rKey;

            this->SetValue(value);
        }

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

        /** destructor
         */
        ~GenProperty()
        {
            if (this->mpData)
                delete (typ*) this->mpData;
        };
        
        /*============================= ACESS      =================================*/

        void SetValue(typ value)
        {
            if (!(this->mpData))
                this->mpData = (void*) new typ(value); 
            else
                *((typ*)(this->mpData)) = value;
        };
    
        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

        typ GetValue()
        {
            if (this->HasValue())
                return *((typ*)this->mpData);
            else
                throw ErrorGenProperty("NO_PROP_VALUE");
        };

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

        std::string GetTypeN()
        {
            return GetTypeName<typ>();
        };

        void Print()
        {
            std::cout << this->GetValue();
        }

        /*============================= OPERATIONS =================================*/

        void ToOutStream(std::ostream& rOut)
        {
            rOut << "[PROP<" << this->GetTypeN() << ">"
                 << this->mKey << ":" << this->GetValue()<< "]";
        }
        
        /*============================= INQUIRY    =================================*/

};

/*============================= OPERATORS ==================================*/

std::ostream& operator<<(std::ostream& rOut, GenPropertyBase& rProp)
{
   rProp.ToOutStream(rOut);
   return rOut;
};



#endif
