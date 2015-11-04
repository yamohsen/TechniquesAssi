#include "ImageWrite.h"
#include "PLYFile.h"
#include <fstream>
#include <cassert>
#include <iostream>

ImageWrite::ImageWrite(int _w, int _h)
{
    m_width = _w;
    m_height = _h;
    m_data = new unsigned char [m_width*m_height*3];
}

ImageWrite::~ImageWrite()
{
  if(m_data != 0)
  {
    delete [] m_data;
  }
}


void ImageWrite::load(const std::string &_fname){

  std::ifstream input;
  std::string inputString;
  input.open(_fname);
  if(!input.is_open()){
    std::cout <<"Problem Oppening the file "<< _fname <<std::endl;
    exit(EXIT_FAILURE);
  }
//read Header
  if(std::getLine(input, inputString)){
    if(inputString.find("ply") < 0 && inputString.find("PLY") < 0){
      std::cout <<"This is not a ply file: "<< _fname <<std::endl;
      exit(EXIT_FAILURE);
    }
  }

  while(std::getline(input, inputString) && inputString.find("end_header") < 0 && inputString.find("END_HEADER") < 0){
    if(inputString.compare(0,7,"comment") != 0) //ignore comment lines
    {
      if(inputString.compare(0,7, "element"))
      {

      }
    }

  }//end of read header

  input.close();
}

void ImageWrite::save(const std::string &_fname)
{
  std::ofstream output;
  output.open(_fname);
  if(!output.is_open())
  {
    std::cout <<"Problem Oppening the file "<< _fname <<std::endl;
    exit(EXIT_FAILURE);
  }
  //Write Header
  output<<"P3\n";
  output<<m_width<<" "<<m_height<<"\n";
  output<<"255"<<"\n";


  for(int y = 0; y<m_height*m_width*3; y++)
  {
    output<<(int)m_data[y] << " ";
  }
  output<<"\n";
  output.close();

}

void ImageWrite::drawLine(int _x0, int _y0, int _x1, int _y1){

  double delta_x = _x1 - _x0;
  double delta_y = _y1 - _y0;

  double error = 0;

  double delta_error = abs(delta_y/delta_x);

  int y = _y0;
  for(int x = _x0 ; x <= _x1; x++)
  {
    setPixel(x,y,255,0,0);
    error += delta_error;
    while (error >= 0.5 && y < m_width)
    {
      setPixel(x,y,255,0,0);
      y += 1;
      error -= 1.0;
    }
  }
}

void ImageWrite::setPixel(int _x, int _y, unsigned char _r, unsigned char _g, unsigned char _b)
{
  assert(_x<=m_width && _y<=m_height);
  unsigned int index =_y*m_width*3+_x*3;
  m_data[index] = _r;
  m_data[index+1] = _g;
  m_data[index+2] = _b;
}

void ImageWrite::clear(unsigned char _r, unsigned char _g, unsigned char _b)
{
  for(int y= 0; y<m_height; ++y)
  {
    for(int x = 0; x<m_width; ++x)
    {
      setPixel(x,y,_r,_g,_b);
    }
  }
}
