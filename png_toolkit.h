#ifndef PNG_TOOLKIT_H
#define PNG_TOOLKIT_H

#include <string>
#include "base_filter.h"
#include "image_data.h"

class png_toolkit
{
public:
    enum class Error {
        WrongSize,
        WrongFormat,
        Ok
    };

    png_toolkit();
    ~png_toolkit();
    bool load( std::string const &pictureName );
    bool save( std::string const &pictureName );
    image_data getPixelData( void ) const;
    void applyFilter( filter::base &f, filter::base::area const &ar );

private:
    image_data imgData;
};

#endif // PNG_TOOLKIT_H
