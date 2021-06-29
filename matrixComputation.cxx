#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

std::vector<int> transpose(std::vector<std::vector<int>> &);
void showVec(std::vector<std::vector<int>> vec);
void showVec(std::vector<double> vec);
void showVec(std::vector<int> vec);


int dotProduct(std::vector<int>a,std::vector<std::vector<int>>b);
double norm(std::vector<double> );
std::vector<double> normalizing(std::vector<double>& );
double distance(std::vector<double> a,std::vector<double>b);
int dotProduct(std::vector<int>a,std::vector<int>b);
double dotProduct(std::vector<double>a,std::vector<double>b,double angle);
std::vector<int> addVector(std::vector<int>,std::vector<int>);
std::vector<std::vector<int>> mTrasnspose (std::vector<std::vector<int>>&);
int rows(std::vector<std::vector<int>>);
int cols(std::vector<std::vector<int>>);


int main(){
    std::cout<<"Matrix computation\t " <<std::endl; 
    std::vector<std::vector<int>>colVec= {
        {1},{2},{3},{4},{5}
    };
    auto k  = transpose(colVec);
    auto dotPro = dotProduct(k,colVec);
    std::cout<<"dot Product Result \t " << dotPro<<std::endl;
    std::vector<double> a {2,2,-1}; 
    std::cout<<"Norm vector a \t: [ " << norm(a) <<"]" <<std::endl; 
    std::cout<<"Before normalizing vector "<<std::endl;
    showVec(a);
    normalizing(a);
    std::cout<<"After normalizing vector "<<std::endl;
    showVec(a);
    std::vector<double> vecA = {1,3,-2,7};
    std::vector<double> vecB = {0,7,2,2};
    std::cout<<"Finding the distance of two vectors "<<std::endl;
    showVec(vecA);
    showVec(vecB);
    std::cout<<"the distance of two vectors is \t: [ " << distance(vecA,vecB) <<"]" <<std::endl;
    //test for overload  dotproduct 
    //vector for test : 
    std::vector<int> caseA {-1,3,5,7}; 
    std::vector<int> caseB {-3,-4,1,0};
    std::cout<<"Show dot product result \t : [ " << dotProduct(caseA,caseB) <<" ]" <<std::endl;  
    //test case with angle as parameter
    std::vector<double> withAngleA {0,0,1}; 
    std::vector<double> withAngleB {0,2,2};
    auto angle = 45.0;
    std::cout<<"Show dot product result \t : [ " << dotProduct(withAngleA,withAngleB,angle) <<" ]" <<std::endl;  

    //case , adding two vector 
    std::cout<<"case, adding two vector " <<std::endl;
    auto tempAdd  = addVector(caseA,caseB);
    showVec(tempAdd);

    //case for matrix transpose  
    std::vector<std::vector<int>> matTr={
        {1,2,3},
        {4,5,6,},
        {6,7,8}
        
    };
    std::cout<<"Original Matrix" <<std::endl;
    showVec(matTr);
    mTrasnspose(matTr);
    std::cout<<"Transposed Matrix" <<std::endl;
    showVec(matTr);
    //testing number of rows and columns
    std::vector<std::vector<int>> checkCol={
        {1,2,3},
        {4,5,6,},
        {6,7,8},
        {6,7,8},
        {6,7,8},
        {6,7,8}
        
    };
    std::cout<<"Row size \t : " << rows(checkCol)<<std::endl;
    std::cout<<"column size \t : " << cols(checkCol)<<std::endl;


     
    
}

std::vector<int> transpose(std::vector<std::vector<int>> &colVec){
    std::vector<int> temp; 
    for (size_t i = 0; i < 5; ++i)
    {
       for (size_t j = 0;j < 1; j++)
       {
           temp.push_back(colVec[i][j]);
       }
       
    }
     
    return temp;
    
}


void showVec(std::vector<std::vector<int>> vec){
    std::cout<<"Show Vector \t: " <<std::endl;
    for (auto &i : vec)
    {
        for (auto j : i)
        {
            std::cout<<j<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}
int dotProduct(std::vector<int>a,std::vector<std::vector<int>>b){
    auto result=0;
    for (size_t i = 0; i < 5; ++i)
    {
        result+=a[i]*b[i][0];
    }
    return result; 
}

double norm(std::vector<double> a){
    //testing for R_n space 
    double normVe=0.0;
    auto begin  = a.begin();
    auto end= a.end();
    while (begin !=end)
    {
        normVe+=pow(*begin,2.0);
        ++begin;
    }
    
     return sqrt(normVe);

}

std::vector<double> normalizing(std::vector<double>&inputVec ){
    auto temp  = (1/norm(inputVec));
    auto begin = inputVec.begin(),end=inputVec.end();
    while (begin!=end)
    {
        *begin*=temp;
        ++begin;
    }
    return inputVec;
    
}
void showVec(std::vector<double> vec){
    std::cout<<"Vector result \t : [";
    for (auto &i : vec)
    {
        std::cout<<i<<"  ";
    }
    std::cout<<"]"<<std::endl;
}

void showVec(std::vector<int> vec){
    std::cout<<"Vector result \t : [";
    for (auto &i : vec)
    {
        std::cout<<i<<"  ";
    }
    std::cout<<"]"<<std::endl;
}

double distance(std::vector<double> a,std::vector<double>b){
    auto temp =0.0;
    auto firstVec= a.begin();
    auto end  = a.end();
    auto secVec = b.begin(); 
    while (firstVec!=end)
    {
        temp+=pow((*firstVec-*secVec),2.0);
        ++secVec;
        ++firstVec;
    }
    return sqrt(temp);
}

int dotProduct(std::vector<int>a,std::vector<int>b){
    auto temp  =0;
    auto begin  = a.begin() ;
    auto end  = a.end();
    auto secondVec  = b.begin(); 
    while (begin!=end)
    {
        temp+=(*begin* (*secondVec));
        ++secondVec;
        ++begin;
    }
    return temp;
    
}
double dotProduct(std::vector<double>a,std::vector<double>b,double angle){
    auto temp=0.0;
    auto normA = norm(a);
    auto normb= norm(b);
    temp = normA*normb*( cos(angle/57.2958));
    return temp; 
}

std::vector<int> addVector(std::vector<int>a,std::vector<int>b){
    std::vector<int> temp ; 
    auto begin = a.begin();
    auto end  = a.end(); 
    auto bBegin = b.begin();  
    while (begin!=end)
    {
        temp.push_back(*begin+(*bBegin));
        ++bBegin;
        ++begin;
    }
    return temp;
    
}

std::vector<std::vector<int>> mTrasnspose (std::vector<std::vector<int>>&a){
    std::vector<std::vector<int>> temp(3,std::vector<int>(3,0));
    
    for (size_t i = 0; i < 3; ++i)
    {
        for (size_t j = 0; j < 3; ++j)
        {
            temp[i][j] = a[j][i];
        }
        
    }
    a = temp;
     
    return a;
}
int rows(std::vector<std::vector<int>>a){
    auto count=0;
    auto begin = a.begin();
    auto end= a.end();
    while (begin!=end)
    {
        ++count;
        ++begin;
    }
    return count;
     
}
int cols(std::vector<std::vector<int>>matrix){
    auto iter =0,cols=0;
    if (iter<1)
    {
        for (auto &i : matrix)
        {
            ++iter;
            
            for (auto j : i)
            {
                ++cols;
            }
            break;
        }
            

    }
    
   
   
    return cols;
}