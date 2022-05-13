
#include <iostream>
#include "Client.h"
#include<boost/property_tree/ptree.hpp>
#include<boost/property_tree/json_parser.hpp>

std::string getFieldFromJson(std::string json, std::string field);

int main()
{
    Client client;
    std::string res = client.getResponse("www.twitch.tv");


    std::cout << "query:" << " " << getFieldFromJson(res, "query") << '\n';
    std::cout << "country:" << " "<< getFieldFromJson(res, "status") << '\n';
    std::cout << "country:" << " "<< getFieldFromJson(res, "country") << '\n';
    std::cout << "countryCode:" << " "<< getFieldFromJson(res, "countryCode") << '\n';
    std::cout << "region:" << " "<< getFieldFromJson(res, "region") << '\n';
    std::cout << "regionName:" << " " << getFieldFromJson(res, "regionName") << '\n';
    std::cout << "city:" << " " << getFieldFromJson(res, "city") << '\n';
    std::cout << "zip:" << " " << getFieldFromJson(res, "zip") << '\n';
    std::cout << "lat:" << " " << getFieldFromJson(res, "lat") << '\n';
    std::cout << "lon:" << " " << getFieldFromJson(res, "lon") << '\n';
    std::cout << "timezone:" << " " << getFieldFromJson(res, "timezone") << '\n';
    std::cout << "isp:" << " " << getFieldFromJson(res, "isp") << '\n';
    std::cout << "org:" << " " << getFieldFromJson(res, "org") << '\n';
    std::cout << "as:" << " " << getFieldFromJson(res, "as")  << '\n';
   
    
    return 0;
}
std::string getFieldFromJson(std::string json, std::string field)
{
    std::stringstream jsonEncoded(json);
    boost::property_tree::ptree root;
    boost::property_tree::read_json(jsonEncoded, root);

    if (root.empty())
        return "";

    return root.get<std::string>(field);

}
      // To test use this: https://ip-api.com/docs/api:json#test


