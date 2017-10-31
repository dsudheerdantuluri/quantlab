#include "Trade.h"

//------------------------------------------------------------------------------
Trade::Trade(unsigned long time, 
             const std::string &sym, 
             unsigned long qty, 
             unsigned long price) : m_time(time), 
                                    m_sym(sym), 
                                    m_qty(qty), 
                                    m_price(price)
{

}
//------------------------------------------------------------------------------
