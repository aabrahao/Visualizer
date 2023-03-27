#include <iostream>
#include <string>
#include "Point.h"


const std::string sample = "/home/bilac/Projects/Visualizer/Publisher/sample.json";
const std::string out = "/home/bilac/Projects/Visualizer/Publisher/out.json";

// https://www.cochoy.fr/boost-property-tree/
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

// Short alias for this namespace
namespace pt = boost::property_tree;

std::string indent (int level) {
    std::string s;
    for (int i = 0; i<level; i++)
        s += "  ";
    return s;
}

void print (pt::ptree &pt, int level = 0) {
    if (pt.empty())
        std::cout << "\"" << pt.data() << "\"";
    else {
        if ( level )
            std::cout << std::endl;
        std::cout << indent (level) << "{" << std::endl;
        for ( auto pos = pt.begin(); pos != pt.end(); ) {
            std::cout << indent (level + 1) << "\"" << pos->first << "\": ";
            print(pos->second, level + 1);
            ++pos;
            if (pos != pt.end())
                std::cout << ",";
            std::cout << std::endl;
        }
        std::cout << indent ( level ) << " }";
    }
    // std::cout << std::endl;
    return;
}

template <typename T>
void put(pt::ptree &node, std::string key, const std::vector<T> values) {
    pt::ptree children;
    for ( auto value : values ) {
        pt::ptree child;
        child.put("", value);
        children.push_back(std::make_pair("", child));
    }
    node.add_child(key, children);
}

int main ( int argc, char *argv[] )
{

    pt::ptree root;
    pt::read_json ( sample, root );

    //print(root, 0);

    std::cout << root.get<std::string>("some.complex.path") << std::endl
              << root.get<std::string>("some.complexx.path","Not found") << std::endl
              << root.get<int>("heightt",-1) << std::endl << std::endl;

    for (auto node = root.begin(); node != root.end(); ++node) {
        std::cout << node->first;
        if (node->second.empty())
            std::cout << " : " << node->second.get_value<std::string>();
        else
            std::cout << " Object";
        std::cout << std::endl;

    }


    pt::ptree color;
    color.put<std::string>("name", "Anthony Abrahao");
    color.put<int>("age", 50);

    put(color, "color", std::vector<int>({1, 2, 3, 4}));

    pt::write_json(out, color);

    return 0;
}
