class Solution {
public:
int f(string date,vector<int>& cumMonthDays){
    int month =stoi(date.substr(0,2));
    int day =stoi(date.substr(3));
    return cumMonthDays[month-1]+day;
}
    int countDaysTogether(string a, string b, string c, string d) {
    vector<int> monthDays={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<int> cumMonthDays(13,0);
        cumMonthDays[1]=31;
        for(int i=2;i<13;i++){
            cumMonthDays[i] = cumMonthDays[i-1]+monthDays[i-1];
        }
        return max(0, min(f(b,cumMonthDays), f(d,cumMonthDays)) - max(f(a,cumMonthDays), f(c,cumMonthDays)) + 1);
    }
};