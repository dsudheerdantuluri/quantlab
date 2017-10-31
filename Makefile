all: tradecal

Trade.o: Trade.cc
					g++ -std=c++11 -c Trade.cc
			
TradeStreamReader.o: TradeStreamReader.cc TradeStreamReader.h
											g++ -std=c++11 -c TradeStreamReader.cc

TradeProcessor.o: TradeProcessor.cc TradeProcessor.h
											g++ -std=c++11 -c TradeProcessor.cc

TradeMTGap.o: TradeMTGap.cc TradeMTGap.h TradeOperation.h
											g++ -std=c++11 -c TradeMTGap.cc

TradeVolume.o: TradeVolume.cc TradeVolume.h TradeOperation.h
											g++ -std=c++11 -c TradeVolume.cc

TradeWAP.o: TradeWAP.cc TradeWAP.h TradeOperation.h
											g++ -std=c++11 -c TradeWAP.cc

TradeMax.o: TradeMax.cc TradeMax.h TradeOperation.h
											g++ -std=c++11 -c TradeMax.cc

tradecal.o: tradecal.cc
					g++ -std=c++11 -c tradecal.cc 
					
tradecal:	tradecal.o TradeStreamReader.o Trade.o TradeProcessor.o TradeMTGap.o TradeVolume.o TradeWAP.o TradeMax.o 
					g++ -std=c++11 -o tradecal tradecal.o TradeStreamReader.o Trade.o TradeProcessor.o TradeMTGap.o TradeVolume.o TradeWAP.o TradeMax.o

clean:	
				rm -rf tradecal *.o
