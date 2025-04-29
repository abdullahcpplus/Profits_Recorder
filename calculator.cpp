#include<iostream>
#include<mysql.h>
#include<mysqld_error.h>
#include<resultset.h>
#include<windows.h>
#include<conio.h>
#include<string>
using namespace std;
char user[] = "root";
char pass[] = "abcd@12345678";
class operations {
    int sale, totalPcost, totalBcost, totalDelcost,totalSold, totalprofit;
    int buyprice, sellprice, packingcost, delcost, yprofit;
    string todate;
    string name;
    // database
    string dbname = " profits";
    string host = " loaclhost";
public:
    MYSQL* conn;
    operations() {
    conn = mysql_init(NULL);
        cout << "connecting with database...." << endl;
        Sleep(1000);
        system("cls");
        if (!mysql_real_connect(conn, "localhost", user, pass, "profits", 3306, NULL, 0)) {
            cout << "\t\t\t" << mysql_error(conn) << endl;
        }
        else {
            cout << "\t\t connect with database sucessfully" << endl;
            Sleep(1000);
        }
    }
    void setsell() {
        system("cls");
        totalBcost = 0;
        totalPcost = 0;
        totalDelcost = 0;
        totalprofit = 0;
    }
    void enterItems() {
        string iio;
        string iio2;
        system("cls");
        cout << "  ************************* Add items **********************************" << endl;
        cout << "\tEnter current date (yyyy-mm-dd): ";
        cin >> todate;
        cout << "\tEnter how many slippers you sold on today: ";
        cin >> sale;
        cout << "\tEnter total buy price of all slippers:     ";
        cin >> totalBcost;
        cout << "\tEnter total packing cost of all slippers:  ";
        cin >> totalPcost;
        cout << "\tTotal Delivery cost of all slippers:       ";
        cin >> totalDelcost;
        cout << "\tEnter total sold price of all slippers:    ";
        cin >> totalSold;
        totalprofit = totalSold-totalBcost - totalPcost - totalDelcost;
        string ins =
            "INSERT INTO chart (date,Total_sale_today,Total_Buy_cost,packing_cost,delivery_cost,Total_sold_price,total_profit)";
        ins+=
           "VALUES('" +todate+ "', '"+to_string(sale)+"', '"+to_string(totalBcost) + "','"+to_string(totalPcost) + "','"+to_string(totalDelcost)+ "','"+to_string(totalSold) + "','"+to_string(totalprofit) + "')";
        if (mysql_query(conn, ins.c_str())) {
            cout << "ERROR: " << mysql_error(conn) << endl;
        }
        else {
        
        cout << endl;
        cout << endl;
        cout << "NOTE: your data is saved in database" << endl;

        }
        cout << "Press any key to exit: ";
        cin >> iio;
    }

    void showtotals() {
        string iio;
        system("cls");
        cout << "**************************** Profit Claculator *****************************" << endl;
        cout << "\t*********************************************************" << endl;
        cout << "\t                                                         " << endl;
        cout << "\t  Your Totla buying price                  : " << totalBcost << endl;
        cout << "\t  Totla delivery cost of all slippers      : " << totalDelcost << endl;       //somr point missing
        cout << "\t  Total packig cost of all slippers        : " << totalPcost << endl;
        cout << "\t  Total Profit cost of all slippers        : " << totalprofit << endl;
        cout << "\t                                                       " << endl;
        cout << "\t*********************************************************" << endl;
        cout << "Press any key to exit." << endl;
        cin >> iio;
    }

};


int main() {


    operations ahm;
    char cho;
    bool run = true;
    cout << "\n\n\n\n\n\n\n\t\t\tWelcome Ahmad" << endl; \
        Sleep(1000);
    while (run) {
        system("cls");
        cout << "**************************** Profit Claculator *****************************" << endl;
        cout << "\t*********************************************************" << endl;
        cout << "\t**                                                     **" << endl;
        cout << "\t**  1) Add slippers you sell on today.                 **" << endl;
        cout << "\t**  2) claculate your total profit today.              **" << endl;
        cout << "\t**  3) Exit                                            **" << endl;
        cout << "\t**                                                     **" << endl;
        cout << "\t*********************************************************" << endl;
        cout << "Enter your choice: ";
        cin >> cho;
        if (cho == '1') {
            ahm.setsell();
            ahm.enterItems();
        }
        else if (cho == '2') {
            ahm.showtotals();
        }
        else if (cho == '3') {
            system("cls");
            cout << "Goodbye, Have a nice day." << endl;
            Sleep(1500);
            run = false;
        }
        else {
            system("cls");
            cout << "You entered wrong option." << endl;
            cout << "Redircting the perious page." << endl;
            Sleep(1500);
        }
    }

    return 0;
}