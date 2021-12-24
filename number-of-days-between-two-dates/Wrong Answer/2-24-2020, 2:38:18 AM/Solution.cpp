// https://leetcode.com/problems/number-of-days-between-two-dates

class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        int d1 = stoi(date1.substr(8,2));
        int d2 = stoi(date2.substr(8,2));
        
        int m1 = stoi(date1.substr(5,2));
        int m2 = stoi(date2.substr(5,2));
        
        int y1 = stoi(date1.substr(0,4));
        int y2 = stoi(date2.substr(0,4));
        cout << d1 << " " << d2 << " " << y1 << " " << y2 << " " << m1 << " " << m2 <<endl;
        int d = 0;
        int daysl[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
         int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        if(y1 > y2) return 0;
        if(m1 > m2 ) return 0;
        if(d1 > d2) return 0;
        while( m1!= m2 || d1!= d2 || y1!= y2){
            if(y1%4 == 0 && y1%100!=0){
                if(daysl[m1-1] == d1){
                    d1 = 1;
                    if(m1 == 12){
                        m1 = 1;
                        y1++;
                    }
                }else{
                    d1++;
                }
                
            }else{
                if(days[m1-1] == d1){
                    d1 = 1;
                    if(m1 == 12){
                        m1 = 1;
                        y1++;
                    }
                }else{
                    d1++;
                }
            }
            d++;
        }
        return d;
        
    }
};