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

    virtual void name (const QString &) { }
    virtual QString name () const {return m_nome;}

    
private:

    OutputDigitale(const OutputDigitale&);
    OutputDigitale& operator=(const OutputDigitale&);

    QString m_nome;
};

#endif  // D_OutputDigitale_H
