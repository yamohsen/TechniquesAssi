#include<iostream>
#include<fstream>
#include "PLYFile.h"

PLYFile::PLYFile()
{

}

PLYFile PLYFile::readFile(ifstream &input)
{
    std::string inputString;
    PLYFile plyfile = new PLYFile();
    //read Header
    if(std::getline(input, inputString)){
        if(inputString.find("ply") < 0 && inputString.find("PLY") < 0){
          std::cout <<"This is not a ply file: "<< _fname <<std::endl;
          exit(EXIT_FAILURE);
        }

      }


      while(std::getline(input, inputString) && inputString.find("end_header") < 0 && inputString.find("END_HEADER") < 0){
        if(inputString.compare(0,7,"comment") != 0) //ignore comment lines
        {
          if(inputString.compare(0,6, "format")){
//              plyfile.m_fileFormat = sub
              if(inputString.compare(0,7, "element"))
              {

              }
          }
        }

      }//end of read header

}
