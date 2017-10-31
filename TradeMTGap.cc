#include <algorithm>

#include "Trade.h"
#include "TradeMTGap.h"

//------------------------------------------------------------------------------
void TradeMTGap::process(const Trade &t)
{
  std::string sym(t.getSym());
  auto time = t.getTime();
  auto it = m_mtg.find(sym);
  if (it == m_mtg.end()) {
    m_mtg[sym] = {0,time}; 
    return;
  }
  auto &val = it->second; 
  val.first = std::max(val.first, time - val.second);
  val.second = time; 
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
unsigned long TradeMTGap::getVal(const std::string &sym)
{
  return m_mtg[sym].first;
}
//------------------------------------------------------------------------------
