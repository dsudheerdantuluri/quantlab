#include <string>
#include <fstream>
#include <vector>

class Trade;

//------------------------------------------------------------------------------
class TradeStreamReader {

  public:
    TradeStreamReader(const std::string &);
    ~TradeStreamReader();

    TradeStreamReader(const TradeStreamReader &) = delete;
    TradeStreamReader(TradeStreamReader &&) = delete;

    TradeStreamReader &operator=(const TradeStreamReader &) = delete;
    TradeStreamReader &operator=(TradeStreamReader &&) = delete;

    bool hasNext() { return (m_fs.peek() != EOF); }

    Trade next();

  private:
    std::vector<std::string> split(const std::string& s, char delimiter);

  private:
    std::ifstream m_fs;
};
//------------------------------------------------------------------------------
