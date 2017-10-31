#include <iostream>
#include <memory>
#include <exception>

#include "Trade.h"
#include "TradeStreamReader.h"
#include "TradeProcessor.h"

#include "TradeMTGap.h"
#include "TradeVolume.h"
#include "TradeMax.h"
#include "TradeWAP.h"

//------------------------------------------------------------------------------
int main()
{
  std::shared_ptr<TradeOperation> p_mtg = std::make_shared<TradeMTGap>();
  std::shared_ptr<TradeOperation> p_tv = std::make_shared<TradeVolume>();
  std::shared_ptr<TradeOperation> p_wap = std::make_shared<TradeWAP>();
  std::shared_ptr<TradeOperation> p_tm = std::make_shared<TradeMax>();

  TradeProcessor tp;
  tp.addOperation(p_mtg.get());
  tp.addOperation(p_tv.get());
  tp.addOperation(p_wap.get());
  tp.addOperation(p_tm.get());

  try {
    TradeStreamReader tr("input.csv");
    while (tr.hasNext()) {
      Trade t = tr.next();
      tp.process(t);
    }

    tp.dumpResults("output.csv");
  } catch(std::exception &e) {
    std::cout << e.what() << '\n';
  }

  return 0;
}
//------------------------------------------------------------------------------
