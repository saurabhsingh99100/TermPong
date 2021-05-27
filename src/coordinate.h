#ifndef __COORDINATE_H
#define __COORDINATE_H

/**
 * @brief Coordinate class
 * 
 */
class coordinate
{
    private:
    int x, y;

    public:
    /**
     * @brief Construct a new coordinate object
     * 
     * @param x 
     * @param y 
     */
    coordinate(int x, int y);
    
    /**
     * @brief Construct a new coordinate object
     */
    coordinate();
    
    /**
     * @brief get x coordinate
     * 
     * @return int 
     */
    int getX();

    /**
     * @brief get y coordinate
     * 
     * @return int 
     */
    int getY();

    /**
     * @brief set x coordinate
     * 
     * @param val 
     */
    void setX(int val);

    /**
     * @brief set y coordinate
     * 
     * @param val 
     */
    void setY(int val);
};

#endif // __COORDINATE_H