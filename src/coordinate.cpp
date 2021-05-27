/**
 * TermPong v1
 * 
 * File: coordinate.cpp
 * 
 * Description:
 *  Coordinate class implementation
 * 
 * Author: 
 *  Saurabh Singh (saurabh.s99100@gmail.com)
 *
 * MIT License
 * 
 * Copyright (c) 2021 Saurabh Singh
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 */


#include "coordinate.h"

/**
 * @brief Construct a new coordinate object
 * 
 * @param x 
 * @param y 
 */
coordinate::coordinate(int x, int y)
{
    this->x = x;
    this->y = y;
}

/**
 * @brief Construct a new coordinate object
 */
coordinate::coordinate()
{
    this->x = 0;
    this->y = 0;
}

/**
 * @brief get x coordinate
 * 
 * @return int 
 */
int coordinate::getX()
{
    return this->x;
}

/**
 * @brief get y coordinate
 * 
 * @return int 
 */
int coordinate::getY()
{
    return this->y;
}

/**
 * @brief set x coordinate
 * 
 * @param val 
 */
void coordinate::setX(int val)
{
    this->x = val;
}

/**
 * @brief set y coordinate
 * 
 * @param val 
 */
void coordinate::setY(int val)
{
    this->y = val;
}
