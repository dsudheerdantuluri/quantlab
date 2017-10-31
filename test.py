import re;
import csv;
import sys;

hash = {};
with open('input.csv', 'rb') as csvfile:
  reader = csv.reader(csvfile, delimiter=',');
  for row in reader: 
    sym = row[1];
    time = int(row[0]);
    qty = int(row[2]);
    price = int(row[3]);
    if (not hash.has_key(sym)):
      hash[sym] = {};
      hash[sym][qty] = 0;
      hash[sym][price] = 0;
      hash[sym]['tc'] = 0;
      hash[sym]['cq'] = 0;
      hash[sym]['mp'] = 0;
      hash[sym]['mtg'] = 0;
      hash[sym]['pt'] = time;
    hash[sym]['cq'] += qty
    hash[sym]['mp'] = max(hash[sym]['mp'], price);
    hash[sym]['tc'] += price * qty;
    hash[sym]['mtg'] = max(hash[sym]['mtg'], time - hash[sym]['pt']);
    hash[sym]['pt'] = time;

for key in sorted(hash.keys()):
  print(key + "," + str( hash[key]['mtg']) + "," + str(hash[key]['cq']) + "," + str(hash[key]['tc']/hash[key]['cq']) + "," + str(hash[key]['mp']));
