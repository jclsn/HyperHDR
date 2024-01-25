/* Image.cpp
*
*  MIT License
*
*  Copyright (c) 2020-2024 awawa-dev
*
*  Project homesite: https://github.com/awawa-dev/HyperHDR
*
*  Permission is hereby granted, free of charge, to any person obtaining a copy
*  of this software and associated documentation files (the "Software"), to deal
*  in the Software without restriction, including without limitation the rights
*  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*  copies of the Software, and to permit persons to whom the Software is
*  furnished to do so, subject to the following conditions:
*
*  The above copyright notice and this permission notice shall be included in all
*  copies or substantial portions of the Software.

*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*  SOFTWARE.
*/

#ifndef PCH_ENABLED
	#include <utils/Image.h>
#endif

template <typename ColorSpace>
Image<ColorSpace>::Image() :
	Image(1, 1)
{
}

template <typename ColorSpace>
Image<ColorSpace>::Image(unsigned width, unsigned height) :
	_sharedData(new ImageData<ColorSpace>(width, height))
{
}

template <typename ColorSpace>
Image<ColorSpace>::Image(const Image<ColorSpace>& other) :
	_sharedData(other._sharedData)
{
}

template <typename ColorSpace>
Image<ColorSpace>& Image<ColorSpace>::operator=(const Image<ColorSpace>& other)
{
	_sharedData = other._sharedData;
	return *this;
}

template <typename ColorSpace>
Image<ColorSpace>& Image<ColorSpace>::operator=(Image<ColorSpace>&& other) noexcept
{
	_sharedData = std::move(other._sharedData);
	return *this;
}

template <typename ColorSpace>
QString Image<ColorSpace>::adjustCache()
{
	return ImageData<ColorSpace>::adjustCache();
}

template <typename ColorSpace>
bool Image<ColorSpace>::setBufferCacheSize() const
{
	return _sharedData->setBufferCacheSize();
}

template <typename ColorSpace>
bool Image<ColorSpace>::checkSignal(int x, int y, int r, int g, int b, int tolerance)
{
	return _sharedData->checkSignal(x, y, r, g, b, tolerance);
}

template <typename ColorSpace>
void Image<ColorSpace>::fastBox(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint8_t r, uint8_t g, uint8_t b)
{
	_sharedData->fastBox(x1, y1, x2, y2, r, g, b);
}

template <typename ColorSpace>
void Image<ColorSpace>::gradientHBox(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint8_t r, uint8_t g, uint8_t b)
{
	_sharedData->gradientHBox(x1, y1, x2, y2, r, g, b);
}

template <typename ColorSpace>
void Image<ColorSpace>::gradientVBox(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint8_t r, uint8_t g, uint8_t b)
{
	_sharedData->gradientVBox(x1, y1, x2, y2, r, g, b);
}

template <typename ColorSpace>
unsigned Image<ColorSpace>::width() const
{
	return _sharedData->width();
}

template <typename ColorSpace>
unsigned Image<ColorSpace>::height() const
{
	return _sharedData->height();
}

template <typename ColorSpace>
const ColorSpace& Image<ColorSpace>::operator()(unsigned x, unsigned y) const
{
	return _sharedData->operator()(x, y);
}

template <typename ColorSpace>
ColorSpace& Image<ColorSpace>::operator()(unsigned x, unsigned y)
{
	return _sharedData->operator()(x, y);
}

template <typename ColorSpace>
void Image<ColorSpace>::resize(unsigned width, unsigned height)
{
	_sharedData->resize(width, height);
}

template <typename ColorSpace>
uint8_t* Image<ColorSpace>::rawMem()
{
	return _sharedData->rawMem();
}

template <typename ColorSpace>
const uint8_t* Image<ColorSpace>::rawMem() const
{
	return _sharedData->rawMem();
}

template <typename ColorSpace>
size_t Image<ColorSpace>::size() const
{
	return _sharedData->size();
}

template <typename ColorSpace>
void Image<ColorSpace>::clear()
{
	_sharedData->clear();
}

template class Image<ColorRgb>;
