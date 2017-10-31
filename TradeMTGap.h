#include <unordered_map>

#include "TradeOperation.h"

//------------------------------------------------------------------------------
class TradeMTGap : public TradeOperation {

  public:
    void process(const Trade &t);    

    unsigned long getVal(const std::string &sym);

  private:
    std::unordered_map<std::string, std::pair<unsigned long, unsigned long>> 
      m_mtg;
};
//------------------------------------------------------------------------------
