#include <iostream>
#include <cmath>

using namespace std;

struct point{
    float x = 0.f;
    float y = 0.f;
};

struct math_vector{
    point start;
    point end;
    float x_delta = end.x - start.x;
    float y_delta = end.y - start.y;
};

enum operation{
    add = 1,
    subtract = 2,
    scale = 3,
    length = 4,
    normalize = 5
};

void definition_delta(math_vector& vector){
    vector.x_delta = vector.end.x - vector.start.x;
    vector.y_delta = vector.end.y - vector.start.y;
}

math_vector addVectors(math_vector& vector_first, math_vector& vector_second){
    math_vector vector_result;
    if (vector_first.end.x == vector_second.start.x &&
            vector_first.end.y == vector_second.start.y){
        vector_result.start = vector_first.start;
        vector_result.end = vector_second.end;
    } else
        cout << "\timposible\n";

    return vector_result;
}

math_vector subtractVectors(math_vector& vector_first, math_vector& vector_second){
    math_vector vector_result;
    if (vector_first.start.x == vector_second.start.x &&
            vector_first.start.y == vector_second.start.y){
        vector_result.start = vector_first.end;
        vector_result.end = vector_second.end;
    } else
        cout << "\timposible\n";

    return vector_result;
}

void scaleVectors(math_vector& vector, float& lambda){
    vector.x_delta *= lambda;
    vector.y_delta *= lambda;
    vector.end.x = vector.start.x + vector.x_delta;
    vector.end.y = vector.start.y + vector.y_delta;
}

float lengthVector (math_vector& vector){
    return sqrt(pow(fabs(vector.x_delta), 2) + pow(fabs(vector.y_delta), 2));
}

void normalizeVectors(math_vector& vector){
    vector.x_delta /= lengthVector(vector);
    vector.y_delta /= lengthVector(vector);
    vector.end.x = vector.start.x + vector.x_delta;
    vector.end.y = vector.start.y + vector.y_delta;
}

void fillTheVector(math_vector& vector){
    for (int i = 0; i < 2; i++){
        cout << "input " << ((i == 0) ? "start" : "end") <<" coordinate" << endl;
        cout << "   x:";
        cin >> ((i == 0) ? vector.start.x : vector.end.x);
        cout << "   y:";
        cin >> ((i == 0) ? vector.start.y : vector.end.y);
    }
    definition_delta(vector);
}

void print_vectors(math_vector& vector_first, math_vector& vector_second){
    cout << "1st vector = (" << vector_first.x_delta << "; " << vector_first.y_delta << ")" << endl;
    cout << "2nd vector = (" << vector_second.x_delta << "; " << vector_second.y_delta << ")" << endl;
}

operation number_of_operation(){
    int num;
    cout << "What do you want to do?" << endl;
    cout << "\t1. Add\n"
            "\t2. Subtract\n"
            "\t3. Scale\n"
            "\t4. Length\n"
            "\t5. Normalize" << endl;
    do {
        cin >> num;
        if (num < 1 || num > 5) cout << "\tincorrect, again" << endl;
    } while (num < 1 || num > 5);
    return (operation)num;
}

void choose_the_vector(math_vector& vector, math_vector& vector_first, math_vector& vector_second){
    cout << "What vector do you want (1st/2nd)?" << endl;
    int num;
    do {
        cin >> num;
        if (num != 1 && num != 2) cout << "we don't have so many vectors.. again" << endl;
    } while (num != 1 && num != 2);
    vector = (num == 1) ? vector_first : vector_second;

}

void do_operation (operation& com, math_vector& vector_first, math_vector& vector_second){
    math_vector vector;
    switch (com) {
        case add:
            vector = addVectors(vector_first, vector_second);
            break;

        case subtract:
            vector = subtractVectors(vector_first, vector_second);
            break;

        case scale:
            choose_the_vector(vector, vector_first, vector_second);
            cout << "How much to multiply?" << endl;
            float multiply;
            cin >> multiply;
            scaleVectors(vector, multiply);
            break;

        case length:
            choose_the_vector(vector, vector_first, vector_second);
            cout << "lenth = " << lengthVector(vector) << endl;
            break;
        case normalize:
            choose_the_vector(vector, vector_first, vector_second);
            normalizeVectors(vector);
            break;
    }
    definition_delta(vector);
    cout << "result = (" << vector.x_delta << "; " << vector.y_delta << ")" << endl;
}

int main() {
    cout << "\nTask  #3.\n  Implementation of the mathematical vector\n" << endl;

    math_vector vector_first;
    math_vector vector_second;

    cout << "   Filling two vectors" << endl;
    for (int i = 0; i < 2; i++){
        cout << ((i == 0) ? "\t1st" : "\t2nd") << " vector" << endl;
        fillTheVector(((i == 0) ? vector_first : vector_second));
        cout << "------------------------" << endl;
    }

    print_vectors(vector_first, vector_second);
    operation command = number_of_operation();
    do_operation(command, vector_first, vector_second);

    return 0;
}
