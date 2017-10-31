#include <string>

class Trade;

//------------------------------------------------------------------------------
#ifndef TRADEOPERATION_H
#define TRADEOPERATION_H

class TradeOperation {

  public:
    virtual void process(const Trade &t) = 0;    

    virtual unsigned long getVal(const std::string &sym) = 0;    
};

#endif
//------------------------------------------------------------------------------
