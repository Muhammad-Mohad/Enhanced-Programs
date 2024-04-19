#include "Circle.h"
#include "Triangle.h"

int main()
{
    Circle c(3, 4, 2.5);
    c.Print();


    /*
        The Output is:

        Point() Called

        Circle() Called
 
        The centre of the circle is (3 , 4) and radius is 2.5

        ~Circle() Called

        ~Point() Called
    */

    Triangle obj(1, 0, 0, 1, 0, 0);
    obj.Print();

    /*
    
        The Output is:

        Point() Called

        Circle() Called

        The centre of the circle is (3 , 4) and radius is 2.5

        Point() Called

        Point() Called

        Point() Called

        Triangle() Called

        The coordinates of the corners of the triangle are (1 , 0), (0 , 1) and (0 , 0)

        ~Triangle() Called

        ~Point() Called

        ~Point() Called

        ~Point() Called

        ~Circle() Called

        ~Point() Called
    

    */

    return 0;
}




