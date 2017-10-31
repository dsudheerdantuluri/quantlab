#include <algorithm>

#include "Trade.h"
#include "TradeMax.h"

//------------------------------------------------------------------------------
void TradeMax::process(const Trade &t)
{
  auto &val = m_tmax[t.getSym()];
  val = std::max(val, t.getPrice());
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
unsigned long TradeMax::getVal(const std::string &sym)
{
  return m_tmax[sym];
}
//------------------------------------------------------------------------------
