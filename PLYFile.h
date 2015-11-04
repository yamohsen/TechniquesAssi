#ifndef PLYFILE_H__
#define PLYFILE_H__

#include<string>


class PLYFile
{
public:
  PLYFile();
  struct ElementType{
    std::string m_name;
    int count;
    int countOfProperties;
    Property * property_types;
  };

  struct Element{
    void * properties;
  };

  struct Property{
    std::string propertyType;
    std::string numberInListType;
    std::string list;
    std::string propertyName;
  };

 private:
  std::String m_fileFormat;
  ElementType *m_elementTypes;
  Element *m_elements;

};

#endif // PLYFILE_H
