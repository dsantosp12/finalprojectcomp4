/**
*	
*
*
*/
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "body.hpp"
#include "SpaceObject.hpp"
#include "Star.hpp"

/**
 *  @author Daniel Santos & Hung Nguyen
 *
 *  @brief  This is the namespace for the classes
 *  definition.
 * *//**
 *  @author Daniel Santos & Hung Nguyen
 *
 *  @brief  This is the namespace for the classes
 *  definition.
 * */
namespace Universe {

class Universe {
 public:
  Universe();
  ~Universe();
  void run();
  sf::Vector2f translateCoordinates(float x, float y);
  void printState();
  sf::Text& getTextTime() const;
  void setTextTime(std::string text);
  int getElapsaedTime() const;

 private:
  void fetchBody();
  void fetchStar();
  void updateTime();
  void updateUniverse();
  std::vector<Body> bodyList_;
  std::vector<Star> starList_;
  int elapsedTime_;
  sf::Font fontTime_;
  sf::Text textTime_;
};

}