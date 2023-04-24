#include <iostream>
class Figure
{
protected:
    std::string f_name;
    int a, b, c, d, A, B, C, D;
    bool f_sides = false;
public:
    bool getf_side() { return f_sides; }
    std::string getName() { return f_name; }
    int geta() { return a; }
    int getb() { return b; }
    int getc() { return c; }
    int getd() { return d; }
    int getA() { return A; }
    int getB() { return B; }
    int getC() { return C; }
    int getD() { return D; }
};

class Triangle : public Figure
{

public:
    Triangle() {};
    Triangle(int a_, int b_,int c_, int A_, int B_, int C_) {
        f_name = "Треугольник";
        a = a_;
        b = b_;
        c = c_;
        A = A_;
        B = B_;
        C = C_;
    }   
};
class R_Triangle : public Triangle {
  
public:
    R_Triangle(int a_, int b_, int c_, int A_, int B_) {
        f_name = "Прямоугольный треугольник";
        a = a_;
        b = b_;
        c = c_;
        A = A_;
        B = B_;
        C = 90;
    }
};

class Isosceles_Triangle : public Triangle {
public:

    Isosceles_Triangle(int a_, int b_, int A_, int B_) {
        f_name = "Равнобедренный треугольник";
        a = c = a_;
        b = b_;
        A = C = A_;
        B = B_;           
    }
};
    
class Equilateral_Triangle: public Triangle
{
public:
    Equilateral_Triangle(int a_) {
        f_name = "Равносторонний треугольник";
        a = b = c = a_;
        A = B = C = 60;          
   }
};


class Quadrilateral : public Figure
{
public:
    Quadrilateral() {};
   
    Quadrilateral(int a_, int b_, int c_, int d_, int A_, int B_, int C_, int D_) {
        f_name = "Четырехугольник";
        f_sides = true;
        a = a_;
        b = b_;
        c = c_;
        d = d_;
        A = A_;
        B = B_;
        C = C_;
        D = D_;           
    }  
};
class Parallelogram : public Quadrilateral {
public:
    Parallelogram() {};
    Parallelogram(int a_, int b_, int A_, int B_) {
        f_name = "Параллелограмм";
        a = c = a_;
        b = d = b_;
        A = C = A_;
        B = D = B_;
    }
};

class Rectangle : public Parallelogram {
public:
    Rectangle(int a_, int b_) {
        f_name = "Прямоугольник";
        a = c = a_;
        b = d = b_;
        A = B = C = D = 90;
    }
};

class Rhomb : public Parallelogram {
public:
    Rhomb() {};
    Rhomb(int a_, int A_, int B_) {
        f_name = "Ромб";
        a = b = c = d = a_;
        A = C = A_;
        B = D = B_;
    }
};

class Square : public Rhomb {
public:
    Square(int a_) {
        f_name = "Квадрат";
        a = b = c = d = a_;
        A = B = C = D = 90;
    }
};

void print_info(Figure& figure)
{
    std::cout << std::endl;
    std::cout << figure.getName() << ":" << std::endl;

    std::cout << "Стороны:";
    std::cout << " a = " << figure.geta() << ", b = " << figure.getb() << ", с = " << figure.getc();
    if (figure.getf_side())
    {
        std::cout << ", d = " << figure.getd() << std::endl;
    }
    else
    { std::cout << std::endl; }

    std::cout << "Углы:";
    std::cout << " А = " << figure.getA() << ", В = " << figure.getB() << ", С = " << figure.getC();
    if (figure.getf_side()) 
    { std::cout << ", D = " << figure.getD() << std::endl; }
    else
    { std::cout << std::endl; }
}

int  main()
{
    setlocale(LC_ALL, "RUS");
    Triangle triangle( 20, 30, 40, 30, 20, 50);
    print_info(triangle);
    R_Triangle r_triangle(20, 30, 40, 30, 60);
    print_info(r_triangle);
    Isosceles_Triangle isosceles_triangle(20, 60, 30, 40);
    print_info(isosceles_triangle);
    Equilateral_Triangle equilateral_triangle(20);
    print_info(equilateral_triangle);
    Quadrilateral quadrilateral(20, 30, 40, 50, 60, 30, 30, 60);
    print_info(quadrilateral);
    Parallelogram parallelogram(45, 60, 30, 20);
    print_info(parallelogram);
    Rectangle rectangle(40, 50);
    print_info(rectangle);
    Rhomb rhomb(40, 30, 40);
    print_info(rhomb);
    Square square(30);
    print_info(square);



}
