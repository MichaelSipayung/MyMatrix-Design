#include <iostream>
#include <vector>
#include <cmath>
#include  <array>
double minFunct(double x,double y) ;

std::vector<int> insertionSort(std::vector<int>&);
void showSorted(std::vector<int>);
std::vector<std::vector<int>> secDimension(std::vector<std::vector<int>> &);
void showVector(std::vector<std::vector<int>>);
void showVector(std::vector<std::vector<double>>);

void vecA();
void vecB();
std::vector<std::vector<int>> addingVec(std::vector<std::vector<int>> vecA,std::vector<std::vector<int>> vecB,std::vector<std::vector<int>> &vecC);
std::vector<std::vector<int>> multiplyMat(std::vector<std::vector<int>> vecA,std::vector<std::vector<int>> vecB,std::vector<std::vector<int>> &vecC);
//std::vector<std::vector<double>> rotateR2(std::vector<std::vector<double>> vecA,std::vector<std::vector<double>> vecB,std::vector<std::vector<double>> &vecC);
std::vector<std::vector<double>> rotateR2(std::vector<std::vector<double>> vecA,std::vector<std::vector<double>> vecB,std::vector<std::vector<double>> &vecC);
std::vector<std::vector<double>> spiralOp(std::vector<std::vector<double>> vecA,std::vector<std::vector<double>> vecB,std::vector<std::vector<double>> &vecC);
std::vector<std::vector<double>> modelSpiral(std::vector<std::vector<double>> vecA,std::vector<std::vector<double>> vecB,std::vector<std::vector<double>> third,std::vector<std::vector<double>> &vecC);


int main(){

    std::vector<int> unSortedData = {5,2,4,6,1,3};
    insertionSort(unSortedData);
    showSorted(unSortedData);
    std::vector<std::vector<int>> matrix(9,std::vector<int>(9,0));
    secDimension(matrix);
    showVector(matrix);
    std::vector<std::vector<int>> a(5,std::vector<int>(5));
    a ={
        {1,2,3,1,1},
        {1,2,3,4,5},
        {2,1,1,4,5},
        {1,2,3,1,5},
        {3,2,1,4,1}
        
    };


    std::vector<std::vector<int>> b(5,std::vector<int>(5));
    b ={
       {1,2,3,1,1},
        {1,2,3,4,5},
        {2,1,1,4,5},
        {1,2,3,1,5},
        {3,2,1,4,1}
         
    };
    std::vector<std::vector<int>> vecResult(5,std::vector<int>(5,0));
    addingVec(a,b,vecResult);
    showVector(vecResult);
    std::vector<std::vector<int>> vecMulti(5,std::vector<int>(5,0));
    multiplyMat(a,b,vecMulti);
    showVector(vecMulti);
    std::vector<std::vector<double>> standartRotate{
        {cos(30.0/57.2958),-sin(30.0/57.2958)},
        {sin(30.0/57.2958),cos(30.0/57.2958)}

    };
    std::vector<std::vector<double>> currentPosition{
        {1},
        {1}
    };
    std::vector<std::vector<double>> imageResult{
        {0},
        {0}
    };
    std::cout<<"size\t: " <<imageResult[1][0]<<std::endl;;
    //rotateR2(standartRotate,currentPosition,imageResult);
    showVector(imageResult);
    showVector(standartRotate);
    showVector(currentPosition);
    double vecStandart[][2]={
        {cos(30.0/57.2958),-sin(30.0/57.2958)},
        {sin(30.0/57.2958),cos(30.0/57.2958)}
    };
    double imageVec[][1]={
        {1},
        {1}
    };
    double resultVec[][1]={
        {0},{0}
    };

    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j<= 1; j++)
        {
            for (size_t k = 0; k < 2; k++)
            {
                 resultVec[i][k]+=standartRotate[i][j]*imageVec[j][k];
            }
            
        }
        
    }
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j< 1; j++)
        {
            std::cout<<resultVec[i][j];
        }
        std::cout<<std::endl;
        
    }
    
    std::array<std::array<double,2>,2> standMat{{ 
        {cos(30.0/57.2958),-sin(30.0/57.2958)},
        {sin(30.0/57.2958), cos(30.0/57.2958)}
        }};

    //new line for vector
    std::vector<std::vector<double>> matrixStandart{
        {cos(30.0/57.2958),-sin(30.0/57.2958)},
        {sin(30.0/57.2958),cos(30.0/57.2958)}

    };

    std::vector<std::vector<double>> curPos{
        {1.0},{1.0}
    };
    std::vector<std::vector<double>> images{
        {0.0},{0.0}
    };
    rotateR2(matrixStandart,curPos,images);
    std::cout<<"Result test"<<std::endl;
    showVector(images);
    
    //spiral test 
    std::cout<<"current line bound to spiral model"<<std::endl;
    auto r=0.95;
    std::vector<std::vector<double>> spiralMatrixStandart{
        {cos(45.0/57.2958),-sin(45.0/57.2958)},
        {sin(45.0/57.2958),cos(45.0/57.2958)}

    };

    std::vector<std::vector<double>> spiralCurPos{
        {10.0},{10.0}
    };
    std::vector<std::vector<double>> rParameter{
        {0.9,0},
        {0,0.9}
    };
    std::vector<std::vector<double>> spiralImages{
        {0.0},{0.0}
    };
    std::vector<std::vector<double>> spiralResult{
        {0.0},{0.0}
    };
    auto data1= minFunct(2.0,2.0);
    std::vector<std::vector<double>> generatePoint{
        {data1},{data1}
    };
    
    spiralOp(spiralMatrixStandart,spiralCurPos,spiralImages);
    showVector(spiralImages);

    //line for test minima 
    std::cout<<"Minima functon at point (-1,-1)\t: " << minFunct(-2.9,-2.9)<<std::endl;
    modelSpiral(rParameter,spiralMatrixStandart,generatePoint,spiralResult);
    std::cout<<"Testing spiral result \t: "<<std::endl;
    showVector(spiralResult);

   

}



