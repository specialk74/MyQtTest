#ifndef D_InputDigitale_H
#define D_InputDigitale_H

///////////////////////////////////////////////////////////////////////////////
//
//  InputDigitale is responsible for ...
//
///////////////////////////////////////////////////////////////////////////////

#include "AbstractInputOutputDigitale.h"

class InputDigitale : public AbstractInputOutputDigitale
{
    Q_OBJECT

public:
    explicit InputDigitale(QObject *parent = NULL);
    virtual ~InputDigitale();

    virtual bool isInput() { return true; }

    virtual bool canChangeType() { return true; }
    virtual AbstractInputOutputDigitale::TipoDigitale getType();
    virtual bool canChangeTypeIn (AbstractInputOutputDigitale::TipoDigitale);

protected:
    virtual void setTypeProtected(AbstractInputOutputDigitale::TipoDigitale);

private:

    InputDigitale(const InputDigitale&);
    InputDigitale& operator=(const InputDigitale&);
    
    AbstractInputOutputDigitale::TipoDigitale m_tipo;
};

#endif  // D_InputDigitale_H
