#include <hwlib.hpp>
#include <HC_SR04_c.hpp>

//#include <iostream>
#include <fstream>
int main(){
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(1000);
    hwlib::cout << "this works via arduino" << hwlib::endl;
    auto echo_pin = hwlib::target::pin_in(hwlib::target::pins::d7);
    auto trigger_pin = hwlib::target::pin_out(hwlib::target::pins::d8);
 
    R2D2::Distance::HC_SR04_c sensor(echo_pin, trigger_pin);
    //std::ofstream sonar_file;
    //sonar_file.open("sonar_test_results.txt");
    char test_char = 'y';
    while(test_char == 'y'){
        hwlib::wait_ms(100);
        hwlib::cout << sensor.get_distance()  <<"\n";
        //sonar_file << sensor.get_distance() << " centimeters \n";
        hwlib::cout << "another test?: \n";
        hwlib::cin >> test_char;
    }
    //sonar_file.close();
}