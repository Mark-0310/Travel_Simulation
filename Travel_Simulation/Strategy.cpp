#include "Strategy.h"
#include <iostream>
#include <set>
#include <QtSql>

using std::set;
using std::cout;
using std::endl;

Strategy::Strategy(int t, string d1, string d2, Time T)
{
    type = t;
    depart = d1;
    dest = d2;
    expectedTime = T;
}

void Strategy::startStrategy()
{
    switch (type) {
        case 1:
            cheapestStrategy();
            break;
        case 2:
            fastestStrategy();
            break;
        case 3:
            timeLimitStrategy();
            break;
    }
}

void Strategy::cheapestStrategy()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    //std::cout << QDir::currentPath().toStdString() << std::endl;
    db.setDatabaseName(QDir::currentPath() + QString("/travel_query.db"));
    if (!db.open())
        std::cerr << "Failed to connect to database" << std::endl;
   // db.exec("select * from time_table");
    QSqlQuery query(db);
    query.exec("select * from time_table");
    vector<string> cityList;
    set<string> _set;
    string str;
    while (query.next()) {
        str = query.value("Dep").toString().toStdString();
        _set.insert(str);
    }
    set<string>::iterator iter;

    cout << "录入城市：" << endl;
    for (iter = _set.begin(); iter != _set.end(); iter++) {
        cityList.push_back(*iter);
        cout << *iter << " ";
    }
    cout << std::endl << cityList.end() - cityList.begin() << endl;

}

void Strategy::fastestStrategy()
{

}

void Strategy::timeLimitStrategy()
{

}
