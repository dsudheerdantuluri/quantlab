#include <algorithm>

#include "Trade.h"
#include "TradeWAP.h"

//------------------------------------------------------------------------------
void TradeWAP::process(const Trade &t)
{
  auto &val = m_wap[t.getSym()];
  val.first += t.getPrice() * t.getQty(); 
  val.second += t.getQty(); 
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
unsigned long TradeWAP::getVal(const std::string &sym)
{
  auto &val = m_wap[sym];
  return val.first/val.second;
}
//------------------------------------------------------------------------------
