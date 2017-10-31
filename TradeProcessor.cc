#include <fstream>

#include "Trade.h"
#include "TradeOperation.h"
#include "TradeProcessor.h"

//------------------------------------------------------------------------------
void TradeProcessor::addOperation(TradeOperation *p_to)
{
  m_ops.push_back(p_to);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void TradeProcessor::process(const Trade &t)
{
  for (auto p_op : m_ops) {
    p_op->process(t);
  }

  m_syms.insert(t.getSym());
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void TradeProcessor::dumpResults(const std::string &fileName)
{
  std::ofstream ofs(fileName);
  for (auto sym: m_syms) {
    ofs << sym;
    for(auto p_op: m_ops) {
      ofs << "," << p_op->getVal(sym);
    }
    ofs << "\n";
  }
}
//------------------------------------------------------------------------------
