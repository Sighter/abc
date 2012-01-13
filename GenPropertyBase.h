
/* GenProperty.h
 * @Author:      The Sighter (sighter@resource-dnb.de)
 * @License:     GPL
 * @Created:     2012-01-12.
 * @Editor:      Vim
 */

#include <iostream>
#include <string>

#ifndef GENPROPERTYBASE_H
#define GENPROPERTYBASE_H


/** declare the abstract base class
 */
class GenPropertyBase
{
    protected:
        std::string mKey;

        void* mpData;

    public:

        GenPropertyBase()
        :   mKey(""),
            mpData(NULL)
        {
        }

        virtual ~GenPropertyBase() {};

        void SetKey(std::string const& rKey) {this->mKey = rKey; };

        virtual void Print() = 0;
        virtual void ToOutStream(std::ostream& rOut) = 0;
};

#endif
