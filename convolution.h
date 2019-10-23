#ifndef CONVOLUTION_H
#define CONVOLUTION_H

#include <array>
#include "base_filter.h"

namespace filter {
template<int N>
class convolution : public base {
public:
    convolution( std::string const &filterName, std::array<std::array<double, N>, N> const &ker ) :
        base(filterName), ker(ker) {}

    void operator()( image_data &imgData, area &ar ) override
    {/*
        auto convolute =
                [&imgData, cpp, &indices, matrixSize]( int pixelX, int pixelY ) -> void
        {
            int
                xStart = std::max(0, pixelX - matrixSize / 2),
                yStart = std::max(0, pixelY - matrixSize / 2),
                xEnd = std::min(imgData.w - 1, pixelX + matrixSize / 2),
                yEnd = std::min(imgData.h - 1, pixelY + matrixSize / 2);

            int i = 0;
            for (int y = yStart; y <= yEnd; y++)
                for (int x = xStart; x <= xEnd; x++)
                    indices[i++] = (y * imgData.w + x) * cpp  + channel;

            std::sort(indices.begin(),
                      indices.begin() + (yEnd - yStart + 1) * (xEnd - xStart + 1),
                        [&imgData]( int idx1, int idx2 ) -> bool
                        {
                            return imgData.pixels[idx1] < imgData.pixels[idx2];
                        });

            for (int i = 0; i < (yEnd - yStart + 1) * (xEnd - xStart + 1) / 2; i++)
                imgData.pixels[indices[i]] = 0;
        };

        auto cpp = imgData.compPerPixel;
        if (cpp == 4 || cpp == 3) {
            int y = ar.top == 0 ? 0 : imgData.h / ar.top;
            for (; y < imgData.h / ar.bottom; y++) {
                int x = ar.left == 0 ? 0 : imgData.w / ar.left;
                for (; x < imgData.w / ar.right; x++)
                {
                    imgData.pixels[(y * imgData.w + x) * cpp + 0] = 255;
                    imgData.pixels[(y * imgData.w + x) * cpp + 1] = 0;
                    imgData.pixels[(y * imgData.w + x) * cpp + 2] = 0;
                    imgData.pixels[(y * imgData.w + x) * cpp + 3] = 255;
                }
            }
        }*/
    }

private:
    std::array<std::array<double, N>, N> ker;
};
}

#endif // CONVOLUTION_H
