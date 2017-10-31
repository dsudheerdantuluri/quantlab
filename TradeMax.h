#include <unordered_map>

#include "TradeOperation.h"

//------------------------------------------------------------------------------
class TradeMax : public TradeOperation {

  public:
    void process(const Trade &t);    

    unsigned long getVal(const std::string &sym);

  private:
    std::unordered_map<std::string, unsigned long> m_tmax;
};
//------------------------------------------------------------------------------
