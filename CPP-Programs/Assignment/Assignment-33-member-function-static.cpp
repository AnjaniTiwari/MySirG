#include <iostream>
#include <cstring>

using namespace std;

//Q1
class Complex {
    int n1, n2;
    public:
        void setData(int n1, int n2);
        void showData();
        Complex add(Complex);
        Complex subtract(Complex);
        Complex multiply(Complex);
};

void Complex::setData(int a, int b) {
    n1 = a;
    n2 = b;
}

void Complex::showData() {
    cout << "Real: " << n1 << " Imaginary: " << n2 << endl;
}

Complex Complex::add(Complex obj) {
    Complex tmp;
    tmp.n1 = n1 + obj.n1;
    tmp.n2 = n2 + obj.n2;
    return tmp;
}

Complex Complex::subtract(Complex obj) {
    Complex tmp;
    tmp.n1 = n1 - obj.n1;
    tmp.n2 = n2 - obj.n2;
    return tmp;
}

Complex Complex::multiply(Complex obj) {
    Complex tmp;
    tmp.n1 = n1 * obj.n1;
    tmp.n2 = n2 * obj.n2;
    return tmp;
}

//Q2
class Time {
    int hours, minutes, seconds;
    public:
        void setTime(int h, int m, int s);
        void showTime();
        void normalize();
        Time add(Time);
        bool isGrater(Time);
};

void Time::setTime(int h, int m, int s) {
    hours = h;
    minutes = m;
    seconds = s;
    normalize();
}

void Time::showTime() {
    cout << hours << " Hr " << minutes << " min " << seconds << " sec" << endl;
}

void Time::normalize() {
    if(seconds >= 60) {
        minutes += (seconds/60);
        seconds %= 60;
    }
    if(minutes >= 60) {
        hours += (minutes/60);
        minutes %= minutes;
    }
}

Time Time::add(Time obj) {
    Time tmp;
    tmp.hours = hours + obj.hours;
    tmp.minutes = minutes + obj.minutes;
    tmp.seconds = seconds + obj.seconds;
    tmp.normalize();
    return tmp;
}

bool Time::isGrater(Time obj) {
    if(hours > obj.hours)
        return true;
    else if(hours < obj.hours)
        return false;
    else if(minutes > obj.minutes)
        return true;
    else if(minutes < obj.minutes)
        return false;
    else if(seconds > obj.seconds)
        return true;
    else
        return false;
}

//Q3
class TestResult {
    private:
        int roll_no, right, wrong, net_score;
        static int right_weightage, wrong_weightage;
    public:
        void setRollno(int r) { roll_no = r; }
        void setRight(int r) { right = r; }
        void setWrong(int w) { wrong = w; }
        void setNetScore(int n) { net_score = n; }
        int getRollno() { return roll_no; }
        int getRight() { return right; }
        int getWrong() { return wrong; }
        int getNetScore() { return net_score; }
        static void setRightWeightage(int w) { right_weightage = w; }
        static void setWrongWeightagr(int r) { wrong_weightage = r; }
        static int getRightWeightage() { return right_weightage; }
        static int getWrongWeightage() { return wrong_weightage; }
};

int TestResult::right_weightage = 3;
int TestResult::wrong_weightage = 1;

void setTestResult(TestResult& obj, int rollno, int right, int wrong) {
    obj.setRollno(rollno);
    obj.setRight(right);
    obj.setWrong(wrong);
    obj.setNetScore(right*obj.getRightWeightage()-wrong*obj.getWrongWeightage());
}

//Q4
void sortByNetScore(TestResult* ptr, int size) {
    TestResult tmp;
    for(int round = 0; round < size-1; ++round) {
        for(int i = 0; i < size-1-round; ++i)
        if(ptr[i].getNetScore() > ptr[i+1].getNetScore()) {
            tmp = ptr[i];
            ptr[i] = ptr[i+1];
            ptr[i+1] = tmp;
        }
    }
}

void printTestResult(TestResult obj) {
    cout << "Rollno: " << obj.getRollno() << " Right: " << obj.getRight();
    cout << " Wrong: " << obj.getWrong() << " Netscore: " << obj.getNetScore() << endl;
}

//Q5
class Matrix {
    int m[3][3];
    public:
        void setMatrix(int arr[][3]);
        void printMatrix();
        Matrix addMatrix(Matrix obj);
        Matrix subtractMatrix(Matrix obj);
        Matrix maltiplyMatrix(Matrix obj);
        Matrix transposeMatrix();
        bool isSingularMatrix();
};

void Matrix::setMatrix(int arr[][3]) {
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            m[i][j] = arr[i][j];
}

void Matrix::printMatrix() {
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j)
            cout << m[i][j] << " ";
        cout << endl;
    }
}

Matrix Matrix::addMatrix(Matrix obj) {
    Matrix tmp;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j)
            tmp.m[i][j] = m[i][j] + obj.m[i][j];
    }
    return tmp;
}

Matrix Matrix::subtractMatrix(Matrix obj) {
    Matrix tmp;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j)
            tmp.m[i][j] = m[i][j] - obj.m[i][j];
    }
    return tmp;
}

Matrix Matrix::maltiplyMatrix(Matrix obj) {
    Matrix tmp;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            tmp.m[i][j] = 0;
            for(int k = 0; k < 3; ++k) {
                tmp.m[i][j] += (m[i][k] * obj.m[k][j]);
            }
        }
    }
    return tmp;
}

Matrix Matrix::transposeMatrix() {
    Matrix tmp;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            tmp.m[j][i] = m[i][j];
        }
    }
}

bool Matrix::isSingularMatrix() {
    int determinent;
    determinent = m[0][0]*(m[1][1]*m[2][2] - m[1][2]*m[2][1])
                  - m[0][1]*(m[1][0]*m[2][2] - m[1][2]*m[2][0])
                  + m[0][2]*(m[1][0]*m[2][1]- m[1][1]*m[2][0]);
    if(determinent == 0)
        return 1;
    return 0;
}

int main() {
    // Complex obj1, obj2, tmp;
    // obj1.setData(1, 2);
    // obj2.setData(2, 4);
    // tmp = obj1.add(obj2);
    // tmp.showData();
    // tmp = obj1.subtract(obj2);
    // tmp.showData();
    // tmp = obj1.multiply(obj2);
    // tmp.showData();

    TestResult obj[5];
    setTestResult(obj[0], 100, 90, 10);
    setTestResult(obj[1], 100, 80, 20);
    setTestResult(obj[2], 100, 70, 30);
    setTestResult(obj[3], 100, 60, 40);
    setTestResult(obj[4], 100, 50, 50);
    sortByNetScore(obj, 5);
    for(int i = 0; i < 5; ++i)
        printTestResult(obj[i]);
    return 0;
}