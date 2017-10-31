#include <algorithm>

#include "Trade.h"
#include "TradeVolume.h"

//------------------------------------------------------------------------------
void TradeVolume::process(const Trade &t)
{
  m_tvol[t.getSym()] += t.getQty();
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
unsigned long TradeVolume::getVal(const std::string &sym)
{
  return m_tvol[sym];
}
//------------------------------------------------------------------------------
