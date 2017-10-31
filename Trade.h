#include <string>

//------------------------------------------------------------------------------
class Trade {

  public:
    Trade(unsigned long, const std::string &, unsigned long, unsigned long);
    ~Trade() = default;

    Trade(const Trade &) = default;
    Trade(Trade &&) = default;

    Trade &operator=(const Trade &) = default;
    Trade &operator=(Trade &&) = default;

    unsigned long getTime() const { return m_time; }
    std::string getSym() const { return m_sym; }
    unsigned long getPrice() const { return m_price; }
    unsigned long getQty() const { return m_qty; }
    
  private:
    unsigned long m_time;
    const std::string m_sym;
    unsigned long m_price;
    unsigned long m_qty;
};
//------------------------------------------------------------------------------
