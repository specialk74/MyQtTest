#ifndef D_OutputDigitale_H
#define D_OutputDigitale_H

///////////////////////////////////////////////////////////////////////////////
//
//  OutputDigitale is responsible for ...
//
///////////////////////////////////////////////////////////////////////////////

#include "AbstractInputOutputDigitale.h"

class OutputDigitale : public AbstractInputOutputDigitale
{
    Q_OBJECT

public:
    explicit OutputDigitale();
    virtual ~OutputDigitale();
    
    virtual bool isInput() { return false; }
    
    virtual AbstractInputOutputDigitale::TipoDigitale type();
    virtual void type (AbstractInputOutputDigitale::TipoDigitale) { }
    virtual bool canChangeTypeIn (AbstractInputOutputDigitale::TipoDigitale) { return false; }
    
private:

    OutputDigitale(const OutputDigitale&);
    OutputDigitale& operator=(const OutputDigitale&);
};

#endif  // D_OutputDigitale_H
