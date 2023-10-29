#include <iostream>
using namespace std;
class Polynomial {
    int *degCoeff;
    int capacity;
    public:
        Polynomial(){
            degCoeff = new int[5];
            capacity = 5;
            for(int i=0; i<capacity; i++){
                degCoeff[i] = 0;
            }
        }
        void setCoefficient(int deg, int coeff){
            if(deg >= capacity){
                int size = capacity*2;
                while(size <= deg){
                    size *= 2;
                }
                int *newdegCoeff = new int[size];
                for(int i=0;i<size; i++){
                    newdegCoeff[i] = 0;
                }
                for(int i=0;i<capacity; i++){
                    newdegCoeff[i] = degCoeff[i];
                }
                capacity = size;
                delete [] degCoeff;
                degCoeff = newdegCoeff;
            }
            degCoeff[deg] = coeff;
        }
        void print(){
            for(int i=0; i<capacity; i++){
                if(degCoeff[i] != 0){
                    cout<<degCoeff[i]<<"x"<<i<<" ";
                }
            }
            cout<<endl;
        }
        Polynomial(Polynomial const &p){
            this->degCoeff = new int[p.capacity];
            this->capacity = p.capacity;
            for(int i=0; i<p.capacity; i++){
                this->degCoeff[i] = p.degCoeff[i];
            }
        }
        void operator=(Polynomial const &p){
            delete [] degCoeff;
            this->degCoeff = new int[p.capacity];
            this->capacity = p.capacity;
            for(int i=0; i<p.capacity; i++){
                this->degCoeff[i] = p.degCoeff[i];
            }
        }
        Polynomial operator+(Polynomial const &p){
            Polynomial p3;
            int i=0, j=0;
            while(i<this->capacity && j<p.capacity){
                p3.setCoefficient(i,this->degCoeff[i]+p.degCoeff[j]);
                i++;
                j++;
            }
            if(i<this->capacity){
                while(i<this->capacity){
                    p3.setCoefficient(i,this->degCoeff[i]);
                    i++;
                }
            }
            if(j<p.capacity){
                while(j<p.capacity){
                    p3.setCoefficient(j,p.degCoeff[j]);
                    j++;
                }
            }
            
            return p3;
        }
        Polynomial operator-(Polynomial const &p){
            Polynomial p3;
            int i=0, j=0;
            while(i<this->capacity && j<p.capacity){
                p3.setCoefficient(i,this->degCoeff[i]-p.degCoeff[j]);
                i++;
                j++;
            }
            if(i<this->capacity){
                while(i<this->capacity){
                    p3.setCoefficient(i,this->degCoeff[i]);
                    i++;
                }
            }
            if(j<p.capacity){
                while(j<p.capacity){
                    p3.setCoefficient(j,(-1 * p.degCoeff[j]));
                    j++;
                }
            }
            
            return p3;
        }
        Polynomial operator*(Polynomial const &p){
            Polynomial p3;
            for(int i=0; i<this->capacity; i++){
                if(this->degCoeff[i] != 0){
                    for(int j=0; j<p.capacity; j++){
                        if(p.degCoeff[j] != 0){
                            int data = this->degCoeff[i]*p.degCoeff[j];
                            int deg = i+j;
                            if(deg > p3.capacity){
                                p3.setCoefficient(deg, data);
                            }
                            else{
                                p3.setCoefficient(deg, p3.degCoeff[deg] + data);
                            }
                        }
                    }
                }
            }
            return p3;
        }
    
};
int main() {
      Polynomial p1;
      p1.setCoefficient(1,-3);
      p1.setCoefficient(2,5);
      p1.setCoefficient(10,8);
      p1.print();
      Polynomial p2(p1);
     
      p2.setCoefficient(7,7);
      p2.print();
      
    //   Polynomial p3;
    //   p3 = p1+p2;
    //   p3.print();
    
    //   Polynomial p3;
    //   p3 = p2-p1;
    //   p3.print();
    
    
    
    //   Polynomial p3;
    //   p3 = p1;
    //   p1.setCoefficient(13,4);
    //   p1.print();
    //   p3.print();
    
    Polynomial p3;
    p3 = p1*p2;
    p3.print();
    
    // Input
    // p1 -> -3x1 5x2 8x10 
    // p2 -> -3x1 5x2 7x7 8x10
    // p2-p1 => 7x7
    // p1+p2 => -6x1 10x2 7x7 16x10
    // p1*p2 => 9x2 -30x3 25x4 -21x8 35x9 -48x11 80x12 56x17 64x20
    return 0;
}