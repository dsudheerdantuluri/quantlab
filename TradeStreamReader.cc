#include "TradeStreamReader.h"
#include "Trade.h"
#include <sstream>

//------------------------------------------------------------------------------
TradeStreamReader::TradeStreamReader(const std::string &file)
{
  m_fs.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
  m_fs.open(file, std::ifstream::in);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
Trade TradeStreamReader::next()
{
  std::string line;
  getline(m_fs, line);
  std::vector<std::string> tokens = split(line, ',');
  return Trade(stoul(tokens[0]), 
               tokens[1], 
               stoul(tokens[2]), 
               stoul(tokens[3]));
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
TradeStreamReader::~TradeStreamReader()
{
  if (m_fs.is_open()) {
    m_fs.close();
  }
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
std::vector<std::string> TradeStreamReader::split(const std::string& s, 
                                                  char delimiter)
{
  std::vector<std::string> tokens;
  std::string token;
  std::istringstream tokenStream(s);
  while (std::getline(tokenStream, token, delimiter)) {
    tokens.push_back(token);
  }
  return tokens;
}
//------------------------------------------------------------------------------
