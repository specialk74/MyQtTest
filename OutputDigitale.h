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
    virtual int type (AbstractInputOutputDigitale::TipoDigitale) { return -1;}
    virtual int canChangeTypeIn (AbstractInputOutputDigitale::TipoDigitale) { return 0; }

    virtual int name (const QString &) { return 0; }
    virtual QString name () const {return m_nome;}

    
private:

    OutputDigitale(const OutputDigitale&);
    OutputDigitale& operator=(const OutputDigitale&);

    QString m_nome;
};

#endif  // D_OutputDigitale_H
