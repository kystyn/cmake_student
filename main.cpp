#include <iostream>
#include "png_toolkit.h"
#include "red_filter.h"
#include "threshold.h"

int main( int argc, char *argv[] )
{
    // toolkit filter_name base_pic_name student_pic_name
    // toolkit near test images!
    try
    {
        if (argc != 4)
            throw "Not enough arguments";

        png_toolkit studTool;
        if (!studTool.load(argv[2]))
            std::cout << "Bad file name\n";
        filter::red r("Red");
        filter::threshold t("Threshold");
        filter::base::area a;
        a.top = 0;
        a.left = 0;
        a.bottom = 4;
        a.right = 4;

        auto f = filter::base::filters.find(argv[1]);
        if (f != filter::base::filters.end())
            studTool.applyFilter(*(f->second), a);
        else
            std::cout << "Bad filter name\n";

        if (!studTool.save(argv[3]))
            std::cout << "Could not save picture\n";
    }
    catch (const char *str)
    {
        std::cout << "Error: " << str << std::endl;
        return 1;
    }

    return 0;
}
