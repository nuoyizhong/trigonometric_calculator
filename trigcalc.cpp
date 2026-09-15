#include <iostream>
#include <cmath>

int main();
double getResult();
double Rcalculation(double radians);
double DegreesToRadians(double degrees);


int main() {
    double result;
    std::cout << "this is a trignometry calculator!" << '\n';
    result = getResult();
    if ( result == -999.0 ){
        std::cout << "sorry, your operation request is invalid. " << '\n';
    }
    else if ( result == -998.0 ){
        std::cout << "your result is: " << " DNE " << '\n';
    }
    else{
    std::cout << "your result is: " << result << '\n';
    }
    std::cout << "thank you for using the trig calculator!" << '\n';
    return 0;
}

double getResult(){
    double number;
    char type;
    double result;
    std::cout << "entering your number" << '\n';
    std::cin >> number;
    std::cout << "entering R for Radians / D for Degrees" << '\n';
    std::cin >> type;
    switch (type){
        case 'R': 
            result = Rcalculation(number);
            break;
        case 'D':
            result = Rcalculation(DegreesToRadians(number));
            break;
        default: 
            std::cout << "please enter R for Radians or D for Degrees ONLY" << '\n';
            return getResult();
    }
    return result;
}

double Rcalculation(double radians){
    int choice;
    std::cout << "which trig operation you want to do?" << '\n';
    std::cout << "enter the corresponding number:" << '\n';
    std::cout << "1.sine" << '\n';
    std::cout << "2.cosine" << '\n';
    std::cout << "3.tangent" << '\n';
    std::cout << "4.cosecant" << '\n'; 
    std::cout << "5.secant" << '\n';
    std::cout << "6.cotangent" << '\n';
    std::cout << "7.arcsine" << '\n';
    std::cout << "8.arccosine" << '\n';
    std::cout << "9.arctangent" << '\n';
    do{
        std::cin >> choice;
        if (choice < 1 || choice > 9){
            std::cout << "invalid choice" << '\n';
            std::cout << "please only enter number 1-9" << '\n';
        }
    }while (choice < 1 || choice > 9);
    switch (choice){
        case 1:
            return sin(radians);
        case 2:
            return cos(radians);
        case 3:
            return tan(radians);
        case 4:
        if ( sin(radians) == 0 ){
            return -999.0;
        }
        else{
            return 1/sin(radians);
        } 
        case 5:
        if ( cos(radians) == 0 ){
            return -999.0;
        }
        else{
            return 1/cos(radians);
        }            
        case 6:
        if ( tan(radians) == 0 ){
            return -999.0;
        }
        else{
            return 1/tan(radians);
        }
        case 7:
        if ( radians < -1 || radians > 1 ){
            return -998.0;
        }
        else{
            return asin(radians);
        } 
        case 8:
        if ( radians < -1 || radians > 1 ){
            return -998.0;
        }
        else{
            return acos(radians);
        } 
        case 9:
            return atan(radians);
        default:
            return -998.0;
    }
}   

double DegreesToRadians(double degrees){
    double radians;
    radians = degrees * acos(-1.0) / 180.0;  // use acos(-1.0) to get pi
    return radians;
}
