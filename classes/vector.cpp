#pragma once
#include <stdio.h>      /* printf */
#include <iostream>
#include <math.h>       /* pow */


struct point
{
    double x;
    double y;
    double z;
};
class Vector { 
public :
    explicit Vector(double x = 0. , double y = 0. , double z = 0.){ 
    coords[0] = x;
    coords[1] = y;
    coords[2] = z;
    };
    //useful functions
    void print_vector(){
        std::cout<< coords[0] << " " << coords[1] << " " << coords[2] << std::endl;
    }
    // Vector operations
    Vector& operator+=(const Vector& b) {
    coords[0] += b[0]; coords[1] += b[1]; coords[2] += b[2];
    return *this; 
    }

    Vector& operator-=(const Vector& b) {
    coords[0] -= b[0]; coords[1] -= b[1]; coords[2] -= b[2];
    return *this; 
    }

    double norm(){
        return sqrt((pow(coords[0],2) + pow(coords[1],2) + pow(coords[2],2)));
    }

    void normalize(){
        double norm = this->norm();
        if (norm){
        coords[0] /= norm; coords[1] /= norm; coords[2] /= norm;
        }
    }

    point give_point(){
        point p;
        p.x = coords[0];
        p.y = coords[1];
        p.z = coords[2];
        return p;
    }
    //Arithmetic
    Vector& operator+=(const double b) {
    coords[0] += b; coords[1] += b; coords[2] += b;
    return *this; 
    }

    Vector& operator*=(const double b) {
    coords[0] *= b; coords[1] *= b; coords[2] *= b;
    return *this; 
    }

    Vector& operator-=(const double b) {
    coords[0] -= b; coords[1] -= b; coords[2] -= b;
    return *this; 
    }
    

    const double& operator [] (int i) const { return coords [i] ; } 
    double& operator [](int i) { return coords[i]; }


private :
    double coords[3];
    double albedo[3];
};

//Arithmetic operations
Vector operator+(const Vector& a, const double b){
    return Vector(a[0] + b , a[1] + b , a[2] + b); 
    }

Vector operator+(const double b,const Vector& a){
    return Vector(a[0] + b , a[1] + b , a[2] + b); 
    }

//CAREFUL: We need to declare the symmetry
Vector operator*(const Vector& a, const double b){
    return Vector(a[0] * b , a[1] * b , a[2] * b); 
    }

Vector operator*(const double b,const Vector& a){
    return Vector(a[0] * b , a[1] * b , a[2] * b); 
    }

Vector operator-(const Vector& a, const double b){
    return Vector(a[0] - b , a[1] - b , a[2] - b); 
    }

Vector operator-(const double b,const Vector& a){
    return Vector(a[0] - b , a[1] - b , a[2] - b); 
    }

Vector pow(const Vector& a,double exp){
    return Vector(pow(a[0],exp) , pow(a[1],exp)  , pow(a[2],exp));
}

// Vector operations
Vector operator+(const Vector& a, const Vector &b){
    return Vector(a[0] + b[0] , a[1] + b[1] , a[2] + b[2]); 
    }

Vector operator-(const Vector& a, const Vector &b){
    return Vector(a[0] - b[0] , a[1] - b[1] , a[2] - b[2]); 
    }

double dot(const Vector& a, const Vector& b) { 
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
    }

Vector cross(const Vector& a, const Vector& b) { 
    return Vector(a[1] * b[2] - a[2] * b[1],
                  a[2] * b[0] - a[0] * b[2],
                  a[0] * b[1] - a[1] * b[0]);
    }

