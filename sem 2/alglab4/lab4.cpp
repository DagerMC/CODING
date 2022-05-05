#include <iostream>
#include "hashmap.h"

int main() {
    hashmap<int> map;
    map["Intellect"] = 100;
    map["Jaba"] = 25;
    map["Jabab"] = 30;
    map["Gordan"] = 55;
    map["Baka Mitai"] = 45;
    map.print_items();
    map.delete_("Jaba");

    hashmap<std::string> mapp;
    mapp["In The End"] = "Linkin Park";
    mapp["Prism"] = "Lindsey Stirling";
    mapp["Point it Black"] = "The Rolling Stones";
    mapp["Baka Mitai"] = "Senshi Ongaku";
    mapp["Killer Queen"] = "Queen";
    mapp["Animal I Have Become"] = "Three Gays Grace";
    mapp["BLOODY STREAM"] = "Coda";
    mapp["Come on Closer"] = "Jam";
    mapp["Relax, take it easy"] = "MIKA";
    mapp["99.9"] = "MOB CHOIR feat. sajou no";
    mapp["Say So"] = "Doja Cat";
    mapp["Duality"] = "Slipknot";
    mapp["Beat It"] = "Michael Jackson";
    mapp["Otherside"] = "Red Hot Chili Peppers";
    mapp["Nightcall"] = "Kavinsky";
    map.print_items();
    mapp.print_items();

    return 0;
}