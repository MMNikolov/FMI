#include "date.hpp"

int main(){
    //Input files
    date calendarDate;
    date calendarDate2;
    std::ifstream is("year.txt");
    if (!is)
    {
        std::cerr << "cannot open input stream file";
        return 0;
    }
    
    calendarDate.readText(is);
    calendarDate2.readText(is);

    calendarDate.printDate();
    calendarDate2.printDate();

    //Output files
    std::ofstream os("yearOutput.txt");
    if (!os)
    {
        std::cerr << "There was a problem with the output stream file";
        return 0;
    }
    
    calendarDate.writeText(os);

    //Which day of the week it is


    //Date difference
    std::cout << "difference in days: ";
    printDateDifference(calendarDate2, calendarDate);

    is.close(); os.close();
    return 0;
}