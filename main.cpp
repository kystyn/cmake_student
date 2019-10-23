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
        if (argc != 3)
            throw "Not enough arguments";

        png_toolkit studTool;

        if (!studTool.load(argv[2]))
        {
            std::cout << "Bad file name\n";
            return 0;
        }
        filter::red r("Red");
        filter::threshold t("Threshold");
        filter::base::area a;

        a.top = 2;
        a.left = 0;
        a.bottom = 1;
        a.right = 1;
        studTool.applyFilter(r, a);

        a.top = 0;
        a.left = 0;
        a.bottom = 2;
        a.right = 2;
        studTool.applyFilter(t, a);


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
