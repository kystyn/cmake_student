#include <iostream>
#include <fstream>
#include "png_toolkit.h"
#include "red_filter.h"
#include "threshold.h"
#include "convolution.h"

std::istream & operator>>( std::istream &is, filter::base::area &ar )
{
    is >> ar.top >> ar.left >> ar.bottom >> ar.right;
    return is;
}

int main( int argc, char *argv[] )
{
    // toolkit config base_pic_name student_pic_name
    // toolkit near test images!
    try
    {
        if (argc != 4)
            throw "Not enough arguments";

        png_toolkit studTool;

        if (!studTool.load(argv[2]))
        {
            std::cout << "Bad file name\n";
            return 0;
        }
        filter::red r("Red");
        filter::threshold t("Threshold");
        filter::convolution<3> blur("Blur",
            std::array<std::array<double, 3>, 3>{
                std::array<double, 3>{1.0, 1.0, 1.0},
                {1.0, 1.0, 1.0},
                {1.0, 1.0, 1.0}
            });
        filter::convolution<3> border("Border",
            std::array<std::array<double, 3>, 3>{
                std::array<double, 3>{-1.0, -1.0, -1.0},
                {-1.0, 9.0, -1.0},
                {-1.0, -1.0, -1.0}
            });


        std::ifstream ifs(argv[1]);
        if (!ifs)
            throw  "Bad file name";

        studTool.load(argv[2]);
        while (ifs)
        {
            std::string filterName;
            filter::base::area ar;
            ifs >> filterName >> ar;

            if (filterName.empty())
                break;

            auto f = filter::base::filters.find(filterName);
            if (f != filter::base::filters.end())
                studTool.applyFilter(*(f->second), ar);
            else
                throw "Bad filter";
        }

        if (!studTool.save(argv[3]))
            throw "Could not save picture";

        std::cout << "OK\n";
    }
    catch (const char *str)
    {
        std::cout << "Error: " << str << std::endl;
        return 1;
    }

    return 0;
}
