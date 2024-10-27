#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

float calculateTrapezoidArea(){
    cout << "calculate trapezoid area";
    float a, b, h;
    cin >> a >> b >> h;
    return (a + b) * h / 2;
}
float calculateParllelogramArea(){
    cout << "calculate Parllelogram area\n";
    cout << "select which method to use to calculate parallelogram area\n"
    << "1 - for using one of the parrallel sides and height\n"
    << "2 - for using lenghts of sides with the angle between them\n"
    << "3 - for using diagonals witht the angle between them\n";
    int selection;
    cin >> selection;
    if (selection == 1){
        float b, h;
        cin >> b >> h;
        return b * h;
    } else if (selection == 2){
        float a, b, angle;
        cin >> a >> b >> angle;
        return a * b * sin(angle);
    } else if (selection == 3){
        float d1, d2, x;
        cin >> d1 >> d2 >> x;
        return d1 * d2 * sin(x) / 2;
    }
    return 0;

}
float calculateCircleArea(){
    cout << "calculate Circle area";
    float r;
    cin >> r;
    return M_PI * r * r;
}
int main() {
    double result = calculateParllelogramArea();
    cout << fixed << setprecision(6) << result << endl;
    return 0;
}