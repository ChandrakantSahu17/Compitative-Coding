class UndergroundSystem {
    unordered_map< unsigned int, pair< string, unsigned int > > buffer;
    map< pair< string, string>, pair< unsigned int, double > > DB; 
public:
    
    void checkIn(int id, string stationName, int t) {
        buffer[id] = make_pair( stationName, t );
    }
    
    void checkOut(int id, string stationName, int t) {
        pair< string, unsigned int >& p = buffer[ id ];
        pair< string, string > key = make_pair( p.first, stationName);
        
        if( DB.find( key ) != DB.end() ){
            pair< unsigned int, double >& value = DB[key];
            value.first++;
            value.second += t - p.second;
        }
        else{
            pair< unsigned int, double > value = make_pair( 1, t - p.second );
            DB[key] = value;
        }     
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair< string, string > key = make_pair( startStation, endStation);
        pair< unsigned int, double >& value = DB[key];
        double res = value.second / value.first;
        return res;
    }
};
