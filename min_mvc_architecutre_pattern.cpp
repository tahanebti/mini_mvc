/*
*       mini MVC design pattern 
*       Author : Taha Nebti
*       github : github.com/tahanebti
*/


#include <string>
#include <iostream>
using namespace std;

namespace _tn
{
  
class Model {
  public:
    void reciveInput(const string& input){
      data = input;
    }
    string getData(){
      return data;
    }
  private:
    string data;
};

class View {
  public:
    void displayData(Model& model){
      cout<<"displaying data:"<<model.getData()<<endl;
    }
};

class Controller{
  public:
    void getAndSendUserIput(Model& model){
      cout<<"Enter input:";
      string input;
      cin>>input;
      model.reciveInput(input);
    }
};

}

#define USE_MODEL_VIEW_CONROLLER
int main()
{
  _tn::Model model;
  _tn::View view;
  _tn::Controller controller;
  #ifdef USE_MODEL_VIEW_CONROLLER
  while(true)
  {
    controller.getAndSendUserIput(model); //send user input to the model
    view.displayData(model); //display data from the model
  }
  #else
  //this is the equivalent of program without using MVC
  while(true)
  {
    cout<<"Enter input:";
    string data;
    cin>>data;
    cout<<"displaying data:"<<data<<endl;
  }
  #endif // USE_MODEL_VIEW_CONROLLER
  return 0;
}
