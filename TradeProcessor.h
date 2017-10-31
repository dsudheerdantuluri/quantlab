#include <set>
#include <vector>

#include "TradeOperation.h"

//------------------------------------------------------------------------------
class TradeProcessor {

  public:
    void addOperation(TradeOperation *top);
    
    void process(const Trade &top);

    void dumpResults(const std::string &fileName);

  private:
    std::set<std::string> m_syms;

    std::vector<TradeOperation *> m_ops;
};
//------------------------------------------------------------------------------

