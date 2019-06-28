#pragma once

namespace r2d2::led_strip {
    /**
     *  \brief
     *  Struct which contains red, green and blue 
     */
    struct rgb_s {
        uint8_t red;
        uint8_t green;
        uint8_t blue;

        /**
         * \brief
         * == operator
         *
         * @return returns true/false if equal too  
         */    
        bool operator == (const rgb_s &rhs) const {
            return  this->red     == rhs.red      &&
                    this->green   == rhs.green    &&
                    this->blue    == rhs.blue; 
        
        }
    };
}