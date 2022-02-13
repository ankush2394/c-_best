#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;

class User {
public:
    string userName;
    string userPhoneNumber;
    string userPin;
    string userId;

    User() = default;
    User(string name, string phoneNumber,string pin) {
        userName = name;
        userPhoneNumber = phoneNumber;
        userPin = pin;
        userId = getUserId(name, phoneNumber); //any hash
    }

    string getUserId(string name , string phoneNumber) {
        return name+phoneNumber;
    }
};

class Restaurant {
public:
    string restName, resPhoneNumber;
    set<string> servicePinCodes;
    string foodName;
    int foodPrice, quantity;
    int rating=0;
    int count = 0;
    float actualRating=0;
    string restId ;

    Restaurant() = default;
    Restaurant (string name,string resPhoneNumber, set<string> pinCodes,string dishName, int price,int qty) {
        restName = name;
        servicePinCodes = pinCodes;
        foodName = dishName;
        foodPrice = price;
        quantity = qty;
        this->resPhoneNumber = resPhoneNumber;
        restId = getRestId(restName, this->resPhoneNumber);
    }

    string getRestId(string restName , string resPhoneNumber) {
        return restName+resPhoneNumber;
    }
};

class Mappings {
public:

    Mappings() {}
    static map<string, User> userMap;
    static map<string, Restaurant> restaurantMap;
    static map<string, vector<Restaurant>> userPinRestaurantsMap;
    static map<string, vector<Restaurant>> userRestMap;

};

//INITIALISATION OF STATICS
map<string, User> Mappings::userMap;
map<string, Restaurant> Mappings::restaurantMap;
map<string, vector<Restaurant>> Mappings::userRestMap;
map<string, vector<Restaurant>> Mappings::userPinRestaurantsMap;


void register_restaurant(string name,string restPhone, set<string> pinCodes,string dishName, int price, int qty) {
    Restaurant res = Restaurant(name, restPhone, pinCodes, dishName, price, qty);
    Mappings::restaurantMap[name+restPhone] = (res);

    for (auto it = pinCodes.begin();it!=pinCodes.end();it++) {
        Mappings::userPinRestaurantsMap[*it].push_back(res);
    }
}

void register_user(string name, string phoneNumber,string pin) {
    Mappings::userMap[name+phoneNumber] = User(name,phoneNumber, pin);
}

string update_quantity(string restName, string restPhone, int qty) {
    Restaurant rest = Mappings::restaurantMap[restName+restPhone];
    rest.quantity  += qty;
    Mappings::restaurantMap[restName+restPhone]= rest;
    return restName +" "+ to_string(rest.quantity);
}


string place_order(string userName, string restName, int qty, string userPhone, string restPhone) {

    Restaurant rest = Mappings::restaurantMap[restName+ restPhone];
    User us = Mappings::userMap[userName+ userPhone];

    if (rest.quantity >= qty && rest.servicePinCodes.find(us.userPin) != rest.servicePinCodes.end()) {
        rest.quantity -= qty;
        Mappings::restaurantMap[restName+ restPhone] = rest;
        Mappings::userRestMap[userName+ userPhone].push_back(rest); //userRestMap[us].insert(rest);
        return "Order Placed Successfully.";
    } else {
        return "Cannot place order";
    }
}

string rateRestaurant(string userName, string userPhone, string restName, string restPhone, int rating) {

    User us = Mappings::userMap[userName+ userPhone];
    Restaurant rest = Mappings::restaurantMap[restName+ restPhone];

    vector<Restaurant> restaurants= Mappings::userRestMap[us.userName+us.userPhoneNumber];
    if (!restaurants.empty()) {
        for(int i=0;i<restaurants.size();i++) {
            if (restaurants[i].restId == rest.restId) {
                rest.rating += rating;
                rest.count+=1;
                rest.actualRating = (float)rest.rating/(float)rest.count;
                Mappings::restaurantMap[restaurants[i].restName+restaurants[i].resPhoneNumber] = rest;
                return "Rating Done";
            }
        }
    }

    return "PLease do order first";
}


bool compare(const Restaurant a , const Restaurant b) {
    if (a.actualRating > b.actualRating) {
        return true;
    } else if (a.actualRating == b.actualRating){
        if (a.foodPrice > b.foodPrice) {return true;}
    }
    return false;
}

vector<Restaurant> show_restaurant(string userName, string userPhone) {

    User us = Mappings::userMap[userName+ userPhone];
    string userPin = us.userPin;

    vector<Restaurant> restaurants = Mappings::userPinRestaurantsMap[userPin];
    sort(restaurants.begin(),restaurants.end(),compare);
    return restaurants;

}




//int main() {
//    // your code goes here
//    register_restaurant("KFC", "9599673279", set<string>{"124","123"}, "chickenTikka", 450, 10);
//    register_user("ankush", "9599673270", "123");
//    register_user("aniket", "9136361369", "124");
//
//    cout<<update_quantity("KFC", "9599673279",15)<<endl;
//
//    cout<<place_order("ankush", "KFC", 20,"9599673270", "9599673279")<<endl;
//    cout<<place_order("aniket", "KFC", 20,"9136361369", "9599673279")<<endl;
//
//
//    cout<<show_restaurant("ankush", "9599673270")[0].restName<<endl;
//
//    cout<<Mappings::restaurantMap["KFC9599673279"].quantity<<endl;
//
//    cout<<rateRestaurant("ankush", "9599673270", "KFC", "9599673279", 4)<<endl;
//
//    cout<<Mappings::restaurantMap["KFC9599673279"].actualRating<<endl;
//
//    return 0;
//}