std::vector<int> insertionSort(std::vector<int>&data){
    auto key=0,i=0;
    for (size_t j =1; j <data.size(); ++j)
    {
         key=data[j];
         i=j-1;
         while (i>=0&&data[i]>key)
         {
             data[i+1]=data[i];
             --i;
         }
         data[i+1]=key;//place i+1  to j_th position of the data 
         
    }
    return data;
}

void showSorted(std::vector<int>data){
    for (auto &i : data)
    {
        std::cout<<i<<"|";
    }
    std::cout<<std::endl;
    
}
std::vector<std::vector<int>> secDimension(std::vector<std::vector<int>> &data){
  
   for (size_t i = 0; i <data.size(); ++i)
   {
      for (size_t j = 0; j < data.size(); ++j)
      {
          data[i][j]=i+j;
      }
      
   }
   
  return data;
}

void showVector(std::vector<std::vector<int> >data){
    for (auto &i : data)
    {
        for (auto j : i)
        {
            std::cout<<j<<"  ";
        }
        std::cout<<std::endl;
    }
    
}
void showVector(std::vector<std::vector<double>>data){
    for (auto &i : data)
    {
        for (auto j : i)
        {
            std::cout<<j<<"  ";
        }
        std::cout<<std::endl;
    }
    
}
std::vector<std::vector<int>> addingVec(std::vector<std::vector<int>> vecA,std::vector<std::vector<int>> vecB,std::vector<std::vector<int>> &vecC){
    for (size_t i = 0; i < 5; ++i)
    {
        for (size_t j = 0; j < 5; ++j)
        {
          vecC[i][j]=vecA[i][j]+vecB[i][j];
        }
        
    }
    return vecC;
}

  
std::vector<std::vector<int>> multiplyMat(std::vector<std::vector<int>> vecA,std::vector<std::vector<int>> vecB,std::vector<std::vector<int>> &vecC){
    int colsb=5,rowsa=5,colsa=5;

    for (size_t i = 0; i < rowsa; ++i)
    {
        for (size_t j = 0; j < colsb; ++j)
        {
            for (size_t k = 0; k< colsa; ++k)
            {
                vecC[i][k]+=vecA[i][j]*vecB[j][k];
            }
            
        }
        
    }
    return vecC;
}
std::vector<std::vector<double>> rotateR2(std::vector<std::vector<double>> vecA,std::vector<std::vector<double>> vecB,std::vector<std::vector<double>> &vecC){
    int colsb=1,rowsa=2,colsa=2;

    for (size_t i = 0; i < rowsa; i++)
    {
        for (size_t k= 0; k <colsb;k++)
        {
            vecC[i][k]=0;
            for (size_t j = 0; j< colsa; j++)
            {
                vecC[i][k]+=vecA[i][j]*vecB[j][k];
            }
            
        }
        
    }
    return vecC;
}

std::vector<std::vector<double>> spiralOp(std::vector<std::vector<double>> vecA,std::vector<std::vector<double>> vecB,std::vector<std::vector<double>> &vecC){
    auto r=0.95;
    int colsb=1,rowsa=2,colsa=2;
    auto k1= 0;
    
    
        for (size_t i = 0; i < rowsa; i++)
        {
            for (size_t k= 0; k <colsb;k++)
            {
                vecC[i][k]=0;
                for (size_t j = 0; j< colsa; j++)
                {
                    vecC[i][k]+=vecA[i][j]*vecB[j][k];
                }
                
            }
            
        }
                                                                       
    for (size_t i = 0; i < 2; i++)
    {
       for (size_t j = 0; j < 1; j++)
       {
           vecC[i][j]*=r;
       }
       
    }
    
    return vecC;
}
double minFunct(double x,double y) {
    return (((pow(x,4.0)-16*pow(x,2.0)+5*x)/2)+((pow(y,4.0)-16*pow(y,2.0)+5*y)/2));
}

std::vector<std::vector<double>> modelSpiral(std::vector<std::vector<double>> vecA,std::vector<std::vector<double>> vecB,std::vector<std::vector<double>> thirdParam,
std::vector<std::vector<double>> &vecC){
    auto r=0.95;
    int colsb=2,rowsa=2,colsa=2,colThird=1;
    auto k1= 0;
    std::vector<std::vector<double>> temporary={
        {0,0},
        {0,0}
    } ;
    
        for (size_t i = 0; i < rowsa; i++)
        {
            for (size_t k= 0; k <colsb;k++)
            {
                temporary[i][k]=0;
                for (size_t j = 0; j< colsa; j++)
                {
                    temporary[i][k]+=vecA[i][j]*vecB[j][k];
                }
                
            }
            
        }
                                                                       
    for (size_t i = 0; i < rowsa; i++)
        {
            for (size_t k= 0; k <colThird;k++)
            {
                vecC[i][k]=0;
                for (size_t j = 0; j< colsa; j++)
                {
                    vecC[i][k]+=temporary[i][j]*thirdParam[j][k];
                }
                
            }
            
        }
    return vecC;
}