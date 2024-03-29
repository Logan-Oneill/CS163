//Logan Miller
//CS163
//Program #1 Vehicle_List ADT

#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

//Second Node for vehicle features
struct FeatureNode
{
    char * feature;
    FeatureNode * next;
};

//A vehicle is made up of 10 different features, 9 char *'s and a node that 
//will be used to create a LLL of features that will also be char *'s
struct Vehicle
{
    char * manufacturer;
    char * model;
    char * year;
    char * price;
    char * fuelType;
    char * fuelEff;
    char * vehicleType;
    char * engine;
    char * numPeople;
    
    FeatureNode * featureHead;
    FeatureNode * featureTail;
};

//Node used for building a LLL of vehicles. Has data for a vehicle as well as
//an integer that will be used for assigning a point rating of each vehicle
struct Node
{
    Vehicle vehicle;
    int pointVal;
    Node * next;
};

//Class Vehicle_List is an ADT that manages a LLL of vehicles that are loaded
//in from an external text file.
class Vehicle_List
{

public:
    Vehicle_List();
    ~Vehicle_List();
    bool sortMan();
    bool getDeterminants(char * &unwanted, char * &wanted);
    bool findVehicle(char * &car);
private:
    //private data members
    Node * head;
    Node * tail;
    //Reads in data from an external data file parses the information, creates
    //a node from the data, passes node to build list
    bool fileRead();
    bool buildList(Node * &temp);
    bool buildNestedList(Node * &temp, char * &tempArr);
    bool nestedList(Node * &temp, FeatureNode * &tempFeat);
    bool assignUnwanted(char * &unwanted);
    bool assignWanted(char * &wanted);
    bool sortWishHelper();
    bool sortManHelper();
    bool displayList();
    bool sortWishList();
};
